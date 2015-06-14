class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        
        if (rowIndex < 0) {
            return row;
        }
        
        row.push_back(1);
        
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                if (j == i) {   //Last number of the new row
                    row.push_back(1);
                } else {    //currentRow[j] = previousRow[j-1] + previousRow[j]
                    row[j] += row[j-1];
                }
            }
        }
        
        return row;
    }
};
