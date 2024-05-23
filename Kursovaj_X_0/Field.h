#ifndef Field_h
#define Field_h
#include "Screen.h"
#include "Consol.h"

class Field {
  private:
    Consol* _consol = nullptr;
    Screen* _screen = nullptr;
    int _cellWidth;
    int _cellHeight;
    byte _fieldSaveDraw [3][3] = {        
      {0,0,0},
      {0,0,0},
      {0,0,0}
    };
  public:
    Field(Consol* consol, Screen* screen){
      _consol = consol;
      _screen = screen;
      _cellWidth = _screen->GetScreenWidth()/3;
      _cellHeight = _screen->GetScreenHeight()/3;
    }

    bool DrawX(int row, int column){
      if(_fieldSaveDraw [row][column] != 0){
        return false;
      };
      _screen->DrawX(column*_cellWidth, row*_cellHeight, _cellWidth, _cellHeight);
      _fieldSaveDraw [row][column] = 1;
      return true;
    }
    bool DrawO(int row, int column){
      if(_fieldSaveDraw [row][column] != 0){
        return false;
      };
      _screen->DrawO(column*_cellWidth, row*_cellHeight, _cellWidth, _cellHeight);
      _fieldSaveDraw [row][column] = -1;
      return true;
    }
};

#endif
