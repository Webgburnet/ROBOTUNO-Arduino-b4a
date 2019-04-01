#include <Servo.h>
#include <ServoPlus360.h>

boolean __ardublockDigitalRead(int pinNumber)
{
  pinMode(pinNumber, INPUT);
  return digitalRead(pinNumber);
}


void Avancer();
ServoPlus360  monServoPlus360_8;
ServoPlus360  monServoPlus360_9;
void Reculer();
void Stop();
void Gauche();
void Droite();

void setup()
{
  pinMode( 2 , INPUT);
  pinMode( 3 , INPUT);
  pinMode( 5 , OUTPUT);
  pinMode( 6 , OUTPUT);
  Serial.begin(9600);
  monServoPlus360_8.brancher(8);

  monServoPlus360_9.brancher(9);

  Stop();

  digitalWrite(5 , LOW);

  digitalWrite(6 , LOW);

}

void loop()
{
  if (( ( __ardublockDigitalRead(4) ) == ( HIGH ) ))
  {
    if (( ( __ardublockDigitalRead(2) ) == ( HIGH ) ))
    {
      Serial.print("--");
      Serial.println();
      Serial.print("Obstacle a gauche");
      Serial.println();
      digitalWrite(5 , HIGH);
      digitalWrite(6 , HIGH);
      delay( 1000 );
      digitalWrite(5 , LOW);
      digitalWrite(6 , LOW);
      Stop();
      delay( 500 );
      Reculer();
      Droite();
    }
    else
    {
    }
    if (( ( __ardublockDigitalRead(3) ) == ( HIGH ) ))
    {
      Serial.print("--");
      Serial.println();
      Serial.print("Obstacle a droite");
      Serial.println();
      digitalWrite(5 , HIGH);
      digitalWrite(6 , HIGH);
      delay( 1000 );
      digitalWrite(5 , LOW);
      digitalWrite(6 , LOW);
      Stop();
      delay( 500 );
      Reculer();
      Gauche();
    }
    else
    {
    }
    if (( ( ( __ardublockDigitalRead(2) ) == ( HIGH ) ) && ( ( __ardublockDigitalRead(3) ) == ( HIGH ) ) ))
    {
      Serial.print("--");
      Serial.println();
      Serial.print("Obstacle a gauche et a droite");
      Serial.println();
      digitalWrite(5 , HIGH);
      digitalWrite(6 , HIGH);
      delay( 1000 );
      digitalWrite(5 , LOW);
      digitalWrite(6 , LOW);
      Stop();
      delay( 500 );
      Reculer();
      Reculer();
    }
    else
    {
    }
    Avancer();
  }
  else
  {
    Stop();
  }
}

void Avancer()
{
  Serial.print("Avancer");
  Serial.println();
  monServoPlus360_8.inverserRotation(OUI);
  monServoPlus360_8.ecrireRotation(1000);
  monServoPlus360_9.inverserRotation(NON);
  monServoPlus360_9.ecrireRotation(1000);
}

void Reculer()
{
  Serial.print("Reculer");
  Serial.println();
  monServoPlus360_8.inverserRotation(NON);
  monServoPlus360_8.ecrireRotation(1000);
  monServoPlus360_9.inverserRotation(OUI);
  monServoPlus360_9.ecrireRotation(1000);	
  delay( 1000 );
}

void Stop()
{
  Serial.print("STOP");
  Serial.println();
  monServoPlus360_8.inverserRotation(NON);
  monServoPlus360_8.ecrireRotation(500);
  monServoPlus360_9.inverserRotation(NON);
  monServoPlus360_9.ecrireRotation(500);
}

void Gauche()
{
  Serial.print("Gauche");
  Serial.println();
  monServoPlus360_8.inverserRotation(OUI);
  monServoPlus360_8.ecrireRotation(1000);
  monServoPlus360_9.inverserRotation(OUI);
  monServoPlus360_9.ecrireRotation(1000);	
  delay( 1000 );
}

void Droite()
{
  Serial.print("Droite");
  Serial.println();
  monServoPlus360_8.inverserRotation(OUI);
  monServoPlus360_8.ecrireRotation(1000);
  monServoPlus360_9.inverserRotation(OUI);
  monServoPlus360_9.ecrireRotation(1000);	
  delay( 1000 );
}


