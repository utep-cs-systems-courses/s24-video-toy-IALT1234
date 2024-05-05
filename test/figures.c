#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define SCREEN_CENTER_X (screenWidth / 2)
#define SCREEN_CENTER_Y (screenHeight / 2)
#define SQUARE_SIZE 20
#define BG_COLOR COLOR_BLACK
#define SQUARE_COLOR COLOR_YELLOW

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

#define A 2272
#define E 3024
#define E4 1516
#define D 1702
#define G 2551
#define B 2028
#define F 2863
#define C3 3816
#define PAUSE 0

#define BUTTON1 BIT0
#define BUTTON2 BIT2

void button_init() {
  P2DIR &= ~(BUTTON1 | BUTTON2);
  P2REN |= (BUTTON1 | BUTTON2);
  P2OUT |= (BUTTON1 | BUTTON2);
}

int button_down() {
  return !(P2IN & BUTTON1); // Return true if button is pressed (P2.2 is low)
}
int button2_down() {
  return !(P2IN & BUTTON2); // Return true if button 2 (P2.1) is pressed
}
void draw_square(int x, int y, unsigned int color) {
  fillRectangle(40,40, SQUARE_SIZE, SQUARE_SIZE, color);
}

void play_note(int note){
  buzzer_set_period(note); __delay_cycles(2000000);//IN
  buzzer_set_period(PAUSE); __delay_cycles(2000000);
  
}
void play_verse(){
  int notes[] = {B,PAUSE, C3, D, PAUSE,PAUSE,PAUSE, B,A,PAUSE,B,G,PAUSE,PAUSE,PAUSE,B,PAUSE,B,A,PAUSE,G,E,PAUSE,PAUSE,E,B,PAUSE,B,A};
  int size = sizeof(notes) / sizeof(notes[0]);  
  for (int i = 0; i < size; i++) {
    play_note(notes[i]);
  }

}
void main() {
  
  configureClocks();
  lcd_init();
  clearScreen(BG_COLOR);
  buzzer_init();
  button_init();

  while (1) {
    if (button_down()) {

 
     
      fillRectangle(0,20,screenWidth,screenHeight-20, COLOR_BLUE);
      fillRectangle(0,0,screenWidth,50, COLOR_SKY_BLUE);
      fillRectangle(30,60, 80,40, COLOR_YELLOW);
      fillRectangle(90,60, 20,20, COLOR_NAVY);
      fillRectangle(SCREEN_CENTER_X,40, 5,20, COLOR_BLACK);
      fillRectangle(SCREEN_CENTER_X,40, 20,5, COLOR_BLACK);
      fillRectangle(18,83, 12,2, COLOR_GRAY);
      fillRectangle(16,77, 2,6, COLOR_GRAY);
      fillRectangle(16,85, 2,6, COLOR_GRAY);
            
      // play_verse();
    }
  }
}
