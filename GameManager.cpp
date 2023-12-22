// File name:GameManager.cpp
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

GameManager::GameManager(board *bptr, Player *playerPtr[2]) {
    boardPtr=bptr;
    players[0]=playerPtr[0];
    players[1]=playerPtr[1];
}

void GameManager::run(){
    string m{};
    boardPtr->display_board();
    while(!boardPtr->game_is_over()){
        for(int i:{0,1}){
            players[i]->get_move(m);
            while(!boardPtr->update_board(m,players[i]->get_symbol())){
                players[i]->get_move(m);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                if(boardPtr->get_winner()=='X')
                    cout << players[0]->to_string() << " wins\n";
                else
                    cout << players[1]->to_string() << " wins\n";
                return;
            }
            if(boardPtr->is_draw()){
                cout << "Looks like a tie!\n";
                return;
            }
        }
    }
}