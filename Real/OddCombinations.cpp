#include <iostream>;
#include <vector>;
#include <stack>;
using namespace std;

typedef unsigned int uint;

class OddCombinations
{
public:
    void findOddCombinations (uint n)
    {
        cout<<"--------- Find Odd Combinations ----------"<<endl;
        findOddCombinationsCore(n, 1);
        cout<<endl;
    }

private:
   vector<int> combination;

    void findOddCombinationsCore(uint remainder, uint currentOdd)
    {
        if (remainder == 0)
        {
            printCombinations();
        }
        else
        {
            for (int i = currentOdd; i <= remainder; i +=2)
            {
                combination.push_back(i);
                findOddCombinationsCore(remainder - i, i);
                combination.pop_back();
            }
        }
    }

    void printCombinations()
    {
        const int n = combination.size();
        for (int i = 0; i < n; i++)
        {
            cout<<combination[i];
            if (i != n-1)
                cout<<" + ";
            else
                cout<<endl;
        }
    }
};


int main(int argc, _TCHAR* argv[])
{
    OddCombinations oc;
    oc.findOddCombinations(8);

    return 0;
}
