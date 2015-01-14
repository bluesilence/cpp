class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> strs;
        for_each(num.begin(), num.end(), [&](int i) {
            strs.push_back(to_string(i));
        });
        
        //If a concats b > b concats a, put a before b
        sort(strs.begin(), strs.end(), [&](const string& a, const string& b) {
           return (a + b) > (b + a); 
        });
        
        string result = "";
        for_each(strs.begin(), strs.end(), [&](string& s) {
            if (result == "" && s == "0")  //Largest number is 0
                return;
            result += s;
        });
        
        return result == "" ? "0" : result;
    }
};
