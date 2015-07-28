class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        
        const int SLEN = haystack.length();
        const int PLEN = needle.length();
        
        vector<int> pattern = findPattern(needle);
        
        int i = 0;
        int j = 0;
        
        while (i < SLEN && j < PLEN) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = pattern[j-1] + 1;
                } else {
                    i++;
                }
            }
        }
        
        if (j == PLEN) {
            return i - PLEN;
        } else {
            return -1;
        }
    }

private:
    vector<int> findPattern(const string& needle) {
        const int N = needle.size();
        vector<int> pattern(N, -1);
        
        int i = 0;
        int j = 1;
        
        while (j < N) {
            if (needle[i] == needle[j]) {
                pattern[j] = i;
                i++;
                j++;
            } else {
                if (i > 0) {
                    i = pattern[i-1] + 1;
                } else {
                    j++;
                }
            }
        }
        
        return pattern;
    }
};
