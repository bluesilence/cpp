class Solution {
public:
    bool isMatch(const char *s, const char *p) {   
        if (*p == 0)
            return *s == 0;  
            
        if (*(p+1) != '*')  {  
            if (*s != 0 && (*p == *s || *p == '.'))
                return isMatch(s+1, p+1);
            else 
                return false;
        } else { // *(p+1) == '*'  
            while (*s != 0 && (*s == *p || *p == '.')) { //Try to match *p for (0~n) times 
                if (isMatch(s, p+2))
                    return true;
                    
                s++;  
            }
            
            //Skip *p and *(p+1), try to match from *(p+2). Catch tail cases (*s == 0)
            return isMatch(s, p+2);  
        }  
    }
};
