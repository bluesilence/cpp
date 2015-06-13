class Solution {
public:
    //The best video to learn kmp: https://www.quora.com/What-is-the-best-resource-to-learn-KMP-Algorithm
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        
        if (haystack.empty())
            return -1;
        
        vector<int> next(needle.size(), 0);
        
        genNext(needle, next);
        
        int hIndex = 0;
        int nIndex = 0;
        
        while (nIndex < needle.size() && hIndex < haystack.size()) {
            if (needle[nIndex] == haystack[hIndex]) {
                nIndex++;
                hIndex++;
            } else {
                if (nIndex == 0) {
                    hIndex++;
                } else {
                    while (nIndex > 0 && needle[nIndex] != haystack[hIndex]) {
                        nIndex = next[nIndex-1] + 1;
                    }
                }
            }
        }
        
        if (nIndex == needle.size()) {
            return hIndex - nIndex;
        } else {    //Not found
            return -1;
        }
    }

private:
    void genNext(string &needle, vector<int> &next) {
        next[0] = -1;
        
        int i = 1;
        int j = 0;
        
        while (i < needle.size()) {
            if (needle[i] == needle[j]) {
                next[i] = j;
                i++;
                j++;
            } else {
                while (j > 0 && needle[i] != needle[j]) {
                        j = next[j-1] + 1;
                }
                
                if (j == 0) {
                    next[i] = -1;
                    i++;
                }
            }
        }
    }
};
