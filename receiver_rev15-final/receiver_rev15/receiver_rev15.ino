/***********************************************************
* DMX-512 Reception                                        *
* Developed by Max Pierson                                 *
* Version Rev15 9 Oct 2010                                 *
* Released under the WTFPL license, although I would       *
* appreciate Attribution and Share-Alike                   *
* See blog.wingedvictorydesign.com for the latest version. *
************************************************************/



/******************************* Addressing variable declarations *****************************/

#include <EEPROM.h>
#define PIN_START 4
#define DEBUG_MODE false
#define NUMBER_OF_CHANNELS 5
//the number of channels we want to receive (8 by default).

#define SWITCH_PIN_0 7 //the pin number of our "0" switch
#define SWITCH_PIN_1 8 //the pin number of our "1" switch
unsigned int dmxaddress = 5;
/* The dmx address we will be listening to.  The value of this will be set in the Addressing()
*  function and read from EEPROM addresses 510 and 511.

/******************************* MAX485 variable declarations *****************************/

#define RECEIVER_OUTPUT_ENABLE 2
/* receiver output enable (pin2) on the max485.  
*  will be left low to set the max485 to receive data. */

#define DRIVER_OUTPUT_ENABLE 3
/* driver output enable (pin3) on the max485.  
*  will left low to disable driver output. */

#define RX_PIN 0   // serial receive pin, which takes the incoming data from the MAX485.
#define TX_PIN 1   // serial transmission pin

/********************************************************************/
#define PIN_ROUGE  11
#define PIN_VERT  10
#define PIN_BLEU  9
volatile byte dmx_rouge = 0;
volatile byte dmx_vert = 0;
volatile byte dmx_bleu = 0;
volatile byte dmx_dim_gnl = 0;
volatile byte dmx_strobe = 0;
volatile byte strobe_on_time = 50;
volatile byte tmp = 0;
/********************************************************************/



/******************************* DMX variable declarations ********************************/

volatile byte i = 0;              //dummy variable for dmxvalue[]
volatile byte dmxreceived = 0;    //the latest received value
volatile unsigned int dmxcurrent = 0;     //counter variable that is incremented every time we receive a value.
volatile byte dmxvalue[NUMBER_OF_CHANNELS];     
/*  stores the DMX values we're interested in using-- 
 *  keep in mind that this is 0-indexed. */
volatile boolean dmxnewvalue = false; 
/*  set to 1 when updated dmx values are received 
 *  (even if they are the same values as the last time). */

/******************************* Timer2 variable declarations *****************************/

volatile byte zerocounter = 0;          
/* a counter to hold the number of zeros received in sequence on the serial receive pin.  
*  When we've received a minimum of 11 zeros in a row, we must be in a break.  */




void setup() {
  dmxaddress +=3; // JE SAIS PAS POURQUOI IL Y A UN DECALLAGE ... EN ATTENDANT MIEUX... ON FERA AVEC ...!
  /******************************* Max485 configuration ***********************************/
  pinMode(PIN_START, INPUT);
  pinMode(13, OUTPUT);

  pinMode(PIN_ROUGE, OUTPUT);
  pinMode(PIN_VERT,OUTPUT);
  pinMode(PIN_BLEU,OUTPUT);
  
  
  //pinMode(RECEIVER_OUTPUT_ENABLE, OUTPUT);
  //pinMode(DRIVER_OUTPUT_ENABLE, OUTPUT);
  //digitalWrite(RECEIVER_OUTPUT_ENABLE, LOW);
  //digitalWrite(DRIVER_OUTPUT_ENABLE, LOW);    //sets pins 3 and 4 to low to enable reciever mode on the MAX485.

  pinMode(RX_PIN, INPUT);  //sets serial pin to receive data

  /******************************* Addressing subroutine *********************************/

  pinMode(SWITCH_PIN_0, INPUT);           //sets pin for '0' switch to input
  digitalWrite(SWITCH_PIN_0, HIGH);       //turns on the internal pull-up resistor for '0' switch pin
  pinMode(SWITCH_PIN_1, INPUT);           //sets pin for '1' switch to input  
  digitalWrite(SWITCH_PIN_1, HIGH);       //turns on the internal pull-up resistor for '1' switch pin
  
  /* Call the addressing subroutine.  Three behaviors are possible:
  *  1. Neither switch is pressed, in which case the value previously stored in EEPROM
  *  510 and 511 is recalled,
  *  2. Both switches are pressed, in which case the address is reset to 1.
  *  3. Either switch is pressed (but not both), in which case the new address may 
  *  be entered by the user.
  */
  //set this equal to a constant value if you just want to hardcode the address.
  //dmxaddress = Addressing();
  
  /******************************* USART configuration ************************************/
  
  Serial.begin(250000);
  /* Each bit is 4uS long, hence 250Kbps baud rate */
  
  cli(); //disable interrupts while we're setting bits in registers
  
  bitClear(UCSR0B, RXCIE0);  //disable USART reception interrupt
  
  /******************************* Timer2 configuration ***********************************/
  
  //NOTE:  this will disable PWM on pins 3 and 11.
  bitClear(TCCR2A, COM2A1);
  bitClear(TCCR2A, COM2A0); //disable compare match output A mode
  bitClear(TCCR2A, COM2B1);
  bitClear(TCCR2A, COM2B0); //disable compare match output B mode
  bitSet(TCCR2A, WGM21);
  bitClear(TCCR2A, WGM20);  //set mode 2, CTC.  TOP will be set by OCRA.
  
  bitClear(TCCR2B, FOC2A);
  bitClear(TCCR2B, FOC2B);  //disable Force Output Compare A and B.
  bitClear(TCCR2B, WGM22);  //set mode 2, CTC.  TOP will be set by OCRA.
  bitClear(TCCR2B, CS22);
  bitClear(TCCR2B, CS21);
  bitSet(TCCR2B, CS20);   // no prescaler means the clock will increment every 62.5ns (assuming 16Mhz clock speed).
  
  OCR2A = 64;                
  /* Set output compare register to 64, so that the Output Compare Interrupt will fire
  *  every 4uS.  */
  
  bitClear(TIMSK2, OCIE2B);  //Disable Timer/Counter2 Output Compare Match B Interrupt
  bitSet(TIMSK2, OCIE2A);    //Enable Timer/Counter2 Output Compare Match A Interrupt
  bitClear(TIMSK2, TOIE2);   //Disable Timer/Counter2 Overflow Interrupt Enable          
  
  sei();                     //reenable interrupts now that timer2 has been configured. 

}  //end setup()


void loop()  {
  // the processor gets parked here while the ISRs are doing their thing. 
  if (DEBUG_MODE && digitalRead(PIN_START))
  {
    Serial.end();
    Serial.begin(9600);
    delay(200);
    Serial.println(dmx_rouge);
    Serial.println(dmx_vert);
    Serial.println(dmx_bleu);
    Serial.println(dmx_dim_gnl);
    Serial.println(dmx_strobe);
    tmp = dmx_bleu * dmx_dim_gnl / 255;
    Serial.print("tmpB :");
    Serial.println(tmp);
    tmp = dmx_rouge * dmx_dim_gnl / 255;
    Serial.print("tmpR :");
    Serial.println(tmp);
    tmp = dmx_vert * dmx_dim_gnl / 255;
    Serial.print("tmpG :");
    Serial.println(tmp);
    Serial.end();
    Serial.begin(250000);

 }
  
  if (dmxnewvalue == 1) {    //when a new set of values are received, jump to action loop...
    action();
    dmxnewvalue = 0;
    dmxcurrent = 0;
    zerocounter = 0;      //and then when finished reset variables and enable timer2 interrupt
    i = 0;
    bitSet(TIMSK2, OCIE2A);    //Enable Timer/Counter2 Output Compare Match A Interrupt
  }
} //end loop()


//Timer2 compare match interrupt vector handler
ISR(TIMER2_COMPA_vect) {
  if (bitRead(PIND, PIND0)) {  // if a one is detected, we're not in a break, reset zerocounter.
    zerocounter = 0;
    }
  else {
    zerocounter++;             // increment zerocounter if a zero is received.
    if (zerocounter == 23)     // if 20 0's are received in a row (80uS break)
      {   
      bitClear(TIMSK2, OCIE2A);    //disable this interrupt and enable reception interrupt now that we're in a break.
      bitSet(UCSR0B, RXCIE0);
      }
  }
} //end Timer2 ISR



ISR(USART_RX_vect){
  dmxreceived = UDR0;
  /* The receive buffer (UDR0) must be read during the reception ISR, or the ISR will just 
  *  execute again immediately upon exiting. */
 
  dmxcurrent++;                        //increment address counter
 
  if(dmxcurrent > dmxaddress) {         //check if the current address is the one we want.
    dmxvalue[i] = dmxreceived;
    i++;
    if(i == NUMBER_OF_CHANNELS) {
      bitClear(UCSR0B, RXCIE0); 
      dmxnewvalue = 1;                        //set newvalue, so that the main code can be executed.
    } 
  }
} // end ISR
