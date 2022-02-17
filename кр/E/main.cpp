#include <iostream>
#include <vector>
//#include <cmath>

/*
class Piece{
public:

    char v;
    unsigned short int h;
    Piece(Cell c): h(c.h),v(v.c){}
    virtual bool available();
};

class King:public Piece{
public:
    King(Cell c): Piece(c) {}
    bool available(Cell c){
        if (abs(c.v - v) <= 1 && abs(c.h - h) <=1){return true;}
        else {return false;}
    }
};

class Bishop:public Piece{
public:
    Bishop(Cell c): h(c.h),v(v.c){}

    bool available(Cell c){
        if ( abs(c.h-h) == abs((c.v) - (v)) ) {return true;}
        else {return false;}
    }
};

class Rook:public Piece{
public:
    Rook(Cell c): h(c.h),v(v.c){}

    bool available(Cell c){
        if ( ((c.v)==(v)) or (c.h==h) ){return true;}
        else {return false;}
    }
};

class Queen:public Piece{
public:
    Queen(Cell c): h(c.h),v(v.c){}

    bool available(Cell c){
        if ( ((c.v)==(v)) or (c.h==h) or (abs(c.h-h) == abs((c.v) - (v))) ){return true;}
        else {return false;}
    }
};
*/
class Cell final {
public:
    char v;
    unsigned short int h;
    Cell(): Cell('A', 1) {}
    Cell(char v, unsigned short int h): v(v), h(h) {}
};

int abs1(int a){
    if (a>=0){
        return a;
    } else
        return -a;
}


class Piece {
public:
    char v;
    unsigned short int h;
    Piece(): Piece('A', 1){}
    Piece(char v, unsigned short int h): v(v), h(h) {}
    Piece(Cell c): v(c.v), h(c.h) {}
    virtual bool available(Cell c){}
};

class King:public Piece{
public:
    King(Cell c): Piece(c) {}
    bool available(Cell c){
        if (abs1(c.v - v) == 1 && abs1(c.h - h) ==1){return true;}
        else {return false;}
    }
};

class Bishop:public Piece{
public:
    Bishop(Cell c): Piece(c){}

    bool available(Cell c){
        if ( (abs1(c.h-h) == abs1((c.v) - (v))) && (c.h != h && c.v!=v) ) {return true;}
        else {return false;}
    }
};

class Rook:public Piece{
public:
    Rook(Cell c): Piece(c){}

    bool available(Cell c){
        if ( ((c.v==v) or (c.h==h)) && (c.h != h && c.v!=v) ){return true;}
        else {return false;}
    }
};

class Queen:public Piece{
public:
    Queen(Cell c): Piece(c){}

    bool available(Cell c){
        if ( ((c.v==v) or (c.h==h)) or ((abs1(c.h-h) == abs1(c.v - v)) ) && (c.h != h && c.v!=v) ){return true;}
        else {return false;}
    }
};

std::vector <bool> are_available(Cell c, std::vector<Piece*> const &pieces) {
    std::vector<bool> answ;
    for (auto p : pieces)
        answ.push_back(p->available(c));
    return answ;
}

std::vector<bool> are_available(Cell c, std::vector<Piece*> const &pieces);

int main() {
    std::vector<Piece*> pieces;
    pieces.push_back(new King(Cell('A',1)));
    pieces.push_back(new Queen(Cell('B',2)));
    pieces.push_back(new Rook(Cell('C',3)));
    pieces.push_back(new Bishop(Cell('D',4)));

    for(auto b : are_available(Cell('A',1),pieces))
        std::cout << b << ' ';
    std::cout << std::endl;

    for (auto p : pieces)
        delete p;
    return 0;
}
