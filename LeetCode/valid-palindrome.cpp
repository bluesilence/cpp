class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 1)
            return true;
        
        int start = 0;
        int end = s.size() - 1;
        
        while (start < end) {
            while (start < end && !isAlphaNumeric(s[start]))
                start++;
            
            while (start < end && !isAlphaNumeric(s[end]))
                end--;
                
            if (toLower(s[start]) != toLower(s[end]))
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }

private:
    bool isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9');
    }
    
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        else
            return c;
    }
};
