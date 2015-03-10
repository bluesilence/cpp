#include <vector>;
#include <iostream>;
using namespace std;

class Solution {
public:
    int LongestAscendingSequence(vector<int> &nums) {
        if (nums.empty())
            return 0;

        int result = 1;
        int n = nums.size();

        // longestTrail[i] stands for the length of longest ascending subsequence that ends with nums[i]
        int *longestTrail = new int[n];
        //memset will fill byte by byte, so 1 won't produce correct result below:
        //memset(longestTrail, 1, sizeof(longestTrail));
        for (int i = 0; i < n; i++)
            longestTrail[i] = 1;

        for (int i = 1; i < n; i++) {
            int tempTrail = longestTrail[i];

            // Check all the candidate trails
            // longestTrail[i] = max(longestTrail[i], longestTrail[j] where (0 <= j < i && nums[j] < nums[i]) + 1)
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && longestTrail[j] + 1 > tempTrail)
                    tempTrail = longestTrail[j] + 1;
            }

            longestTrail[i] = tempTrail;
            if (tempTrail > result)
                result = tempTrail;
        }

        delete longestTrail;

        return result;
    }
};

void main() {
    Solution test;
    vector<int> inputs;
    inputs.push_back(3);
    inputs.push_back(4);
    inputs.push_back(1);
    inputs.push_back(2);
    cout<<test.LongestAscendingSequence(inputs);
}
