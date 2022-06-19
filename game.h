#include <vector>
#include <iostream>
// "Include guard" prevents multiple inclusion:
#ifndef GAME_CONDITION_H_ALREADY_INCLUDED
#define GAME_CONDITION_H_ALREADY_INCLUDED

class Game
{
public:
    std::vector<std::vector<char>> layout;
    void print()
    {
        std::cout << "-----------------" << std::endl;
        for (int i = 0; i < 6; i++)
        {
            std::cout << "| ";
            for (int j = 0; j < 7; j++)
                std::cout << layout[i][j] << " ";
            std::cout << "|" << std::endl;
        }
        std::cout << "-----------------" << std::endl;
        std::cout << std::endl;
    }
};

Game initialize_game();
Game copy_game_condition(Game current);
Game apply_move(Game current, int column, char player);
std::vector<Game> generate_children(Game game, char player);
// End include guard:
#endif
