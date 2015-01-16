class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        int closestSum = 0;
        int numSize = num.size();
        int tmpSum = 0;
        bool isFirstSum = true;
        
        
        for (int i = 0; i < numSize; i++) {
            int j = i + 1;
            int k = num.size() - 1;
            
            while(j < k) {
                tmpSum = num[i] + num[j] + num[k];
                if (isFirstSum) {
                    closestSum = tmpSum;
                    isFirstSum = false;
                } else if (abs(tmpSum - target) < abs(closestSum - target)) {
                    closestSum = tmpSum;                                         
                }
                
                //Found closest, no need to continue
                if (closestSum == target)
                    return closestSum;
                
                //Similar to 2-partitioned search, move index according to the difference between current sum and target
                if (tmpSum > target)
                    k--;
                else
                    j++;
            }
        }
        
        return closestSum;
    }
};
