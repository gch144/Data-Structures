#include <bits/stdc++.h>
using namespace std;
// Characcter arrays
/*QQ6 - Given an integer array containing n elements. Find the element in the array for which all the elements to its
left are smaller than it and all the elements to the right of it are larger than it.Here 1<n<101

&x: arr=[1,6,5,7,10,8,9]
Output: 7

Explanation: Here all the elements to the left of 7 are smaller than it and all the elements to the right of it
are greater than it.

Ex: arr=[5,6,2,8,10,9]
Output: -1

Explanation: Here there is no element in the array which satisfies the given condition.

*/
int rev(int a[], int n)
{
    int surfix[n];
    int perfix[n];
    perfix[0] = INT_MIN;
    surfix[n - 1] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        perfix[i] = max(perfix[i - 1], a[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        surfix[i] = min(surfix[i + 1], a[i + 1]);
    }
    int pos = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (perfix[i] < a[i] && a[i] < surfix[i])
        {
            return a[i];
            break;
        }
        // surfix=min(surfix,a[i]);
    }

    return pos;
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