#include <gb.h>

void PrinterInit(void);
void PrinterCommand(char *PrinterCmd);
int PrinterGetStatus();
int PrinterErrorCheck();
void PrintTile(char *Tile);
int PrinterDetect();
void SendByte(char byte);