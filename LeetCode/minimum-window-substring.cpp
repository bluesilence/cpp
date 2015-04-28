class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        
        if (t == s)
            return s;
        
        int alphaCountS[256];
        int alphaCountT[256];
        int uniqueAlphaCountT = 0;
        int allAlphaFoundCountS = 0;
        
        memset(alphaCountS, 0, sizeof(alphaCountS));
        memset(alphaCountT, 0, sizeof(alphaCountT));
        
        for (int i = 0; i < t.size(); i++) {
            if (alphaCountT[t[i]] == 0)
                uniqueAlphaCountT++;
            
            alphaCountT[t[i]]++;
        }
        
        int start = 0;
        int minWidth = s.size();
        int minStart = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (alphaCountT[s[i]] == 0) //The character hasn't appeared in t
                continue;
                
            alphaCountS[s[i]]++;
            //Once allAlphaFoundCountS == uniqueAlphaCountT, in the expansion to right, we always have alphaCountS[s[i]] > alphaCountT[s[i]]
            //If alphaCountS[s[i]] > alphaCountT[s[i]], just go to L38 and contract left boundary to right
            if (alphaCountS[s[i]] == alphaCountT[s[i]])
                allAlphaFoundCountS++;
            
            if (allAlphaFoundCountS == uniqueAlphaCountT) { //Found all alphas in target
                //Even if alphaCountS[s[i]] > alphaCountT[s[i]], no need to contract window with regard to j
                //Because in this case, (i - start + 1) >= minWidth, the global minimum won't be affected
                while (alphaCountT[s[start]] == 0 || alphaCountS[s[start]] > alphaCountT[s[start]]) {   //Move left pointer to right
                    if (alphaCountS[s[start]] > 0)
                        alphaCountS[s[start]]--;
                        
                    start++;
                }
                
                //Important: (minStart == -1) is added here, otherwise if (i - start + 1) == s.size(), minStart won't be updated 
                if (minStart == -1 || i - start + 1 < minWidth) {   
                    minWidth = i - start + 1;
                    minStart = start;
                }
            }
        }
        
        if (minStart == -1)
            return "";
        else
            return s.substr(minStart, minWidth);
    }
};
