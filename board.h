#ifndef BOARD_H_
#define BOARD_H_
#include "pieces.h"

using namespace std;

class Board{
protected:
    Piece **board;
public:
    Board();
    ~Board();
    void show();
};

#endif