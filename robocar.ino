const int enableA = 10;
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int enableB = 11;

const int fullPower = 255;
const int medPower = 100;

void setup()
{
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enableB, OUTPUT);
}

void loop() 
{
  if (Serial.available())
  {
    char val = Serial.read();
    switch(val)
    {
      case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        leftTurnOnPlace();
        break;
      case 'R':
        rightTurnOnPlace();
        break;
      case 'G':
        leftForwardTurn();
        break;
      case 'I':
        rightForwardTurn();
        break;
      case 'H':
        leftBackwardTurn();
        break;
      case 'J':
        rightBackwardTurn();
        break;
      default:
        motorsOff();
    }
  }
}

void moveForward()
{
  rightMotorsForward(fullPower);
  leftMotorsForward(fullPower);
}

void moveBackward()
{
  rightMotorsBackward(fullPower);
  leftMotorsBackward(fullPower);
}

void rightTurnOnPlace()
{
  leftMotorsForward(fullPower);
  rightMotorsBackward(fullPower);
}

void leftTurnOnPlace()
{
  rightMotorsForward(fullPower);
  leftMotorsBackward(fullPower);
}

void rightForwardTurn()
{
  rightMotorsForward(medPower);
  leftMotorsForward(fullPower);
}

void leftForwardTurn()
{
  rightMotorsForward(fullPower);
  leftMotorsForward(medPower);
}

void rightBackwardTurn()
{
  rightMotorsBackward(medPower);
  leftMotorsBackward(fullPower);  
}

void leftBackwardTurn()
{
  rightMotorsBackward(fullPower);
  leftMotorsBackward(medPower);  
}

void rightMotorsForward(int power)
{
  analogWrite(enableA, power);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void rightMotorsBackward(int power)
{
  analogWrite(enableA, power);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void leftMotorsForward(int power)
{
  analogWrite(enableB, power);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void leftMotorsBackward(int power)
{
  analogWrite(enableB, power);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void motorsOff()
{
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);
}
