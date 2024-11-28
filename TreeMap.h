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
	BinaryTree<K> keySet();
	//void put(K key, V value);
	//int size();
	//bool removeKey();
	//V& operator[](K key);
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
void TreeMap<K, V>::clear() 
{
	this->tree.clear();
}

//Contains Key
template <typename K, typename V>
bool TreeMap<K, V>::containsKey(K key) 
{
	V value = new V();
	Entity<K, V> entity = entity(key, value);
	if (this->tree.get(entity))
	{
		return false;
	}
	else
		return true;
}

template<typename K, typename V>
V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> entityToFind = Entity<K, V>(key, V());
	Entity<K, V>* entityFound = this->tree.find(entityToFind);

	if (entityFound == nullptr)
		throw std::runtime_error("Key not found");
	else
		return entityFound->value;
}