class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        sort(strs.begin(), strs.end());
        
        string prefix = "";
        
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return prefix;
                }
            }
            
            prefix += c;
        }
        
        return prefix;
    }
};
