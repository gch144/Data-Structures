#include <iostream>
#include<vector>
using namespace std;



int main(){
  vector<int>v;

  std::cout<<"enter size of vector \n";
  int n;
  std::cin>>n;
  for (int i = 0; i < n; i++)
  {
    int ele;
   std:: cin>>ele;
    v.push_back(ele);
  }
   int pd =v[1]-v[0]; // checking difference 
   int j= 2;// at least 2 number length minimum 
   int curr=2;//at least 2 number length minimum 
   int ans=2;//at least 2 number length minimum 
    while (j<=n)
    {
      if (pd==v[j]-v[j-1])
      {
        curr++;
      }
      else{
        pd = v[j]-v[j-1];
        curr=2;
      }
      ans=max(curr,ans);
      j++;
    }
  cout<<ans<<endl;
  return 0;
    
   }
