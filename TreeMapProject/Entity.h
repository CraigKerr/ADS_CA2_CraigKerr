#pragma once
#include <iostream>
using namespace std;
template <class K, class V>
class Entity
{
	K first;
	V second;
public:
	Entity(const K& f,const V& s);
	void setFirst(K& f);
	void setSecond(V& s);
	K& getFirst();
	V& getSecond();

	template <class K, class V>
	friend ostream& operator<<(ostream& out, Entity<K, V>& pair);
};
template <class K, class V>
ostream& operator<<(ostream& out, Entity<K, V>& pair)
{
	out << "[" << pair.first << ", " << pair.second << "]" << endl;
	return out;
}

template <class K, class V>
Entity<K, V>::Entity(const K& f,const V& s)
{
	this->first = f;
	this->second = s;
}

template <class K, class V>
void Entity<K, V>::setFirst(K& f)
{
	this->first = f;
}
template <class K, class V>
void Entity<K, V>::setSecond(V& s)
{
	this->second = s;
}
template <class K, class V>
K& Entity<K, V>::getFirst()
{
	return this->first;
}
template <class K, class V>
V& Entity<K, V>::getSecond()
{
	return this->second;
}