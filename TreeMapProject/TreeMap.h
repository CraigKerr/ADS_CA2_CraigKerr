#pragma once
#include "BinaryTree.h"
template <class K , class V> 
class TreeMap
{
	BinaryTree<Entity<K, V>*> map;
public:
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	V& operator[K key];
};

template <class K, class V>
void clear()
{
	map.clear();
};

template <class K, class V>
bool containsKey(K key)
{
	V obj;
	Entity keyEntity(key, obj);
	try
	{
		Entity found = map.get(keyEntity);
		return true;
	}
	catch (logic_error e)
	{
		return false;
	}
};

template <class K, class V>
V& get(K key)
{
	V obj;
	Entity keyEntity(key, obj);
	try
	{
		Entity found = tree.get(keyEntity);
		return found.getSecond();
	}
	catch (logic_error e)
	{
		throw e;
	}
};
//to do
template <class K, class V>
BinaryTree<K> keySet()
{

};

template <class K, class V>
void put(K key, V value)
{
	V obj;
	Entity newEntity(key, value);
	map.add(newEntity);
};

template <class K, class V>
int size()
{
	return map.count();
};

template <class K, class V>
bool removeKey(K key)
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

template <class K, class V>
V& operator[](K key)
{

};
