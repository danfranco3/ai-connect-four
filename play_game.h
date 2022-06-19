#include "game.h"

// "Include guard" prevents multiple inclusion:
#ifndef PLAY_GAME_H_ALREADY_INCLUDED
#define PLAY_GAME_H_ALREADY_INCLUDED

Game minmax(Game current, int maxDepth);
bool terminalState(Game current);
Game alpha_beta_search(Game current, int maxDepth);
#endif