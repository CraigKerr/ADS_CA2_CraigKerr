// TreeMapProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TreeMap.h"
#include "Entity.h"
#include "Game.h"

//Creating Map
TreeMap<string, Game> gamesMap;

//Read File and add Games to game Vector
vector<Game> readFile(const string& fname)
{
    vector<Game> games;
    ifstream file(fname);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << fname << endl;
        return games;
    }

    string line;
    bool isFirstLine = true;

    while (getline(file, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            continue;
        }

        stringstream ss(line);
        string title, developer, genre, ratingStr, priceStr;

        getline(ss, title, ',');
        getline(ss, developer, ',');
        getline(ss, genre, ',');
        getline(ss, ratingStr, ',');
        getline(ss, priceStr, ',');

        float rating = stof(ratingStr);
        float price = stof(priceStr);

        games.emplace_back(title, developer, genre, rating, price);
    }

    file.close();
    return games;
}

//Iterate through games vector and create Entity and add to Map
void addGamesToMap(vector<Game>& games)
{
	for (Game& game : games)
	{
		Entity<string, Game> e(game.getTitle(), game);
		gamesMap.put(e.getFirst(), e.getSecond());
	}
}


int main()
{

    const string fname = "games.csv";
    vector<Game> games = readFile(fname);
	addGamesToMap(games);
    
	gamesMap.containsKey("The Witcher 3: Wild Hunt") 
        ? cout << "The Witcher 3: Wild Hunt is in the map" << endl : 
        cout << "The Witcher 3: Wild Hunt is not in the map" << endl;

	gamesMap.keySet().printInOrder();
};
