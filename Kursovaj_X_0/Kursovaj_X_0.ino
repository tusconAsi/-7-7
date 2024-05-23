#include <TFT.h>
#include <SPI.h>
#include "Pins.h"
#include "ScreenManager.h"
#include "IrDa.h"
#include "Consol.h"

//IrDaButtonsCallback zz = IrDaButtonsCallback();

Consol* consol = new Consol();
ScreenManager* screenManager = new ScreenManager(consol);
IrDa* irda = new IrDa(screenManager, consol);
 //Screen _screen = Screen();

void setup() {
  consol->Init();
  consol->Welcome();
  consol->StartInitProcess();
  screenManager->Init();
  irda->Init(); 
 // _screen.InitScreen();
  //delay(1000);
  //_screen.ClearScreen();
  //_screen.ShowCheckScreen();
  //irda.Init();
  //screenManager.OnChButtonClick();
  /*screen.InitScreen();
  screen.ShowCheckScreen();
  screen.DrawO(20, 20, 20, 20);
  screen.DrawX(100, 100, 30, 30);
  screen.DrawField();
*/
  delay(INITIALIZE_DELAY);
  consol->InitProcessFinished();
}

void loop() { 
  if(IRDA_SHOW_SIGNAL_ONLY){
    irda->ShowResievedSignal();
  } else {
    irda->ProccesSignal();
  }
  delay(LOOP_DELAY);
}