#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <typename K, typename V>
class TreeMap
{
	BinaryTree <Entity<K, V>> tree;
public:
	TreeMap();
	~TreeMap();
	void clear();
	bool containsKey(K key);
	V& get(K key);
	void put(K key, V value);
	BinaryTree<K> keySet();
	int size();
	bool removeKey(K key);
	V& operator[](K key);

	BinaryTree <Entity<K, V>> getBinaryTree();
	void setBinaryTree(BinaryTree <Entity<K, V>> other);

	BSTNode<K>* keySetHelper(const BSTNode<Entity<K, V>>* other);
};

//Constructor
template <typename K, typename V>
TreeMap<K, V>::TreeMap() 
{

}

//Destructor
template <typename K, typename V>
TreeMap<K, V>::~TreeMap() 
{
	delete this->tree.root;
}

template <typename K, typename V>
BinaryTree <Entity<K, V>> TreeMap<K, V>::getBinaryTree()
{
	return this->tree;
}

template <typename K, typename V>
void TreeMap<K, V>::setBinaryTree(BinaryTree <Entity<K, V>> other)
{
	this->tree = other;
}

template <typename K, typename V>
void TreeMap<K, V>::clear() 
{
	this->tree.clear();
}

//Contains Key
template <typename K, typename V>
bool TreeMap<K, V>::containsKey(K key)
{
	try
	{
		Entity<K, V> entity(key);
		this->tree.get(entity);
		return true;
	}
	catch (std::logic_error&)
	{
		return false;
	}
}

template <typename K, typename V>
V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> entity(key);
	try {
		return this->tree.get(entity).getValue();
	}
	catch (const std::logic_error&) {
		throw std::out_of_range("Key not found in TreeMap.");
	}
}

template <typename K, typename V>
void TreeMap<K, V>::put(K key, V value)
{
	Entity<K, V> entity(key, value);
	if (containsKey(key))
	{
		this->tree.get(entity).setValue(value);
	}
	else
	{
		this->tree.add(entity);
	}
}

template <typename K, typename V>
BinaryTree<K> TreeMap<K, V>::keySet()
{

}

template <typename K, typename V>
BSTNode<K>* TreeMap<K, V>::keySetHelper(const BSTNode<Entity<K, V>>* other)
{

}

template <typename K, typename V>
int TreeMap<K, V>::size()
{
	return this->tree.count();
}

template <typename K, typename V>
bool TreeMap<K, V>::removeKey(K key)
{
	Entity<K, V> entity(key);
	return this->tree.remove(entity);
}

//Operator Overloading
template <typename K, typename V>
V& TreeMap<K, V>::operator[](K key)
{
	if (!containsKey(key))
	{
		put(key, V());
	}
	return get(key);	
}