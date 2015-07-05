class Solution {
public:
    void reverseWords(string &s) {
        //Scan the string and locate each word, overwrite redundant spaces along the way
        //Use 2 indices, 1 points to the beginning of a word, 1 points to the end
        //Reverse each word once the end pointer reaches a space
        //After the whole string is scanned, reverse it as result
        int scan = 0;
        int begin = 0;
        int end = 0;
        
        //sentinel for the last word
        if (s[s.size() - 1] != ' ') {
            s.push_back(' ');
        }
        
        const int N = s.size();
        
        while (scan < N) {
            while (s[scan] == ' ') {
                scan++;
            }
            
            while (scan < N && s[scan] != ' ') {
                s[end++] = s[scan++];
            }
            
            if (scan < N) { //s[scan] == ' '
                reverse(s, begin, end - 1);
                s[end] = ' ';   //Separation between 2 words
                end++;  //Locate to the beginning of next word after trim
                begin = end;
            }
        }
        
        if (end >= 2)
            s = s.substr(0, end - 2 + 1);
        else
            s = "";
        
        if (s.size() > 1)
            reverse(s, 0, s.size() - 1);
    }

private:
    void reverse(string &s, int begin, int end) {
        if (begin < 0 || end >= s.size())
            return;
        
        while (begin < end) {
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            
            begin++;
            end--;
        }
    }
};
