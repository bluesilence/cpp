class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty())
            return true;
        
        return matchCore(s, 0, p, 0);
    }

private:
    bool matchCore(string s, int sBegin, string p, int pBegin) {
        if (sBegin == s.size() && pBegin == p.size())
            return true;
        
        char pChar = p[pBegin];
        bool result = false;
        if (pBegin + 1 < p.size()) {
            char pCharNext = p[pBegin + 1];
        
            if (pCharNext == '*') {
                result = matchCore(s, sBegin, p, pBegin + 2);
                while (!result && sBegin < s.size() && (s[sBegin] == pChar || pChar == '.')) {
                    sBegin++;
                    result = matchCore(s, sBegin, p, pBegin + 2);
                }
            }
        }
        
        if (!result) {
            result = (s[sBegin] == p[pBegin] || p[pBegin] == '.') && matchCore(s, sBegin + 1, p, pBegin + 1);
        }
        
        return result;
    }
};
