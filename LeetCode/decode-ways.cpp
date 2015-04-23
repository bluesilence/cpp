class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
            
        int size = s.size();
        if (size == 1)
            return 1;
        
        vector<int> f(size , 0);   //f[i] indicates how many ways to decode till index i in string s
        
        f[0] = 1;
        f[1] = 2;
        
        //Special cases: s[1] == '0'
        if (s[1] == '0' && (s[0] == '1' || s[0] == '2'))    //s[0] and s[1] form 10 and 20. s[1] cannot be decoded as 1 digit '0'
            f[1] = 1;
        
        //Special cases: s[1] == '0' 
        if (s[1] == '0' && !(s[0] == '1' || s[0] == '2'))   //30, 40, ..., 90 are invalid codes
            return 0;
            
        if (s[0] == '2' && s[1] > '6' || s[0] > '2')    //s[0] and s[1] cannot form 2-digit-number which <= 26, the only way to decode s[1] is to decode it as 1 digit
            f[1] = 1;
        
        for(int i = 2; i < size; i++) {
            f[i] = f[i-1];    //Decode digit i as 1-digit number
            if(s[i] == '0' && (s[i-1] == '1' || s[i-1] == '2')) { //10 and 20
                f[i] = f[i-2];
                continue;
            }
            
            if(s[i] == '0' && !(s[i-1] == '1' || s[i-1] == '2'))  //Invalid code
                return 0;
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6'))   //Decode digit i with digit (i-1) as 2-digit number
                f[i] += f[i-2];
        }
        
        return f[size-1];
    }
};
