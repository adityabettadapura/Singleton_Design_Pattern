/*
* Author: Aditya Bettadapura
*
* Contains the Player class methods
*/

#include<cstring>
#include "chess.h"
#include "player.h"

  Player::Player() :initpos(0), finalpos(0), name(new char[1]) {name[0]='\0'; }

  Player::Player(const char* iname) : initpos(0), finalpos(0), name(new char[strlen(iname)+1]) {
    strcpy(name, iname);
  } 

  Player::Player(const Player& P): initpos(P.initpos), finalpos(P.finalpos), name(new char[strlen(P.name)+1]){
    strcpy(name, P.name);
  } 
  
  Player::~Player() { delete[] name;}
  
  Player& Player::operator=(const Player& P){
    if(this == &P){
      return *this;
    }
    delete this->name;
    this->name = new char[strlen(P.name)+1];
    strcpy(this->name, P.name);
    return *this;
  }
  
  const char* Player::getName(){
    return name;
  }

  bool Player::checkValid(const int ipos, const int fpos, ChessBoard* current) {
    std::string initpawn = (*current)(ipos);
    std::string finalpawn = (*current)(fpos);
    std::cout <<"initpawn=" << initpawn << "\t" << "finalpawn=" << finalpawn << std::endl;
    if(initpawn == "0"){
      std::cout << "Invalid move!" << std::endl;
      return false; 
    } else if (initpawn[0] == finalpawn[0]){
      std::cout << "Invalid move!" << std::endl;
      return false;
    } else {
      return true;
    }
  } 
  
  bool Player::checkBounds(const int initpos, const int finalpos){
    int initrow = (initpos/10)-1;
    int initcol = (initpos%10)-1;
    int finalrow = (finalpos/10)-1;
    int finalcol = (finalpos%10)-1;
    
    if(initrow < 0 || initcol < 0 || initrow > 7 || initcol > 7){
      std::cout << "Initial position out of bounds" << std::endl;
      return false;
    }
    if(finalrow < 0 || finalcol < 0 || finalrow > 7 || finalcol > 7){
      std::cout << "Final position out of bounds" << std::endl;
      return false;
    }
    
    return true; 
  }
  
  void Player::setPos(const int x, const int y){
    initpos = x;
    finalpos = y;
  }

  int Player::getInitPos(void){ return initpos; }
  
  int Player::getFinalPos(void){ return finalpos; } 



