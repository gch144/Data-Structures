#include<iostream>
#include<vector>
#include<algorithm>
/*
Given a square matrix and roate by 90 degree in 
clockwise direction without using any extra space

input:{
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

output: 7,4,1
        8,5,2
        9,6,3
*/
void rotaate90degree(std::vector<std::vector<int>>& v){
// first transpose the array
for (int i = 0; i < v.size(); i++)
{
    for (int j = i; j <v[i].size(); j++)
    // for (int j = 0; j <i; j++)
    {
        std::swap(v[i][j],v[j][i]);
    }
    
}

//second than revese the row

for (int i = 0; i < v.size(); i++){
    // std::reverse(v[i].begin(),v[i].end()); // By using reverse inbuild function
    int l=0,r=v[i].size()-1;
    while (l<r)
    {
        std::swap(v[i][l],v[i][r]);
        l++;
        r--;
    }
    
}
// return;
}
void printmatrix(std::vector<std::vector<int>>&mat){
    for(std::vector<int>& row :mat){
        for(int num: row){
            std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    }
}

int main(){
    std::vector<std::vector<int>>matrix={
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };
rotaate90degree(matrix);
printmatrix(matrix);

    return 0;
}

/*For rotate 180 degree 
  
input:{
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

output: 9,8,7
        6,5,4
        3,2,1

Solution: 

        1,2,3                        7,8,9                     9,8,7
        4,5,6    reverse the columes 4,5,6    reverse the rows 6,5,4
        7,8,9                        1,2,3                     3,2,1

*/ 
/*For rotate 270 degree 
  
input:{
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

output: 3,6,9
        2,5,8
        1,4,7

Solution: solve think like anti clockwise of 90 degree

        1,2,3                        1,4,7                     3,6,9
        4,5,6    transpose the matri 2,5,8    reverse the colm 2,5,8
        7,8,9                        3,6,9                     1,4,7

*/ 