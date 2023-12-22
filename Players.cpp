// File name:Players.cpp
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
#include <cstdlib>
#include <algorithm>
#include <cctype>

Player::Player(int order, char symbol){
    cout << "Welcome player " << order << endl;
    cout << "Enter your name: ";
    cin >> name;
    this->symbol= symbol;
}

Player::Player(char symbol) {
    this->symbol=symbol;
}

void Player::get_move(string& m) {
    cout << "\nPlease enter your move: ";
    getline(cin, m);
    m.erase(remove_if(m.begin(), m.end(), ::isspace), m.end());
}

string Player::to_string() {
    return "Player: " + name;
}

char Player::get_symbol(){
    return symbol;
}

RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol) {
    this->dimension=dimension;
    this->name= "Random Computer Player";
    cout << "My name is " << name << endl;
}

void RandomPlayer::get_move(string& m) {
    if(dimension==1){
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> distribution(0, 9);
        m[0]= static_cast<char>(distribution(rng)+'0');
    }
    else if(dimension==2){
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> distribution(1, 7);
        m[0]= static_cast<char>(distribution(rng)+'0');
    }
    else if(dimension==3){
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> distribution(0, 5);
        m[0]= static_cast<char>(distribution(rng)+'0');
        std::mt19937 rng2(std::random_device{}());
        std::uniform_int_distribution<int> distribution2(0, 5);
        m[1]= static_cast<char>(distribution(rng2)+'0');
    }
    else if(dimension==4){
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> distribution(0, 2);
        m[0]= static_cast<char>(distribution(rng)+'0');
        std::mt19937 rng2(std::random_device{}());
        std::uniform_int_distribution<int> distribution2(0, 2);
        m[1]= static_cast<char>(distribution(rng2)+'0');
    }

}
Pyramid_AiPlayer::Pyramid_AiPlayer(char symbol): Player(symbol){
    this->name= "Ai Player";
    cout << "My name is " << name << endl;
}
void Pyramid_AiPlayer::get_move(string &m) {
    for(int c=0; c <  9; c++){
        if(pyramic_board->get_value(c) == ' '){
            pyramic_board->set_value(c, 'X');
            if(pyramic_board->is_winner()){
                m[0]=c+'0';
                pyramic_board->set_value(c,' ');
                return;
            }
            pyramic_board->set_value(c,' ');
        }
    }
    for(int c=0; c <9; c++){
        if(pyramic_board->get_value(c) == ' '){
            pyramic_board->set_value(c, 'O');
            if(pyramic_board->is_winner()){
                m[0]=c+'0';
                pyramic_board->set_value(c,' ');
                return;
            }
            pyramic_board->set_value(c,' ');
        }
    }
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 9);
    m[0]= static_cast<char>(distribution(rng)+'0');
}
