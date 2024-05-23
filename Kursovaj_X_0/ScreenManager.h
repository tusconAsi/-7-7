#ifndef ScreenManager_h
#define ScreenManager_h

#include "IrDaButtonsCallback.h"
#include "Screen.h"
#include "Consol.h"
#include "Game.h"

class ScreenManager : public IrDaButtonsCallback{
  private:
    Screen* _screen = nullptr;
    Consol* _consol = nullptr;//ссылка которая является ничем,или нулем среди ссылок.
    Game* _game = nullptr;
  public: 
    ScreenManager(Consol* consol){
      _consol = consol;
      _screen = new Screen();
      _game = new Game(consol, _screen);
    }
    void Init(){
      _screen->InitScreen();
      OnChPButtonClick();
      _consol->ScreenManagerInitialized();
    }

    void OnChButtonClick() override{
      _consol->ShowButtonClicked("ScreenManager","Ch");
      _screen->ClearScreen();
      _screen->ShowCheckScreen();
    }
    void OnChPButtonClick() override{
      _consol->ShowButtonClicked("ScreenManager","Ch+");
      delete _game;
      _game = new Game(_consol, _screen);
      _game->Init();
    }
    void OnChMButtonClick() override{
      _consol->ShowButtonClicked("ScreenManager","Ch-");
      _screen->ClearScreen();
      _screen->DrawO(20, 20, 20, 20);
      _screen->DrawX(100, 100, 30, 30);
    }
    void On1ButtonClick() override{
      _game->On1ButtonClick();
    }
    void On2ButtonClick() override{
      _game->On2ButtonClick();
    }
    void On3ButtonClick() override{
      _game->On3ButtonClick();
    }
    void On4ButtonClick() override{
      _game->On4ButtonClick();
    }
    void On5ButtonClick() override{
      _game->On5ButtonClick();
    }
    void On6ButtonClick() override{
      _game->On6ButtonClick();
    }
    void On7ButtonClick() override{
      _game->On7ButtonClick();
    }
    void On8ButtonClick() override{
      _game->On8ButtonClick();
    }
    void On9ButtonClick() override{
      _game->On9ButtonClick();
    }
};


#endif