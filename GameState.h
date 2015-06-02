//
// Ponder This May 2015 Solution by Richard George (rg.george1@gmail.com)
//

#ifndef GameState_H
#define GameState_H

#include <iostream>

class GameState {
   public: 
   
      GameState();
      GameState(int p1,int p2,int p3);
      GameState(const GameState &initial,int move);
      GameState(const GameState &source);

      bool isValid() const;
      
      friend std::ostream &operator<<(std::ostream &,const GameState &);
      friend bool operator <(const GameState &a,const GameState &b);
      
      GameState &operator=(const GameState &a);
      
   private:
      int values[3];

      void playMove(int m);
      void sort();
};

#endif

