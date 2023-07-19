#include <iostream>
#include <vector>
/*
Print a spiral matrix 
input:{
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };
output:
1,2,3,6,9,8,7,4,5

Dry run:
we have to go left to right form top of the matrix

*/



void spiral(std::vector<std::vector<int>>&v){
 int left=0;
 int right=v[0].size()-1;
 int top= 0;
 int bottom=v.size()-1;

 int direction=0;
while(){
    if(direction==0){
        for (int col = left; col < right; col++)
        {
            
        }
        
    }

}
 
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        std::cin>>matrix[i][j];
    }
    
}
spiral(matrix);
    return 0;
}
