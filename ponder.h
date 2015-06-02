//
// Ponder This May 2015 Solution by Richard George (rg.george1@gmail.com)
//

#ifndef Ponder_H
#define Ponder_H

#include <set>

#include "GameState.h"

int main(int argc,char **argv,char **envp);
bool sanity();
void solve_problem(const char *);

int explore_game(const GameState &starting);
bool explore_game2(std::set<GameState> &known,std::set<GameState> &to_explore,std::set<GameState> &to_explore2,int);

#endif
