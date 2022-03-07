#include "avl.hpp"
#include "bst.hpp"

using namespace std;

int main()
{
     // AVL tree tests
     AVLTree<int, int> avl;

     if (!(avl.count() == 0))
     {
          cerr << "Error AVL: with size method!\n";
     }

     avl.clear();

     if (!(avl.count() == 0))
     {
          cerr << "Error AVL: with clear method!\n";
     }

     try
     {
          avl[0] = avl.find(0);
          cerr << "Error AVL: with find and [] method!\n";
     }
     catch (std::invalid_argument &iv)
     {
     }

     for (int i = 1; i <= 100; i++)
     {
          avl.insert(i, i);
     }

     for (int i = 50; i <= 150; i++)
     {
          avl.insert(i, i);
     }

     if (!(avl.count() == 150))
     {
          cerr << "Error AVL: with size method!\n";
     }

     for (int i = 1; i <= 150; i++)
     {
          try
          {
               avl[i] = avl.find(i);
          }
          catch (std::invalid_argument &iv)
          {
               cerr << "Error AVL: with find and [] method!\n";
          }
     }

     avl.clear();

     if (!(avl.count() == 0))
     {
          cerr << "Error AVL: with clear method!\n";
     }

     listing(counter("TheVoyageoftheBeagle.txt"));

     // BST tree tests
     BinarySearchTree<int, int> bst;

     if (!(bst.count() == 0))
     {
          cerr << "Error BST: with size method!\n";
     }

     bst.clear();

     if (!(bst.count() == 0))
     {
          cerr << "Error BST: with clear method!\n";
     }

     try
     {
          bst[0] = bst.find(0);
          cerr << "Error BST: with find and [] method!\n";
     }
     catch (std::invalid_argument &iv)
     {
     }

     for (int i = 1; i <= 100; i++)
     {
          bst.insert(i, i);
     }

     for (int i = 50; i <= 150; i++)
     {
          bst.insert(i, i);
     }

     if (!(bst.count() == 150))
     {
          cerr << "Error BST: with size method!\n";
     }

     for (int i = 1; i <= 150; i++)
     {
          try
          {
               bst[i] = bst.find(i);
          }
          catch (std::invalid_argument &iv)
          {
               cerr << "Error BST: with find and [] method!\n";
          }
     }

     for (int i = 1; i <= 150; i++)
     {
          try
          {
               bst.remove(i);
          }
          catch (std::invalid_argument &iv)
          {
               cerr << "Error BST: remove method\n";
          }
     }

     if (!(bst.count() == 0))
     {
          cerr << "Error BST: remove method!\n";
     }

     cout << "End of tests\n";
}