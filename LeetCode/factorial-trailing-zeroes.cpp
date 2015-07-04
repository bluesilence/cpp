class Solution {
public:
    int trailingZeroes(int n) {
        //The count of zeroes is capped by the count of 5s in all numbers from 1 to n
        //If a number is times of 5 but not times of 5 * 5, it contributes 1 '0' to the total counts
        //If a number is times of 5 * 5 but not times of 5 * 5 * 5, it contributes 2 '0's to the total counts
        //Thus, the total count of zeroes = # numbers which is times of 5 + # numbers which is times of 5 * 5 (1 among the 2 contributions of 5s is included in previous # as times of 5) + ...
        int count = 0;
        
        while (n) {
            count += n / 5;
            n /= 5;
        }
        
        return count;
    }
};
