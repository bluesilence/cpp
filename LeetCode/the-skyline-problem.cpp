class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> horizontalVerticalPoints;
        
        for (int i = 0; i < buildings.size(); i++) {
            int left = buildings[i][0];
            int right = buildings[i][1];
            int height = buildings[i][2];
            horizontalVerticalPoints.push_back({left, 0 - height});
            horizontalVerticalPoints.push_back({right, height});
        }
        
        sort(horizontalVerticalPoints.begin(), horizontalVerticalPoints.end());
        
        multiset<int> heights;
        int lastHeight = 0;
        heights.insert(lastHeight); //Necessary so that the last point of height 0 is also collected
        
        vector<pair<int, int>> result;
        
        for (auto iter = horizontalVerticalPoints.begin(); iter != horizontalVerticalPoints.end(); iter++) {
            int horizontalPos = (*iter).first;
            int verticalPos = (*iter).second;
            
            if (verticalPos < 0) {  //Left boundary of building
                heights.insert(0 - verticalPos);
            } else {    //Right boundary of building
                heights.erase(heights.find(verticalPos));
            }
            
            int currentHeight = *heights.rbegin();  //rbegin() returns the max height for the remaining buildings
            if (currentHeight != lastHeight) {  //Turning point
                result.push_back({horizontalPos, currentHeight});
                lastHeight = currentHeight;
            }
        }
        
        return result;
    }
};
