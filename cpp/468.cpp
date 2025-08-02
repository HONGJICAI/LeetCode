class Solution {
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        int start = 0, end = 0;
        while (end < str.size()) {
            end = str.find(delimiter, start);
            if (end == string::npos) {
                end = str.size();
            }
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        }
        return tokens;
    }
    bool isxdigit(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
               (c >= 'A' && c <= 'F');
    }
    bool isdigit(char c) { return c >= '0' && c <= '9'; }

public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            vector<string> parts = split(queryIP, '.');
            if (parts.size() != 4)
                return "Neither";
            for (const string& part : parts) {
                if (part.empty() || (part[0] == '0' && part.size() > 1) ||
                    part.size() > 3 ||
                    ranges::any_of(part, [&](char c) { return !isdigit(c); }))
                    return "Neither";
                if (auto num = stoi(part); num < 0 || num > 255)
                    return "Neither";
            }
            return "IPv4";
        } else if (queryIP.find(':') != string::npos) {
            vector<string> parts = split(queryIP, ':');
            if (parts.size() != 8)
                return "Neither";
            for (const string& part : parts) {
                if (part.empty() || part.size() > 4)
                    return "Neither";
                for (char c : part) {
                    if (!isxdigit(c))
                        return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};