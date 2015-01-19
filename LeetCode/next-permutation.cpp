class Solution {
public:
    void nextPermutation(vector<int> &num) {
        //Find the first number backwards which is greater than its lower adjacent number
        int i = 0;
        for (i = num.size() - 2; i >= 0 && num[i] >= num[i + 1]; i--);
        
        if (i < 0) {    //No possible arrangement, rearrange to the lowest possible order
            reverse(num.begin(), num.end() - 1);
        } else {    //num[i] < num[i + 1]
            int j = i + 2;
            //Find the lowest number after num[i] which is greater than num[i]
            while (j < num.size() && num[j] > num[i]) {
                j++;
            }
            
            j--;
            
            swap(num, i, j);
            
            //Because i is the end of the descending sequence num[i + 1] ... num.end() - 1, this reverse will make num[i + 1]...num.end() - 1 smallest
            reverse(num.begin() + i + 1, num.end() - 1);
        }
    }

private:
    void reverse(vector<int>::iterator i1, vector<int>::iterator i2) {
        while (i1 < i2) {
            *i1 ^= *i2;
            *i2 ^= *i1;
            *i1 ^= *i2;
            
            i1++;
            i2--;
        }
    }
    
    void swap(vector<int> &num, int i, int j) {
        num[i] ^= num[j];
        num[j] ^= num[i];
        num[i] ^= num[j];
    }
};
