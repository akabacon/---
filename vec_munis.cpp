#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool IsCarry(int a, int b, int carry)
{                                       // 1~10 1~10 carry
  return a % 10 + b % 10 + carry >= 10; // unit Digit is carry
}

vector<int> add(vector<int> a, vector<int> b) // must be the same size
{
  vector<int> sum;
  int MAX = a.size();
  int L_carry, W_carry, digit;       // last carry, whether carry
  for (int i = MAX - 1; i >= 0; i--) // max-1=4
  {
    W_carry = IsCarry(a[i + 1], b[i + 1], L_carry); // first from right digit
    if (i + 1 > MAX - 1)                            //(i start from 4,max is 5),MAX-1 do this
    {                                               // 4+1 is greater than 4
      digit = (a[i] + b[i]) % 10;                   // first from the right have no Last carry
      sum.insert(sum.begin(), digit);
    }
    else if (i <= MAX - 1 && i >= 0) // i=MAX-2~0
    {
      digit = (a[i] + b[i] + W_carry) % 10;
      sum.insert(sum.begin(), digit);

      if (i == 0 && (a[0] + b[0] + W_carry) >= 10)
      { // i=0 first from left,equal or greater than 10
        sum.insert(sum.begin(), 1);
      }
      else if (i == 0 && (a[0] + b[0] + W_carry) < 10)
      {
        sum.insert(sum.begin(), 0);
      }
    }

    L_carry = W_carry;
  }

  return sum;
}

vector<int> minus_vec(vector<int> a, vector<int> b)
{
  vector<int> result;
  int aIsBig = -1;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] > b[i])
    { // digit from left of a is bigger
      aIsBig = 1;
      break;
    }
    else if (a[i] < b[i])
    {
      aIsBig = 0;
      break;
    }
  }

  if (aIsBig == -1) // a and b are the same
  {
    for (int i = 0; i < a.size(); i++)
    {
      result.insert(result.begin(), 0);
    }
    return result;
  }

  else if (aIsBig == 1)
  {               // positive result
    int bDig = 0; // borrow digit
    int dig = -1; // every digit

    for (int i = a.size() - 1; i >= 0; i--)
    { // first from the right
      if (a[i] - b[i] >= 0)
      {                             // digit no need borrow digit
        dig = (a[i] - b[i] - bDig); // difference-last borrow or not(if so then minus one)
        bDig = 0;
      }
      else if (a[i] - b[i] < 0)
      {                                  // digit need borrow
        dig = (a[i] - b[i] - bDig) + 10; // borrow 10
        bDig = 1;
      }
      result.insert(result.begin(), dig);
    }
    return result;
  }

  else if (aIsBig == 0)
  {               // negative result
    int bDig = 0; // borrow digit
    int dig = -1; // every digit
    for (int i = a.size() - 1; i >= 0; i--)
    { // start from unit digit(change to make (vector a) bigger)
      swap(a[i], b[i]);
    }

    for (int i = a.size() - 1; i >= 0; i--)
    { // first from the right
      if (a[i] - b[i] >= 0)
      {                             // digit no need borrow digit
        dig = (a[i] - b[i] - bDig); // difference-last borrow or not(if so then minus one)
        bDig = 0;
      }
      else if (a[i] - b[i] < 0)
      {                                  // digit need borrow
        dig = (a[i] - b[i] - bDig) + 10; // borrow 10
        bDig = 1;
      }
      result.insert(result.begin(), dig);
      // cout<<"digit="<<dig<<endl;
    }

    for (int i = 0; i < result.size(); i++)
    { // change to negative
      if (result[i] != 0)
      {
        result[i] *= -1;
        break;
      }
    }
    return result;
  }
}

void print(vector<int> c)
{
  for (int i = 0; i < c.size(); i++)
  {
    cout << c[i];
  }
  puts("");
}
vector<int> raze_0(vector<int> a)
{
  vector <int> result=a;
  int index;
  for (int i = 0; result[i] == 0 && i<result.size(); i++)
  {
    index = i;
  }
  //cout << index << endl;
  
  if (index==result.size()-1) //index denote last element (it's all zero)
  { // unit digit of a is not zero(it's all zero)
     for (int i = 0; i <= index-1; i++)
    {
      result.erase(result.begin()); //leave a unit zero,and erase others
    }

  }
 
  else if (index!=result.size()-1)
  {
    for (int i = 0; i <= index; i++)
    {
      result.erase(result.begin());
    }
  }
  
  return result;
}
int main()
{
  vector<int> a = {1, 9, 9, 9, 9};
  vector<int> b = {0, 0, 0, 0, 1};
  // vector<int> sum = add(a, b);
  // print(sum);

  vector<int> c = {0, 0, 0, 0, 0};
  vector<int> d = {0, 0, 0, 0, 1};
  vector<int> substract_with0 = minus_vec(c, d);
  print(substract_with0);
  vector<int> substract = raze_0(substract_with0);

  print(substract);
  puts("");
  return 0;
}
