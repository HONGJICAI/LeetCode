class Solution {
    const string colors = "RYBGW";
    class Map {
        uint32_t container = 0;
        int getBitPos(char color) {
            switch (color) {
                case 'R': return 0;
                case 'Y': return 4;
                case 'B': return 8;
                case 'G': return 12;
                case 'W': return 16;
            }
            return -1;
        }
public:
        Map(unordered_map<char, int> &map) {
            for (auto& [color, cnt]: map) {
                set(color, cnt);
            }
        }
        Map(const Map& map) {
            container = map.container;
        }
        bool contains(char color) {
            auto pos = getBitPos(color);
            return ((container >> pos) & 15) > 0;
        }
        bool empty() {
            return container == 0;
        }
        void set(char color, int val) {
            auto pos = getBitPos(color);
            uint32_t mask = ~(0b1111 << pos);
            container &= mask;
            container |= val << pos;
        }
        int get(char color) {
            auto pos = getBitPos(color);
            return container << (28 - pos) >> 28;
        }
        void take(char color) {
            auto val = get(color);
            set(color, val - 1);
        }
        void add(char color) {
            auto val = get(color);
            set(color, val + 1);
        }
    };
    using Node = pair<string, Map>;
    string compute(string& s, int idx, char color) {
        const char NoColor = 'X';
        int l = idx - 1, r = idx;
        bool remove = false;        
        for (char lc = s[idx], rc = s[idx]; (l >= 0 || r < s.size()) && (color == lc || color == rc); ) {
            int stepL = 0, stepR = 0;
            while (l - stepL >= 0 && s[l - stepL] == lc && lc == color)
                ++stepL;
            while (r + stepR < s.size() && s[r + stepR] == lc && rc == color)
                ++stepR;
            if (stepL + stepR + (remove == false) > 2) {
                remove = true;
                l -= stepL;
                r += stepR;
            } else {
                break;
            }
            lc = l >= 0 ? s[l] : NoColor;
            rc = r < s.size() ? s[r] : NoColor;
            color = lc == NoColor ? rc : lc;
        }
        if (!remove) return s.substr(0, idx) + color + s.substr(idx);
        return s.substr(0, l + 1) + s.substr(r);
    }
    int bfs(list<Node>& li) {
        list<Node> next;
        unordered_set<string> nextSet;
        for (auto& [board, map]: li) {
            if (map.empty()) return -1;
            for (auto color: colors) {                
                if (!map.contains(color)) 
                    continue;
                for (int i = 1; i <= board.size(); ++i) {
                    if (board[i] == board[i - 1] || board[i] == color || board[i - 1] == color){ // key
                        auto newBoard = compute(board, i, color);
                        if (newBoard.size() == 0) {
                            return 1;
                        } else if (!nextSet.contains(newBoard)) {
                            map.take(color);
                            nextSet.insert(newBoard);
                            next.push_back(make_pair(newBoard, map));
                            map.add(color);
                        }
                        if (board.size() > newBoard.size()) {                            
                            while (i <= board.size() && board[i] == color) ++i;
                        }                     
                    }
                }
            }
        }
        if (auto res = bfs(next); res != -1) return 1 + res;
        return -1;
    }
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> handMap, boardMap;
        for (auto c: hand)
            ++handMap[c];
        for (auto c: board)
            ++boardMap[c];
        if (ranges::any_of(boardMap, [&](auto& p) { return p.second + handMap[p.first] <= 2;}))
            return -1;
        list<Node> l = { make_pair(board, Map(handMap)) };
        return bfs(l);
    }
};