// Whack an LED

// Game variables
int rNum;        //random int choosing the random light to turn on
int wins=0;      //counting consecutive wins
int highScore=0; //saving the highest score of consecutive wins

// time to react
const int easy=1000;
const int medium=500;
const int hard=325;
const int xtreme=250;


int ledPins[]={8,9,10,11,12}; //initializing led's
int pinCount=5;
int buttPins[] = {2,3,4,5,6};
int buttCount = 5;

void setup() {



for (int thisPin = 0; thisPin < pinCount; thisPin++) { //assigning all the pins as outputs in a for loop
    pinMode(ledPins[thisPin], OUTPUT);
  }
for(int thisButt = 0; thisButt < buttCount; thisButt++){ //assigning all the buttons as inputs by for loop
    pinMode(buttPins[thisButt], INPUT);
  }
}

void loop() {
  Serial.begin(9600);
  digitalWrite(3,HIGH);
  rNum=random(0,5); //generating random choice
  delay(500);
  digitalWrite(ledPins[rNum], HIGH); //lighting the randomly chosen bulb
  delay(hard); //difficulty
  
 
  int buttonStates[5];
  
  for(int i = 0; i < 5; i++){
      buttonStates[i] = digitalRead(buttPins[i]);
    }
    
  digitalWrite(ledPins[rNum], LOW); //turning off the randomly selected bulb, after the button choice was made
    
  if (buttonStates[rNum] == HIGH) //checking if the user pressed the correct button of the lit bulb
  {
    wins++;
    //blinking green light indicating correct choice     
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
  }
  else
  {
    if (wins>highScore) { 
        highScore=wins;
        wins=0;
  }
  //blinking red light indicating incorrect choice
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
  }
  Serial.println(highScore);
  
  }
