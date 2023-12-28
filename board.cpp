// File name:board.cpp
// Purpose:a working integrated game
// Author(s):
////Farah Ali Mohammed
////Hana Ragab Ahmed
////Reem Mohammed Mahmoud
// ID(s):20220497, 20221192, 20221230
// Section: S18
// Date:16/12/2023
// Version: 1
#include "board.h"
#include <limits>
#include <algorithm>
pyramic_XO::pyramic_XO() {
    gameboard= {{0,' '},
                {1,' '}, {2, ' '},{3, ' '},
                {4, ' '}, {5, ' '}, {6, ' '}, {7, ' '}, {8, ' '}};
}

bool pyramic_XO::update_board(string m, char symbol) {
    int l;
    l=m[0]-'0';
    if(!(l<0 or l>9) && gameboard[l]==' '){
        gameboard[l]= toupper(symbol);
        no_moves++;
        return true;
    }
    else
        return false;
}

void pyramic_XO::display_board() {
    int current_key=0;
    auto it=gameboard.find(current_key);
    if(current_key==0){
        if(it->second==' '){
            cout << "    " << it->first << endl;
            it++;
        }
        else{
            cout << "    " << it->second << endl;
            it++;
        }
    }
    cout << "  ";
    for(int i=1; i < 4; i ++){
        if(it->second==' '){
            cout << it->first <<  " ";
            it++;
        }
        else{
            cout << it->second <<  " ";
            it++;
        }
    }
    cout << endl;
    for(int i=4; i <9; i++) {
        if(it->second==' '){
            cout << it->first << " ";
            it++;
        }
        else{
            cout << it->second << " ";
            it++;
        }
    }
    cout << endl;
}

bool pyramic_XO::is_winner(){
    if(gameboard[0]!=' '){
        if(gameboard[0]==gameboard[1] && gameboard[0]==gameboard[4]){
            winner = gameboard[0];
            return true;
        }
        else if(gameboard[0]==gameboard[3] && gameboard[0]==gameboard[8]){
            winner = gameboard[0];
            return true;
        }

        else if(gameboard[0]==gameboard[2] && gameboard[0]==gameboard[6]) {
            winner = gameboard[0];
            return true; }
    }
    if(gameboard[1]!=' '){
        if(gameboard[1]==gameboard[2] && gameboard[1]==gameboard[3]) {
            winner = gameboard[1];
            return true; }
    }
    if(gameboard[6]!=' '){
        if(gameboard[5]==gameboard[4] && gameboard[5]==gameboard[6]) {
            winner = gameboard[6];
            return true; }
        else if(gameboard[5]==gameboard[6] && gameboard[5]==gameboard[7]) {
            winner = gameboard[6];
            return true; }
        else if(gameboard[7]==gameboard[6] && gameboard[6]==gameboard[8]) {
            winner = gameboard[6];
            return true; }
    }
    return false;
}

bool pyramic_XO::is_draw(){
    return (no_moves==9 && !is_winner());
}

bool pyramic_XO::game_is_over() {
    return no_moves >= 9;
}

char pyramic_XO::get_value(int& m){
    return gameboard[m];
}
void pyramic_XO::set_value(int& m, char s){
    gameboard[m]= s;
}
bool fourinarowBoard:: update_board(string m,char symbol){
    int x = m[0]-'0';
    int y=m[1]-'0';
    if (x>=0 && x<=n_cols) {
        for (int i = 0; i < 6; i++)
        {
            if(b[6-i][x-1]=='.'){
                b[6-i][x-1]=toupper(symbol);
                no_moves+=1;
                return true;
            }
        }


    } //checks whether the input is within range of board size
    return false;
}
fourinarowBoard::fourinarowBoard(){
    n_rows=6;
    n_cols=7;
}
bool fourinarowBoard::is_draw(){
    // if(n_moves==n_rows*n_cols)
    return no_moves==n_rows*n_cols;
}
void fourinarowBoard::display_board(){
    cout<<"| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    for (int i = 0; i < 6; i++)
    {
        cout<<"|";
        for (int j = 0; j < 7; j++)
        {
            cout<<' '<<b[i][j]<<" |";
        }
        cout<<"\n-----------------------------\n";

    }
}

bool fourinarowBoard::is_winner(){
    // Check for a winner horizontally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (b[i][j] != '.' && b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i][j + 3]) {
                winner=b[i][j];
                return true;
            }
        }
    }

    // Check for a winner vertically
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (b[i][j] != '.' && b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j] && b[i][j] == b[i + 3][j]) {
                winner=b[i][j];
                return true;
            }
        }
    }

    // Check for a winner diagonally (bottom-left to top-right)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (b[i][j] != '.' && b[i][j] == b[i + 1][j + 1] && b[i][j] == b[i + 2][j + 2] && b[i][j] == b[i + 3][j + 3]) {
                winner=b[i][j];
                return true;
            }
        }
    }

    // Check for a winner diagonally (top-left to bottom-right)
    for (int i = 3; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (b[i][j] != '.' && b[i][j] == b[i - 1][j + 1] && b[i][j] == b[i - 2][j + 2] && b[i][j] == b[i - 3][j + 3]) {
                winner=b[i][j];
                return true;
            }
        }
    }

    return false;

}
bool fourinarowBoard::game_is_over(){
    return is_winner()||is_draw();

}
// Set the board
tictactoe::tictactoe () {
    n_rows = n_cols = 9;
    gameboard = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        gameboard [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            gameboard[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool tictactoe::update_board (string m, char symbol){
    // Only update if move is valid
    int x=m[0]-'0';
    int y=m[1]-'0';
    if(no_moves>=24){
        return true;
    }

    if ((x>=0 && x<5) &&( y>=0 && y<5) && gameboard[x+2][y+2]==0) {
        gameboard[x+2][y+2] = toupper(symbol);
        no_moves++;
        return true;
    }
    else{
        return false;}
}

// Display the board and the pieces on it
void tictactoe::display_board() {
    if(no_moves<=24){
        for (int i=2;i<7;i++) {
            cout << "\n| ";
            for (int j=2;j<7;j++) {
                cout << "(" << i-2 << "," << j-2 << ")";
                cout << setw(2) << gameboard [i][j] << " |";
            }
            cout << "\n-----------------------------";
        }
        cout << endl;
    }
}

bool tictactoe::is_winner() {
    if(no_moves>=24){
        for (int i=2;i<7;i++) {
            for (int j=2;j<7;j++) {
                if ((gameboard[i][j]!= 0) && (gameboard[i][j] == gameboard[i + 1][j + 1] && gameboard[i][j]== gameboard[i + 2][j + 2] )) {
                    if(gameboard[i][j]=='X'){
                        x_counter++;
                    }
                    else{
                        y_counter++;
                    }
                }
                if ((gameboard[i][j]!= 0) && (gameboard[i][j] == gameboard[i + 1][j ] && gameboard[i][j]== gameboard[i + 2][j]  )) {
                    if(gameboard[i][j]=='X'){
                        x_counter++;
                    }
                    else{
                        y_counter++;
                    }
                }
                if ((gameboard[i][j]!= 0) && (gameboard[i][j] == gameboard[i][j + 1] && gameboard[i][j] == gameboard[i][j + 2] )) {
                    if(gameboard[i][j]=='X'){
                        x_counter++;
                    }
                    else{
                        y_counter++;
                    }
                }
                if ((gameboard[i][j]!= 0) && (gameboard[i][j] == gameboard[i + 1][j - 1] && gameboard[i][j] == gameboard[i + 2][j - 2] )) {
                    if(gameboard[i][j]=='X'){
                        x_counter++;
                    }
                    else{
                        y_counter++;
                    }
                }
            }
        }
        if (x_counter > y_counter){
            winner='X';
            return true;
        }
        else if(y_counter > x_counter){
            winner='Y';
            return true;
        }
        else
            return false;
    }
    else{
        return false;
    }
}


// Return true if 9 moves are done and no winner
bool tictactoe::is_draw() {
    if(no_moves >= 24 && y_counter==x_counter){
        return true;
    }
    else{
        return false;
    }
}

bool tictactoe::game_is_over () {
    if(no_moves>=24 && (is_winner() || is_draw())){
        return true;
    }
    else if(no_moves>=24){
        no_moves++;
        return false;
    }
    else{
        return false;
    }
}

// Set the board
X_O_Board::X_O_Board () {
    n_rows = n_cols = 3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (string m, char symbol){
    // Only update if move is valid
    int x=m[0]-'0';
    int y=m[1]-'0';
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
        board[x][y] = toupper(symbol);
        no_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
        {
            winner = row_win[i];
            return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {
        winner=diag_win[0];
        return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (no_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return no_moves >= 9;
}
