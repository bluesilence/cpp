class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        
        if(matrix.empty()) {
			return result;
		} else if(matrix.size() == 1) {
            for(int i = 0; i < matrix[0].size(); i++) {
                result.push_back(matrix[0][i]);
            }
        } else if(matrix[0].size() == 1) {
			for(int i = 0; i < matrix.size(); i++) {
				result.push_back(matrix[i][0]);
			}
		} else {
            int minWidth = matrix.size() > matrix[0].size() ? matrix[0].size() : matrix.size();
			int round = minWidth & 0x01 == 0 ? minWidth >> 1 : 1 + minWidth >> 1;
            for(int i = 1; i <= round; i++) {
                scanLeftToRight(matrix, result, i);
                scanTopToBottom(matrix, result, i);
                scanRightToLeft(matrix, result, i);
                scanBottomToTop(matrix, result, i);
            }
        }
        
        return result;
    }
    
private:
    void scanLeftToRight(vector<vector<int> > &matrix, vector<int> &result, int round) {
        int startCol = round - 1;
        int endCol = matrix[0].size() - round;
        for(int i = startCol; i <= endCol; i++ ) {
            result.push_back(matrix[round - 1][i]);
        }
    }
    
    void scanRightToLeft(vector<vector<int> > &matrix, vector<int> &result, int round) {
        //There are more cols in currrent round to traverse, aka. matrix.size() - 2 * (round - 1) > 1
		if (round - 1 < matrix.size() - round) {
			int startCol = matrix[0].size() - round - 1;
			int endCol = round - 1;
			for(int i = startCol; i >= endCol; i-- ) {
				result.push_back(matrix[matrix.size() - round][i]);
			}
		}
    }
    
    void scanTopToBottom(vector<vector<int> > &matrix, vector<int> &result, int round) {
        int startRow = round;
        int endRow = matrix.size() - round;
        for(int i = startRow; i <= endRow; i++ ) {
            result.push_back(matrix[i][matrix[0].size() - round]);
        }
    }
    
    void scanBottomToTop(vector<vector<int> > &matrix, vector<int> &result, int round) {
        //There are more rows in currrent round to traverse, aka. matrix[0].size() - 2 * (round - 1) > 1
		if (round - 1 < matrix[0].size() - round) {
			int startRow = matrix.size() - round - 1;
			int endRow = round;
			for(int i = startRow; i >= endRow; i-- ) {
				result.push_back(matrix[i][round - 1]);
			}
		}
    }
};
