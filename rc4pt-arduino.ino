/*
 * Remote Controller for PopcornTime using Arduino with IR remote receiver.
*/
 
#include <IRremote.h>

#define ON_OFF 16753245
#define VOL_UP 16736925
#define FUNC_STOP 16769565
#define PREVIOUS 16720605
#define PLAY_PAUSE 16712445
#define NEXT 16761405
#define DOWN 16769055
#define VOL_DOWN 16754775
#define UP 16748655
#define BTN_0 16738455
#define EQ 16750695
#define ST_REPT 16756815
#define BTN_1 16724175
#define BTN_2 16718055
#define BTN_3 16743045
#define BTN_4 16716015
#define BTN_5 16726215
#define BTN_6 16734885
#define BTN_7 16728765
#define BTN_8 16730805
#define BTN_9 16732845
 
int IR_Recv = 3;   //IR Receiver Pin 3
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    //switch case to use the selected remote control button
    switch (results.value){
      case ON_OFF:
        Serial.println("rc4pt:on-off");
        break;
        
      case VOL_UP:
        Serial.println("rc4pt:volume-up");
        break;
        
      case VOL_DOWN:
        Serial.println("rc4pt:volume-down");
        break;
        
      case PLAY_PAUSE:
        Serial.println("rc4pt:toggleplaying");
        break;
      
      case FUNC_STOP:
        Serial.println("rc4pt:togglefullscreen");
        break;
        
      case PREVIOUS:
        Serial.println("rc4pt:previous");
        break;
      
      case NEXT:
        Serial.println("rc4pt:next");
        break;
      
      case BTN_2:
        Serial.println("rc4pt:up");
        break;
        
      case BTN_8:
        Serial.println("rc4pt:down");
        break;
        
      case BTN_4:
        Serial.println("rc4pt:left");
        break;
        
      case BTN_6:
        Serial.println("rc4pt:right");
        break;
        
      case BTN_5:
        Serial.println("rc4pt:enter");
        break;
        
      case BTN_0:
        Serial.println("rc4pt:showfavourites");
        break;
        
      case DOWN:
        Serial.println("rc4pt:previous-tab");
        break;
        
      case UP:
        Serial.println("rc4pt:next-tab");
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
}
