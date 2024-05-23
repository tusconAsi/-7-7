#ifndef IrDaButtonsCallback_h
/*директива компилятора - означает скомпилировать если макро(название IrDaButtonsCallback_h)
(название заменяемого куска кода)не определена или не существует!!!*/
#define IrDaButtonsCallback_h
//директива компилятора - определить или создать макро(IrDaButtonsCallback_h)

class IrDaButtonsCallback {
  public:
    virtual void OnChButtonClick() {}
    virtual void OnChPButtonClick(){}
    virtual void OnChMButtonClick(){}
    virtual void On0ButtonClick(){}
    virtual void On1ButtonClick(){}
    virtual void On2ButtonClick(){}
    virtual void On3ButtonClick(){}
    virtual void On4ButtonClick(){}
    virtual void On5ButtonClick(){}
    virtual void On6ButtonClick(){}
    virtual void On7ButtonClick(){}
    virtual void On8ButtonClick(){}
    virtual void On9ButtonClick(){}
};

#endif
//директива компилятора означает конец блока #ifndef


