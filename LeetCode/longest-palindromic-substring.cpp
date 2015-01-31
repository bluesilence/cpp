class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int longestLen = 1;
        int tempLen = 1;
        int start = 0;
        int end = 0;
        for (int i = 0; i < len; i++) {
            maxPalindromeLen(s, len, i, tempLen, start, end);
        }
        
        return s.substr(start, end - start + 1);
    }

private:
    //Find the longest palindrome centered from each character of the string
    int maxPalindromeLen(string s, int len, int index, int &tempMax, int &start, int &end) {
        if (len < 2)
            return len;
        
        int oddStart = index - 1, oddEnd = index + 1;
        while (oddStart >= 0 && oddEnd < len && s[oddStart] == s[oddEnd]) {
            oddStart--;
            oddEnd++;
        }
        
        int maxLenOdd = oddEnd - oddStart - 1;
        
        int evenStart = index - 1, evenEnd = index;
        while (evenStart >= 0 && evenEnd < len && s[evenStart] == s[evenEnd]) {
            evenStart--;
            evenEnd++;
        }
        
        int maxLenEven = evenEnd - evenStart - 1;
        
        if (maxLenOdd > maxLenEven && maxLenOdd > tempMax) {
            start = oddStart + 1;
            end = oddEnd - 1;
            tempMax = maxLenOdd;
        } else if (maxLenEven > maxLenOdd && maxLenEven > tempMax) {
            start = evenStart + 1;
            end = evenEnd - 1;
            tempMax = maxLenEven;
        }
    }
};
