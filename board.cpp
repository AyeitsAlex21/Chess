#include <iostream>
#include <stdlib.h>

#include "board.h"
#include "pieces.h"

using namespace std;

Board::Board(){
    // initialize board
    
    board = (Piece **) malloc(sizeof(Piece *) * 8);
    for(int i = 0; i < 8; i++){
        board[i] = (Piece *) malloc(sizeof(Piece) * 8);
    }
 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i <= 1 || 6 <= i){
                // create WHITE's pawns
                if(i == 1)
                    board[i][j] = (Piece('P', white));
                // create BLACK's paws
                else if(i == 6)
                {
                    board[i][j] = (Piece('p', black));
                }
                else if(i == 0){
                    //create WHITE's special pieces
                    if(j == 0 || j == 7)
                        board[i][j] = (Piece('R', white));
                    else if(j == 1 || j == 6)
                        board[i][j] = (Piece('N', white));
                    else if(j == 2 || j == 5)
                        board[i][j] = (Piece('B', white));
                    else if(j == 3)
                        board[i][j] = (Piece('Q', white));
                    else
                        board[i][j] = (Piece('K', white));
                }
                else{
                    //create BLACK's special pieces
                    if(j == 0 || j == 7)
                        board[i][j] = (Piece('r', white));
                    else if(j == 1 || j == 6)
                        board[i][j] = (Piece('n', white));
                    else if(j == 2 || j == 5)
                        board[i][j] = (Piece('b', white));
                    else if(j == 3)
                        board[i][j] = (Piece('q', white));
                    else
                        board[i][j] = (Piece('k', white));
                }
            }
            else{
                // placeholders for empty spots on board
                board[i][j] = (Piece('F', white));
            }
            cout << board[i][j].get_type() << " i = " << i << " j = " << j << endl;
        }
    }
};

Board::~Board(){
    for(int i = 0; i < 8; i++){
        free(board[i]);
    }
    free(board);
};

void Board::show(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j].get_type();
        }
        cout << endl;
    }
}