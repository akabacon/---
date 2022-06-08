#include <iostream>
using namespace std;

struct complex
{
  complex(long long a) : re(a) {//建構子
  }
  complex operator+(complex &other);
  complex operator-(complex &other);

  void show() { cout << re << endl; }

private:
  int re, im;
};

// Operator overloaded using a member function
complex complex::operator+(complex &other)
{
  return complex(re + other.re);
}
complex complex::operator-(complex &other)
{
  return complex(re - other.re);
}

int main()
{
  char op = 0;
  int l, r;
  int flag;
  complex c = complex(0);
  do
  {
    flag = 1;
    cin >> op;
    cin >> l >> r;
    complex a = complex(l);
    complex b = complex(r);
    switch (op)
    {
    case '+':
      c = a + b;
      c.show();
      break;
    case '-':
      c = a - b;
      c.show();
      break;
    case '#':
      flag = 0;
      break;
    default:
      cout << "error\n";
      break;
    }
  }
  while(flag);


  return 0;
}