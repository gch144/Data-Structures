#include <iostream>
using namespace std;
int main()
{
  int m, n;
  cout << "enter number of row and columns:\n";
  cin >> m >> n;
  // Dynamically allocate memory for the 2D array
  int **arr = new int *[m];
  for (int i = 0; i < m; i++)
  {
    arr[i] = new int[n];
  }
     // Input matrix elements
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  int **temp = new int *[n];
  for (int i = 0; i < n; i++)
  {
    temp[i] = new int[m];
    for (int j = 0; j < m; j++)
    {
      temp[i][j] = arr[j][i];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }

    // Deallocate memory
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0; i < n; i++) {
        delete[] temp[i];
    }
    delete[] temp;


  return 0;
}