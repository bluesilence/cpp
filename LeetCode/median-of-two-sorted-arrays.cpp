class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int totalNumCount = m + n;
		if (isOdd(totalNumCount))
			return findKth(A, m, B, n, totalNumCount / 2 + 1);
		else    //The global medium is the average of the 2 middle numbers
			return (findKth(A, m, B, n, totalNumCount / 2)
					+ findKth(A, m, B, n, totalNumCount / 2 + 1)) / 2;
	}

private:
    double findKth(int a[], int m, int b[], int n, int k)  {  
        //always assume that m is equal or smaller than n  
        if (m > n)  
            return findKth(b, n, a, m, k);  
        if (m == 0)  
            return b[k - 1];  
        if (k == 1)  
            return min(a[0], b[0]);  
        
        //divide k into two parts  
        int pa = min(k / 2, m), pb = k - pa;  
        if (a[pa - 1] < b[pb - 1])  
            return findKth(a + pa, m - pa, b, n, k - pa);  
        else if (a[pa - 1] > b[pb - 1])  
            return findKth(a, m, b + pb, n - pb, k - pb);  
        else  
            return a[pa - 1];  
    }  
    
    bool isOdd(int num) {
        return num & 0x1;
    }
};
