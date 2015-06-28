class Solution {
public:
    string shortestPalindrome(string s) {
        const int LEN = s.size();
        
        if (s.size() < 2)
            return s;
        
        int prefixEnd = 0;
        
        //Find the longest palindrome which is also a prefix of s
        //Then we just need to reverse (s - longest palindrome) and append it in front of s
        for (int i = 0; i <= LEN / 2;) {    //If i > LEN / 2, the palindrome centered at i is impossible to be a prefix of s
            int start = i;
            int end = i;
            
            while (end + 1 < LEN && s[end+1] == s[end]) {   //Locate the end of the center of palindrome
                end++;
            }
            
            i = end + 1;  //Locate to next center for the outer loop
            
            while (start > 0 && end + 1 < LEN && s[start-1] == s[end+1]) {
                start--;
                end++;
            }
            
            if (start == 0) {   //Found a palindrome which is also a prefix of s
                if (end > prefixEnd) {
                    prefixEnd = end;
                }
            }
        }
        
        string nonPalindrome = s.substr(prefixEnd + 1);
        reverse(nonPalindrome.begin(), nonPalindrome.end());
        
        return nonPalindrome + s;
    }
};
