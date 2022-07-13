 //Base code used as library for DHT11 from http://www.electronicwings.com
 //Non-comercial use
 //Modified and extended by Katarzyna Pióro
 #include "dht11.h"

 void Request()				/* Microcontroller send start pulse/request */
 {
	 DDRD |= (1<<DHT11_PIN);
	 PORTD &= ~(1<<DHT11_PIN);	/* set to low pin */
	 _delay_ms(20);			/* wait for 20ms */
	 PORTD |= (1<<DHT11_PIN);	/* set to high pin */
 }

 void Response()				/* receive response from DHT11 */
 {
	 DDRD &= ~(1<<DHT11_PIN);
	 while(PIND & (1<<DHT11_PIN));
	 while((PIND & (1<<DHT11_PIN))==0);
	 while(PIND & (1<<DHT11_PIN));
 }

 uint8_t Receive_data8bit()			/* receive data */
 {
	 for (int q=0; q<8; q++)
	 {
		 while((PIND & (1<<DHT11_PIN)) == 0);  /* check received bit 0 or 1 */
		 _delay_us(30);
		 if(PIND & (1<<DHT11_PIN))/* if high pulse is greater than 30ms */
			c = (c<<1)|(0x01);	/* then its logic HIGH */
		 else			/* otherwise its logic LOW */
			c = (c<<1);
		 while(PIND & (1<<DHT11_PIN));
	 }
	 return c;
 }

 /* Modified and extended code */
void Print_Measurements()
 {
	 Request();		/* send start pulse */
	 Response();		/* receive response */
	 I_RH=Receive_data8bit();	/* store first eight bit in I_RH */
	 D_RH=Receive_data8bit();	/* store next eight bit in D_RH */
	 I_Temp=Receive_data8bit();	/* store next eight bit in I_Temp */
	 D_Temp=Receive_data8bit();	/* store next eight bit in D_Temp */
	 CheckSum=Receive_data8bit();/* store next eight bit in CheckSum */
	 
	 char data1[5];
	 char data2[5];
	 
	 
	 if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
	 {
		 LCD_GoTo(0,0);
		 LCD_WriteText("Error");
	 }
	 
	 else
	 {
		 
		 //Wypisywanie pomiarow na ekranie
		 //Wilgotnosc
		 itoa(I_RH,data1,10);
		 itoa(D_RH,data2,10);
		 LCD_GoTo(11,0);
		 LCD_WriteText(data1); // Procent
		 LCD_WriteText(".");
		 LCD_WriteText(data2);
		 LCD_WriteText("%");

		 //Temperatura
		 itoa(I_Temp,data1,10);
		 itoa(D_Temp,data2,10);
		 LCD_GoTo(6,1);
		 LCD_WriteText(data1); // Stopnie Celsjusza
		 LCD_WriteText(".");
		 LCD_WriteText(data2);
		 LCD_WriteText(" st.C");
	 }
 }