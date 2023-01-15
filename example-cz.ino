/* 
 * Copyright (c) Pájeníčko s.r.o. Všechna práva vyhrazena.
 *
 * Tento software je open-source a k dispozici pod licencí MIT.
 * Další informace naleznete v souboru "LICENSE" v kořenovém adresáři projektu.
 *
 * Pájeníčko s.r.o.
 * 
 * 
 * Tento kód slouží k ovládání relé pomocí 74HC595 převodníku logických úrovní.
 *  
 */

/* 
 * Proměnné latchPin, clockPin, dataPin a oePin jsou přiřazeny k jednotlivým pinům 74HC595. 
 */
int latchPin = 12;  // Latch pin 74HC595
int clockPin = 13; // Clock pin 74HC595 
int dataPin = 14;  // Data pin 74HC595
int oePin = 5;    // oePin pin 74HC595 (nepoužívá se)

/* 
 * Funkce setup() nastavuje všechny piny 74HC595 jako výstupní. 
 */
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(oePin, OUTPUT);

}

/* 
 *  Funkce setRelays(uint16_t data) slouží k nastavení stavu relé pomocí dat předaných v argumentu.
 */
void setRelays(uint16_t data)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, (data >> 8));
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

/* 
 * Funkce loop() zavolá funkci setRelays() s různými hodnotami binárních dat, 
 * což má za následek postupné zapínání a vypínání relé.
 */
void loop()
{
  /*
   * delay(100) a delay(10000) slouží k tomu, 
   * aby se stavy relé změnily pomalu a aby se zajistilo, že lze stavy relé vidět.
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
