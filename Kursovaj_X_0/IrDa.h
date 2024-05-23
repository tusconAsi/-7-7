#ifndef IrDa_h
#define IrDa_h

#include <IRremote.h>
#include "IrDaButtons_Mi.h"
#include "Settings.h"
#include "IrDaButtonsCallback.h"
#include "Consol.h"

class IrDa{
  private:
    IRrecv _irda = IRrecv(irda_pin);
    bool _isSerialEnabled = IRDA_SERIAL_ENABLED;
    Consol* _consol = nullptr;
    ScreenManager* _screenManager = nullptr;
  public:
    IrDa(ScreenManager* screenManager, Consol* consol){
      _consol = consol;
      _screenManager = screenManager;
    }
    void Init(){
      _irda.enableIRIn();  
      pinMode(irda_pin, INPUT);
      _consol->IrDaInitialized(); 
    }
    void ShowResievedSignal(){
      if (_isSerialEnabled == false){
        return;
      }
     if (_irda.decode()) {
        _irda.resume();
        _consol->ShowIrDaComand(_irda.decodedIRData.command);
      }
    }
    void ProccesSignal(){
      if (_irda.decode()){
        _irda.resume();
        _consol->ShowIrDaComand(_irda.decodedIRData.command);
        switch (_irda.decodedIRData.command){
          case IRDA_CH_BUTTON:
            _screenManager->OnChButtonClick();
            break;
          case IRDA_CH_P_BUTTON:
            _screenManager->OnChPButtonClick();
            break;
          case IRDA_CH_M_BUTTON:
            _screenManager->OnChMButtonClick();
            break;
          case IRDA_0_BUTTON:
            _screenManager->On0ButtonClick();
            break;
          case IRDA_1_BUTTON:
            _screenManager->On1ButtonClick();
            break;
          case IRDA_2_BUTTON:
            _screenManager->On2ButtonClick();
            break;
          case IRDA_3_BUTTON:
            _screenManager->On3ButtonClick();
            break;
          case IRDA_4_BUTTON:
            _screenManager->On4ButtonClick();
            break;
          case IRDA_5_BUTTON:
            _screenManager->On5ButtonClick();
            break;
          case IRDA_6_BUTTON:
            _screenManager->On6ButtonClick();
            break;
          case IRDA_7_BUTTON:
            _screenManager->On7ButtonClick();
            break;
          case IRDA_8_BUTTON:
            _screenManager->On8ButtonClick();
            break;
          case IRDA_9_BUTTON:
            _screenManager->On9ButtonClick();
            break;
        }
      }
    }
};

#endif
