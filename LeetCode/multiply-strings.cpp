class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "";
        
        if (!isValidNum(num1) || !isValidNum(num2))
            throw "Invalid number string";
            
        vector<int> v1 = convertStrToVec(num1);
        vector<int> v2 = convertStrToVec(num2);
        
        vector<int> result(num1.size()+num2.size(), 0);

        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                result[i+j] += v1[i] * v2[j];
            }
        }
        
        for (int k = 0; k+1 < result.size(); k++) {
            if (result[k] > 9) {    //Carry to next digit
                result[k+1] += result[k]/10;
                result[k] %= 10;
            }
        }
        
        return convertVecToStr(result);
    }

private:
    bool isValidNum(string num) {
        if (num.empty())
            return false;
        
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < '0' || num[i] > '9')
                return false;
        }
        
        return true;
    }
    
    vector<int> convertStrToVec(string &num) {
        vector<int> result(num.size(), 0);
        for (int i = 0; i < num.size(); i++) {
            result[i] = num[num.size()-1-i] - '0';
        }
        
        return result;
    }
    
    string convertVecToStr(vector<int> &vec) {
        string result = "";
        int highestDigit = vec.size() - 1;
        while (highestDigit >= 1 && vec[highestDigit] == 0)	//If highestDigit = 0, then num = 0
            highestDigit--;
            
        for (int i = highestDigit; i >= 0; i--) {
            result += vec[i] + '0';
        }
        
        return result;
    }
};
