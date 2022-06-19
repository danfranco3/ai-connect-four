#include <iostream>
#include "play_game.h"
#include "utility.h"

int ask_for_input(){
    switch(rand() % 4){
        case 3:
            std::cout << "Your turn, fellow player." << std::endl;
            break;
        case 2:
            std::cout << "It is your turn to amaze me, little one." << std::endl;
            break;
        case 1:
            std::cout << "You go." << std::endl;
            break;
        default:
            std::cout << "Your turn now, choose wisely..." << std::endl;
    }
    int column;
    std::cin >> column;
    std::cout << std::endl;
    return column;
}

void computer_thoughts(){
    switch (rand() % 4)
    {
    case 3:
        std::cout << "Oh, okay. I see what you are trying to do... But can you do this?" << std::endl;
        break;
    case 2:
        std::cout << "Well, hello pro player! Let's see if you can handle a REAL pro." << std::endl;
        break;
    case 1:
        std::cout << "Okay Mr. Connect Four! Let me show you how it's done..." << std::endl;
        break;
    default:
        std::cout << "Impressive! Watch this next one though..." << std::endl;
    }
    std::cout << std::endl;
}

void finish_game(char winner){
    if(winner == 'X')
        std::cout << "Congratulations little one! Now, if you need me I will be training, I MEAN THINKING, I MEAN... Ah, just go enjoy your victory." << std::endl;
    else
        std::cout << "Look who won! Better luck next time!" << std::endl;
    std::cout << std::endl;
    exit(0);
}

Game computer_move(Game current, std::string algorithm, int maxDepth);

Game human_move(Game current, std::string algorithm, int maxDepth)
{
    bool invalidInput = true;
    int column;
    Game next;
    while(invalidInput){
        try
        {
            invalidInput = false;
            std::cin >> column;
            next = apply_move(current, column - 1, 'X');
        }
        catch (std::string s)
        {
            invalidInput = true;
            std::cout << s << std::endl;
            std::cout << std::endl;
        }
    }
    next.print();
    if(utility(next.layout) == 512) finish_game('X');
    computer_thoughts();
    return next;
}

Game computer_move(Game current, std::string algorithm, int maxDepth){
    
    Game next;
    if (algorithm == std::string("minmax"))
        next = minmax(current, maxDepth);
    else if(algorithm == std::string("alphabeta"))
        next = alpha_beta_search(current, maxDepth);
    next.print();
    if(utility(next.layout) == -512) finish_game('O');
    std::cout << "Your turn: ";
    return next;
}

void start_game(std::string algorithm, int maxDepth){
    Game game = initialize_game();
    std::cout << "Do you want to play first? (y/n)" << std::endl;
    char answer;
    std::cin >> answer;
    std::cout << std::endl;
    std::cout << "Hello! I will let you know when I am done with my turn." << std::endl;
    std::cout << std::endl;
    std::cout << "When I do, just type in the column number from 1 to 7 to indicate where you want to play next." << std::endl;
    std::cout << std::endl;

    for(int i = 0; true; i++){
        if(i == 0){
            if (answer == 'y')
            {
                std::cout << "Choose the column for your first move: ";
                game = human_move(game, algorithm, maxDepth);
                continue;
            }
            else if (answer == 'n')
            {
                std::cout << "I'll begin then." << std::endl;
                game = computer_move(game, algorithm, maxDepth);
                continue;
            }
        }
        if(answer == 'y'){
            game = computer_move(game, algorithm, maxDepth);
            game = human_move(game, algorithm, maxDepth);
        }
        else{
            game = human_move(game, algorithm, maxDepth);
            game = computer_move(game, algorithm, maxDepth);
        }
    }
}