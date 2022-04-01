char dir;
int ENA = 6; // MCU PWM Pin 10 to ENA on L298n Board
int IN1 = 2;
int IN2 = 3;

int ENB = 9;  // MCU PWM Pin 9 to ENB on L298n Board
int IN3 = 4;
int IN4 = 5;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(ENA, OUTPUT); //Set all the L298n Pin to output
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void loop() { // run over and over
  if (Serial.available()) {
    dir = Serial.read();
    //  Serial.write("dir is read \n");
    //Serial.write(Serial.read());
  }
  switch (dir) {

    case 'F': // forward
      Serial.write("forward \n");
      forward();
      delay(1000);
      off();
      dir = 'O';
      break;

    case 'B': //backward
      Serial.write("backward \n");
      backward();
      delay(1000);
      off();
      dir = 'O';
      break;

    case 'R': //right
      Serial.write("right \n");
      right();
      delay(500);
      //      forward();
      //      delay(2000);
      off();
      dir = 'O';
      break;

    case 'L': //left
      Serial.write("left \n");
      left();
      delay(500);
      //      forward();
      //      delay(2000);
      off();
      dir = 'O';
      break;

    case 'O': // off
      off();
      delay(1000);
      dir = 'O';
      Serial.write("off \n");
      break;
  }

}


void forward()
{
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  // Run the motors on both direction at fixed speed
  digitalWrite(IN1, HIGH); // Turn HIGH motor A
  digitalWrite(IN2, LOW);
  //  analogWrite(ENA, 200); // TO set the turning speed to 200 out of possible range 0 to 255

  digitalWrite(IN3, HIGH); // turn HIGH motor B
  digitalWrite(IN4, LOW);  // To set the turning speed to 200 out of possible range 0 to 255
  //  analogWrite(ENB, 200);
}

void backward()
{
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void off()
{
  digitalWrite(IN1, LOW); // Turn the motor off
  digitalWrite(IN2, LOW); // Turn the motor off
  digitalWrite(IN3, LOW); // Turn the motor off
  digitalWrite(IN4, LOW); // Turn the motor off
}

void right()
{
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  // Run the motors on both direction at fixed speed
  digitalWrite(IN1, HIGH); // Turn HIGH motor A
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW); // turn HIGH motor B
  digitalWrite(IN4, HIGH);
}

void left()
{
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  // Run the motors on both direction at fixed speed
  digitalWrite(IN1, LOW); // Turn HIGH motor A
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH); // turn HIGH motor B
  digitalWrite(IN4, LOW);
}
