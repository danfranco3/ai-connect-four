#include "utility.h"
#include "interaction.h"
int main(int argc, char const *argv[])
{
    if(std::string(argv[1]) == "minmax" && argc > 2){
        if(std::string(argv[2]) == "shallow")
            start_game("minmax", 3);
        else if(std::string(argv[2]) == "medium")
            start_game("minmax", 5);
        else if (std::string(argv[2]) == "deep")
            start_game("minmax", 6);
    }
    else if(std::string(argv[1]) == "alphabeta" && argc > 2){
        if(std::string(argv[2]) == "shallow")
            start_game("alphabeta", 5);
        else if (std::string(argv[2]) == "medium")
            start_game("alphabeta", 8);
        else if (std::string(argv[2]) == "deep")
            start_game("alphabeta", 12);
    }
    else std::cout << "Please run the program with an option specified in the readme." << std::endl;
    return 0;
}
