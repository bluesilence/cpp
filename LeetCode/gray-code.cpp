class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i = 0; i < n; i++){
            int highest = 1<<i;
            int len = result.size();
            for(int j = len - 1; j >= 0; j--){
                result.push_back(highest + result[j]);
            }
        }
        
        return result;
    }
};
