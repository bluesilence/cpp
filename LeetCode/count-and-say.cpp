class Solution {
public:
    string countAndSay(int n) {
        //What about negative integers? They might overflow.
        long long ln = n;
        
        if (ln < 0)
            return '-' + countAndSayCore(0 - ln);
        else
            return countAndSayCore(ln);
    }

private:
    string countAndSayCore(long long n) {
        string num = itoa(n);
        
        string result = "";
        
        char pre = num[0];
        int count = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == pre) {
                count++;
            } else {
                result += itoa(count) + pre;
                
                pre = num[i];
                count = 1;
            }
        }
        
        //Adding last group of duplicate digits
        result += itoa(count) + pre;
        
        return result;
    }
    
    string itoa(long long n) {
        if (n == 0)
            return "0";
            
        string result = "";
        
        int digit = 0;
        while (n) {
            digit = n % 10;
            char digitChar = digit + '0';
            result = digitChar + result;
            n /= 10;
        }
        
        return result;
    }
};
