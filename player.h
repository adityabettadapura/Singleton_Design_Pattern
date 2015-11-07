/*
* Author: Aditya Bettadapura
*
* Contains the Player class specifications
*/

#include<iostream>

class Player{
public:
  Player();
  Player(const char* iname); 
  Player(const Player& P);
  ~Player();
  Player& operator=(const Player& P);
  bool checkValid(const int ipos, const int fpos, ChessBoard* current);
  bool checkBounds(const int initpos, const int finalpos);
  void setPos(const int x, const int y);
  int getInitPos(void);
  int getFinalPos(void); 
  const char* getName();

private: 
  int initpos;
  int finalpos;
  char* name;
};


