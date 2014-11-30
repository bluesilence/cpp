class Solution {
public:
    void reverseWords(string &s) {
        //Reverse each word seperated by space
        int begin = 0, end = 0;
        while (begin < s.size() && s[begin] == ' ')
            begin++;
                    
        if (begin == s.size()) //All spaces
            s = "";
        
        end = begin;
        while (end < s.size()) {
            while (end < s.size() && s[end] != ' ')
                end++;
            
            reverse(s, begin, end - 1);
            if (end < s.size()) {
                //Skip the spaces between words
                while (end < s.size() && s[end] == ' ')
                    end++;
                    
                begin = end;
            }
        }
        
        //Reverse the whole sentence
        reverse(s, 0, s.size() - 1);
        
        //Trim spaces
        begin = 0;
        end = s.size() - 1;
        while (begin < s.size() && s[begin] == ' ')
            begin++;
        
        while (end > begin && s[end] == ' ' )
            end--;
            
        string ss;
        for (int i = begin; i <= end; i++) {
            if (s[i] != ' ' || (i > 0 && s[i-1] != ' '))    //Trim duplicate spaces between words
                ss.push_back(s[i]);
        }
        
        s = ss;
    }

private:
    void reverse(string &s, int begin, int end) {
        if (begin < 0 || end >= s.size() || begin >= end)
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
