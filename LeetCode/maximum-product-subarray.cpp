#define MAX(x, y)   ((x) > (y) ? (x) : (y))
#define MIN(x, y)   ((x) < (y) ? (x) : (y))

class Solution {
public:
    int maxProduct(int A[], int n) {
        //If n < 1, return 0
        //If n == 1, return A[0]
        //Difference from maxSum: if tempSum < 0, discard the tempSum and start from next number
        //In product, if next number and tempProduct produces a positive number, it may be the new max
        //So need a n*n array to store the products. Eg. products[i][j] stores the product from A[i] to A[j]
        //Thus it is a half matrix, because j >= i
        //Then we scan the matrix to get the global max.
        if (1 > n || !A)
            return 0;
        
        if (n == 1)
            return A[0];
    
        int max_local = A[0];
        int min_local = A[0];

        int max_global = A[0];
        for (int i = 1; i < n; i++) {
            //Store previous max_local before updating max_local
            int max_copy = max_local;
            
            //3 options: continue with previous max product, start from A[i]. continue with previous min product
            max_local = MAX(MAX(A[i] * max_local, A[i]), A[i] * min_local);
            
            //Store current min because negative * negative may produce positive max
            min_local = MIN(MIN(A[i] * max_copy, A[i]), A[i] * min_local);
            max_global = MAX(max_global, max_local);
        }
    
        return max_global;
    }
};
