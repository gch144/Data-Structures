// #include <iostream>
// #include <vector>

// using namespace std;

// void printmatrix(vector<vector<int>>& matri) {
//     for (vector<int>& row : matri) { // Use matri instead of triangle
//         for (int num : row) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     // Example usage:
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     printmatrix(matrix);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

void rotaate90degree(std::vector<std::vector<int>>& v) {
    // First transpose the array
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v[i].size(); j++) {
            std::swap(v[i][j], v[j][i]);
        }
    }

    // Then reverse each row individually
for (int i = 0; i < v.size(); i++){
    // std::reverse(v[i].begin(),v[i].end()); // By using reverse inbuild function
    int l=0,r=v[i].size()-1;
    while (l<r)
    {
        std::swap(v[l][i],v[r][i]);
        l++;
        r--;
    }
    
}
}

void printmatrix(const std::vector<std::vector<int>>& mat) {
    for (const std::vector<int>& row : mat) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotaate90degree(matrix);
    
    std::cout << "Rotated Matrix:" << std::endl;
    printmatrix(matrix);

    return 0;
}

// int main() {
//     //int dynamicInt=5;
//     int* dynamicInt = new int;  // Dynamically allocate memory for an integer

//     *dynamicInt = 10.5;  // Assign a value to the dynamically allocated integer

//     std::cout << "Dynamic Integer: " << *dynamicInt << std::endl;

//     delete dynamicInt;  // Deallocate the dynamically allocated memory

//     return 0;
// }
