#ifndef GAME_H
#define GAME_H
#include "IrDaButtonsCallback.h"
#include "Field.h"
#include "Consol.h"
#include "Screen.h"

class Game : public IrDaButtonsCallback{
  private:
    Consol* _consol = nullptr;
    Field* _field = nullptr;
    Screen* _screen = nullptr;
    bool _isDrawX = true; 
  public:
    Game(Consol* consol, Screen* screen){
      _consol = consol;
      _screen = screen;
      _field = new Field(_consol, _screen);
    }
    void Init(){
      _screen->ClearScreen();
      _screen->DrawField();
      _consol->GameInitialized();
    }
    void DrawFigure(int row, int column){
      bool isFigureDrawed;
      if (_isDrawX == true){
        isFigureDrawed = _field -> DrawX(row, column);
      } else {
        isFigureDrawed = _field -> DrawO(row, column);
      }
      if(isFigureDrawed){
        _isDrawX = ! _isDrawX;
      }
    }
    void On1ButtonClick() override{
      _consol->ShowButtonClicked("Game","1");
      DrawFigure(0, 0);
    }
    void On2ButtonClick() override{
      _consol->ShowButtonClicked("Game","2");
      DrawFigure(0, 1);
    }
    void On3ButtonClick() override{
      _consol->ShowButtonClicked("Game","3");
      DrawFigure(0, 2);
    }
    void On4ButtonClick() override{
      _consol->ShowButtonClicked("Game","4");
      DrawFigure(1, 0);
    }
    void On5ButtonClick() override{
      _consol->ShowButtonClicked("Game","5");
      DrawFigure(1, 1);
    }
    void On6ButtonClick() override{
      _consol->ShowButtonClicked("Game","6");
      DrawFigure(1, 2);
    }
    void On7ButtonClick() override{
      _consol->ShowButtonClicked("Game","7");
      DrawFigure(2, 0);
    }
    void On8ButtonClick() override{
      _consol->ShowButtonClicked("Game","8");
      DrawFigure(2, 1);
    }
    void On9ButtonClick() override{
      _consol->ShowButtonClicked("Game","9");
      DrawFigure(2, 2);
    }
};

#endif