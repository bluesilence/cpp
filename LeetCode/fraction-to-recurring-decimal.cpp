class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //Integral part
        if (denominator == 0)
            throw "DivideByZero";
        
        if (numerator == 0)
            return "0";
        
        bool signNumerator = numerator > 0;
        bool signDenominator = denominator > 0;
        
        long long numeratorLong = abs((long long)numerator);
        long long denominatorLong = abs((long long)denominator);
        
        string integralPart = to_string(numeratorLong / denominatorLong);
        
        //If the signs are different, the result is negative
        string result = (signNumerator ^ signDenominator) ? "-" : "";
        result += integralPart;
        
        long long rem = numeratorLong % denominatorLong;
        
        if (rem == 0)
            return result;
        
        //Fractional part
        result += '.';
        
        int index = 1;
        
        //Record the first occurrence of a remainder
        map<int, int> remPosMap;
        
        char digitQuotient;
        
        rem *= 10;  //First "* 10" doens't append an extra '0'
        remPosMap[rem] = result.size(); //Record the start of first remainder
        
        while (rem) {
            while (rem < denominatorLong) {
                rem *= 10;
                result += '0';
                remPosMap[rem] = result.size(); //Remember to record this remainder too!
            }
            
            digitQuotient = rem / denominatorLong + '0';
            result.push_back(digitQuotient);
            
            rem %= denominatorLong;
            rem *= 10;  //Like L33, form the new numerator
            
            if (remPosMap.find(rem) != remPosMap.end()) {
                result = result.substr(0, remPosMap[rem]) + "(" + result.substr(remPosMap[rem]) + ")";
                
                break;
            } else {
                remPosMap[rem] = result.size();
            }
        }

        return result;
    }
};
