
int input1 = 2; // Define the pin number on ardiuno board(as much as you need) 
int input2 = 3; // Define the pin number on ardiuno board
// 

int action;

void setup() {
  


pinMode(input1,OUTPUT);
pinMode(input2,OUTPUT);

Serial.begin(9600);

}

void loop() 
{
  
 //example 
    MotorIndexCheck('A',input1,input2);
//implement more if there are more motors
    

}



//Check the input singnal from unity corresponds to which motor
//the variable "index" is the ID of the Motor(a single letter or number inputs from unity), "inputPin0","inputPin1" is the two pins connected to the motor
void MotorIndexCheck(int index,int inputPin0,int inputPin1)
{
   if(Serial.available()>0)
  {
    while (Serial.peek()==index)
    {
      Serial.read();
      action=Serial.parseInt();

      if(action==0)
      {
        digitalWrite(inputPin0,HIGH);
        digitalWrite(inputPin1,LOW);
      }
        
      else if(action==1)
      {
        digitalWrite(inputPin0,LOW);
        digitalWrite(inputPin1,HIGH);
      }
      else if(action==2)
      {
        digitalWrite(inputPin0,LOW);
        digitalWrite(inputPin1,LOW);
       }
      }
      while (Serial.available()>0)
      {
        Serial.read();
      }
  }
}
