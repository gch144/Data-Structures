#include <bits/stdc++.h>
using namespace std;

/*
Problem 6: For Q inputs, check if the given number is present in the array or not.
Note: Value of all the elements in the array is less than 105
.
 */
int main()
{
int n;
cin>> n;
vector<int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
const int N=1e5+10;
vector<int>feq(N,0);
   for (int i = 0; i < n; i++)
   {
    feq[v[i]]++;
   }
 int q;
 cin >> q;
while (q--) {
int val;
cin >> val;
if (feq[val] > 0) {
cout << "YES" << endl;
} else cout << "NO" << endl;
}

    return 0;
}


   