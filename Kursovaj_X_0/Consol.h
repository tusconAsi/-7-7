#ifndef CONSOL_H
#define CONSOL_H
#include "Settings.h"

class Consol{
  public:
    void Welcome(){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println("----------------------");
      Serial.println("Welcome to the game XO");
      Serial.println("----------------------");
    }
    void WriteLine(char *line){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println(line);
    }
    void Init(){
      if (IRDA_SERIAL_ENABLED == true){
        Serial.begin(IRDA_SERIAL_SPEED);
      }
    }
    void StartInitProcess(){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println("----------------------");
      Serial.println("Start Init Process");
    }
    void InitProcessFinished(){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println("Init Process Finished");
      Serial.println("----------------------");
    }
    void ScreenManagerInitialized(){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println("ScreenManager Initialized");
    }
    void IrDaInitialized(){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println("IrDa Initialized");
    }
    void ShowIrDaComand(uint16_t comand){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.print("IrDa Comand [");
      Serial.print(comand);
      Serial.println("] Resieved");
    }
    void ShowButtonClicked(char* senderId,char* buttonId){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.print("[");
      Serial.print(senderId);
      Serial.print("] Button [");
      Serial.print(buttonId);
      Serial.println("] Clicked");
    }
    void GameInitialized(){
      if (IRDA_SERIAL_ENABLED == false){
        return;
      }
      Serial.println("Game Initialized");
    }
};


#endif