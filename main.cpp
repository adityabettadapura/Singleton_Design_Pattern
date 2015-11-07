/*
* Author: Aditya Bettadapura
*
* Main function for the chessboard game. 
* The game does not have any AI. But can be used
* by two human players playing against each other.
*
* Go through README for more details.
*/

#include <iostream>
#include "chess.h"
#include "player.h"

ChessBoard* ChessBoard::instance = NULL;


int main(){
 
  ChessBoard* board = ChessBoard::getInstance();
  Player white("aditya"), black("malloy");
  int x=0, y=0;
  static int gameover=0;
  board->displayBoard();
  
  while(!gameover){
    std::cout << "If gameover, enter 0,0,0,0" << std::endl;
    std::cout << white.getName() << " enter initial pawn position:" << std::endl;
    std::cin >> x;
    std::cout << white.getName() << " enter final position:" << std::endl;
    std::cin >> y;
    board->gameOver(x,y, gameover);
    white.setPos(x,y);
    if(white.checkBounds(white.getInitPos(), white.getFinalPos())){
      if(white.checkValid(white.getInitPos(), white.getFinalPos(), board)){
        board->updateBoard(white.getInitPos(), white.getFinalPos(),board);
        board->displayBoard();
      }
    }
    std::cout << black.getName() << " enter initial pawn position:" << std::endl;
    std::cin >> x;
    std::cout << black.getName() << " enter final position:" << std::endl;
    std::cin >> y;
    board->gameOver(x,y,gameover);
    black.setPos(x,y);
    if(black.checkBounds(black.getInitPos(), black.getFinalPos())){
      if(black.checkValid(black.getInitPos(), black.getFinalPos(), board)){
        board->updateBoard(black.getInitPos(), black.getFinalPos(), board);
        board->displayBoard();
      }
    }
  }
  board->displayBoard();
  delete board;
}


