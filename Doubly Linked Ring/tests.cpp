#include "ring.hpp"
#include <iostream>
#include <vector>
#include <utility>

template <typename Key, typename Info>
bool compare(const bi_ring<Key, Info> &br1, const bi_ring<Key, Info> &br2)
{
     if (br1.size() != br2.size())
     {
          return false;
     }
     auto i1 = br1.cbegin(), i2 = br2.cbegin();
     for (int i = 0; i < br1.size(); i++)
     {
          if (i1->key != i2->key or i1->info != i2->info)
          {
               return false;
          }
          i1++;
          i2++;
     }
     return true;
}

template <typename Key, typename Info>
bool compare(const bi_ring<Key, Info> &br1, const std::vector<std::pair<Key, Info>> &br2)
{
     if (br1.size() != br2.size())
     {
          return false;
     }
     auto i1 = br1.cbegin();
     auto i2 = br2.cbegin();
     for (auto i2 : br2)
     {
          if (i1->key != i2.first or i1->info != i2.second)
          {
               return false;
          }
          i1++;
     }
     return true;
}

int main()
{
     // copy constructor check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(3, 9);
          bi_ring<int, int> br2(br1);
          if (!compare<int, int>(br1, br2))
          {
               std::cout << "Error in Copy Constructor\n";
          }
     }
     // assignment operator check
     {
          bi_ring<int, int> br1, br2;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(3, 9);

          br2 = br1;
          if (!compare<int, int>(br1, br2))
          {
               std::cout << "Error in Assignment operator\n";
          }
     }

     // push_front check
     {
          bi_ring<int, int> br1;
          br1.push_front(1, 1);
          br1.push_front(2, 4);
          br1.push_front(3, 9);
          if (!compare<int, int>(br1, {{3, 9}, {2, 4}, {1, 1}}))
          {
               std::cout << "Error in push_front method\n";
          }
     }

     // pop_front check
     {
          bi_ring<int, int> br1;
          br1.push_front(1, 1);
          br1.push_front(2, 4);
          br1.push_front(3, 9);
          br1.pop_front();
          if (!compare<int, int>(br1, {{2, 4}, {1, 1}}))
          {
               std::cout << "Error in pop_front method\n";
          }
     }

     // push_front check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(3, 9);
          if (!compare<int, int>(br1, {{1, 1}, {2, 4}, {3, 9}}))
          {
               std::cout << "Error in push_front method\n";
          }
     }

     // pop_front check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(3, 9);
          br1.pop_back();
          if (!compare<int, int>(br1, {{1, 1}, {2, 4}}))
          {
               std::cout << "Error in pop_front method\n";
          }
     }

     // insert check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(4, 16);
          br1.insert(br1.begin() + 2, 3, 9);
          if (!compare<int, int>(br1, {{1, 1}, {2, 4}, {3, 9}, {4, 16}}))
          {
               std::cout << "Error in insert method\n";
          }
     }

     // insert_after check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(4, 16);
          br1.insert_after(br1.begin() + 1, 3, 9);
          if (!compare<int, int>(br1, {{1, 1}, {2, 4}, {3, 9}, {4, 16}}))
          {
               std::cout << "Error in insert_back method\n";
          }
     }

     // erase check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(4, 16);
          br1.erase(br1.begin() + 1);
          if (!compare<int, int>(br1, {{1, 1}, {4, 16}}))
          {
               std::cout << "Error in erase method\n";
          }
     }

     // empty check
     {
          bi_ring<int, int> br1, br2;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(4, 16);
          if (!(!br1.empty() && br2.empty()))
          {
               std::cout << "Error in empty method\n";
          }
     }

     // size check
     {
          bi_ring<int, int> br1, br2;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(4, 16);
          if (!((br1.size() == 3) and (br2.size() == 0)))
          {
               std::cout << "Error in size method\n";
          }
     }

     // shuffle check
     {
          bi_ring<int, int> br1;
          br1.push_back(1, 1);
          br1.push_back(2, 4);
          br1.push_back(4, 16);
          br1.clear();
          if (!(br1.size() == 0 && br1.empty()))
          {
               std::cout << "Error in shuffle function\n";
          }
     }

     // shuffle check
     bi_ring<int, int> br1, br2, result;
     br1.push_back(1, 1);
     br1.push_back(2, 4);
     br1.push_back(3, 9);
     br1.push_back(4, 16);
     br2.push_back(10, 100);
     br2.push_back(20, 400);
     br2.push_back(30, 900);
     result = shuffle(br1, 3, br2, 2, 3);
     if (!(compare(result,{{1,1},{2,4},{3,9},{10,100},{20,400},{4,16},{1,1},{2,4},{30,900},{10,100},{3,9},{4,16},{1,1},{20,400},{30,900}})))
     {
          std::cout << "Error in clear method\n";
     }

     std::cout << "End of tests" << std::endl;

     return 0;
}
