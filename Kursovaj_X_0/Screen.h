#ifndef screen_h
#define screen_h

#include <TFT.h>
#include "settings.h"

class Screen{
  private:
    TFT _screen = TFT (cs_pin, dc_pin, rst_pin);
    int _screenWidth = _screen.width();
    int _screenHeight = _screen.height();  
    int _screenCenterX = _screenWidth / 2;
    int _screenCenterY = _screenHeight / 2;
  public:
    Screen(){}
    void InitScreen (){
      _screen.begin();
      _screen.background(BACKGROUND_COLOR); 
      _screen.setTextSize(2); 
      _screen.fill(DEFAULT_FILL_COLOR);
      _screen.stroke(DEFAULT_STROKE_COLOR);
    }
    int GetScreenWidth(){
      return _screenWidth;
    }
    int GetScreenHeight(){
      return _screenHeight;
    }
    void ShowCheckScreen(){
      //Serial.println("ShowCheckScreen3");
      _screen.fill(CHECK_SCREEN_COLOR);
      _screen.rect (_screenCenterX - 10, _screenCenterY - 10, 20, 20);
      _screen.rect (0, 0, 20, 20);
      _screen.rect (_screenWidth - 20, _screenHeight - 20, 20, 20);
      _screen.rect (0, _screenHeight - 20, 20, 20);
      _screen.rect (_screenWidth - 20, 0, 20, 20);
    }
    void DrawX(int x, int y, int width, int height){
      int left = x;
      int top = y;
      int right = x + width;
      int bottom = y + height;
      float borderCofficient = 1 - FIGURE_COEFFICIENT;
      int borderX = width * borderCofficient;
      int borderY = height * borderCofficient;
      int innerLeft = left + borderX;
      int innerTop = top + borderY;
      int innerRight = right - borderX;
      int innerBottom = bottom - borderY;
      _screen.stroke(X_COLOR);
      _screen.line(innerRight, innerBottom, innerLeft, innerTop);
      _screen.line(innerRight, innerTop, innerLeft, innerBottom);
      for(int counter = 1; counter <= X_WIDTH; counter++){
        _screen.line(innerRight - counter, innerBottom, innerLeft, innerTop + counter);
        _screen.line(innerRight, innerBottom - counter, innerLeft + counter, innerTop);
        _screen.line(innerRight - counter, innerTop, innerLeft, innerBottom - counter);
        _screen.line(innerRight, innerTop + counter, innerLeft + counter, innerBottom);
      }
    }
    void DrawO(int x, int y, int width, int height){
      int centerX = (width / 2) + x;
      int centerY = (height / 2) + y;
      int outerRadius = width > height ? height / 2 : width / 2;
      outerRadius = outerRadius * FIGURE_COEFFICIENT;
      //int innerRadius = outerRadius * (1 - O_WIDTH_COEFFICIENT);
      _screen.noFill();//_screen.fill(O_COLOR);
      _screen.stroke(O_COLOR);
      //_screen.circle(int16_t centerX, int16_t centerY, int16_t outerRadius);
      _screen.circle( centerX, centerY, outerRadius);
      for(int counter = 1; counter <= O_WIDTH; counter++){
        _screen.circle(centerX, centerY, outerRadius - counter);
      }
      //_screen.fill(BACKGROUND_COLOR);
      //_screen.circle( centerX, centerY, innerRadius);
    }
    void DrawField(){
      int cellSizeY = _screenHeight / FIELD_ROWS_COUNT;
      int cellSizeX = _screenWidth / FIELD_COLUMS_COUNT;
      _screen.stroke(FIELD_COLOR);

      for(int counter = 0; counter <= FIELD_ROWS_COUNT; counter++){
        int y = cellSizeY * counter;
        _screen.line(0, y, _screenWidth, y);
        for(int deltaCounter = 1; deltaCounter <= FIELD_LINES_WIDTH; deltaCounter++){
          _screen.line(0, y + deltaCounter, _screenWidth, y + deltaCounter);
          _screen.line(0, y - deltaCounter, _screenWidth, y - deltaCounter);

        }
      }
      for(int counter = 0; counter <= FIELD_COLUMS_COUNT; counter++){
        int x = cellSizeX * counter;
        _screen.line(x, 0, x, _screenHeight);
        for(int deltaCounter = 1; deltaCounter <= FIELD_LINES_WIDTH; deltaCounter++){
          _screen.line(x + deltaCounter, 0, x + deltaCounter, _screenHeight);
          _screen.line(x - deltaCounter, 0, x - deltaCounter, _screenHeight);
        }
      }
    }
    void ClearScreen(){
      _screen.background(BACKGROUND_COLOR);
    }
};

#endif
