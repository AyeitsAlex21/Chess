#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "board.h"
#include "pieces.h"

using namespace std;

Board::Board(){
    // initialize board
    board = new Piece*[8];
    for(int i = 0; i < 8; i++){
        board[i] = new Piece[8];
        for(int j = 0; j < 8; j++){
            if(i <= 1 || 6 <= i){
                // create WHITE's pawns
                if(i == 1)
                    board[i][j].Piece_init('P', white);
                // create BLACK's paws
                else if(i == 6)
                {
                    board[i][j].Piece_init('p', black);
                }
                else if(i == 0){
                    //create WHITE's special pieces
                    if(j == 0 || j == 7)
                        board[i][j].Piece_init('R', white);
                    else if(j == 1 || j == 6)
                        board[i][j].Piece_init('N', white);
                    else if(j == 2 || j == 5)
                        board[i][j].Piece_init('B', white);
                    else if(j == 3)
                        board[i][j].Piece_init('Q', white);
                    else
                        board[i][j].Piece_init('K', white);
                }
                else{
                    //create BLACK's special pieces
                    if(j == 0 || j == 7)
                        board[i][j].Piece_init('r', black);
                    else if(j == 1 || j == 6)
                        board[i][j].Piece_init('n', black);
                    else if(j == 2 || j == 5)
                        board[i][j].Piece_init('b', black);
                    else if(j == 3)
                        board[i][j].Piece_init('q', black);
                    else
                        board[i][j].Piece_init('k', black);
                }
            }
            else{
                // placeholders for empty spots on board
                board[i][j].Piece_init('F', white);
            }
        }
    }
};

Board::~Board(){
    for(int i = 0; i < 8; i++){
        delete[] board[i];
    }
    delete[] board;
};

void Board::show(){
    char print_piece;
    string col_names = "ABCDEFGH";

    cout << "\n\n" << "   ";

    for(int i = 0; i < 8; i++){
        cout << "  " << col_names[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 8; i++){
        cout << i << " { ";
        for(int j = 0; j < 8; j++){
            if(board[i][j].get_type() != 'F')
                print_piece = board[i][j].get_type();
            else
                print_piece = ' ';
            
            cout << "[" << print_piece << "] ";
        }
        cout << "}" << endl;
    }
}

int Board::move_piece(){
    // moves a piece to player desired location

}

int Board::checkmate(){
    // checks if a player has won
    return 1;
}