#include "utility.h"
#include <chrono>

int nNodes = 0;

bool terminalState(Game current)
{
    if (utility(current.layout) == 512 || utility(current.layout) == -512 || utility(current.layout) == 0)
        return true;
    else return false;
}

int max_value(Game current, int depth, int maxDepth);

int min_value(Game current, int depth, int maxDepth)
{
    nNodes++;
    if (terminalState(current) || depth == maxDepth)
        return utility(current.layout);
    int v = INT32_MAX;
    std::vector<Game> successors = generate_children(current, 'O');
    for (Game s : successors)
    {
        v = std::min(v, max_value(s, depth+1, maxDepth));
    }
    return v;
}

int max_value(Game current, int depth, int maxDepth)
{
    nNodes++;
    if (terminalState(current) || depth == maxDepth)
        return utility(current.layout);
    int v = INT32_MIN;
    std::vector<Game> successors = generate_children(current, 'X');
    for (Game s : successors)
    {
        v = std::max(v, min_value(s, depth + 1, maxDepth));
    }
    return v;
}

Game minmax(Game current, int maxDepth)
{
    std::vector<Game> successors = generate_children(current, 'O');
    int size = successors.size();
    Game toReturn = successors[0];
    auto start = std::chrono::high_resolution_clock::now();
    int v = max_value(toReturn, 1, maxDepth);
    // this cycle is the equivalent of min_value(root) -> since the computer is playing min nodes, it was only done this way because it was easier to return the move
    for (int i = 1; i < size; i++)
    {
        int cur = max_value(successors[i], 1, maxDepth);
        if(cur < v){
            v = cur;
            toReturn = successors[i];
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
# ifdef DEBUG
    std::cout << "Number of nodes explored: " << nNodes << std::endl
                << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms" << std::endl
                << std::endl;
#endif
    nNodes = 0;
    return toReturn;
}

int max_alpha_beta(Game current, int alpha, int beta, int depth, int maxDepth);

int min_alpha_beta(Game current, int alpha, int beta, int depth, int maxDepth)
{
    nNodes++;
    if (terminalState(current) || depth == maxDepth)
        return utility(current.layout);
    int v = INT32_MAX;
    std::vector<Game> successors = generate_children(current, 'O');
    for (Game s : successors)
    {
        v = std::min(v, max_alpha_beta(s, alpha, beta, depth+1, maxDepth));
        if (v <= alpha){
            return v;
        }
        beta = std::min(beta, v);
    }
    return v;
}

int max_alpha_beta(Game current, int alpha, int beta, int depth, int maxDepth){
    nNodes++;
    if(terminalState(current) || depth == maxDepth)
        return utility(current.layout);
    int v = INT32_MIN;
    std::vector<Game> successors = generate_children(current, 'X');
    for(Game s : successors){
        v = std::max(v, min_alpha_beta(s, alpha, beta, depth+1, maxDepth));
        if(v >= beta){
            return v;
        }
        alpha = std::max(alpha, v);
    }
    return v;
}

Game alpha_beta_search(Game current, int maxDepth){
    std::vector<Game> successors = generate_children(current, 'O');
    int size = successors.size();
    Game toReturn = successors[0];
    auto start = std::chrono::high_resolution_clock::now();
    int v = max_alpha_beta(toReturn, INT32_MIN, INT32_MAX, 1, maxDepth);
    for (int i = 1; i < size; i++)
    {
        int cur = max_alpha_beta(successors[i], INT32_MIN, INT32_MAX, 1, maxDepth);
        if (cur < v)
        {
            v = cur;
            toReturn = successors[i];
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
#ifdef DEBUG
    std::cout << "Number of nodes explored: " << nNodes << std::endl
              << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << "ms"<<  std::endl
              << std::endl;
#endif
    nNodes = 0;
    return toReturn;
}


