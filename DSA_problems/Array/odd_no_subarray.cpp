#include <bits/stdc++.h>
using namespace std;

/*
​There is a man going on a trek. The trek consists of n + 1 points at different altitudes. The
man starts his trek on point 0 with altitude equal 0. You are given an integer array height
of length n where height[i] is the net height in altitude between points i​ and i + 1 for all
(0 <= i < n). Return the highest altitude of a point.
 */
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int val=0;
    for (int j = i; j < n; j++)
    {
     val+=v[j];
     if(val%2!=0){
      count++;
     }

      cout << v[j] << " ";
    }
    // cout<<endl;
  }
  cout<<endl<<count;
  return 0;
}
/*int numOfSubarrays(vector<int>& arr) {
       int mod = 1000000007;
    //prefix sum
    int sum = 0;
    //count the prefix sum is even and odd
    int even = 1, odd = 0;
    int res = 0;
    for(int i : arr){
        sum += i;
        if((sum & 1) != 0){
            //if sum is odd, so the odd sub array count is even,
            //because even + odd = odd,
            //if [0, j] subarray is even, so (j, i] is odd
            res = (res + even) % mod;
            odd++;
        }else{
            res = (res + odd) % mod;
            even++;
        }
    }
    return res;
}*/