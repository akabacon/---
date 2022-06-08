#include <iostream>
#include <algorithm>
using namespace std;
int N = 15, M = 3;
bool cmp(int a, int b)
{
  if ()
    
  else
    cout << "error" << endl;
}

int main()
{
  int a[10010];
  int T;
  cin>>T;
  while (T--)
  {
    cin>>N>>M;
    cout << N << " " << M << endl; // 15 3

    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
    }

    sort(a, a + N, cmp);
    for (int i = 0; i < N; i++)
    {
      cout << a[i] << endl;
    }
  }

  return 0;
}