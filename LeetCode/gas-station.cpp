class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (n < 1)
            return -1;
        else {
            vector<int> netGas;
            for (int i = 0; i < n; i++) {
                netGas.push_back(gas[i] - cost[i]);
            }
            
            int gasInCar = 0;
            int i = 0;  //Index of current gas station
            int begin = 0;
            int end = 0;
            do {
                gasInCar += netGas[i];
                if (gasInCar < 0) { //Moving backward
                    begin--;
                    if (begin < 0)
                        begin = n - 1;
                        
                    i = begin;
                } else {    //Moving forward
                    end++;
                    if (end == n)
                        end = 0;
                    
                    i = end;
                }
            } while (begin != end);
                
            if (gasInCar >= 0)   //Valid
                return begin;
            else
                return -1;
        }
    }
};
