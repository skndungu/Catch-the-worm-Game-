int wormInterval = 100;
const int ledPin1 = 2; // declaring the pins to attach on the arduino
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;

const int switch1 = 31;
const int switch2 = 32;
const int switch3 = 33;
const int switch4 = 34;

int switchStatus1 = 0;  // declaring and initialise the variable to store the status of the pushbutton whether its pressed or not
int switchStatus2 = 0;
int switchStatus3 = 0;
int switchStatus4 = 0;

int HeadStatus1 = 0;
int HeadStatus2 = 0;
int HeadStatus3 = 0;
int HeadStatus4 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
    
  pinMode(switch1,INPUT);
  pinMode(switch2,INPUT);
  pinMode(switch3,INPUT);
  pinMode(switch4,INPUT);

  digitalWrite(switch1,HIGH);
  digitalWrite(switch2,HIGH);
  digitalWrite(switch3,HIGH);
  digitalWrite(switch4,HIGH);

  start();

}

void loop ()
{
  takeReading();
  ReadHeadStatus();
  

  if(switchStatus1 == 0 &&HeadStatus1 == 0)
  {
    flashFiveTimes();
  }

  else 
  {
    wormsMove();
  
  }
 
}

void wormsMove()
{
  worm1();
  worm1Off();
  delay(wormInterval);
  worm2();
  worm2Off();
  delay(wormInterval);
}

void start()
{
  lightPin1();
  lightPin2();
  lightPin3();
  lightPin4();
}

void verify ()
{
  verify1();
  verify2();
  verify3();
  verify4();
  verify21();
  verify22();
  verify23();
  verify21();
}

void flashFiveTimes()  // function that enables flashing five times
{
  flashAllLeds();
  flashAllLeds();
  flashAllLeds();
  flashAllLeds();
  flashAllLeds();
}

void lightPin1()               //function to turn on an led
{
 digitalWrite(ledPin1,HIGH);
  delay(400);
 digitalWrite(ledPin1,LOW);
}

void lightPin2()           //function to turn on an led
{
 digitalWrite(ledPin2,HIGH);
  delay(400);
 digitalWrite(ledPin2,LOW);
}

void lightPin3()              //function to turn on an led
{
 digitalWrite(ledPin3,HIGH);
  delay(400);
 digitalWrite(ledPin3,LOW);
}

void lightPin4()               //function to turn on an led
{
 digitalWrite(ledPin4,HIGH);
  delay(400);
digitalWrite(ledPin4,LOW);
}

void worm1()                   // function to create a worm in a certain direction
{
  lightHead1();
  lightStomach1();
}

void worm1Off()
{
  putOffHead1();
  putOffStomach1();
}

void worm2()                   // function to create a worm in a certain direction
{
  lightHead2();
  lightStomach2();
}

void worm2Off()
{
  putOffHead2();
  putOffStomach2();
}

void worm22()
{
  lightHead22();
  lightStomach22();
}

void worm22Off()
{
  putOffHead22();
  putOffStomach22();
}

void worm11()              // function to create a worm in a certain direction
{
  lightHead11();
  lightStomach11();
}

void worm11Off()
{
  putOffHead11();
  putOffStomach11();
}


void lightHead22()                // function that creates the head part for a specific worm
{
  digitalWrite(ledPin2,HIGH);
  delay(500);
}

void putOffHead22()
{
  digitalWrite(ledPin2,LOW);
}

void lightStomach22()               // function that creates the stomach  part for a specific worm
{
  digitalWrite(ledPin3,HIGH);
  delay(500);
}

void putOffStomach22()
{
  digitalWrite(ledPin3,LOW);
}

void lightHead1()                   // function that creates the head part for a specific worm
{
  digitalWrite(ledPin1,HIGH);
  delay(1000);
}

void putOffHead1()
{
  digitalWrite(ledPin1,LOW);
  //delay(500);
}

void lightHead2()                 // function that creates the head part for a specific worm
{
  digitalWrite(ledPin2,HIGH);
  delay(500);
}

void putOffHead2()
{
  digitalWrite(ledPin2,LOW);
  //delay(500);
}


void lightStomach1()             // function that creates the stomach  part for a specific worm
{
  digitalWrite(ledPin3,HIGH);
  delay(500);
}

void putOffStomach1()
{
  digitalWrite(ledPin3,LOW);
  //delay(500);
}

void lightStomach2()             // function that creates the stomach  part for a specific worm
{
  digitalWrite(ledPin4,HIGH);
  delay(500);
}
void putOffStomach2()
{
  digitalWrite(ledPin4,LOW);
  //delay(500);
}


void lightHead11()       // function that creates the head part for a specific worm
{
  digitalWrite(ledPin1,HIGH);
  delay(500);
}

void putOffHead11()
{
  digitalWrite(ledPin1,LOW);
  //delay(500);
}

void lightStomach11()            // function that creates the stomach  part for a specific worm
{
  digitalWrite(ledPin4,HIGH);
  delay(500);
}

void putOffStomach11()
{
  digitalWrite(ledPin4,LOW);
  //delay(500);
}


void flashAllLeds()                      // function to cause flash of leds
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);


  delay (200);

  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);


  delay(200);
}

void takeReading()                    // function to read the status of the switch
{
  switchStatus1 = digitalRead(switch1);
  switchStatus2 = digitalRead(switch2);
  switchStatus3 = digitalRead(switch3);
  switchStatus4 = digitalRead(switch4);
 
}

void ReadHeadStatus()
{
  HeadStatus1 = digitalRead(ledPin1);
  HeadStatus1 = digitalRead(ledPin2);
  HeadStatus1 = digitalRead(ledPin3);
  HeadStatus1 = digitalRead(ledPin4);
}

void verify1 ()
{
    if(switchStatus1 == 0 &&HeadStatus1 == 0)
  {
    flashFiveTimes();
  }

}
void verify2 ()
{
    if(switchStatus1 == 0 &&HeadStatus1 == 0)
  {
    flashFiveTimes();
  }
  
}

void verify3 ()
{
    if(switchStatus3 == 0 &&HeadStatus2 == 0)
  {
    flashFiveTimes();
  }

  else 
  {
    wormsMove();
  }
}
void verify4 ()
{
    if(switchStatus4 == 0 &&HeadStatus2 == 0)
  {
    flashFiveTimes();
  }

  else 
  {
    wormsMove();
  }
}

void verify21 ()
{
    if(switchStatus1 == 0 &&HeadStatus3 == 0)
  {
    flashFiveTimes();
  }

}
void verify22 ()
{
    if(switchStatus1 == 0 &&HeadStatus1 == 0)
  {
    flashFiveTimes();
  }

}

void verify23 ()
{
    if(switchStatus3 == 0 &&HeadStatus4 == 0)
  {
    flashFiveTimes();
  }

}
  
void verify24 ()
{
    if(switchStatus4 == 0 &&HeadStatus1 == 0)
  {
    flashFiveTimes();
  }


}


