//
// Ponder This May 2015 Solution by Richard George (rg.george1@gmail.com)
//

#include <algorithm>
#include <iostream>
#include <set>

#include "GameState.h"

// Class body definitions

GameState::GameState()
{
   // Default constructor

   values[0] = 0;
   values[1] = 0;
   values[2] = 0;
}

GameState &GameState::operator=(const GameState &a)
{ 
   // Copy operator
   int i;
   for (i=0;i<3;i++) values[i] = a.values[i];
   sort();
   return *this;   
}

GameState::GameState(int p1,int p2,int p3)
{
   // Provide explicit values for the starting capital of the three players

   values[0] = p1;
   values[1] = p2;
   values[2] = p3;
   
   sort();
}

GameState::GameState(const GameState &g)
{
   // Copy constructor
   int i;
   for (i=0;i<3;i++) values[i]=g.values[i];
   // we assume the GameState is already sorted 
}

GameState::GameState(const GameState &g,int m)
{
   // Copy and play move 'm'
   int i;
   for (i=0;i<3;i++) values[i]=g.values[i];
   playMove(m);
}

std::ostream &operator<<(std::ostream &os,const GameState &g)
{
   // Convenience to report value of game state
   os << "(" << g.values[0] << ", " << g.values[1] << ", " << g.values[2] << ")";
   return os;
}
      
void GameState::playMove(int m)
{
   // m = 0 : players 0,1 do battle
   // m = 1 : players 1,2 do battle
   // m = 2 : players 0,2 do battle
   
   int x,y;
   
   switch (m)
   {
      case 0:
      x=0;
      y=1;
      break;
      
      case 1:
      x=1;
      y=2;
      break;
      
      case 2:
      x=0;
      y=2;
   }
   
   // The betting rule
   if (values[x]<values[y])
   {
      values[y]-=values[x];
      values[x]*=2;  
   }
   else
   {
      values[x]-=values[y];
      values[y]*=2;
   }

   // Report tuples of player money in ordered form
   sort();
}

void GameState::sort()
{
   std::sort(&values[0],&values[3]);
}

bool GameState::isValid() const
{
   // No player can have zero or negative money
   if (values[0]<=0) return false;
   if (values[1]<=0) return false;
   if (values[2]<=0) return false;

   // Each player should have a different amount of money
   if (values[0]==values[1]) return false;
   if (values[1]==values[2]) return false;
   if (values[0]==values[2]) return false;

   return true;
}

bool operator <(const GameState &a,const GameState &b)
{
   // Compare two GameStates - needed to allow GameStates to be stored in std::set

   if (a.values[0]<b.values[0]) return true;
   if (a.values[0]>b.values[0]) return false;
   
   if (a.values[1]<b.values[1]) return true;
   if (a.values[1]>b.values[1]) return false;

   if (a.values[2]<b.values[2]) return true;
   if (a.values[2]>b.values[2]) return false;
   
   return false;
}
