class SolutionSearch { // only beat 5%
    bool emptyPattern(auto itP, auto itPE) {
        for (;itP != itPE; ++itP) {
            if ((*itP >= 'a' && *itP <= 'z') || *itP == '.')
                return false;
        }
        return true;
    }
    bool search(auto itS, auto itP, auto itSE, auto itPE) {
        while(itS != itSE && itP != itPE) {
            if (*itS == *itP) {
                ++itS, ++itP;
            } else if (*itP == '.') {                
                ++itS, ++itP;
            } else {
                if (*itP == '!') {
                    for (auto it = itS; it <= itSE; ++it)
                        if (search(it, itP + 1, itSE, itPE))
                            return true;
                } else if (*itP >= 'A' && *itP <= 'Z') {                    
                    if (search(itS, itP + 1, itSE, itPE)) // zero
                        return true;
                    char ch = *itP - 'A' + 'a';
                    for (auto it = itS; it <= itSE; ++it){
                        if (search(it, itP + 1, itSE, itPE))
                            return true;
                        if (it != itSE && *it != ch)
                            break;
                    }
                }
                return false;
            }
        }
        return itS == itSE && emptyPattern(itP, itPE);
    }
public:
    bool isMatch(string s, string p) {
        string newP; // aA.!
        for (auto ch: p) {
            if (ch == '*') {
                auto preCh = newP.back();
                newP.pop_back();
                newP.push_back(preCh == '.' ? '!' : preCh - 'a' + 'A');
            } else {
                newP += ch;
            }
        }
        return search(s.begin(), newP.begin(), s.end(), newP.end());
    }
};