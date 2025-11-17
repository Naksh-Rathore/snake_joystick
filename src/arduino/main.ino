#define UP_Y 1023
#define DOWN_Y 0

#define LEFT_X 1023
#define RIGHT_X 0

const int joyStickXPin { A0 };
const int joyStickYPin { A1 };
const int joyStickButtonPin { 2 }; 

void setJoyStickValues(int &joyStickXVal, int &joyStickYVal);
int setButtonVal(int buttonPin);

void setup() {
  Serial.begin(9600);

  pinMode(joyStickButtonPin, INPUT_PULLUP);
}

void loop() {
  int joyStickXVal{};
  int joyStickYVal{};

  setJoyStickValues(joyStickXVal, joyStickYVal);
  int buttonVal { setButtonVal(joyStickButtonPin) };

  Serial.print(joyStickXVal);
  Serial.print(" ");
  Serial.print(joyStickYVal);
  Serial.print(" ");
  Serial.println(buttonVal);

  if (joyStickXVal != 512 || joyStickYVal != 512 || buttonVal != 0)
    delay(100);

  delay(10);
}

void setJoyStickValues(int &joyStickXVal, int &joyStickYVal) {
  bool directionSet { false };

  int rawjoyStickXVal { analogRead(joyStickXPin) };
  int rawjoyStickYVal { analogRead(joyStickYPin) };

  if (rawjoyStickXVal > 900)      
        joyStickXVal = LEFT_X;

    else if (rawjoyStickXVal < 100) 
        joyStickXVal = RIGHT_X;

    else
        joyStickXVal = 512;         

  
    if (rawjoyStickYVal > 900)      
        joyStickYVal = UP_Y;

    else if (rawjoyStickYVal < 100) 
        joyStickYVal = DOWN_Y;

    else
        joyStickYVal = 512;        
}

int setButtonVal(int buttonPin) {
  int buttonVal { digitalRead(buttonPin) };

  if (buttonVal == LOW)
    return 1;

  return 0;
}
