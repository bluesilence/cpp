class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Suppose there is no chance of overflow
        const int N = nums.size();
        vector<int> left(N, 1);   //If left/right has only 1 number, the product should be the number itself
        vector<int> right(N, 1);
        
        //result[i] = (nums[0]*...*nums[i-1])*(nums[i+1]*...*nums[N-1])
        //result[i+1] = (nums[0]*...*nums[i])*(nums[i+2]*...*nums[N-1])
        //result[i] = left[i] * right[i]
        //left[i+1] = left[i] * nums[i]
        //right[i] = right[i+1] * nums[i+1]
        //First scan, traverse from left to right, calculate left array
        //Second scan, traverse from right to left, calculate right array
        //Third scan, traverse from left to right, calculate left * right array
        
        for (int i = 0; i < N - 1; i++) {
            left[i+1] = left[i] * nums[i];
        }
        
        for (int i = N - 2; i >= 0; i--) {
            right[i] *= right[i+1] * nums[i+1];
        }
        
        for (int i = 0; i < N; i++) {
            left[i] *= right[i];
        }
        
        return left;
    }
};
