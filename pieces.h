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
    Piece();
    Piece(char type, enum color side);
    ~Piece();
    char get_type();
    enum color get_side();
    void set_type(char type);
    void set_side(color side);
    void Piece_init(char type, enum color side);
    bool isGamePiece();
};

#endif