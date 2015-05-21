class Solution {
public:
    string multiply(string num1, string num2) {
        if (!isValid(num1) || !isValid(num2))
            return "";
        
        vector<int> numVec1(num1.size(), 0);
        vector<int> numVec2(num2.size(), 0);
        
        strToVec(num1, numVec1);
        strToVec(num2, numVec2);
        
        vector<int> resultVec(num1.size() + num2.size(), 0);
        
        multiplyVec(numVec1, numVec2, resultVec);
        
        return vecToStr(resultVec);
    }

private:
    bool isValid(const string &num) {
        if (num.empty())
            return false;
        
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > '9' || num[i] < '0')
                return false;
        }
        
        return true;
    }
    
    void strToVec(const string &num, vector<int> &vec) {
        const int len = num.size();
        for (int i = 0; i < len; i++) {
            vec[len - 1 - i] = num[i] - '0';
        }
    }
    
    string vecToStr(vector<int> &vec) {
        int len = vec.size();
        for (int i = len - 1; i > 0; i--) { //Preserve the only 0 at index 0
            if (vec[i] == 0)
                vec.pop_back(); //Remove redundant 0 at highest digit
            else
                break;
        }
        
        len = vec.size();
        string result;
        
        for (int i = len - 1; i >= 0; i--) {
            result += vec[i] + '0';
        }
        
        return result;
    }
    
    void multiplyVec(vector<int> &numVec1, vector<int> &numVec2, vector<int> &resultVec) {
        const int len1 = numVec1.size();
        const int len2 = numVec2.size();
        
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                resultVec[i + j] += numVec1[i] * numVec2[j];
            }
        }
        
        int carry = 0;
        for (int i = 0; i < len1 + len2; i++) {
            resultVec[i] += carry;
            carry = resultVec[i] / 10;
            resultVec[i] -= 10 * carry;
        }
    }
};
