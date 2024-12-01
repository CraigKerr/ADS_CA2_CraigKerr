#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "Entity.h"

using namespace std;

class Game
{
	string title;
	string developer;
	string genre;
	float rating;
	float price;
public:
	Game();
	Game(string title, string developer, string genre, float rating, float price);
	string getTitle();
	string getDeveloper();
	string getGenre();
	float getRating();
	float getPrice();
	friend ostream& operator<<(ostream& out, Game& game);
};

Game::Game()
{
	this->title = "";
	this->developer = "";
	this->genre = "";
	this->rating = 0.0;
	this->price = 0.0;
}

Game::Game(string title, string developer, string genre, float rating, float price)
{
	this->title = title;
	this->developer = developer;
	this->genre = genre;
	this->rating = rating;
	this->price = price;
}

string Game::getTitle()
{
	return this->title;
}

string Game::getDeveloper()
{
	return this->developer;
}

string Game::getGenre()
{
	return this->genre;
}

float Game::getRating()
{
	return this->rating;
}

float Game::getPrice()
{
	return this->price;
}

ostream& operator<<(ostream& out, Game& game)
{
	out << "Title: " << game.title << endl;
	out << "Developer: " << game.developer << endl;
	out << "Genre: " << game.genre << endl;
	out << "Rating: " << game.rating << endl;
	out << "Price: " << game.price << endl;
	return out;
}

