class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        
        while (n > 0) {
            result += (n - 1) % 26 + 'A';   //Higher digits are added after lower digits
            n = (n - 1) / 26;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
