#include "pieces.h"

struct Piece::ChesirePiece{
    color side; // which players piece
    char type; // type of piece it is
};

Piece::Piece(){
    smile = new(ChesirePiece);
}

Piece::Piece(char type, color side){
    smile = new(ChesirePiece);
    this->smile->side = side;
    this->smile->type = type;
}

char Piece::get_type(){
    return (smile->type);
}

color Piece::get_side(){
    return (smile->side);
}

void Piece::set_type(char type){
    smile->type = type;
}

void Piece::set_side(color side){
    smile->side = side;
}

void Piece::Piece_init(char type, color side){
    this->smile->side = side;
    this->smile->type = type;
}

bool Piece::isGamePiece(){
    bool ret = true;
    if(smile->type == 'F')
        ret = false;
    return ret;
}

Piece::~Piece(){
    delete smile;
}