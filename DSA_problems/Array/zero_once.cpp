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
cin>> n;
vector<int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
int max_length = 0;
  int count_0 = 0;
  int count_1 = 0;
  for (int i ;i<n;i++) {
    int element=v[i];
    if (element == 0) {
      count_0++;
    } else {
      count_1++;
    }
    if (count_0 == count_1) {
      max_length = max(max_length, count_0 + count_1);
    }
  }
  cout<<max_length;
return 0;
    
}


   