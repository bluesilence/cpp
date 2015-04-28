struct Node {
    int value;
    string roman;
    Node(int v, string r) {
        value = v;
        roman = r;
    }
};

class Solution {
public:
    Solution() {
        digits.push_back(Node(1000, "M"));
        digits.push_back(Node(900, "CM"));
        digits.push_back(Node(500, "D"));
        digits.push_back(Node(400, "CD"));
        digits.push_back(Node(100, "C"));
        digits.push_back(Node(90, "XC"));
        digits.push_back(Node(50, "L"));
        digits.push_back(Node(40, "XL"));
        digits.push_back(Node(10, "X"));
        digits.push_back(Node(9, "IX"));
        digits.push_back(Node(5, "V"));
        digits.push_back(Node(4, "IV"));
        digits.push_back(Node(1, "I"));
    }
    
    string intToRoman(int num) {
        string result = "";
        if (num < 1)
            return result;
        
        int highestDigit = 0;
        while (num) {
            while (highestDigit < digits.size() && num / digits[highestDigit].value == 0)
                highestDigit++;
            
            if (highestDigit < digits.size()) {
                int count = num / digits[highestDigit].value;
                for (int i = 0; i < count; i++) {
                    result += digits[highestDigit].roman;
                }
                
                num -= count * digits[highestDigit].value;
            }
        }
        
        return result;
    }

private:
    vector<Node> digits;
};
