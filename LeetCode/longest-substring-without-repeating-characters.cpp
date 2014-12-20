class Solution {  
public:  
    int lengthOfLongestSubstring(string s) {
        int max = 0;  
          
        // The start index of a sub string 
        int idx = 0;  
          
        // The latest occurrence of each char 
        int locs[256];  
        memset(locs, -1, sizeof(int) * 256);  
        
        for (int i = 0; i < s.size(); i++) {  
            // If s[i] already appeared in current sub string
            if (locs[s[i]] >= idx) {  
                // Set the start of next sub string to be locs[s[i]] + 1
                idx = locs[s[i]] + 1;  
            }
            
            // Update max length of sub strings 
            if (i - idx + 1 > max) {  
                max = i - idx + 1;  
            }
            
            // Update the latest occurrence of current char
            locs[s[i]] = i;  
        }
        
        return max;  
    }  
};  
