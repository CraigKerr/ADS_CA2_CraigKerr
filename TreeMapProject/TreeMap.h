#pragma once
#include "BinaryTree.h"

template <class K , class V> 
class TreeMap
{
	BinaryTree<Entity<K, V>*> map;
public:
	void clear();
	bool containsKey(K key);
	V* get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	void printMap();
	//V& operator[K key];
};

template <class K, class V>
void TreeMap<K, V>::clear()
{
	map.clear();
};

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	V obj;
	Entity<K, V>* keyEntity = new Entity<K, V>(key, obj);
	try
	{
		Entity<K, V>* found = map.get(keyEntity);
		delete keyEntity;
		return true;
	}
	catch (logic_error e)   
	{
		delete keyEntity;
		return false;
	}
};

template <class K, class V>
V* TreeMap<K, V>::get(K key)
{
	V obj;
	Entity<K, V> keyEntity(key, obj);
	try
	{
		Entity<K, V>* found = map.get(keyEntity);
		return found->getSecond();
	}
	catch (logic_error e)
	{
		throw e;
	}
};


//This has changed many times as I tried to get a working solution,
//My solution in my previous commit wasn't correct and I tried to just create a vector to store and implemented a proper traversal method to access the keys
//Traversal methods I used from class examples
template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> mapKeys;
	
	std::vector<Entity<K, V>*> entities = map.printInOrder();
	for (auto entity : entities) {
		mapKeys.add(entity->getFirst());
	}
};

template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
	Entity<K, V>* newEntity = new Entity<K, V>(key, value);
	map.add(newEntity);
};

template <class K, class V>
int TreeMap<K, V>::size()
{
	return map.count();
};

template <class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	V obj;
	Entity keyEntity(key, obj);
	try
	{
		Entity found = map.get(keyEntity);
		delete keyEntity;
		return true;
	}
	catch (logic_error e)
	{
		throw e;
		return false;
	}
};


//template <class K, class V>
//V& operator[](K key)
//{
//
//};
