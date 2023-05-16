#include <bits/stdc++.h>
using namespace std;

/*
- Given an integer array arr, return an array ans such that ans[i] is equal to the product of
all the elements of arr except arr[i].
 */
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> answer(v.size());
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++)
  {
    int product = 1;
    for (int j = 0; j < n; j++)
    {
      if (j != i)
      {
          product=product*v[j];
      }
    }
    answer[i]=product;
  }
  //return answer;
  for (int i : answer)
  {
    cout << i<< " ";
  }

  return 0;
}
