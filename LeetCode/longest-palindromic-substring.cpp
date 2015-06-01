class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        
        int tmpLen = 0;
        int maxLen = 0;
        int tmpStart = 0;
        int tmpEnd = 0;
        int maxStart = 0;
        int maxEnd = 0;
        
        for (int i = 0; i + 1 < s.size(); i++) {
            longestPalindrome(s, i, tmpStart, tmpEnd);
            tmpLen = tmpEnd - tmpStart + 1;
            if (tmpLen > maxLen) {
                maxLen = tmpLen;
                maxStart = tmpStart;
                maxEnd = tmpEnd;
            }
        }
        
        return s.substr(maxStart, maxEnd - maxStart + 1);
    }

private:
    void longestPalindrome(const string &s, int centre, int &start, int &end) {
        if (centre < 0 || centre >= s.size())
            return;
        
        int evenStart = 0;
        int evenEnd = 0;
        //Even length palindrome
        if (s[centre] == s[centre + 1]) {
            evenStart = centre;
            evenEnd = centre + 1;
            while (evenStart > 0 && evenEnd + 1 < s.size() && s[evenStart - 1] == s[evenEnd + 1]) {
                evenStart--;
                evenEnd++;
            }
        }
        
        int oddStart = 0;
        int oddEnd = 0;
        //Odd length palindrome
        if (centre > 0 && s[centre - 1] == s[centre + 1]) {
            oddStart = centre - 1;
            oddEnd = centre + 1;
            while (oddStart > 0 && oddEnd + 1 < s.size() && s[oddStart - 1] == s[oddEnd + 1]) {
                oddStart--;
                oddEnd++;
            }
        }
        
        int evenLen = evenEnd - evenStart + 1;
        int oddLen = oddEnd - oddStart + 1;
        if (evenLen > oddLen) {
            start = evenStart;
            end = evenEnd;
        } else {
            start = oddStart;
            end = oddEnd;
        }
    }
};
