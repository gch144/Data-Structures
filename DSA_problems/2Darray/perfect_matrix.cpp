// Given a m*n matrix, Write a function which returns true if the matrix is a perfect matrix. A matrix is
// called perfect if every diagonal from top-left to bottom-right has the same elements.

#include<iostream>
#include<vector>
using namespace std;
bool check(vector<vector<int>> &vec){
   for (int i = 1; i < vec.size(); i++)
   {
      for (int j = 1; j < vec[0].size(); j++)
      {
         if(vec[i][j]!=vec[i-1][j-1]){
            return false;
         }
      }
      
   }
   return true;
   
}



int main(){
   int n,m;
cout<<"enter the number of row and col:\n";
cin>>n>>m;
vector<vector<int>>vec(n,vector<int>(m));
for (int i = 0; i < n; i++)
{
   for (int j = 0; j <m; j++)
   {
      cin>>vec[i][j];
   }
}
cout<<"Array :\n";
for (int i = 0; i < n; i++)
{
   for (int j = 0; j <m; j++)
   {
      cout<<vec[i][j]<<" ";
   }
   cout<<endl;
}
if (check(vec))
{
   cout<<"True";
}
else{
   cout<<"False";
}

}