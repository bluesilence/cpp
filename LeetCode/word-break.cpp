class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        //s[i...j] can be segmented if s[i...k] can be segmented and s[k+1...j] is found in the dict
        const int LEN = s.size();
        vector<bool> canBreak(LEN + 1);
        canBreak[0] = true;
        
        for (int len = 1; len <= LEN; len++) {
            for (int i = len - 1; i >= 0; i--) {
                if (canBreak[i] && wordDict.find(s.substr(i, len - i)) != wordDict.end()) {
                    canBreak[len] = true;
                    break;
                }
            }
        }
        
        return canBreak[LEN];
    }
};
