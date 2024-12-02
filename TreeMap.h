#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <typename K, typename V>
class TreeMap
{
	//Binary tree to hold entities (key-value pairs)
	BinaryTree <Entity<K, V>> tree;
public:
	TreeMap(); //initializes treemap object
	~TreeMap(); //frees up memory
	void clear(); //clears all elements in the tree
	bool containsKey(K key); //checks if the tree contains a specific key
	V& get(K key); //retrieves the value associated to that key
	void put(K key, V value); //adds a key-value pair to tree
	BinaryTree<K> keySet(); //returns a set of all keys in tree
	int size(); //returns the number of elements in tree
	bool removeKey(K key); //removes a key-value pair from tree using key
	V& operator[](K key); //overloads the operator to allow accessing values using array

	BinaryTree <Entity<K, V>> getBinaryTree(); //returns the binary tree object of tree
	void setBinaryTree(BinaryTree <Entity<K, V>> other); //sets the binary tree of the tree to another binary tree

	BSTNode<K>* keySetHelper(const BSTNode<Entity<K, V>>* other); //helper function for keyset
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
//checks if the tree contains a key
template <typename K, typename V>
bool TreeMap<K, V>::containsKey(K key)
{
	try
	{
		//creates an entity to search for by key
		Entity<K, V> entity(key);
		this->tree.get(entity); //retrieves the entity from tree
		return true;
	}
	catch (std::logic_error&)
	{
		return false;
	}
}

//retrieves the value using a key
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

//adds keyvalue pair in tree
template <typename K, typename V>
void TreeMap<K, V>::put(K key, V value)
{
	Entity<K, V> entity(key, value);
	if (containsKey(key))
	{
		this->tree.get(entity).setValue(value);//if the key exists update the value
	}
	else
	{
		this->tree.add(entity); //else add the new value to tree
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

//shows how many elements are in the tree
template <typename K, typename V>
int TreeMap<K, V>::size()
{
	return this->tree.count(); //uses the trees count to return size
}

//removes a keyvalue pair by key from tree
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