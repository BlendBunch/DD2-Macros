#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

/*
	The goal of this program is to show a terminal screen that has all the options needed for dd2 macros like auto ready and also options for your alt, and being able to click on the boxes to turn them on, and have a visual cue to show that something is on or off
*/

// TO-DO
//
//redo the textbounds function to instead return an array of coords

HANDLE consoleIn;
HANDLE consoleOut;
CONSOLE_SCREEN_BUFFER_INFO terminalInfo;

typedef struct{
	COORD leftBound;
	COORD rightBound;
}textBoundingBox;

void autoMana(){

}

void autoReady(){

}

void grabLoot(){

}

void getTextBounds(textBoundingBox box, char* text){
	GetConsoleScreenBufferInfo(consoleOut, &terminalInfo);
	box.leftBound = terminalInfo.dwCursorPosition;
	printf("%s", text);
	GetConsoleScreenBufferInfo(consoleOut, &terminalInfo);
	box.rightBound = terminalInfo.dwCursorPosition;
}

bool textBoundCheck(COORD mousePos, COORD textBound[]){

}

void *checkForClick( void *arg )
{
	for (;;)
	{
		INPUT_RECORD irInBuf[128];
		DWORD cNumRead;
		// read up to 128 events
		if ( ! ReadConsoleInput( consoleIn, irInBuf, 128, &cNumRead ) )
		{
			fprintf( stderr,  "Error in function ReadConsoleInput!\n" );
			ExitProcess( 0 );
		}

		// process one event per loop iteration
		for ( DWORD i = 0; i < cNumRead; i++ )
		{
			printf("processing event: %lu\n", irInBuf[i].EventType);
			if ( irInBuf[i].EventType == MOUSE_EVENT )
			{
				printf("Got mouse event\n");
				MOUSE_EVENT_RECORD *pme = &irInBuf[i].Event.MouseEvent;

				switch ( pme->dwEventFlags )
				{
					case 0:
						if ( pme->dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED )
						{
							printf( "Left pressed\n" );
							fflush( stdout );
						}
				}
			}
		}
	}
}

int main(){
	//basic setup with variables and such
	consoleIn = GetStdHandle(STD_INPUT_HANDLE);
	consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD fdwMode = (ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE;
	if((SetConsoleMode(consoleIn, fdwMode)) == 0){
		printf("Console set failed\n");
	}

	//print the basic screen & get button coords




	//clear screen
	system("cls");

	//move to main account title pos
	printf("\n\n\n\t\t");

	//print the title
	printf("\033[1;4mToggles for Main Account\033[0m");

	//move to alt account title pos
	printf("\t\t\t\t\t");

	//print the title
	printf("\033[1;4mToggles for Alt. Account\033[0m");


	//move the auto ready button
	printf("\n\n\n\n\t\t\t");

	//get the auto ready button pos & print the button
	textBoundingBox autoReadyBox;
	getTextBounds(autoReadyBox, "Auto Ready");

	//move to the alt auto ready button
	printf("\t\t\t\t\t\t\t");

	//get the alt auto ready button pos & print the button
	textBoundingBox altAutoReadyBox;
	getTextBounds(altAutoReadyBox, "Auto Ready");


	//move to the mana button
	printf("\n\n\n\n\t\t\t");

	//get the mana button pos & print the button
	textBoundingBox autoManaBox;
	getTextBounds(autoManaBox, "Auto Mana");
	
	//move to alt mana button
	printf("\t\t\t\t\t\t\t ");

	//get the alt mana button pos & print the button
	textBoundingBox altAutoManaBox;
	getTextBounds(altAutoManaBox, "AutoMana");


	//move to the grab loot button
	printf("\n\n\n\n\t\t      ");

	//get the grab loot button pos & print the button
	textBoundingBox autoLootBox;
	getTextBounds(autoLootBox, "Auto Grab Loot");

	//move to the alt grab loot button
	printf("\t\t\t\t\t\t       ");

	//get the alt grab loot button pos & print the button
	textBoundingBox altAutoLootBox;
	getTextBounds(altAutoLootBox, "AutoGrabLoot");








	//check if the user clicks, and is focused on the terminal, then call the corresponding function and update the screen




	//find, & check user mouse pos with button bounds
	pthread_t thread1;
	pthread_create(&thread1, NULL, checkForClick, NULL);
	pthread_join(thread1, NULL);
	









	return 0;
}
