#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "board.h"
#include "pieces.h"

using namespace std;
extern unordered_map<char, int> row;
extern unordered_map<char, int> column;
 
int main(int argc, char *argv[]){
    if(argc != 1){
        cout << "Invalid number of arguments" << endl;
        exit(EXIT_FAILURE);
    }

    // NOTE could have used something more elegant but i wanted
    // to practice C++ hashmap
    column['A'] = 0;
    column['B'] = 1;
    column['C'] = 2;
    column['D'] = 3;
    column['E'] = 4;
    column['F'] = 5;
    column['G'] = 6;
    column['H'] = 7;
    
    row['0'] = 0;
    row['1'] = 1;
    row['2'] = 2;
    row['3'] = 3;
    row['4'] = 4;
    row['5'] = 5;
    row['6'] = 6;
    row['7'] = 7;

    Board board;
    do
    {
        board.show();
        board.move_piece();

    }while(board.checkmate());
}