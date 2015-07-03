class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty() || gas.size() != cost.size())
            return -1;
        
        const int N = gas.size();
        
        int startingIndex = 0;
        
        while (startingIndex < N) {
            int gasLeft = 0;
			int travelledStations = 0;
			
            for (; travelledStations < N; travelledStations++) {
                int currentIndex = (startingIndex + travelledStations) % N;
                gasLeft += gas[currentIndex] - cost[currentIndex];
                if (gasLeft < 0)
                    break;
            }
            
            if (travelledStations == N)
                return startingIndex;
                
            startingIndex += travelledStations + 1;
        }
        
        return -1;
    }
};
