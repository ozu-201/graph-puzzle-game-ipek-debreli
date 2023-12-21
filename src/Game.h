//
// Created by id033803 on 12/21/2023.
//

#ifndef DATASTRUCTURES_CPP_GAME_H
#define DATASTRUCTURES_CPP_GAME_H

#include <vector>
#include <string>
#include "List/Graph/Graph.h"

namespace list{
    class Graph;
}

class Game{
public:
    //std::vector<std::string> readDictionary();
    void readDictionary();
    list::Graph createGraph(const std::vector<std::string> words, int length);
    bool isConnected(const std::string& word1,const std::string& word2);

};



#endif //DATASTRUCTURES_CPP_GAME_H
