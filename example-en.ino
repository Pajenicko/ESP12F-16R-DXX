/* 
 * Copyright (c) Pájeníčko s.r.o. All rights reserved.
 *
 * This software is open-source and available under the MIT license.
 * More information can be found in the "LICENSE" file in the root directory of the project.
 *
 * Pájeníčko s.r.o.
 * 
 * 
 * This code is used to control relay using 74HC595 level converter.
 *  
 */

/* 
 * Variables latchPin, clockPin, dataPin and oePin are assigned to individual pins of 74HC595. 
 */
int latchPin = 12;  // Latch pin of 74HC595
int clockPin = 13; // Clock pin of 74HC595 
int dataPin = 14;  // Data pin of 74HC595
int oePin = 5;    // oePin pin of 74HC595 (not used)

/* 
 * The setup() function sets all 74HC595 pins as outputs. 
 */
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(oePin, OUTPUT);

}

/* 
 * The setRelays(uint16_t data) function is used to set the state of the relay using data passed in the argument.
 */
void setRelays(uint16_t data)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, (data >> 8));
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

/* 
 * The loop() function calls the setRelays() function with different binary data values, 
 * which results in the gradual turning on and off of the relay.
 */
void loop()
{
  /*
   * delay(100) and delay(10000) are used to change the relay state slowly and to ensure that the relay state can be seen.
   */
  
  setRelays(0b0000000000000001);
  delay(100);
  setRelays(0b0000000000000011);
  delay(100);
  setRelays(0b0000000000000111);
  delay(100);
  setRelays(0b0000000000001111);
  delay(100);
  setRelays(0b0000000000011111);
  delay(100);
  setRelays(0b0000000000111111);
  delay(100);
  setRelays(0b0000000001111111);
  delay(100);
  setRelays(0b0000000011111111);
  delay(100);
  setRelays(0b0000000111111111);
  delay(100);
  setRelays(0b0000001111111111);
  delay(100);
  setRelays(0b0000011111111111);
  delay(100);
  setRelays(0b0000111111111111);
  delay(100);
  setRelays(0b0001111111111111);
  delay(100);
  setRelays(0b0011111111111111);
  delay(100);
  setRelays(0b0111111111111111);
  delay(100);
  setRelays(0b1111111111111111);
  delay(100);
  setRelays(0b0000000000000000);
  delay(10000);
}
