class Solution {
public:
    // For each individual slot, the capacity depends on the leftHighest and rightHighest
    // The naive solution will be O(N*N)
    // We can use DP to optimize, and get the list leftHighest and rightHighest in O(N)
    // The overall time complexity can be reduced to O(N)
    int trap(int A[], int n) {
        vector<int> leftHighest, rightHighest;
        
        int highest=0;
        for(int i = 0;i < n;i++){
            leftHighest.push_back(highest);
            highest = max(highest, A[i]);
        }
        
        highest=0;
        for(int i = n - 1;i >= 0;i--){
            rightHighest.push_back(highest);
            highest = max(highest, A[i]);
        }
        
        reverse(rightHighest.begin(), rightHighest.end());
        
        int water = 0;
        for(int i=0;i<n;i++){
            water += max(0, min(leftHighest[i], rightHighest[i]) - A[i]);
        }
        
        return water;
    }
};
