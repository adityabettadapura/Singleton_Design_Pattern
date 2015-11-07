/*
* Author: Aditya Bettadapura
*
* Contains the ChessBoard class methods
*/

#include "chess.h"

ChessBoard* ChessBoard::getInstance(){
    if(!instance){
    	instance = new ChessBoard();
    }
    return instance;
}

std::string& ChessBoard::operator()(const int position) {
    return board[position/10 - 1][position%10 - 1];
}

void ChessBoard::gameOver(const int a, const int b, int& gameover) {
    if((0==a) && (0==b)){
      gameover=1;
    } else {
      gameover=0;
    }
}
  
void ChessBoard::updateBoard(const int initpos, const int finalpos, ChessBoard* current){
    (*current)(finalpos) = (*current)(initpos);
    (*current)(initpos) = "0";
}
  
void ChessBoard::displayBoard(void) {
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
          std::cout << board[i][j] <<"\t";
        }
    std::cout << std::endl;
    }
}
  
