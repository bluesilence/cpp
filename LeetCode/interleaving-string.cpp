class Solution {
public:
    //DP. define f[i][j]: if s3(1, i+j) interleaved by s1(1,i) s2(1,j)?  
    //(1)then the transform equation is below:   
    //if s1[i] == s3[i+j], f[i][j] = f[i-1][j]  
    //if s2[j] == s3[i+j], f[i][j] = f[i][j-1]  
    //(2)Initialize as below :  
    //f[0][0] = true,  
    //f[i][0] = f[i-1][0] && (s1[i-1] == s3[i-1]);  
    //f[0][j] = f[0][j-1] && (s2[j-1] == s3[j-1]);  
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty() && (s2 == s3) || s2.empty() && (s1 == s3))
            return true;
        
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3)
            return false;
        
        vector<vector<bool> > f(l1 + 1, vector<bool>(l2 + 1, false));
        
        f[0][0] = true;  
        for(int i = 0; i <= l1; i++)  {  
            for(int j = 0; j <= l2; j++)  {  
                int len = i + j;  
                if(i >= 1 && s1[i - 1] == s3[len - 1])
                    f[i][j] = f[i][j] || f[i - 1][j];
                    
                if(j >= 1 && s2[j - 1] == s3[len - 1])
                    f[i][j] = f[i][j] || f[i][j - 1];  
            }  
        }
        
        return f[l1][l2];
    }
};
