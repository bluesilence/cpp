class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        
        vector<int> charCountInS(256, 0);
        vector<int> charCountInT(256, 0);
        
        int uniqueCharsInT = 0;
        
        for (int i = 0; i < t.size(); i++) {
            if (charCountInT[t[i]] == 0) {
                uniqueCharsInT++;
            }
            
            charCountInT[t[i]]++;
        }
        
        int foundUniqueTCharsInS = 0;
        int begin = 0;
        int minBegin = -1;
        int minWidth = s.size();
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (charCountInT[c] == 0) {
                continue;
            }
            
            charCountInS[c]++;
            
            if (charCountInS[c] == charCountInT[c]) {
                foundUniqueTCharsInS++;
            }
            
            if (foundUniqueTCharsInS == uniqueCharsInT) {
                while (charCountInT[s[begin]] == 0 || charCountInS[s[begin]] > charCountInT[s[begin]]) {
                    if (charCountInS[s[begin]] > 0)
                        charCountInS[s[begin]]--;
                            
                    begin++;
                }
                    
                if (minBegin == -1 || minWidth > (i - begin + 1)) {
                    minBegin = begin;
                    minWidth = i - begin + 1;
                }
            }
        }
        
        if (minBegin == -1)
            return "";
        else
            return s.substr(minBegin, minWidth);
    }
};
