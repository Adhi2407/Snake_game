#include <LedControl.h>

//Define The Snake as a Struct
typedef struct Snake Snake;
struct Snake{
  int head[2];     // the (row, column) of the snake head
  int body[40][2]; //An array that contains the (row, column) coordinates
  int len;         //The length of the snake 
  int dir[2];      //A direction to move the snake along
};

//Define The Apple as a Struct
typedef struct Apple Apple;
struct Apple{
  int rPos; //The row index of the apple
  int cPos; //The column index of the apple
};

//MAX72XX led Matrix
const int DIN =12;
const int CS =11;
const int CLK = 10;
LedControl lc = LedControl(DIN, CLK, CS,1);

const int varXPin = A3;//X Value  from Joystick
const int varYPin = A4;//Y Value from Joystick

byte pic[8] = {0,0,0,0,0,0,0,0};//The 8 rows of the LED Matrix

Snake snake = {{1,5},{{0,5}, {1,5}}, 2, {1,0}};//Initialize a snake object
Apple apple = {(int)random(0,8),(int)random(0,8)};//Initialize an apple object
#include <LedControl.h>
//Variables To Handle The Game Time

//Define The Snake as a Struct
typedef struct Snake Snake;
float oldTime = 0;
struct Snake{
float timer = 0;
  int head[2];     // the (row, column) of the snake head
float updateRate = 3;
  int body[40][2]; //An array that contains the (row, column) coordinates

  int len;         //The length of the snake 
int i,j;//Counters
  int dir[2];      //A direction to move the snake along
void setup() {
};
  // put your setup code here, to run once:

    /*
//Define The Apple as a Struct
   The MAX72XX is in power-saving mode on startup,
typedef struct Apple Apple;
   we have to do a wakeup call
struct Apple{
   */
  int rPos; //The row index of the apple
  lc.shutdown(0,false);
  int cPos; //The column index of the apple
  /* Set the brightness to a medium values */
};
  lc.setIntensity(0,8);

  /* and clear the display */
//MAX72XX led Matrix
  lc.clearDisplay(0);
const int DIN =12;

const int CS =11;
  //Set Joystick Pins as INPUTs
const int CLK = 10;
  pinMode(varXPin, INPUT);
LedControl lc = LedControl(DIN, CLK, CS,1);
  pinMode(varYPin, INPUT);

}
const int varXPin = A3;//X Value  from Joystick

const int varYPin = A4;//Y Value from Joystick
void loop() {

  // put your main code here, to run repeatedly:
byte pic[8] = {0,0,0,0,0,0,0,0};//The 8 rows of the LED Matrix
  float deltaTime = calculateDeltaTime();

  timer += deltaTime;
Snake snake = {{1,5},{{0,5}, {1,5}}, 2, {1,0}};//Initialize a snake object

Apple apple = {(int)random(0,8),(int)random(0,8)};//Initialize an apple object
  //Check For Inputs

  int xVal = analogRead(varXPin);
//Variables To Handle The Game Time
  int yVal = analogRead(varYPin);
float oldTime = 0;
  
float timer = 0;
  if(xVal<100 && snake.dir[1]==0){
float updateRate = 3;
    snake.dir[0] = 0;

    snake.dir[1] = -1;
int i,j;//Counters
  }else if(xVal >920 && snake.dir[1]==0){
void setup() {
    snake.dir[0] = 0;
  // put your setup code here, to run once:
    snake.dir[1] = 1;
    /*
  }else if(yVal<100 && snake.dir[0]==0){
   The MAX72XX is in power-saving mode on startup,
    snake.dir[0] = -1;
   we have to do a wakeup call
    snake.dir[1] = 0;
   */
  }else if(yVal >920 && snake.dir[0]==0){
  lc.shutdown(0,false);
    snake.dir[0] = 1;
  /* Set the brightness to a medium values */
    snake.dir[1] = 0;
  lc.setIntensity(0,8);
  }
  /* and clear the display */
  
  lc.clearDisplay(0);
  //Update

  if(timer > 1000/updateRate){
  //Set Joystick Pins as INPUTs
    timer = 0;
  pinMode(varXPin, INPUT);
    Update();
  pinMode(varYPin, INPUT);
  }
}
  

  //Render
void loop() {
  Render();
  // put your main code here, to run repeatedly:
  
  float deltaTime = calculateDeltaTime();
}
  timer += deltaTime;


float calculateDeltaTime(){
  //Check For Inputs
  float currentTime = millis();
  int xVal = analogRead(varXPin);
  float dt = currentTime - oldTime;
  int yV…
