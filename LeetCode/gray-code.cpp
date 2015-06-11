class Solution {
public:
    vector<int> grayCode(int n) {
        //The digit 1~n is set to 1 in order
        //For i <- 1 to n, for the digits other than highest digits, the order is the reverse order of them in results
        vector<int> results;
        
        if (n < 0)
            return results;
        
        results.push_back(0);
        
        for (int i = 0; i < n; i++) {
            int highestDigit = 1 << i;
            
            for (int j = results.size() - 1; j >= 0; j--) {
                results.push_back(highestDigit + results[j]);
            }
        }
        
        return results;
    }
};
