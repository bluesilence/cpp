class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        
        if (s.empty())
            return p == "*";
        
        const int SLEN = s.size();
        const int PLEN = p.size();
        
        int indexS = 0;
        int indexP = 0;
        int indexStar = -1;
        int indexMatchStar = -1;
        
        while (indexS < SLEN) {
            if (s[indexS] == p[indexP] || p[indexP] == '?') {
                indexS++;
                indexP++;
                
                continue;
            }
            
            if (p[indexP] == '*') {
                indexStar = indexP;
                indexMatchStar = indexS;
                indexP++;
                
                continue;
            }
            
            if (indexStar > -1) {
                indexS = ++indexMatchStar;
                indexP = indexStar + 1;
                
                continue;
            }
            
            return false;
        }
        
        while (indexP < PLEN && p[indexP] == '*') {
            indexP++;
        }
        
        return indexP == PLEN;
    }
};
