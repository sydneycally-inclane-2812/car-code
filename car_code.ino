#include <Servo.h>
Servo turret; 

#define LEFT_MOTOR_FORWARD 3
#define LEFT_MOTOR_REVERSE 5
#define RIGHT_MOTOR_FORWARD 6
#define RIGHT_MOTOR_REVERSE 11
#define TURRET_PIN 9
#define BAUD_RATE 9600
#define INCREMENT 5
#define MINIMUM_SPEED 77

bool turretControl = 0;
int speed = 0;
int turretPos = 90; // angle of servo

void setup() {
    pinMode(LEFT_MOTOR_FORWARD, OUTPUT);   // left motors forward
    pinMode(LEFT_MOTOR_REVERSE, OUTPUT);   // left motors reverse
    pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);  // right motors forward
    pinMode(RIGHT_MOTOR_REVERSE, OUTPUT);  // right motors reverse
    pinMode(TURRET_PIN, OUTPUT); // output for turret
    turret.attach(TURRET_PIN);
    turret.write(turretPos);
    Serial.begin(BAUD_RATE);
}

// S: stop all cars
void stop() {
    analogWrite(LEFT_MOTOR_FORWARD, 0);
    analogWrite(RIGHT_MOTOR_FORWARD, 0);
    analogWrite(LEFT_MOTOR_REVERSE, 0);
    analogWrite(RIGHT_MOTOR_REVERSE, 0);
}

void loop() {
    if (Serial.available()) {
        const char t = Serial.read();
        Serial.println(t);

        if (isdigit(t) || t == 'q') {
            int origSpeed = atoi(t == 'q' ? "10" : &t); 
            speed = /*origSpeed == 0 ? 0 :*/ map(floor(origSpeed * 255 / 10), 25.5, 255, MINIMUM_SPEED, 255);
            Serial.println(speed);
        } else {
            stop();
            // const int lowerspeed = min(MINIMUM_SPEED, floor(speed / 4));
            const int lowerSpeed = 0;
              switch (t) {
                case 'F': {  // forward
                    analogWrite(LEFT_MOTOR_FORWARD, speed);
                    analogWrite(RIGHT_MOTOR_FORWARD, speed);
                    Serial.println("forward");
                    break;
                }
                case 'B': {  // back
                    analogWrite(LEFT_MOTOR_REVERSE, speed);
                    analogWrite(RIGHT_MOTOR_REVERSE, speed);
                    Serial.println("backward");
                    break;
                }
                case 'L': {  // left
                    if (!turretControl) { 
                        analogWrite(LEFT_MOTOR_REVERSE, speed);
                        analogWrite(RIGHT_MOTOR_FORWARD, speed);
                        Serial.println("left");
                    } else {
                        while (Serial.read() != 'S') {
                            turretPos = turretPos + INCREMENT;
                            turretPos = turretPos < 0 ? 0 : turretPos;
                            turret.write(turretPos);
                            delay(10);
                        }
                    }    
                    break;
                }
                case 'R': {  // right
                    if (!turretControl) {    
                        analogWrite(RIGHT_MOTOR_REVERSE, speed);
                        analogWrite(LEFT_MOTOR_FORWARD, speed);
                        Serial.println("right");
                    } else {
                        while (Serial.read() != 'S') {
                            turretPos = turretPos - INCREMENT;
                            turretPos = turretPos > 180 ? 180 : turretPos;
                            turret.write(turretPos);
                            delay(10);
                        }
                    }
                    break;
                }
                case 'V': {  // turret reset
                    turret.write(90);
                    break;
                }
                case 'H': {  // back left
                    analogWrite(LEFT_MOTOR_REVERSE, lowerSpeed);
                    analogWrite(RIGHT_MOTOR_REVERSE, speed);
                    Serial.println("backleft");
                    break;
                }
                case 'J': {  // back right
                    analogWrite(LEFT_MOTOR_REVERSE, speed);
                    analogWrite(RIGHT_MOTOR_REVERSE, lowerSpeed);
                    Serial.println("backright");
                    break;
                }
                case 'G':{   // forward left
                    analogWrite(LEFT_MOTOR_FORWARD, lowerSpeed);
                    analogWrite(RIGHT_MOTOR_FORWARD, speed);
                    Serial.println("fowardleft");
                    break;
                }
                case 'I':{   // forward right
                    analogWrite(LEFT_MOTOR_FORWARD, speed);
                    analogWrite(RIGHT_MOTOR_FORWARD, lowerSpeed);
                    Serial.println("fowardright");
                    break;
                }
                case 'S': {  // stop
                    stop();
                    Serial.println("stop");
                    break;
                }
                case 'X': {
                    turretControl = 1;
                    break;
                }
                case 'x': {
                    turretControl = 0;
                    break; 
                }
                default:
                    break;
            }
        }
    }
    delay(1);
}
//Credits where credits is due
String driver = "Tran Hung Dat";
String chassis = "Tran Hung Dat";
String code = "Tran Hung Dat - GL - VGB";
String decoration = "Tran Hung Dat - TNL";
String helper = "VGK";
//Went from dream team to wanna-collapse-and-die team, but we all tried our darn hardest.
//Today we shall all dominate the competition.

//Honorable mentions:
String donators = "PGB, NGL"; //for your carless sacrifices
String emotionalSupport = "LNMA"; //for being a great person
//Thank you - Tran Hung Dat
