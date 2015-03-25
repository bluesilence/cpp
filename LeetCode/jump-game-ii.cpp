class Solution {
public:
    int jump(int A[], int n) {
        int minJumps = 0;
        int currentMaxReachablePosition = 0;
        int currentReachablePosition = 0;
        
        for(int i = 0; i < n; i++) {
            if(currentReachablePosition < i && currentMaxReachablePosition >= i) {   //Cannot reach position i unless give it another jump
                minJumps++;
                currentReachablePosition = currentMaxReachablePosition;
            }
            
            currentMaxReachablePosition = max(currentMaxReachablePosition, A[i] + i);
        }
        
        return minJumps;
    }
};
