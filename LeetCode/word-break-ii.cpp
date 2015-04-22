class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length() + 1, false); //dp[i] stands for if sbustring[0, i-1] can be map to dict
        dp[0] = true;
        
        for (int i = 0; i < s.length(); i++) {
            if (dp[i]) {
                for (int len = 1; i + len <= s.length(); len++) {
                    if (dict.find(s.substr(i, len)) != dict.end()) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        
        vector<string> results;
        string result = "";
        if (dp[s.length()]) 
            breakWord(results, s, dict, result, 0, dp);
            
        return results;
    }

private:
    void breakWord(vector<string> &results, string &s, unordered_set<string> &dict, string str, int index, vector<bool> &dp) {
        string substr;
        for (int len = 1; index + len <= s.length(); len++) {
            //s[0, index+len-1] can be mapped to dict, where s[index, index+len-1] is an existing word in the dict
            if (dp[index + len] && dict.find(s.substr(index, len)) != dict.end()) {
                substr = s.substr(index, len);
                if (index + len < s.length()) {
                    breakWord(results, s, dict, str + substr + " ", index + len, dp);
                } else {
                    results.push_back(str + substr);
                    return;
                }
            }
        }
    }
    
};
