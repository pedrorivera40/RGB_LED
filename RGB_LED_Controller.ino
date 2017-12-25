/**
 * This program turns on each of the seven colors of an RGB 
 * LED in periods of 1 second each.
 * It uses a function which maps a byte to a color as follows:
 *  1 -> RED
 *  2 -> GREEN
 *  3 -> YELLOW
 *  4 -> BLUE
 *  5 -> PURPLE
 *  6 -> LIGHT BLUE
 *  7 -> WHITE
 * @author Pedro Luis Rivera
 */

#define RED 9
#define GREEN 10
#define BLUE 11
#define COLORS 7
#define DEF_DELAY 1000

int colors[COLORS] {1, 2, 3, 4, 5, 6, 7};

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600); // Initialize Serial Communitation.
}

void loop() {
  displayColors();
}

void displayColors(){
  for(byte i = 0; i < COLORS; i++){
    turnColor(colors[i]);
    delay(DEF_DELAY);
  }
}

void turnColor(byte color){
  if(color < 0 || color > 7){
    Serial.println("ERROR - color index must be in the following range: [0, 7].");
    return;
  }
  turnOffColors();
  byte r = bitRead(color, 0);
  byte g = bitRead(color, 1);
  byte b = bitRead(color, 2);
  colorEngine(r, g, b);
}

void turnOffColors(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void colorEngine(byte r, byte g, byte b){
  digitalWrite(RED, r);
  digitalWrite(GREEN, g);
  digitalWrite(BLUE, b);
}
