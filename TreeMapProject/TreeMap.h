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
V& TreeMap<K, V>::get(K key)
{
	V obj;
	Entity keyEntity(key, obj);
	try
	{
		Entity found = map.get(keyEntity);
		return found.getSecond();
	}
	catch (logic_error e)
	{
		throw e;
	}
};


//Taken from StackOverflow https://stackoverflow.com/questions/1318980/how-to-iterate-over-a-treemap
template <class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> mapKeys;
	
	for (map.Entry<string, Game> game : treeMap.entrySet();) {
		string key = game.getKey();
		mapKeys.add(key);
	}
};

template <class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
	V obj;
	Entity newEntity(key, value);
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
