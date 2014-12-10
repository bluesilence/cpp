class Solution {
public:
    string addBinary(string a, string b) {
        if ("0" == a)
            return b;
        
        if ("0" == b)
            return a;
            
       string result = "";
       int indexA = a.length() - 1;
       int indexB = b.length() - 1;
       
       int carry = 0;
       int sum = 0;
       while (indexA >= 0 || indexB >= 0) {
		   sum = carry;
		   
		   //Add digit by digit
		   sum += indexA >= 0 ? a[indexA--] - '0' : 0;
		   sum += indexB >= 0 ? b[indexB--] - '0' : 0;
		   
		   char digit = (sum & 0x01) + '0';
		   result = digit + result;
		   carry = sum >> 1;
       }
       
	   if (carry)
		   result = '1' + result;

       return result;
    }
};
