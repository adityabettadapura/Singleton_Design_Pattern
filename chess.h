/*
* Author: Aditya Bettadapura
*
* Contains the ChessBoard class specifications
* Chessboard class is a Singleton Design pattern
*/

#include<iostream>

class ChessBoard{
public:
  static ChessBoard* getInstance();
  std::string& operator()(const int position);
  void updateBoard(const int initpos, const int finalpos, ChessBoard* current);
  void displayBoard(void);
  void gameOver(const int a, const int b, int& gameover);

private:  
  std::string board[8][8];
  static ChessBoard* instance;
  
  ChessBoard(){
    board[0][0]="br";board[0][1]="bn";board[0][2]="bb";board[0][3]="bq";board[0][4]="bk";board[0][5]="bb";board[0][6]="bn";board[0][7]="br"; 
    board[1][0]="bs";board[1][1]="bs";board[1][2]="bs";board[1][3]="bs";board[1][4]="bs";board[1][5]="bs";board[1][6]="bs";board[1][7]="bs"; 
    board[2][0]="0";board[2][1]="0";board[2][2]="0";board[2][3]="0";board[2][4]="0";board[2][5]="0";board[2][6]="0";board[2][7]="0"; 
    board[3][0]="0";board[3][1]="0";board[3][2]="0";board[3][3]="0";board[3][4]="0";board[3][5]="0";board[3][6]="0";board[3][7]="0"; 
    board[4][0]="0";board[4][1]="0";board[4][2]="0";board[4][3]="0";board[4][4]="0";board[4][5]="0";board[4][6]="0";board[4][7]="0"; 
    board[5][0]="0";board[5][1]="0";board[5][2]="0";board[5][3]="0";board[5][4]="0";board[5][5]="0";board[5][6]="0";board[5][7]="0"; 
    board[6][0]="ws";board[6][1]="ws";board[6][2]="ws";board[6][3]="ws";board[6][4]="ws";board[6][5]="ws";board[6][6]="ws";board[6][7]="ws"; 
    board[7][0]="wr";board[7][1]="wn";board[7][2]="wb";board[7][3]="wq";board[7][4]="wk";board[7][5]="wb";board[7][6]="wn";board[7][7]="wr"; 
    std::cout << "Board setup!" << std::endl;
  }
  
  ChessBoard(const ChessBoard&);
  
  ChessBoard& operator=(const ChessBoard&);
};



