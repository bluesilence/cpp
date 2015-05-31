class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Use 2 pointers to constrain the range of substring without repeating letters
        //Use a set to record the distinct letters of the substring
        if (s.empty())
            return 0;
        
        int begin = 0;
        int end = 0;
        
        bool occurredChar[256] = {  false };
        
        int maxLen = 0;
        int tmpLen = 0;
        while (end < s.size()) {
            if (occurredChar[s[end]] == false) {  //Move the window to right
                occurredChar[s[end]] = true;
                end++;
                tmpLen++;
                
                maxLen = maxLen > tmpLen ? maxLen : tmpLen;
            } else {    //Shrink the window from left
                occurredChar[s[begin]] = false;
                begin++;
                tmpLen--;
            }
        }
        
        return maxLen;
    }
};
