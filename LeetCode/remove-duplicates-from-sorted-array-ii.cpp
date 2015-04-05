class Solution {  
public: 
    /*
     题意每个数只允许重复一次，输出去重后的数组和个数，依旧上一题的要求，常数空间也就是只能在原数组上操作。
     允许一个重复，所以判断就不是相邻而是相隔一个的数字是否不一样。
     不一样就需要更新值，但注意到这题更新数组不能是当前的状态，而需要是更新前一个不同的数，用temp存当前值以便于下一次赋值。
     因为如果更新当前的数，下一次判断相隔的数是否不同的时候，访问的就是覆盖后的数组值，就不对了。
    */
    int removeDuplicates(int A[], int n) {  
        if (!A || n < 2)
            return n;
        
        int pos = 1;
        int key = A[1];
        
        for (int i = 2; i < n; i++)  {
            if (A[i] != A[i-2])  {  
                A[pos++] = key;  
                
                key = A[i];
            }  
        }
        
        A[pos++] = key;
        
        return pos;  
    }  
};
