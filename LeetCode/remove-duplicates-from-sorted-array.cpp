class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
            
        int pos = 0;  //Position to copy each distinct number
        int key = A[0]; //Record each distinct number
        for(int i = 1; i < n; i++) {
            if (A[i] != key) {
                A[pos++] = key;
                key = A[i];                
            }
        }
        
        //Important: copy last distinct number
        A[pos++] = key;
        
        return pos;
    }
};
