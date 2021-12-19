#include <iostream>
#include <vector>

#include "board.h"
#include "pieces.h"

using namespace std;

void print_board(Piece **board);

int main(int argc, char *argv[]){
    if(argc != 1){
        cout << "Invalid number of arguments" << endl;
        exit(EXIT_FAILURE);
    }

    Board board;
    //board.show();
}