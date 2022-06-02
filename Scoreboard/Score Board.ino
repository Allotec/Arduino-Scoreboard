#define LeftIncrement 10
#define RightIncrement 14
#define LeftDecrement 7
#define RightDecrement 11
#define Reset 8

const int segDigit[4] = {5, 6, 15, 16};

const int segPlacement[7] = {19, 17, 20, 3, 2, 21, 18};

const char digits[][8] = {
      "1111110", 
      "0110000", 
      "1101101", 
      "1111001", 
      "0110011",
      "1011011",
      "1011111",
      "1110000",
      "1111111",
      "1111011"
};

int leftScore = 0, rightScore = 0;

void setup() {
  //Segment
  for(int i = 0; i < 8; i++){
    pinMode(segPlacement[i], OUTPUT);
  }

  //Digits
  for(int i = 0; i < 4; i++){
    pinMode(segDigit[i], OUTPUT);
    digitalWrite(segDigit[i], LOW);
  }

  pinMode(LeftIncrement, INPUT_PULLUP);
  pinMode(RightIncrement, INPUT_PULLUP);
  pinMode(LeftDecrement, INPUT_PULLUP);
  pinMode(RightDecrement, INPUT_PULLUP);
  pinMode(Reset, INPUT_PULLUP);
}

void loop() {
  
  if(digitalRead(LeftIncrement) == LOW && leftScore < 100){
    for(int i = 0; i < 10; i++){
      delay(5);
      displayScore(leftScore, rightScore);
    }
    
    while(digitalRead(LeftIncrement) == LOW){
      delay(1);
      displayScore(leftScore, rightScore);
    }
    leftScore++;
  }
  else if(digitalRead(LeftDecrement) == LOW && leftScore > 0){
    for(int i = 0; i < 10; i++){
      delay(5);
      displayScore(leftScore, rightScore);
    }
    
    while(digitalRead(LeftDecrement) == LOW){
      delay(1);
      displayScore(leftScore, rightScore);
    }
    
    leftScore--;
  }
  else if(digitalRead(RightIncrement) == LOW && rightScore < 100){
    for(int i = 0; i < 10; i++){
      delay(5);
      displayScore(leftScore, rightScore);
    }
        
    while(digitalRead(RightIncrement) == LOW){
      delay(1);
      displayScore(leftScore, rightScore);
    }
    rightScore++;
  }
  else if(digitalRead(RightDecrement) == LOW && rightScore > 0){
    for(int i = 0; i < 10; i++){
      delay(5);
      displayScore(leftScore, rightScore);
    }
    
    while(digitalRead(RightDecrement) == LOW){
      delay(1);
      displayScore(leftScore, rightScore);
    }
    
    rightScore--;
  }
  else if(digitalRead(Reset) == LOW){
    for(int i = 0; i < 10; i++){
      delay(5);
      displayScore(leftScore, rightScore);
    }
    
    while(digitalRead(Reset) == LOW){
      delay(1);
      displayScore(leftScore, rightScore);
    }
    leftScore = 0;
    rightScore = 0;
  }

  displayScore(leftScore, rightScore);
}

void displayScore(int left, int right){
  displayDigit(0, left / 10);
  displayDigit(1, left % 10);
  displayDigit(2, right / 10);
  displayDigit(3, right % 10);
}

void displayDigit(int digit, int value){
  for(int j = 0; j < 7; j++){
    if(digits[value][j] == '1'){
      digitalWrite(segPlacement[j], LOW);
    }
    else{
      digitalWrite(segPlacement[j], HIGH);
    }
  }
  
  digitalWrite(segDigit[digit], HIGH);
  delay(1);
  digitalWrite(segDigit[digit], LOW);
}
