#include <iostream>;
using namespace std; 

const int N = 100;  
int dimes[] = {1, 2, 5, 10};
//Index represents remained amount of money, value represents count of possible exchange combinations
int arr[N+1] = { 1 };  //arr[0] = 1

int coinExchange(int n)
{  
  int i, j;
  int count = sizeof(dimes)/sizeof(int);
  for (i = 0; i < count; i++)
  {  
    for (j = dimes[i]; j <= n; j++)
      arr[j] += arr[j - dimes[i]];  //Add count of combinations using dimes[i]
    
  }

  return arr[n];  
}  


int main()
{
  int num = coinExchange(N); 
  cout<<num<<endl; 

  return 0; 

}

