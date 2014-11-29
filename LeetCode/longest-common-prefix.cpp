class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (n < 1)
            return "";
        
        sort(strs.begin(), strs.end());
        
        char *temp = new char[n];
        
        //The longest possible prefix is strs[0]
        int maxLen = strs[0].size();
        int i = 0;
        while (i < maxLen) {
            //Pick the ith character of each string
            for (int j = 0; j < n; j++) {
                temp[j] = strs[j][i];
            }
            
            if (!isCommon(temp, n))
                break;
                
            i++;
        }
        
        delete temp;
        
        return strs[0].substr(0, i);
    }

private:
    bool isCommon(char* temp, int n) {
        if (!temp || n < 1)
            return false;
            
        char ch = temp[0];
        for (int i = 1; i < n; i++) {
            if (temp[i] != ch)
                return false;
        }
        
        return true;
    }
};
