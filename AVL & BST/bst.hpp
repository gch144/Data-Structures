#include <iostream>

template <typename Key, typename Info>
class BinarySearchTree
{
     // Node of the AVL tree
     struct Node
     {
     public:
          Key key;
          Info info;
          Node *left;
          Node *right;
          Node(const Key &key, const Info &info)
          {
               this->key = key;
               this->info = info;
               this->left = nullptr;
               this->right = nullptr;
          }
     } * root;

     // Size of the AVL tree
     int size;

     // Recursively copy node data
     void copy(Node *node)
     {
          if (node)
          {
               insert(node->key, node->info);
               copy(node->left);
               copy(node->right);
          }
     }

     // Recursively delete nodes
     void del(Node *n)
     {
          if (n)
          {
               del(n->left);
               del(n->right);
               delete n;
          }
     }

     // Find node with the minimum value(leftmost leaf)
     Node *min_node(Node *n)
     {
          Node *curr = n;

          // Find the leftmost leaf
          while (curr and curr->left != nullptr)
               curr = curr->left;

          return curr;
     }

     // Insert a element
     void insert(Node *n, const Key &key, const Info &info)
     {
          bool left = true;
          Node *p = nullptr;
          while (n)
          {
               p = n;
               if (n->key > key)
               {
                    n = n->left;
                    left = true;
               }
               else if (n->key < key)
               {
                    n = n->right;
                    left = false;
               }
               else
               {
                    return;
               }
          }
          if (p)
          {
               if (left)
                    p->left = new Node(key, info);
               else
                    p->right = new Node(key, info);
               size++;
          }
     }

     Node *remove(Node *n, const Key &key)
     {
          // Return if the tree is empty
          if (n == nullptr)
               return n;

          // Find the node to be deleted
          if (key < n->key)
               n->left = remove(n->left, key);
          else if (key > n->key)
               n->right = remove(n->right, key);
          else
          {
               // If the node is with only one child or no child
               if (n->left == nullptr)
               {
                    Node *temp = n->right;
                    delete n;
                    size--;
                    return temp;
               }
               else if (root->right == nullptr)
               {
                    Node *temp = n->left;
                    delete n;
                    size--;
                    return temp;
               }

               // If the node has two children
               Node *temp = min_node(n->right);

               // Place the inorder successor in position of the node to be deleted
               n->key = temp->key;
               n->info = temp->info;

               // Delete the inorder successor
               n->right = remove(n->right, temp->key);
          }
          return n;
     }

     // Find the node with the given key
     Node *find(Node *n, const Key &key) const
     {
          while (n)
          {
               if (n->key < key)
                    n = n->right;
               else if (n->key > key)
                    n = n->left;
               else
                    return n;
          }
          return nullptr;
     }

     // Print the tree graphically
     void print_tree(Node *n, std::string &indent, const bool &last) const
     {
          if (n != nullptr)
          {
               std::cout << indent;
               if (last)
               {
                    std::cout << "R----";
                    indent += "   ";
               }
               else
               {
                    std::cout << "L----";
                    indent += "|  ";
               }
               std::cout << n->key << std::endl;
               print_tree(n->left, indent, false);
               print_tree(n->right, indent, true);
          }
     }

     void print_inorder(Node *n)
     {
          if (n)
          {
               // Traverse left
               print_inorder(n->left);

               // Traverse root
               std::cout << n->key << " -> ";

               // Traverse right
               print_inorder(n->right);
          }
     }

public:
     BinarySearchTree()
     {
          root = nullptr;
          size = 0;
     }

     BinarySearchTree(const BinarySearchTree &src)
     {
          root = nullptr;
          copy(src.root);
     }

     ~BinarySearchTree()
     {
          del(root);
     }

     BinarySearchTree &operator=(const BinarySearchTree &src)
     {
          if (this != &src)
          {
               clear();
               copy(src.root);
          }
          return *this;
     }

     bool insert(const Key &key, const Info &info)
     {
          if (root)
          {
               int s = size;
               insert(root, key, info);
               if (s == size)
                    return false;
               return true;
          }
          root = new Node(key, info);
          size++;
          return true;
     }

     bool remove(const Key &key)
     {
          int s = size;
          root = remove(root, key);
          if (s == size)
               return false;
          return true;
     }

     Info &find(const Key &key) const
     {
          Node *n = find(root, key);
          if (n)
               return n->info;
          throw std::invalid_argument("Not found!");
     }

     Info &operator[](const Key &key)
     {
          Node *n = find(root, key);
          if (n)
               return n->info;
          throw std::invalid_argument("Not found!");
     }

     int count()
     {
          return size;
     }

     void clear()
     {
          del(root);
          root = nullptr;
          size = 0;
     }

     void print_tree()
     {
          print_tree(root);
     }

     void print_inorder()
     {
          print_inorder(root);
     }
};
