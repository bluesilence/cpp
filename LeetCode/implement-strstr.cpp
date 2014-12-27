class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (!needle || *needle == '\0')
            return 0;
            
        if (!haystack || *haystack == '\0')
            return -1;
        
        int *next = new int[strlen(needle)];
        getNext(needle, next);
        
        int i = 0, j = 0;
        while (haystack[i] != '\0') {
            while (j >= 0 && needle[j] != haystack[i]) {
                j = next[j];
            }
            
            ++i;
            ++j;
            
            if (needle[j] == '\0') {
                delete next;
                return i - j;
            }
        }
        
        delete next;
        return -1;
    }

private:
    void getNext(char *needle, int *next) {
        int i = 0, j = -1;
        next[i] = j;
        
        while (needle[i + 1] != '\0') {
            while (j >= 0 && needle[j] != needle[i]) {
                j = next[j];
            }
            
            ++i;
            ++j;
            next[i] = j;
        }
    }
};
