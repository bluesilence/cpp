class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nSize = num.size();
        vector<vector<int> > results;
        if (nSize < 4)
            return results;
        
        sort(num.begin(), num.end());
        vector<int> result(4);
        set<string> uniqueResults;
        
        for (int i = 0; i < nSize - 3; i++) {
            result[0] = num[i];
            for (int j = i + 1; j < nSize - 2; j++) {
                result[1] = num[j];
                int k = j + 1;
                int m = nSize - 1;
                int sum = target - num[i] - num[j];
                while(k < m) {
                    int tmp = num[k] + num[m];
                    if (sum == tmp) {
                        string str;
                        str += num[i];
                        str += num[j];
                        str += num[k];
                        str += num[m];
                        if (uniqueResults.find(str) == uniqueResults.end()) {
                            uniqueResults.insert(str);
                            result[2] = num[k];
                            result[3] = num[m];
                            results.push_back(result);
                        }
                        
                        k++;
                        m--;
                    }
                    else if(sum > tmp) {
                        k++;
                    } else {
                        m--;
                    }
                }
            }
        }

        return results;
    }
};
