class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size() - 1;
        
        while (begin < end) {
            while (begin < end && !isValidChar(s[begin]))
                begin++;
            while (begin < end && !isValidChar(s[end]))
                end--;
            if (toLower(s[begin]) == toLower(s[end])) {
                begin++;
                end--;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool isValidChar(char c) {
        return c >= 'A' && c <= 'Z' ||  c >= 'a' && c <= 'z' || c >= '0' && c <= '9';
    }
    
    char toLower(char c) {
        if (c <= 'Z' && c >= 'A')
            return c + 'a' - 'A';
        else return c;
    }
};
