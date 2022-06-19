#include <vector>
#include <string>
#include <iostream>
#include "utility.h"

Game initialize_game()
{
    Game initial;
    for (int i = 0; i < 6; i++){
        std::vector<char> layout;
        for(int j = 0; j < 7; j++)
           layout.push_back('-');
        initial.layout.push_back(layout);
    }
    return initial;
}

Game copy_game_condition(Game game){
    Game toReturn;
    for (int i = 0; i < 6; i++){
        std::vector<char> layout;
        for (int j = 0; j < 7; j++){
            layout.push_back(game.layout[i][j]);
        }
        
        toReturn.layout.push_back(layout);
    }
    return toReturn;
}

Game apply_move(Game game, int column, char player){
    Game toReturn;
    toReturn = copy_game_condition(game);
    if(column>=7 || column<0) throw std::string("Invalid column! Please select a number from 1 to 7."); // For human players
    if(toReturn.layout[0][column] != '-') throw std::string("Column already full! Please select another one."); // For human players
    int line;
    for(line = 0; line < 6; line++){
        if(toReturn.layout[line][column] != '-') break;
    }
    toReturn.layout[line-1][column] = player;
    return toReturn;
}

std::vector<Game> generate_children(Game game, char player){
    
    std::vector<Game> toReturn;
    
    for(int i=0; i<7; i++){
        try{
            toReturn.push_back(apply_move(game, i, player));
        }
        catch(std::string s){
            continue;
        }
    }
    return toReturn;
}