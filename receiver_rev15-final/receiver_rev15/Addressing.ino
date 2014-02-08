unsigned int Addressing() {
  //the switch states for the 1 and 0 pin 
  byte switch1 = digitalRead(SWITCH_PIN_1);
  byte switch0 = digitalRead(SWITCH_PIN_0);   
  
//Case 1: Neither switch is pressed.
if (switch0 == HIGH && switch1 == HIGH) {
   //read the previously stored value from EEPROM addresses 510 and 511.
  dmxaddress = EEPROM.read(511);   //read the high byte into dmxaddress
  dmxaddress = dmxaddress << 8;  
  //bitshift the high byte left 8 bits to make room for the low byte
  dmxaddress =  dmxaddress | EEPROM.read(510);   //read the low byte into dmxaddress
  //check for unitialized EEPROM
  if (dmxaddress > 511 || dmxaddress < 1) dmxaddress == 1; 
  }
  
//Case 2: Both switches are pressed, address is reset to 1.
else if (switch0 == LOW && switch1 == LOW)
  {
  dmxaddress = 1;
  newAddressWrite();
  }
    
//Case 3: One switch is pressed, but not the other.
else if (switch0 == 0 ^ switch1 == 0)
  {
  /* if EITHER switch0 or switch1 is held down (but not both), the addressing subroutine is
  *  run.  Since it writes the new address into EEPROM, there's no need to pass anything
  *  back to the main function. */
  digitalWrite(13, HIGH); //turn on pin 13 to indicate addressing mode
  //do nothing until the switch is released
  while (switch0 == LOW || switch1 == LOW) {
            switch0 = digitalRead(SWITCH_PIN_0);
            switch1 = digitalRead(SWITCH_PIN_1);
            }
          delay(50);
  
  byte bitnumber = 0; //the number of bits recorded so far
  //runs until all 9 bits have been recorded into the address.
  while (bitnumber < 9) {
    //first, make sure both switches are released before accepting new bit.
    if (switch0 == LOW || switch1 == LOW) {
          digitalWrite(13, LOW); //flash off pin 13 to indicate bit accepted
          //remain in the while loop while either switch is pressed, then delay half a second to avoid bounce and signal to the user that the bit has been accepted. 
          while (switch0 == LOW || switch1 == LOW) {
            switch0 = digitalRead(SWITCH_PIN_0);
            switch1 = digitalRead(SWITCH_PIN_1);
            }
          delay(500);
          }//end if
    
    //The switches have been released, now wait for the new bit.
    digitalWrite(13, HIGH); //turn on pin 13 to indicate ready for new bit.
    switch0 = digitalRead(SWITCH_PIN_0);
    switch1 = digitalRead(SWITCH_PIN_1);    
    if (switch1 == LOW) {//execute if 1 pin is pressed
        bitSet(dmxaddress, bitnumber);  //write a 1 to the appropriate bit of dmxaddress
        bitnumber++;
        }
    else if (switch0 == LOW) {//execute if 0 pin is pressed
        bitClear(dmxaddress, bitnumber);
        bitnumber++;
        }
    } //end while loop 
    //write the new address to EEPROM
    newAddressWrite();
}//end else if addressing subroutine
  
  
  
dmxaddress = dmxaddress + 3;
/*  this will allow the USART receive interrupt to fire an additional 3 times for every dmx frame.  
*   Here's why:
*   Once to account for the fact that DMX addresses run from 0-511, whereas channel numbers
*        start numbering at 1.
*   Once for the Mark After Break (MAB), which will be detected by the USART as a valid character 
*        (a zero, eight more zeros, followed by a one)
*   Once for the START code that precedes the 512 DMX values (used for RDM).  */

return dmxaddress;
}  //end Addressing()



void newAddressWrite() {
  EEPROM.write(510, lowByte(dmxaddress));//writes the first byte of dmxaddress to EEPROM address 510
  EEPROM.write(511, highByte(dmxaddress));//writes the second byte of dmxaddress to EEPROM address 511

  for (byte i = 0; i < 15; i++) { //blink LED 4 times when new address is received.
    digitalWrite(13, (i & 1));
    //i & 1 will bitwise-and to 1 if i is odd, 0 if even.
    delay(100);
    }
  
  }
