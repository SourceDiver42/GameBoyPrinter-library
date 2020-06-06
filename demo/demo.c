#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>

#include "data/Tiles.c"


void clearScreen();
void printAll();
void moveCursorToTile(UINT8 x, UINT8 y);
void initPrinter();
void checkInput();


UINT8 cursorX;
UINT8 cursorY;


void main() {

    //Initialisation
    cursorX = 0;
    cursorY = 0;

    
    //Initialize Cursor Sprite
    set_sprite_data(0, 3, Tiles);
    set_sprite_tile(0, 2);
    

    HIDE_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;


    //Game loop
    while(1) {
        checkInput();
        moveCursorToTile(cursorX, cursorY);


        wait_vbl_done();
    }
}

void checkInput() {
    switch(joypad()) {
        case J_SELECT:
            printAll();
            SHOW_SPRITES;
            break;

        case J_START:
            clearScreen(); //Resets the screen
            cursorX = 0;
            cursorY = 0;
            break;

        case J_DOWN:
            if (cursorY < 17) { //18 tiles, 0 - 17
                cursorY++;
            }

            delay(100);
            break;

        case J_UP:
            if (cursorY > 0) {
                cursorY--;
            }

            delay(100);
            break;

        case J_LEFT:
            if (cursorX > 0) {
                cursorX--;
            }

            delay(100);
            break;

        case J_RIGHT:
            if (cursorX < 19){ //20 tiles, 0 - 19
                cursorX++;
            }

            delay(100);
            break;

        case J_A:
            box(cursorX * 8, cursorY * 8, cursorX * 8 + 7, cursorY * 8 + 7, 1); //The last parameter should fill the box. Sadly it does not work.

            delay(100);
            break;
    }
}

void clearScreen() {
    UINT8 x, y;
    for(y = 0; y < 18; y++){
        for(x = 0; x < 20; x++){
            gotogxy(x, y);
            wrtchr(' ');
        }
    }
}

void printAll() {
    
    HIDE_SPRITES; //Hide cursor
    //print everything
}

//Move the cursor by x y tiles on the 20x18 grid
void moveCursorToTile(UINT8 x, UINT8 y) {
    move_sprite(0, (x + 1) * 8, (y + 2) * 8); //multiplication by 8, as each tile is 8x8 pixels
}

//Initialize the printer
void initPrinter() {

}
