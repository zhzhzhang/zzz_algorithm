#ifndef _HASHMAP_H_
#define _HASHMAP_H_

//hash表结点
template<typename K, typename V>
class Node
{
public:
    K _key;
    V _value;
    Node *next;

    Node(K key, V value) : _key(key),_value(value),next(NULL){}
    ~HashNode() {}
    Node& operator=(const Node& node)
    {
        _key  = node._key;
        _value = node._value;
        next = node.next;
        return *this;
    }
};

//hash表模板类
template <typename K, typename V, typename HashFunc, typename Equal>
class HashMap
{
public:
    HashMap(int size);
    ~HashMap();
    bool insert(const Key& key, const Value& value);
    bool del(const Key& key);
    Value& find(const Key& key);
    Value& operator [](const Key& key);

private:
    HashFunc hash;
    EqualKey equal;
    HashNode<Key, Value> **table;
    unsigned int _size;
    Value ValueNULL;
};


template <class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::HashMap(int size) : _size(size),hash(),equal()
{
    table = new HashNode<Key, Value>*[_size];
    for (unsigned i = 0; i < _size; i++)
        table[i] = NULL;
}



template <class Key, class Value, class HashFunc, class EqualKey>
HashMap<Key, Value, HashFunc, EqualKey>::~HashMap()
{
    for (unsigned i = 0; i < _size; i++)
    {
        HashNode<Key, Value> *currentNode = table[i];
        while (currentNode)
        {
            HashNode<Key, Value> *temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
    delete table;
}


template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& key, const Value& value)
{
    int index = hash(key)%_size;
    HashNode<Key, Value> * node = new HashNode<Key, Value>(key,value);
    node->next = table[index];
    table[index] = node;
    return true;
}


template <class Key, class Value, class HashFunc, class EqualKey>
bool HashMap<Key, Value, HashFunc, EqualKey>::del(const Key& key)
{
    unsigned index = hash(key) % _size;
    HashNode<Key, Value> * node = table[index];
    HashNode<Key, Value> * prev = NULL;
    while (node)
    {
        if (node->_key == key)
        {
            if (prev == NULL)
            {
                table[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            delete node;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::find(const Key& key)
{
    unsigned  index = hash(key) % _size;
    if (table[index] == NULL)
        return ValueNULL;
    else
    {
        HashNode<Key, Value> * node = table[index];
        while (node)
        {
            if (node->_key == key)
                return node->_value;
            node = node->next;
        }
    }
}


template <class Key, class Value, class HashFunc, class EqualKey>
Value& HashMap<Key, Value, HashFunc, EqualKey>::operator [](const Key& key)
{
    return find(key);
}


#endif