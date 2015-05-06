class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        
        if (haystack.empty())
            return -1;
        
        vector<int> next(needle.size(), 0);
        genNext(needle, next);
        
        int i = 0, j = 0;
        while (i < haystack.size()) {
            while (j >= 0 && needle[j] != haystack[i]) {
                j = next[j];
            }
            
            i++;
            j++;
            
            if (j == needle.size()) {   //matched needle
                return i - j;
            }
        }
        
        return -1;
    }

private:
    void genNext(string &needle, vector<int> &next) {
        int i = 0, j = -1;
        next[i] = j;
        
        while (i + 1 < needle.size()) {
            while (j >= 0 && needle[j] != needle[i]) {
                j = next[j];
            }
            
            //Now needle[i] == needle[j], next character that need to compare is (i+1) and (j+1)
            ++i;
            ++j;
            next[i] = j;
        }
    }
};
