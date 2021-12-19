#ifndef PIECES_H_
#define PIECES_H_
#include <string>
#include <iostream>

using namespace std;
enum color{white, black};

class Piece{
protected:
    struct ChesirePiece;
    ChesirePiece *smile;
public:
    Piece(char type, enum color side);
    ~Piece();
    char get_type();
    enum color get_side();
    bool isGamePiece();
};

#endif