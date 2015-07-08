class Solution {
public:
    //The best video to learn kmp: https://www.quora.com/What-is-the-best-resource-to-learn-KMP-Algorithm
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
        if (haystack.empty()) {
            return -1;
        }
        
        const int M = haystack.size();
        const int N = needle.size();
        
        vector<int> next(N, -1);
        
        genNext(needle, N, next);
        
        int i = 0;
        int j = 0;
        
        while (i < M && j < N) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    while (j > 0 && needle[j] != haystack[i]) {
                        j = next[j-1] + 1;
                    }
                }
            }
        }
        
        if (j == N)
            return i - j;
        else
            return -1;
    }

private:
    void genNext(string &needle, const int N, vector<int> &next) {
        if (needle.empty())
            return;
        
        next[0] = -1;
        
        int i = 1;
        int j = 0;
        
        while (i < N) {
            if (needle[i] == needle[j]) {
                next[i++] = j++;
            } else {
                if (j == 0) {
                    next[i++] = -1;
                } else {
                    while (j > 0 && needle[j] != needle[i]) {
                        j = next[j-1] + 1;
                    }
                }
            }
        }
    }
};
