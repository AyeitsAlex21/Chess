#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "board.h"
#include "pieces.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 1){
        cout << "Invalid number of arguments" << endl;
        exit(EXIT_FAILURE);
    }

    int player = 0; // 0 is whites turn 1 is blacks

    // NOTE could have used something more elegant but i wanted
    // to practice C++ hashmap
    unordered_map<char, int> column;
    column['A'] = 0;
    column['B'] = 1;
    column['C'] = 2;
    column['D'] = 3;
    column['E'] = 4;
    column['F'] = 5;
    column['G'] = 6;
    column['H'] = 7;
    unordered_map<char, int> row;
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

        string from_location, to_location;

        if(!player){
            cout << "\nWhite player's move input a location: ";
        }else{
            cout << "\nBlack player's move input a location: ";
        }

        cin >> from_location;
        while(from_location.size() != 2 || column.find(from_location[0]) == column.end() ||
                        row.find(from_location[1]) == row.end())
        {
            cout << "Invalid input, put column name next to row number";
            if(!player){
                cout << "\nWhite player's move input a location: ";
            }else{
                cout << "\nBlack player's move input a location: ";
            }
            cin >> from_location;
        }

        cout << "Move piece at " << from_location << " to: ";
        cin >> to_location;

        while(to_location.size() != 2 || column.find(to_location[0]) == column.end() ||
                        row.find(to_location[1]) == row.end()){
            
            cout << "Invalid input\n";
            cout << "Move piece at " << from_location << " to: ";
            cin >> to_location;
        }
        cout << "finally";

    }while(board.checkmate());
}