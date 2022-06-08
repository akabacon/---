#include <iostream>
#include <vector>
using namespace std;
bool IsCarry(int a, int b, int carry)
{                                       // 1~10 1~10 carry
  return a % 10 + b % 10 + carry >= 10; // unit Digit is carry
}
int main()
{
  vector<int> a = {1, 9, 9, 9, 9};
  vector<int> b = {0, 0, 0, 0, 1};
  vector<int> sum;
  int MAX = a.size();
  int L_carry, W_carry, digit;       // last carry, whether carry
  for (int i = MAX - 1; i >= 0; i--) // max-1=4
  {
    W_carry = IsCarry(a[i + 1], b[i + 1], L_carry); //first from right digit
    if (i + 1 > MAX - 1) //(i start from 4,max is 5),MAX-1 do this
    {                             // 4+1 is greater than 4
      digit = (a[i] + b[i]) % 10; // first from the right have no Last carry
      sum.insert(sum.begin(), digit);
    }
    else if(i<=MAX-1 && i>=0) //i=MAX-2~0
    {
      digit = (a[i] + b[i] + W_carry) % 10;
      sum.insert(sum.begin(), digit);

      if (i==0 && (a[0] + b[0] + W_carry) >= 10) {//i=0 first from left,equal or greater than 10
        sum.insert(sum.begin(), 1);
      }
      else if(i==0&& (a[0] + b[0] + W_carry) < 10){
        sum.insert(sum.begin(), 0);
      }

    }
  

      L_carry = W_carry;
  }


  for (int i = 0; i <= MAX; i++)
  {
    cout << sum[i];
  }
  puts("");
  return 0;
}
