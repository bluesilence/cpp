class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s || *s == '\0')
            return 0;
            
        //Move pointer to the begin and end of the last word
        int endIndex = 0;
        while (s[endIndex] != '\0')
            endIndex++;
            
        endIndex--;
        while (endIndex >= 0 && s[endIndex] == ' ') //Exclude space at the end
            endIndex--;
        
        if (-1 == endIndex) {   //Empty string with only spaces
            return 0;
        } else {
            endIndex++;
            int beginIndex = endIndex - 1;
            while (beginIndex >= 0 && s[beginIndex] != ' ')
                beginIndex--;
            
            //Consider special case where there is only 1 word and no space
            if (-1 == beginIndex)
                return endIndex;
            else
                return endIndex - beginIndex - 1;
        }
    }
};
