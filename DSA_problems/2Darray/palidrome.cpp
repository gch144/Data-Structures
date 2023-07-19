#include<iostream>
#include<vector>
using namespace std;
// pascal trinagle 
int factorical(int n){
   if(n==0){
      return 1;
   }
   else {
      return n*factorical(n-1);
   }
}
int ncr(int n, int r){
   int num = factorical(n);
   int dinominator = factorical(r)*factorical(n-r);
   return num/dinominator;
}

vector<vector<int>>pascal(int row){
   vector<vector<int>>res(row);
for (int i = 0; i < res.size() ; i++)
{
   res[i].resize(i+1);
   for (int j = 0; j <res[i].size(); j++)
   {
     // res[i][j]=ncr(i,j);   //Uncomment it u can use above function 
     if(j==0||j==i){
      res[i][j]=1;
     }
     else{
      res[i][j]=res[i-1][j]+res[i-1][j-1];
     }
   }
   
}
return res;
}


int main(){
int n;
cout<<"Enter the number of row \n";
cin>>n;
vector<vector<int>>vec;
vec= pascal(n);
for (int i = 0; i <vec.size(); i++)
{
   for (int j = 0; j < vec[i].size(); j++)
   {
      cout<<vec[i][j]<<" ";
}
cout<<endl;
}
}