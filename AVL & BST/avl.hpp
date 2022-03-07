#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename Key, typename Info>
class AVLTree
{
  // Node of the AVL tree
  struct Node
  {
  public:
    Key key;
    Info info;
    Node *left;
    Node *right;
    int height;
    Node(const Key &key, const Info &info)
    {
      this->key = key;
      this->info = info;
      this->left = nullptr;
      this->right = nullptr;
      this->height = 0;
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

  // Get height
  int height(Node *n) const
  {
    if (n)
      return n->height;
    return 0;
  }

  // Rotate right
  Node *rotr(Node *y)
  {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
  }

  // Rotate left
  Node *rotl(Node *x)
  {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
  }

  // Get the balance factor
  int balance_factor(Node *n) const
  {
    if (n)
      return height(n->left) - height(n->right);
    return 0;
  }

  // Insert a element
  Node *insert(Node *n, const Key &key, const Info &info)
  {
    // Find the correct postion and insert the node
    if (n == nullptr)
    {
      size++;
      return (new Node(key, info));
    }
    if (n->key == key)
      return n;
    if (key < n->key)
      n->left = insert(n->left, key, info);
    else if (key > n->key)
      n->right = insert(n->right, key, info);
    else
      return n;

    // Update the balance factor of each node and balance the tree
    n->height = 1 + std::max(height(n->left), height(n->right));
    int b = balance_factor(n);
    if (b > 1)
    {
      if (key < n->left->key)
      {
        return rotr(n);
      }
      else if (key > n->left->key)
      {
        n->left = rotl(n->left);
        return rotr(n);
      }
    }
    if (b < -1)
    {
      if (key > n->right->key)
      {
        return rotl(n);
      }
      else if (key < n->right->key)
      {
        n->right = rotr(n->right);
        return rotl(n);
      }
    }
    return n;
  }

  // Find the node with the given key
  Node *find(Node *n, const Key &key) const
  {
    if (n)
    {
      if (n->key < key)
        return find(n->right, key);
      else if (n->key > key)
        return find(n->left, key);
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

  void get_elements(std::vector<std::pair<Key, Info>> &elements, Node *node) const
  {
    if (node)
    {
      get_elements(elements, node->left);
      elements.emplace_back(std::pair<Key, Info>(node->key, node->info));
      get_elements(elements, node->right);
    }
  }

public:
  AVLTree()
  {
    root = nullptr;
    size = 0;
  }

  AVLTree(const AVLTree &src)
  {
    *this = src;
  }

  ~AVLTree()
  {
    del(root);
  }

  AVLTree &operator=(const AVLTree &src)
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
    int s = size;
    root = insert(root, key, info);
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

  std::vector<std::pair<Key, Info>> get_elements() const
  {
    std::vector<std::pair<Key, Info>> elements;
    get_elements(elements, root);
    return elements;
  }
};

AVLTree<std::string, int> &counter(const std::string &fileName)
{
  AVLTree<std::string, int> *dict = new AVLTree<std::string, int>;
  std::ifstream file(fileName);
  std::string word;
  while (file >> word)
  {
    try
    {
      (*dict)[word]++;
    }
    catch (const std::invalid_argument &iv)
    {
        dict->insert(word, 1);
    }
  }
  file.close();
  return *dict;
}

bool compare(std::pair<std::string, int> lhs, std::pair<std::string, int> rhs)
{
  if (lhs.second == rhs.second)
    return lhs.first < rhs.first;
  return lhs.second < rhs.second;
}

void listing(const AVLTree<std::string, int> &src)
{
  auto elements = src.get_elements();
  std::sort(elements.begin(), elements.end(), compare);
  for (auto ele : elements)
    std::cout << ele.first << ": " << ele.second << "\n";
}
