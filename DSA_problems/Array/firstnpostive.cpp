#include <bits/stdc++.h>
using namespace std;
// Characcter arrays
/*Q5 - Given an array containing n distinct integers in the range [0,n] (inclusive of both 0 and n) (inclusive of both
0 and n). Find and return the only number of the range that is not present in the array. Here l<n<101.

&x: arr=[3,0,1]
Output: 2

n=3, thus the range will be [0,3]

Ex: arr=[8,6,4,2,3,5,0,1]
Output: 7

n=8, thus the range will be [0,8]
*/
void rev(int a[], int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum +=a[i];
    }
    int range_sum=n*(n+1)/2;
    int missing=range_sum-sum;
    cout<<missing<<endl;
    
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
       // cin >> b[i];
    }

    rev(a, n);

    return 0;
}