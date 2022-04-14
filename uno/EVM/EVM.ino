// digital pin 2 has a pushbutton attached to it. Give it a name:
int biden = 13;
int trump = 10;
int submit = 7;
int result = 3;
int safe = 0;
int pb = 0;
int pt = 0;
int rs = 0;

int bidenVote = 0;
int trumpVote = 0;
bool b = false;
bool t = false;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(biden, INPUT);
   pinMode(trump, INPUT);
   pinMode(submit, INPUT);
   pinMode(result, INPUT);
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(biden);
  int buttonStates = digitalRead(trump);
  int buttonStatesSubmit = digitalRead(submit);
  int buttonStatesResult = digitalRead(result);
  
  // print out the state of the button:
  

  if(buttonStatesResult == 1 and rs == 0)
  {
     Serial.println("!!!!Result!!!!");
    if (bidenVote < trumpVote) {
      Serial.println("Trump Win!");
      Serial.println(trumpVote);
    }
    else if (bidenVote > trumpVote) {
      Serial.println("biden Win!");
       Serial.println(bidenVote);
    }
    else {
      Serial.println("Draw!");
    }
    rs = 1;
  }
  
  if(buttonState == 1)
  {
    
    if(pb == 0)
    {
    Serial.println("biden");
    pb = 1;
    pt = 0;
    }
    b = true ; 
    t = false ;
    safe = 0;
     
    
  }

  
//   else
//  {
//    Serial.println(0);
//    
//  }
  if(buttonStates == 1)
  {
    if(pt == 0)
    {
    Serial.println("trump");
    pb = 0;
    pt = 1;
    }

     t = true ; 
     b = false ; 
     safe = 0;
  }
//    else
//  {
//    Serial.println(0);
//    
//  }

   if(buttonStatesSubmit == 1 and safe == 0)
  {
    
    if (t)
    {
      
      trumpVote +=1;
      Serial.println("Voted For trump");
      
      safe= 1;
    }
    if (b)
    {
      bidenVote +=1;
      Serial.println("Voted For biden");
      safe = 1;

    }
    Serial.println("Submit");
    rs = 0;
    pb = 0;
    pt = 0;
  }
//    else
//  {
//    Serial.println(0);
//    
//  }
  delay(10);
    // delay in between reads for stability
}
