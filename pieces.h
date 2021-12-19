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
    bool isGamePiece();
    bool isMyPiece(int player);
    bool isEnemyPiece(int player);
    friend class Board; // so Board can use private fucntions
public:
    Piece();
    Piece(char type, enum color side);
    ~Piece();
    char get_type();
    enum color get_side();
    void set_type(char type);
    void set_side(color side);
    void Piece_init(char type, enum color side);
};

#endif