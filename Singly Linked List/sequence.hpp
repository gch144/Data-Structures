#include <iostream>
#include <stdexcept>

template <typename Key, typename Info>
struct Node
{
    Key key;
    Info info;
    Node<Key, Info> *next;
    Node(Key key, Info info, Node<Key, Info> *next = nullptr) //Node constructor
    {
        this->key = key;
        this->info = info;
        this->next = next;
    }
    Node(const Node &src) //Node Copy Constructor
    {
        this->key = src.key;
        this->info = src.info;
        this->next = nullptr;
    }
}; //Node structure

template <typename Key, typename Info>
class Sequence
{
public:
    Sequence<Key, Info>();                                                           //constructor
    Sequence<Key, Info>(const Sequence<Key, Info> &src);                             //copy constructor
    ~Sequence<Key, Info>();                                                          //Destructor
    Sequence<Key, Info> &operator=(const Sequence<Key, Info> &src);                  //Assignment operator
    unsigned int size() const;                                                       //returns the number of elements
    void push_front(const Key &key, const Info &info);                               //adds element to the front of the Sequence
    bool pop_front();                                                                //removes element from the front of the Sequence and returns true, if empty returns false
    void push_back(const Key &key, const Info &info);                                //adds element to the back of the Sequence
    bool pop_back();                                                                 //removes element from the back of the Sequence and returns true, if empty returns false
    bool push_mid(const Key &key, const Info &info, const Info &pos, int occur = 1); //adds element after the given position key and returns true, if key does not exist returns false
    bool pop_mid(const Info &pos, int occur = 1);                                    //removes element inr the given position key and returns true, if key does not exist returns false
    bool operator==(const Sequence<Key, Info> &src) const;                           //checks if given Sequence and the object have the same elements in the same order and returns true, if not returns false
    Info at(const Key &key, int occur = 1) const;                                    //returns a reference to the Info at the given position key, throws false if key not found
    Key key_at(unsigned int index) const;                                            //returns the key at the given index, else throws false
    void print() const;                                                              //prints all the elements of the Sequence

private:
    Node<Key, Info> *head; //Node head
};

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    head = nullptr;
}

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence &src)
{
    this->head = nullptr;
    if (src.head == nullptr)
    {
        return;
    }
    this->head = new Node<Key,Info>(*src.head);
    Node<Key, Info> *node = head;
    Node<Key, Info> *sn = src.head->next;
    while (sn)
    {
        node->next = new Node<Key,Info>(*sn);
        node = node->next;
        sn = sn->next;
    }
}

template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    Node<Key, Info> *node = head;
    while (node)
    {
        Node<Key, Info> *tmp = node->next;
        delete node;
        node = tmp;
    }
}
template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &src)
{
    Node<Key, Info> *node = head;
    while (node)
    {
        Node<Key, Info> *tmp = node->next;
        delete node;
        node = tmp;
    }
    this->head = nullptr;
    if (src.head == nullptr)
    {
        return *this;
    }
    this->head = new Node<Key,Info>(*src.head);
    node = head;
    Node<Key, Info> *sn = src.head->next;
    while (sn)
    {
        node->next = new Node<Key,Info>(*sn);
        node = node->next;
        sn = sn->next;
    }
    return *this;
}

template <typename Key, typename Info>
unsigned int Sequence<Key, Info>::size() const
{
    Node<Key, Info> *node = head;
    unsigned int size = 0;
    while (node)
    {
        size++;
        node = node->next;
    }
    return size;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::push_front(const Key &key,
                                     const Info &info)
{
    Node<Key, Info> *node = new Node<Key, Info>(key, info, head);
    head = node;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::pop_front()
{
    if (head == nullptr)
    {
        return false;
    }
    Node<Key, Info> *node = head->next;
    delete head;
    head = node;
    return true;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::push_back(const Key &key,
                                    const Info &info)
{
    if (head == nullptr)
    {
        head = new Node<Key, Info>(key, info);
        return;
    }
    Node<Key, Info> *node = head;
    while (node)
    {
        if (node->next == nullptr)
        {
            break;
        }
        node = node->next;
    }
    node->next = new Node<Key, Info>(key, info);
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::pop_back()
{
    if (head == nullptr)
    {
        return false;
    }
    Node<Key, Info> *node = head;
    while (node)
    {
        if (node->next == nullptr)
        {
            break;
        }
        node = node->next;
    }
    delete node->next;
    node->next = nullptr;
    return true;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::push_mid(const Key &key,
                                   const Info &info,
                                   const Info &pos, int occur)
{
    if (this->head == nullptr)
    {
        return false;
    }

    int occ = 1;
    Node<Key, Info> *node = head;
    Node<Key, Info> *prev = nullptr;
    while (node)
    {
        if (node->key == pos)
        {
            if (occ == occur)
            {
                Node<Key, Info> *tmp = node->next;
                Node<Key, Info> *newEle = new Node<Key, Info>(key, info, tmp);
                if (prev == nullptr)
                {
                    head->next = newEle;
                    return true;
                }
                newEle->next = tmp;
                node->next = newEle;
                return true;
            }
            else
            {
                occ++;
            }
        }
        prev = node;
        node = node->next;
    }
    return false;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::pop_mid(const Info &pos, int occur)
{
    if (this->head == nullptr)
    {
        return false;
    }
    int occ = 1;
    Node<Key, Info> *node = head;
    Node<Key, Info> *prev = node;
    while (node)
    {
        if (node->key == pos)
        {
            if (occ == occur)
            {
                Node<Key, Info> *tmp = node->next;
                delete node;
                prev->next = tmp;
                return true;
            }
            else
            {
                occ++;
            }
        }
        prev = node;
        node = node->next;
    }
    return false;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::operator==(const Sequence &src) const
{
    if (size() != src.size())
    {
        return false;
    }
    Node<Key, Info> *node = head;
    Node<Key, Info> *sn = src.head;
    while (node)
    {
        if ((node->key != sn->key) or (node->info != sn->info))
        {
            return false;
        }
        node = node->next;
        sn = sn->next;
    }
    return true;
}

template <typename Key, typename Info>
Info Sequence<Key, Info>::at(const Key &pos, int occur) const
{
    if (this->head == nullptr)
    {
        throw;
    }
    int occ = 1;
    Node<Key, Info> *node = head;
    while (node)
    {
        if (node->key == pos)
        {
            if (occ == occur)
            {
                return node->info;
            }
            else
            {
                occ++;
            }
        }
        node = node->next;
    }
    throw;
}

template <typename Key, typename Info>
Key Sequence<Key, Info>::key_at(unsigned int index) const
{
    if (this->head == nullptr)
    {
        throw;
    }
    unsigned int i = 0;
    Node<Key, Info> *node = head;
    while (node)
    {
        if (i == index)
        {
            return node->key;
        }
        i = i + 1;
        node = node->next;
    }
    throw;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::print() const
{
    Node<Key, Info> *node = head;
    std::cout << "[";
    while (node)
    {
        std::cout << "(" << node->key << " : " << node->info << "), ";
        node = node->next;
    }
    std::cout << "]";
}

template <typename Info>
Info aggregate(const Info &left, const Info &right)
{
    return left + right;
}

template <typename Key, typename Info>
Sequence<Key, Info> join(const Sequence<Key, Info> &left, const Sequence<Key, Info> &right, Info (*aggregate)(const Info &left, const Info &right))
{
    Sequence<Key, Info> *res = new Sequence<Key,Info>(left);
    if (res->size() == 0)
    {
        *res = right;
        return *res;
    }
    if (right.size() == 0)
    {
        return *res;
    }
    if (res->key_at(0) == right.key_at(0))
    {
        res->pop_front();
        Info l = left.at(left.key_at(0));
        Info r = right.at(right.key_at(0));
        Info n = aggregate(l,r);
        res->push_front(right.key_at(0),n);
        for (unsigned int i=1;i<right.size();i++)
        {
            res->push_back(right.key_at(i), right.at(right.key_at(i)));
        }
        return *res;
    }
    for (unsigned int i = 0; i < right.size(); i++)
    {
        res->push_back(right.key_at(i), right.at(right.key_at(i)));
    }
    return *res;
}
