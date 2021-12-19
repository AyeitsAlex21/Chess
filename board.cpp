#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>

#include "board.h"
#include "pieces.h"

using namespace std;

int player = 0; // 0 is whites turn -1 is blacks
unordered_map<char, int> row;
unordered_map<char, int> column;

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

    cout << "\n" << "   ";

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
    string from_location, to_location;

    do
    {
        if(!player){
            cout << "\nWhite player's move input a location: ";
        }else{
            cout << "\nBlack player's move input a location: ";
        }

        cin >> from_location;
        if(from_location.size() == 2 && column.find(from_location[0]) != column.end() &&
                row.find(from_location[1]) != row.end()){
            
            Piece selected = board[row[from_location[1]]][column[from_location[0]]];
            if(selected.isGamePiece() && selected.isMyPiece(player))
                break;
        }
        cout << "Invalid input, put column name next to row number";

    } while (1);
    
    // TODO need to finish where the piece can go, how they move,
    // taking a piece functionality and checkmate checking

    do
    {
        cout << "Move piece at " << from_location << " to: ";
        cin >> to_location;

        if(to_location.size() == 2 && column.find(to_location[0]) != column.end() &&
                    row.find(to_location[1]) != row.end()){
            break;
        }
        
        cout << "Invalid input\n";
    }while(1);

    player = ~player; // reassign players turn

}

int Board::checkmate(){
    // checks if a player has won
    return 1;
}