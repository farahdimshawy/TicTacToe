// File name:board.h
// Purpose:a working integrated game
// Author(s):
////Farah Ali Mohammed
////Hana Ragab Ahmed
////Reem Mohammed Mahmoud
// ID(s):20220497, 20221192, 20221230
// Section: S18
// Date:16/12/2023
// Version: 1
#ifndef PYRAMIC_BOARD_H
#define PYRAMIC_BOARD_H
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <random>
using namespace std;


class board {
protected:
    int no_moves{0};
    char winner;

public:
    char get_winner(){
        return winner;
    }
    virtual bool update_board (string m, char symbol)=0;
    virtual bool is_winner()=0;
    virtual bool is_draw()=0;
    virtual void display_board()=0;
    virtual bool game_is_over()=0;
};
class pyramic_XO: public board{
protected:
    map <int, char> gameboard;
public:
    pyramic_XO();
    bool update_board(string m, char symbol) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
    char get_value(int& m);
    void set_value(int& m, char s);
};
class fourinarowBoard:public board {
protected:
    char b[6][7]={{'.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.'}};
    int n_rows, n_cols;
public:
    fourinarowBoard ();
    bool update_board (string m, char symbol) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
};
class tictactoe:public board {
protected:
    int n_cols,n_rows;
    int x_counter{}, y_counter{};
    char **gameboard;
public:

    tictactoe ();
    bool update_board (string m, char symbol) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
};
class X_O_Board:public board {
    int n_rows, n_cols;
    char** board;
public:
    X_O_Board ();
    bool update_board (string m, char symbol) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
};

class Player{
protected:
    string name;
    char symbol;
    pyramic_XO* pyramic_board;
public:
    Player (char symbol);
    Player (int order, char symbol);
    virtual void get_move(string& m);
    string to_string();
    char get_symbol();
    void get_board(board* bPtr){
        pyramic_board=dynamic_cast<pyramic_XO*>(bPtr);
    }
};
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    RandomPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(string& m) override;
};
class Pyramid_AiPlayer: public Player{
public:
    Pyramid_AiPlayer(char symbol);
    void get_move(string &m) override;
};

///////////////////////////////////////////
class GameManager {
public:
    board* boardPtr;
    Player* players[2];
public:
    GameManager(board*, Player* playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};


#endif //PYRAMIC_BOARD_H
