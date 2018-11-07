//This is a project as part of Introduction to Programming CS12020 module.
//The program defines usefull functions to operate built-in LED lights on arduino shield.


// hardware port definitions
#define LED_RED 3
#define LED_YELLOW 5
#define LED_PINK 6
#define LED_WHITE 9
#define LED_GREEN 10
#define LED_BLUE 11

#define EMU A1

#define SWITCH1 A4
#define SWITCH2 A5

#define POTENTIOMETER A0

//setting up an array with built in LEDs on arduino shield and their colors
int led_list[4] = {LED_PINK, LED_WHITE, LED_GREEN, LED_BLUE};
String colors[4] = {"pink", "white", "green", "blue"};

//function that lights up all the LEDs defined in an array
void setLeds(boolean state) {
  Serial.println(state);
  for (int i = 0; i <= 3 ; i++) {
    digitalWrite(led_list[i], state);

  }
}
//function that lights up LEDs defined in an array in a cycle (one after another)
void cycleLeds() {
  int i = 0;
  while (i <= 3) {
    Serial.println(colors[i]);
    digitalWrite(led_list[i], HIGH);
    delay(200);
    digitalWrite(led_list[i], LOW);
    delay(200);
    i++;
  }
}
//function that allows user control LEDs defined in an array with potentiometer
void manualControl() {
  int  spin = analogRead(POTENTIOMETER) / (1024 / 4);
  setLeds(LOW);
  digitalWrite(led_list[spin], HIGH);




}

void setup()
{
  // initialize the digital pins as an output.
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_PINK, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  // Open hardware serial communications and wait for port to open:
  Serial.begin(57600);
  Serial.println("Software serial LED test program");


  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);


  pinMode(POTENTIOMETER, INPUT);

}

void loop() {
