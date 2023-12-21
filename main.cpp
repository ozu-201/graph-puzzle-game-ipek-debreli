//
// Created by id033803 on 12/21/2023.
//
#include <iostream>
#include "src/Game.h"
#include <fstream>

using namespace std;

int main()
{
    cout << "test" << endl;
    Game game;
    //vector<string> words = game.readDictionary();
//    list::Graph graph3 = game.createGraph(words, 3);
//    list::Graph graph4 = game.createGraph(words, 4);
//    list::Graph graph5 = game.createGraph(words, 5);
    game.readDictionary();

    list::Graph gr{1};

    return 0;


}

void Game::readDictionary() {
    vector<string> words;
    ifstream file("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-ipek-debreli\\src\\dictionary.csv");

    if(!file.is_open()){
        cout << "yapmaaa" << endl;
    }
    string word;
    while (file >> word) {
        words.push_back(word);
        cout <<  word << endl;
    }
    file.close();

}


