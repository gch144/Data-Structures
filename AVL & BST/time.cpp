#include "avl.hpp"
#include "bst.hpp"
#include <vector>
#include <chrono>

using namespace std;

int main()
{
     AVLTree<int, int> avl;
     BinarySearchTree<int, int> bst;
     vector<int>
         size = {1000,
                 10000,
                 100000,
                 1000000,
                 10000000,
                 50000000,
                 100000000,
                 1000000000};

     for (int i : size)
     {
          auto start_avl_insertion = chrono::high_resolution_clock::now();
          for (int j = 1; j <= i; j++)
          {
               avl.insert(j, j);
          }
          auto stop_avl_insertion = chrono::high_resolution_clock::now();

          auto start_bst_insertion = chrono::high_resolution_clock::now();
          for (int j = 1; j <= i; j++)
          {
               bst.insert(j, j);
          }
          auto stop_bst_insertion = chrono::high_resolution_clock::now();

          auto start_avl_finding = chrono::high_resolution_clock::now();
          avl.find(i);
          auto stop_avl_finding = chrono::high_resolution_clock::now();

          auto start_bst_finding = chrono::high_resolution_clock::now();
          bst.find(i);
          auto stop_bst_finding = chrono::high_resolution_clock::now();

          auto duration_avl_insertion = chrono::duration_cast<chrono::microseconds>(stop_avl_insertion - start_avl_insertion);
          auto duration_bst_insertion = chrono::duration_cast<chrono::microseconds>(stop_bst_insertion - start_bst_insertion);
          auto duration_avl_finding = chrono::duration_cast<chrono::microseconds>(stop_avl_finding - start_avl_finding);
          auto duration_bst_finding = chrono::duration_cast<chrono::microseconds>(stop_bst_finding - start_bst_finding);

          cout << "Size: " << i << " Time Insertion(AVL): " << duration_avl_insertion.count() << " Time Insertion(BST): " << duration_bst_insertion.count() << " Time Finding(AVL): " << duration_avl_finding.count() << " Time Finding(BST): " << duration_bst_finding.count() << endl;
     }
}