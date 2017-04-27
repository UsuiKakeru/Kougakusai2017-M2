/**
 * @file Startert.cpp
 * @date 2015/07/15
 * @author motoki nagaoka
 *
 */
#include "Starter.h"

namespace contest{
    Starter* Starter::instance = 0;

    Starter::Starter(){
        touch = Touch::getInstance();
        display = Display::getInstance();

   }

    Starter* Starter::getInstance(){

       if ( ! instance ) {
           instance = new Starter();
        }
        return new Starter();
    }

void Starter::reset(){
    started = false;
    hasPressed = true;
}
    // スタートを受け付ける
bool Starter::start(){
    if  ( !touch->isPressed() )
        hasPressed = false;

    if ( !started && !hasPressed && touch->isPressed()){
        started = true;

        display-> updateDisplay("                            ",  0);
        display-> updateDisplay ("                            ", 1);
        display-> updateDisplay ("                            ", 2);
        display-> updateDisplay ("         S T A R T          ", 3);
    }
    else if ( !started ){
        display-> updateDisplay("                            ",  0);
        display-> updateDisplay ("                            ", 1);
        display-> updateDisplay ("                            ", 2);
        display-> updateDisplay ("         R E A D Y          ", 3);
    }
    return started;
}

}
