// File name:main
// Purpose:a working integrated game
// Author(s):
////Farah Ali Mohammed
////Hana Ragab Ahmed
////Reem Mohammed Mahmoud
// ID(s):20220497, 20221192, 20221230
// Section: S18
// Date:16/12/2023
// Version: 1
#include <iostream>
#include "board.h"
using namespace std;
int main(){
    cout << "Welcome to  Tic-Tac-Toe :)\nChoose your game\n";
    while(1) {
        vector<string> menu{
                "Pyramid Tic Tac Toe",
                "Four In A Row",
                "5x5 Tic Tac Toe",
                "Classic Tic Tac Toe"
        };
        cout << "====================================\n";
        for (int i{1}; i <= menu.size(); i++) {
            cout << i << "-" << menu[i - 1] << endl;
        }
        cout << "0-Exit\n";
        cout << "====================================\n";
        cout << "Response: ";
        int game;
        cin >> game;
        int choice;
        Player* players[2];
        if (game < 0 || game > menu.size()) continue;
            if(game==0)
                return 0;
            else if(game==1) {
                players[0] = new Player(1, 'x');
                cout << "Press 1 if you want to play with computer: ";
                cin >> choice;
                board *bPtr=new pyramic_XO;
                if (choice != 1)
                    players[1] = new Player(2, 'o');
                else
                    //Player pointer points to child
                    players[1] = new Pyramid_AiPlayer('O');
                GameManager pyramid(bPtr, players);
                players[1]->get_board(pyramid.boardPtr);
                pyramid.run();
                system("pause");
            }
            else if(game==2) {
                players[0] = new Player(1, 'x');
                cout << "Press 1 if you want to play with computer: ";
                cin >> choice;
                if (choice != 1)
                    players[1] = new Player(2, 'o');
                else
                    //Player pointer points to child
                    players[1] = new RandomPlayer('o', 2);
                (GameManager(new fourinarowBoard(), players)).run();
                system("pause");
            }
            else if(game==3) {
                players[0] = new Player(1, 'x');
                cout << "Press 1 if you want to play with computer: ";
                cin >> choice;
                if (choice != 1)
                    players[1] = new Player(2, 'o');
                else
                    //Player pointer points to child
                    players[1] = new RandomPlayer('o', 3);
                (GameManager(new tictactoe(), players)).run();
                system("pause");
            }
            else if(game==4) {
                players[0] = new Player(1, 'x');
                cout << "Press 1 if you want to play with computer: ";
                cin >> choice;
                if (choice != 1)
                    players[1] = new Player(2, 'o');
                else
                    //Player pointer points to child
                    players[1] = new RandomPlayer('o', 4);
                (GameManager(new X_O_Board(), players)).run();
                system("pause");
            }
        }
    }

