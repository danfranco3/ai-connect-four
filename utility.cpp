#include "game.h"

int eval(int x, int o){
    if(x == 4) return 512;
    if(o == 4) return -512;
    if(x > 0 && o > 0) return 0;
    if (x == 3)
        return 50;
    if (x == 2)
        return 10;
    if (x == 1)
        return 1;
    if (o == 3)
        return -50;
    if (o == 2)
        return -10;
    if (o == 1)
        return -1;
    return 0;
}

int diagonal(std::vector<std::vector<char>> layout, int iMax, int jStart, int jMax, int signal){
    int utility = 0, x = 0, o = 0;
    for (int i = 0; i < iMax; i++)
    {
        for (int j = jStart; j < jMax; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (layout[i + k][j + signal*k] == 'X')
                    x++;
                if (layout[i + k][j + signal*k] == 'O')
                    o++;
            }
            int p = eval(x, o);
            x = 0;
            o = 0;
            if (p == 512 || p == -512)
                return p;
            utility += p;
        }
    }
    return utility;
}

int utility(std::vector<std::vector<char>> layout)
{
    int x = 0, o = 0, utility = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (layout[i][j + k] == 'X')
                    x++;
                else if (layout[i][j + k] == 'O')
                    o++;
            }
            int p = eval(x, o);
            x = 0;
            o = 0;
            if (p == 512 || p == -512)
                return p;
            utility += p;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (layout[i + k][j] == 'X')
                    x++;
                if (layout[i + k][j] == 'O')
                    o++;
            }
            int p = eval(x, o);
            x = 0;
            o = 0;
            if (p == 512 || p == -512)
                return p;
            utility += p;
        }
    }
    int mainDiagonal = diagonal(layout, 3, 0, 4, 1);
    if(mainDiagonal == 512 || mainDiagonal == -512)
        return mainDiagonal;
    utility += mainDiagonal;
    int antiDiagonal = diagonal(layout, 3, 3, 7, -1);
    if(antiDiagonal == 512 || antiDiagonal == -512)
        return antiDiagonal;
    utility += antiDiagonal;
    return utility;
}

    // 0 1 2 3 4 5 6
    // - - - - - - - 0
    // - - - - - - - 1
    // - - - - - - - 2
    // - - - - - - - 3
    // - - - - - - - 4
    // - - - - - - - 5