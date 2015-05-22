class Solution {
public:
    bool isMatch(string s, string p) {
        //Scan each character of s
        //If s reaches its end && p reaches it end, return true
        //If current character is '*',
        //Record the current position of s and p, move p's index forward to continue normal matching
        //If normal matching failed, reload the position of s and p, move both s's and p's indices forward, record the new position of sIndex, then continue normal matching
        
        int sIndex = 0, pIndex = 0;
        int starIndex = -1;
        int lastSIndex = -1;
        while (sIndex < s.size()) {
            if (s[sIndex] == p[pIndex] || p[pIndex] == '?') {
                sIndex++;
                pIndex++;
                
                continue;
            }
            
            if (p[pIndex] == '*') {
                starIndex = pIndex;
                lastSIndex = sIndex;
                pIndex++;
                
                continue;
            }
            
            if (starIndex > -1 && lastSIndex > -1) {
                sIndex = lastSIndex + 1;
                pIndex = starIndex + 1;
                lastSIndex = sIndex;
                
                continue;
            }
            
            return false;
        }
        
        while (pIndex < p.size() && p[pIndex] == '*') {
            pIndex++;
        }
        
        return pIndex == p.size();
    }
};
