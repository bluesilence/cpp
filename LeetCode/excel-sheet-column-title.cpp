class Solution {
public:
    string convertToTitle(int n) {
        if(n < 1) {
            return "";
        } else {
            string result = "";
            while(n) {  //get every letter in n from right to left
                //This is very important to map to 0~25
                n--;
                result += n % alphabetCount + 'A';
                n /= alphabetCount;
            }
            
            reverse(result.begin(), result.end());
            return result;
        }
    }

private:
    const int alphabetCount = 26;
};
