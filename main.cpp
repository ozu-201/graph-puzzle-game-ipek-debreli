//
// Created by id033803 on 12/21/2023.
//
#include <iostream>
#include "src/Game.h"
#include <fstream>
#include <windows.h>
#pragma execution.chracter_set("utf-8")

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    Game game;
    vector<string> words = game.readDictionary();

    std::cout << "Test Case: Adding Edges with One-Letter Difference (3 letter words)\n";
    std::cout << "Shortest Path from 'cat' to 'dog' (BFS):\n";
    list::Graph graph3 = game.createGraph(words, 3);
    vector<string> word3 = game.filteredWords(words, 3);
    graph3.list::Graph::breadthFirstSearch(word3,"cat","dog");
    std::cout << "------------------------------------------\n";

    std::cout << "Test Case: Adding Edges with One-Letter Difference (4 letter words)\n";
    std::cout << "Shortest Path from 'dark' to 'barn' (BFS):\n";
    list::Graph graph4 = game.createGraph(words, 4);
    vector<string> word4 = game.filteredWords(words, 4);
    graph4.list::Graph::breadthFirstSearch(word4,"dark","barn");
    std::cout << "------------------------------------------\n";

    std::cout << "Test Case: Adding Edges with One-Letter Difference (5 letter words)\n";
    std::cout << "Shortest Path from 'stone' to 'score' (BFS):\n";
    list::Graph graph5 = game.createGraph(words, 5);
    vector<string> word5 = game.filteredWords(words, 5);
    graph5.list::Graph::breadthFirstSearch(word5,"stone","score");
    std::cout << "------------------------------------------\n";


    return 0;


}

vector<string> Game::readDictionary() {
    vector<string> words;
    ifstream file("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-ipek-debreli\\src\\dictionary.csv");

    if(!file.is_open()){
        cout << "yapmaaa" << endl;
    }
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
    return words;

}

vector<string> Game::filteredWords(vector<string> words, int length){
    vector<string> filteredWords;
    for(int i = 0; i < words.size(); i++){
        if(words[i].size() == length){
            filteredWords.push_back(words[i]);
        }
    }
    return filteredWords;
}

list::Graph Game::createGraph(vector<string> dictionary, int length){
    vector<string> filteredList = filteredWords(dictionary,length);
    list::Graph myGraph(filteredList.size());
    for(int i = 0; i < filteredList.size(); i++){
        for(int j = i + 1; j < filteredList.size(); j++){
            if(isConnected(filteredList[i], filteredList[j])){
                myGraph.addEdge(i,j);
                myGraph.addEdge(j,i);
            }
        }
    }
    return myGraph;
}

bool Game::isConnected(const string& word1,const string& word2){
    int differentLetters = 0;
    for(int i = 0; i < word1.size(); i++){
        if(word1[i] != word2[i]){
            differentLetters++;
        }
        if (differentLetters > 1){
            return false;
        }
    }
    return differentLetters == 1;
}




