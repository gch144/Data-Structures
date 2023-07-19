#include <iostream>
// #include<vector>
using namespace std;

int main()
{
  int n, m, n1, m1;
  int arr1[n][m], arr2[n1][m1];
  cout << "enter the size of array (row X columme)\n";
  cin >> n >> m;
  cout << "ENter the size of the 2nd array (row X colume)\n";
  cin >> n1 >> m1;
  if (m != n1)
  {
    cout << " columnof the first matrix must be equal to row to 2nd matrix\n ";
    return 0;
  }
  else
  {
    cout << "enter element of 1st array\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> arr1[i][j];
      }
    }
    cout << "Enter the element of the 2nd matrix\n";
    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < m1; j++)
      {
        cin >> arr2[i][j];
      }
    }
    cout << "Multiplication of the matrices=\n";
    int ans[n][m1];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m1; j++)
      {
        for (int k = 0; k < n; k++)
        {
          ans[i][j] += arr1[i][k] * arr2[k][j];
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m1; j++)
      {
        cout << ans[i][j] << " ";
      }
        cout << endl;
    }
    return 0;
  }

}
