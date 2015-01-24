class Solution {
public:
    void sortColors(int A[], int n) {
        if (!A || n < 2)
            return;
        
        int colorCount[3] = { 0 };
        for (int i = 0; i < n; i++) {
            colorCount[A[i]]++;
        }
        
        int index = 0;
        for (int j = 0; j < 3; j++) {
            int count = colorCount[j];
            while (count-- > 0) {
                A[index++] = j;
            }
        }
    }
};
