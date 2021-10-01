#include <AFMotor.h>
#include <Servo.h>
Servo Smotor;

int Input_Command;


AF_DCMotor Gmotor1(1);
AF_DCMotor Gmotor2(2);
AF_DCMotor Gmotor3(3);
AF_DCMotor Gmotor4(4);

void setup() {

  Serial.begin(115200);

  Smotor.attach(9);
  Smotor.write(180);

  Gmotor1.setSpeed(200);
  Gmotor1.run(RELEASE);

  Gmotor2.setSpeed(200);
  Gmotor2.run(RELEASE);

  Gmotor3.setSpeed(200);
  Gmotor3.run(RELEASE);

  Gmotor4.setSpeed(200);
  Gmotor4.run(RELEASE);
}


void loop() {

  uint8_t i;
  int x_speed=120;

  if (Serial.available()) {

    Input_Command = Serial.read();

    switch (Input_Command)
    {
      case 49:

        Gmotor1.setSpeed(x_speed);
        Gmotor2.setSpeed(x_speed);
        Gmotor3.setSpeed(x_speed);
        Gmotor4.setSpeed(x_speed);
        Gmotor1.run(FORWARD);
        Gmotor2.run(FORWARD);
        Gmotor3.run(FORWARD);
        Gmotor4.run(FORWARD);
        
        break;

      case 50:
        Gmotor1.run(FORWARD);
        Gmotor2.run(FORWARD);
        Gmotor3.run(FORWARD);
        Gmotor4.run(FORWARD);
        for (i = 0; i < x_speed; i++) {
          Gmotor1.setSpeed(i);
          Gmotor2.setSpeed(i);
          Gmotor3.setSpeed(i);
          Gmotor4.setSpeed(i);
          delay(10);
        }
        for (i = x_speed; i != 0; i--) {
          Gmotor1.setSpeed(i);
          Gmotor2.setSpeed(i);
          Gmotor3.setSpeed(i);
          Gmotor4.setSpeed(i);
        }
        
        break;

      case 51:
        Gmotor1.setSpeed(x_speed);
        Gmotor2.setSpeed(x_speed);
        Gmotor3.setSpeed(x_speed);
        Gmotor4.setSpeed(x_speed);
        Gmotor1.run(BACKWARD);
        Gmotor2.run(BACKWARD);
        Gmotor3.run(BACKWARD);
        Gmotor4.run(BACKWARD);
        break;
      

      case 52:

        Gmotor1.run(BACKWARD);
        Gmotor2.run(BACKWARD);
        Gmotor3.run(BACKWARD);
        Gmotor4.run(BACKWARD);
        for (i = 0; i < x_speed; i++) {
          Gmotor1.setSpeed(i);
          Gmotor2.setSpeed(i);
          Gmotor3.setSpeed(i);
          Gmotor4.setSpeed(i);
          delay(10);
        }
        for (i = x_speed; i != 0; i--) {
          Gmotor1.setSpeed(i);
          Gmotor2.setSpeed(i);
          Gmotor3.setSpeed(i);
          Gmotor4.setSpeed(i);
        }
        
        break;

      case 53:
        Gmotor1.setSpeed(x_speed);
        Gmotor2.setSpeed(x_speed);
        Gmotor3.setSpeed(x_speed);
        Gmotor4.setSpeed(x_speed);
        Gmotor1.run(BACKWARD);
        Gmotor2.run(FORWARD);
        Gmotor3.run(FORWARD);
        Gmotor4.run(BACKWARD);
        break;
       
      case 54:
        Gmotor1.setSpeed(x_speed);
        Gmotor2.setSpeed(x_speed);
        Gmotor3.setSpeed(x_speed);
        Gmotor4.setSpeed(x_speed);
        Gmotor1.run(BACKWARD);
        Gmotor2.run(FORWARD);
        Gmotor3.run(FORWARD);
        Gmotor4.run(BACKWARD);
        
        break;

      case 55:
        Gmotor1.setSpeed(x_speed);
        Gmotor2.setSpeed(x_speed);
        Gmotor3.setSpeed(x_speed);
        Gmotor4.setSpeed(x_speed);
        Gmotor1.run(FORWARD);
        Gmotor2.run(BACKWARD);
        Gmotor3.run(BACKWARD);
        Gmotor4.run(FORWARD);
        break;

      case 56:
        Gmotor1.setSpeed(x_speed);
        Gmotor2.setSpeed(x_speed);
        Gmotor3.setSpeed(x_speed);
        Gmotor4.setSpeed(x_speed);
        Gmotor1.run(FORWARD);
        Gmotor2.run(BACKWARD);
        Gmotor3.run(BACKWARD);
        Gmotor4.run(FORWARD);
        break;
        

      case 57:
        Smotor.write(90);
        delay(1000);
        break;

      case 58:
        Smotor.write(180);
        delay(1000);
        break;

      case 48:
        Gmotor1.setSpeed(0);
        Gmotor2.setSpeed(0);
        Gmotor3.setSpeed(0);
        Gmotor4.setSpeed(0);
        Gmotor1.run(RELEASE);
        Gmotor2.run(RELEASE);
        Gmotor3.run(RELEASE);
        Gmotor4.run(RELEASE);
        delay(100);
        break;



    }
  }
}
