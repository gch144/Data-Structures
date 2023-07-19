#include<iostream>
#include<vector>
/*
Given a boolean 2d array , where each row is sorted.
Find the row with the maximum number of 1s:

input:{
    {0,1,1,1},
    {0,0,0,1},
    {0,0,1,1}
    };

output: 0
*/
int maxones(std::vector<std::vector<bool>>& V){
   int maxones=INT_MIN;
   int maxonerow=-1;
   int col_number=V[0].size();
   for (int i = 0; i < V.size(); i++)
   {
   for (int j = 0; j < V[i].size(); j++)
   {
    if (V[i][j]==1)
    {
        int numberofones=col_number-j;
        if(numberofones>maxones){
            maxones=numberofones;
            maxonerow=i;
        }
        break;/*// This will be break the loop as we find the 1 in row so time complexcity is O(r+c)
             // Otherwise O(r_no) for rows and O(col_num) for columes it will itrates indide rows and will become O(r*c)
*/
    }
    
   }
   
   }
   return maxonerow;
}

int maxone1(std::vector<std::vector<bool>>& v)
{
    int leftmostone=-1;
    int maxonerow=-1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j =v[i].size()-1; j >=0; j--)
    {
        if(v[i][j]==1){
            leftmostone=j;
            maxonerow=i;
        }
        else{
            break;
        }
    }
    }
    
    

return maxonerow;
}
int maxone(std::vector<std::vector<bool>>& v)
{
    int leftmostone=-1;
    int maxonerow=-1;
    int j= v[0].size()-1;

    
    for (int i = 0; i < v.size(); i++)
    {
    while (j>=0&&v[i][j]==1)
    {
       leftmostone=j;
       maxonerow=i;
       j--;
    }
    }
    
    

return maxonerow;
}
// void printmatrix(std::vector<std::vector<int>>&mat){
//     for(std::vector<int>& row :mat){
//         for(int num: row){
//             std::cout<<num<<" ";
//     }
//     std::cout<<std::endl;
//     }
// }

int main(){
    std::vector<std::vector<bool>>matrix={
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0}
    };
    int max= maxone1(matrix);
    std::cout<<"Maximum 1's in Row number : "<<max<<std::endl;

    return 0;
}
