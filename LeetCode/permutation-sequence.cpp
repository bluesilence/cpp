class Solution {
public:
    string getPermutation(int n, int k) {
        //The highest digit is in order: 1~n, with (n-1)! repeats for each
        //The second highest digit is in order: 1~n except the highest digit, with (n-2)! repeats for each
        //Suppose the kth permutation is (a1, a2, a3, ..., an), there are in total n! permutations
        //The (n-1) elements except the highest digit have (n-1)! permutations
        //Set k1 = k, then a1 = k1 / (n-1)!
        //Set k2 = k1 % (n-1)!, then a2 = k2 / (n-2)!
        //And so on...
        //Set k(n-1) = k(n-2) % 2!, then a(n-1) = k(n-1) / 1!
        //Set k(n) = k(n-1) % 1!, then a(n) = k(n) / 0!
        if (n < 1 || k < 1)
            throw "n and k must be > 0";
            
        string result = "";
        
        int factorial = 1;  //(n-1)!
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        
        vector<int> nums(n, 0);
        
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        
		k--;	//The index starts from 0
        for (int i = 0; i < n; i++) {
            factorial /= n - i; //(n-i)! => (n-i-1)!
            int j = k / factorial;
            result += nums[j] + '0';    //a(i)
            k %= factorial; //k(i+1) = k(i) % (n-i)!
            
            for (; j + 1 < n - i; j++) {
                nums[j] = nums[j+1];
            }
        }
        
        return result;
    }
};
