#include "pieces.h"

struct Piece::ChesirePiece{
    color side; // which players piece
    char type; // type of piece it is
};



Piece::Piece(char type, color side){
    smile = new(ChesirePiece);
    this->smile->side = side;
    this->smile->type = type;
    cout << this->smile->type << endl;
}

char Piece::get_type(){
    return (smile->type);
}

color Piece::get_side(){
    return (smile->side);
}

bool Piece::isGamePiece(){
    bool ret = true;
    if(smile->type == 'F')
        ret = false;
    return ret;
}

Piece::~Piece(){
    cout << "HEY\n";
    delete smile;
}