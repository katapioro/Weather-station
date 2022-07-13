
// Systemy mikroprocesorowe 1, AGH, Elektronika rok 2
// Projekt: Stacja pogodowa
// Odczyt temperatury i wilgotnoœci
// Wykonanie: £ukasz Piasecki, Katarzyna Pióro
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>

/* Biblioteki */
#include "hd44780.c"
#include "dht11.c"

/* Kod g³ówny */

int main(void)
{
	// Inicjalizacja LCD
	LCD_Initalize();
	LCD_Clear();
	LCD_Home();
	LCD_WriteText("Wilgotnosc =");
	LCD_GoTo(0,1);
	LCD_WriteText("Temp = ");
	
	
	while(1)
	{
		Print_Measurements();

		//OpóŸnienie 500ms
		_delay_ms(500);
	}
	
}
