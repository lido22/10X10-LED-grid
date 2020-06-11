char pass[]={1,2,3,4}, passInd = 0;
bool nums = true, det=false;
byte seq[]={1,1,1,1, 1,1,1,0, 1,1,0,1, 1,1,0,0, 1,0,1,1, 1,0,1,0, 1,0,0,1, 1,0,0,0, 0,1,1,1, 0,1,1,0};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100000, 0b00010100, 0b00001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000};                          
void setup() {
  DDRD = B11111111; //0 => 7
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  testcols();
  testRows();
  cler();
  
}

void loop() {
  detectNum();
}
void detectNum(){
  char detected=20;
  if(digitalRead(A5)){
    cler();
    detected=0;
    det=true;
    if(nums)
      zero();
    else
      emogi0();
  }
  else if(digitalRead(A4)){
    cler();
    detected=1;
    det=true;
    if(nums)
      one();
    else
      emogi1();
  }
    
  else if(digitalRead(A3)){
    cler();
    detected=2;
    det=true;
    if(nums)
      two();
    else
      emogi2();
  }
  else if(digitalRead(A2)){
    cler();
    detected=3;
    det=true;
    if(nums)
      three();
    else
      emogi3();
  }
  else if(digitalRead(A1)){
    cler();
    detected=4;
    det=true;
    if(nums)
      four();
    else
      emogi4();
  }
  else if(digitalRead(A0)){
    cler();
    detected=5;
    det=true;
    if(nums)
      five();
    else
      emogi5();
  }
  else if(digitalRead(13)){
    cler();
    detected=6;
    det=true;
    if(nums)
      six();
    else
      emogi6();
  }
  else if(digitalRead(12)){
    cler();
    detected=7;
    det=true;
    if(nums)
      seven();
    else
      emogi7();
  }
  else if(digitalRead(11)){
    cler();
    detected=8;
    det=true;
    if(nums)
      eight();
    else
      emogi8();
  }
  else if(digitalRead(10)){
    cler();
    detected=9;
    det=true;
    if(nums)
      nine();
    else
      emogi9();
  }
  if(nums && det)
  {
    if(detected==pass[passInd])
    {
      if(passInd==3)
        nums=false;
      
      else{
        passInd++;
      }
      det = false;
    }
    else
      passInd=0;
  }
  else if(!nums && det){
    if(detected==pass[passInd]){
      
      if(passInd==0)
        nums=true;
      
      else
        passInd--;
      det = false;
    }
    else
      passInd=3;
  }
  else{}
}
void cler(){
byte  bigarr[] ={1,1,1,1, 0,1,1,1, 1,0,1,1, 0,0,1,1, 1,1,0,1, 0,1,0,1, 1,0,0,1, 0,0,0,1, 1,1,1,0, 0,1,1,0};
  digitalWrite(8, LOW);
  for(char i=0; i<40; i+=4){ 
    digitalWrite(0,bigarr[i]);
    digitalWrite(1,bigarr[i+1]);
    digitalWrite(2,bigarr[i+2]);
    digitalWrite(3,bigarr[i+3]);
    for(char j=0; j<40; j+=4){
      digitalWrite(4,bigarr[j]);
      digitalWrite(5,bigarr[j+1]);
      digitalWrite(6,bigarr[j+2]);
      digitalWrite(7,bigarr[j+3]);
    }
  }
  digitalWrite(9,LOW);
}
void emogi0(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100111, 0b10010100, 0b11001001, 0b00110010,
  0b00100001, 0b00000111, 0b10000000}; 
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi9(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b10001001, 0b00000010, 0b10100010, 0b01100000, 0b10010100, 0b11001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000}; 
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi8(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100000, 0b00010100, 0b00001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000}; 
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi7(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b11001110, 0b10110011, 0b01100000, 0b00010100, 0b11001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000}; 
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi6(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100111, 0b10010100, 0b11001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000}; 
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi5(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100011, 0b00010100, 0b11001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000};
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi4(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10100001, 0b01100000, 0b00010100, 0b00001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000};
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi3(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100011, 0b00010101, 0b00101001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000};
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
  }
}
void emogi2(){
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100111, 0b10010100, 0b00001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000};
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
    
  }
}
void emogi1(){  
  byte grid[] ={0b11110110, 0b11111110, 0b11110001, 0b11111001, 0b11110101, 0b11111101, 0b11110011, 0b11111011, 0b11110111, 0b11111111,
0b01110110, 0b01111110, 0b01110001, 0b01111001, 0b01110101, 0b01111101, 0b01110011, 0b01111011, 0b01110111, 0b01111111,
0b10110110, 0b10111110, 0b10110001, 0b10111001, 0b10110101, 0b10111101, 0b10110011, 0b10111011, 0b10110111, 0b10111111,
0b00110110, 0b00111110, 0b00110001, 0b00111001, 0b00110101, 0b00111101, 0b00110011, 0b00111011, 0b00110111, 0b00111111,
0b11010110, 0b11011110, 0b11010001, 0b11011001, 0b11010101, 0b11011101, 0b11010011, 0b11011011, 0b11010111, 0b11011111,
0b01010110, 0b01011110, 0b01010001, 0b01011001, 0b01010101, 0b01011101, 0b01010011, 0b01011011, 0b01010111, 0b01011111,
0b10010110, 0b10011110, 0b10010001, 0b10011001, 0b10010101, 0b10011101, 0b10010011, 0b10011011, 0b10010111, 0b10011111,
0b00010110, 0b00011110, 0b00010001, 0b00011001, 0b00010101, 0b00011101, 0b00010011, 0b00011011, 0b00010111, 0b00011111,
0b11100110, 0b11101110, 0b11100001, 0b11101001, 0b11100101, 0b11101101, 0b11100011, 0b11101011, 0b11100111, 0b11101111,
0b01100110, 0b01101110, 0b01100001, 0b01101001, 0b01100101, 0b01101101, 0b01100011, 0b01101011, 0b01100111, 0b01101111};  
  byte emogi[]={0b00011110, 0b00001000, 0b01000100, 0b00001001, 0b01001010, 0b10000000, 0b01100100, 0b10010100, 0b11001001, 0b00000010,
  0b00100001, 0b00000111, 0b10000000};
  digitalWrite(8, HIGH);
  char j=0, count=0, rev[8];
  for(char i=0; i<8; i++){
    rev[7-i] = emogi[j]%2;
    emogi[j] /= 2;
  }
  for(int i=0; i<100; i++){
    if(rev[count]){
      digitalWrite(9, LOW);
      digitalWrite(7,grid[i]%2);
      grid[i] /=2;
      digitalWrite(6,grid[i]%2);
      grid[i] /=2;
      digitalWrite(5,grid[i]%2);
      grid[i] /=2;
      digitalWrite(4,grid[i]%2);
      grid[i] /=2;
      digitalWrite(3,grid[i]%2);
      grid[i] /=2;
      digitalWrite(2,grid[i]%2);
      grid[i] /=2;
      digitalWrite(1,grid[i]%2);
      grid[i] /=2;
      digitalWrite(0,grid[i]%2);
      grid[i] /=2;
      digitalWrite(9, HIGH);
      delay(100);
    }
    count++;
    emogi[j]/=2;
    if(count==8){
      j++;
      count=0;
      for(char i=0; i<8; i++){
        rev[7-i] = emogi[j]%2;
        emogi[j] /= 2;
      }
    }
    
  }
}
void nine(){
  byte arrnine[]={1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 1,1,1,1,0,0,1,1, 0,1,1,1,1,0,0,1, 0,1,1,1,1,0,1,1, 1,0,1,1,1,0,0,1, 1,0,1,1,1,0,1,1, 0,0,1,1,1,0,0,1, 
  0,0,1,1,1,0,1,1, 1,1,0,1,0,1,0,1, 1,1,0,1,1,1,0,1, 1,1,0,1,0,0,1,1, 1,1,0,1,1,0,1,1, 0,1,0,1,1,0,1,1, 1,0,0,1,1,0,1,1, 0,0,0,1,1,0,0,1, 0,0,0,1,1,0,1,1, 
  1,1,1,0,1,0,0,1, 1,1,1,0,0,0,1,1, 0,1,1,0,0,1,0,1, 0,1,1,0,1,1,0,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<168; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrnine[i]);
    digitalWrite(1,arrnine[i+1]);
    digitalWrite(2,arrnine[i+2]);
    digitalWrite(3,arrnine[i+3]);
    digitalWrite(4,arrnine[i+4]);
    digitalWrite(5,arrnine[i+5]);
    digitalWrite(6,arrnine[i+6]);
    digitalWrite(7,arrnine[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void eight(){
  byte arreight[]={1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 0,1,1,1,1,0,0,1, 0,1,1,1,0,0,1,1, 1,0,1,1,0,0,0,1, 1,0,1,1,1,0,1,1, 0,0,1,1,1,0,0,1, 0,0,1,1,0,0,1,1,
  1,1,0,1,0,1,0,1, 1,1,0,1,1,1,0,1, 0,1,0,1,0,1,0,1, 0,1,0,1,1,1,0,1, 1,0,0,1,1,0,0,1, 1,0,0,1,0,0,1,1, 0,0,0,1,0,0,0,1, 0,0,0,1,1,0,1,1, 1,1,1,0,1,0,0,1,
  1,1,1,0,0,0,1,1, 0,1,1,0,0,1,0,1, 0,1,1,0,1,1,0,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<160; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arreight[i]);
    digitalWrite(1,arreight[i+1]);
    digitalWrite(2,arreight[i+2]);
    digitalWrite(3,arreight[i+3]);
    digitalWrite(4,arreight[i+4]);
    digitalWrite(5,arreight[i+5]);
    digitalWrite(6,arreight[i+6]);
    digitalWrite(7,arreight[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void seven(){
  byte arrsev[]={1,1,1,1,1,0,0,1, 1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 1,1,1,1,0,0,1,1, 1,1,1,1,1,0,1,1, 0,1,1,1,1,0,1,1, 1,0,1,1,0,0,1,1, 0,0,1,1,0,0,1,1,
  1,1,0,1,1,1,0,1, 0,1,0,1,1,1,0,1, 1,0,0,1,0,1,0,1, 0,0,0,1,0,1,0,1, 1,1,1,0,1,0,0,1, 0,1,1,0,1,0,0,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<112; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrsev[i]);
    digitalWrite(1,arrsev[i+1]);
    digitalWrite(2,arrsev[i+2]);
    digitalWrite(3,arrsev[i+3]);
    digitalWrite(4,arrsev[i+4]);
    digitalWrite(5,arrsev[i+5]);
    digitalWrite(6,arrsev[i+6]);
    digitalWrite(7,arrsev[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void six(){
  byte arrsix[]={1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 0,1,1,1,1,0,0,1, 0,1,1,1,0,0,1,1, 1,0,1,1,1,0,0,1, 0,0,1,1,1,0,0,1, 1,1,0,1,1,0,0,1, 0,1,0,1,1,0,0,1, 
  0,1,0,1,0,1,0,1, 0,1,0,1,1,1,0,1, 1,0,0,1,1,0,0,1 ,1,0,0,1,0,0,1,1, 0,0,0,1,1,0,0,1, 0,0,0,1,0,0,1,1, 1,1,1,0,1,0,0,1, 1,1,1,0,0,0,1,1, 0,1,1,0,0,1,0,1, 
  0,1,1,0,1,1,0,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<144; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrsix[i]);
    digitalWrite(1,arrsix[i+1]);
    digitalWrite(2,arrsix[i+2]);
    digitalWrite(3,arrsix[i+3]);
    digitalWrite(4,arrsix[i+4]);
    digitalWrite(5,arrsix[i+5]);
    digitalWrite(6,arrsix[i+6]);
    digitalWrite(7,arrsix[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void five(){
  byte arrfive[]={1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 1,1,1,1,0,0,1,1, 1,1,1,1,1,0,1,1, 0,1,1,1,1,0,0,1, 1,0,1,1,1,0,0,1, 0,0,1,1,1,0,0,1, 1,1,0,1,1,0,0,1,
  1,1,0,1,0,1,0,1, 1,1,0,1,1,1,0,1, 1,1,0,1,0,0,1,1, 0,1,0,1,1,0,1,1, 1,0,0,1,1,0,1,1, 0,0,0,1,1,0,1,1, 1,1,1,0,1,0,0,1, 1,1,1,0,0,0,1,1, 0,1,1,0,0,1,0,1,
  0,1,1,0,1,1,0,1};

  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<144; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrfive[i]);
    digitalWrite(1,arrfive[i+1]);
    digitalWrite(2,arrfive[i+2]);
    digitalWrite(3,arrfive[i+3]);
    digitalWrite(4,arrfive[i+4]);
    digitalWrite(5,arrfive[i+5]);
    digitalWrite(6,arrfive[i+6]);
    digitalWrite(7,arrfive[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void four(){
  byte arrfour[]={1,1,1,1,1,0,0,1, 1,1,1,1,0,0,1,1, 0,1,1,1,1,0,0,1, 0,1,1,1,0,0,1,1, 1,0,1,1,1,0,0,1, 1,0,1,1,0,0,1,1, 0,0,1,1,1,0,0,1, 0,0,1,1,0,1,0,1,
  0,0,1,1,1,1,0,1, 0,0,1,1,0,0,1,1, 1,1,0,1,0,0,1,1, 0,1,0,1,0,0,1,1, 1,0,0,1,0,0,1,1, 0,0,0,1,0,0,1,1, 1,1,1,0,0,0,1,1, 0,1,1,0,0,0,1,1};
digitalWrite(8, HIGH);
  for(unsigned char i=0; i<128; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrfour[i]);
    digitalWrite(1,arrfour[i+1]);
    digitalWrite(2,arrfour[i+2]);
    digitalWrite(3,arrfour[i+3]);
    digitalWrite(4,arrfour[i+4]);
    digitalWrite(5,arrfour[i+5]);
    digitalWrite(6,arrfour[i+6]);
    digitalWrite(7,arrfour[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void three(){
byte arrthree[]={1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 0,1,1,1,1,0,0,1, 0,1,1,1,0,0,1,1, 1,0,1,1,0,0,1,1, 0,0,1,1,1,1,0,1, 1,1,0,1,0,1,0,1, 0,1,0,1,1,1,0,1,
1,0,0,1,0,0,1,1, 0,0,0,1,1,0,0,1, 0,0,0,1,0,0,1,1, 1,1,1,0,0,1,0,1, 1,1,1,0,1,1,0,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<104; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrthree[i]);
    digitalWrite(1,arrthree[i+1]);
    digitalWrite(2,arrthree[i+2]);
    digitalWrite(3,arrthree[i+3]);
    digitalWrite(4,arrthree[i+4]);
    digitalWrite(5,arrthree[i+5]);
    digitalWrite(6,arrthree[i+6]);
    digitalWrite(7,arrthree[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void two(){
  byte arrtwo[]={1,1,1,1,1,0,0,1, 1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 1,1,1,1,0,0,1,1, 0,1,1,1,0,0,0,1, 0,1,1,1,1,0,1,1, 1,0,1,1,1,0,1,1, 0,0,1,1,0,0,1,1,
  1,1,0,1,1,1,0,1, 0,1,0,1,0,1,0,1, 1,0,0,1,1,0,0,1, 0,0,0,1,0,0,0,1, 1,1,1,0,0,0,0,1, 0,1,1,0,1,0,0,1, 0,1,1,0,0,1,0,1, 0,1,1,0,1,1,0,1, 0,1,1,0,0,0,1,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<136; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrtwo[i]);
    digitalWrite(1,arrtwo[i+1]);
    digitalWrite(2,arrtwo[i+2]);
    digitalWrite(3,arrtwo[i+3]);
    digitalWrite(4,arrtwo[i+4]);
    digitalWrite(5,arrtwo[i+5]);
    digitalWrite(6,arrtwo[i+6]);
    digitalWrite(7,arrtwo[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void zero(){
  byte arrzero[] ={1,1,1,1,1,0,0,1, 1,1,1,1,0,1,0,1, 1,1,1,1,1,1,0,1, 1,1,1,1,0,0,1,1, 0,1,1,1,0,0,0,1, 0,1,1,1,1,0,1,1, 1,0,1,1,0,0,0,1, 1,0,1,1,1,0,1,1,
0,0,1,1,0,0,0,1, 0,0,1,1,1,0,1,1, 1,1,0,1,0,0,0,1, 1,1,0,1,1,0,1,1, 0,1,0,1,0,0,0,1, 0,1,0,1,1,0,1,1, 1,0,0,1,0,0,0,1, 1,0,0,1,1,0,1,1, 0,0,0,1,0,0,0,1,
0,0,0,1,1,0,1,1, 1,1,1,0,0,0,0,1, 1,1,1,0,1,0,1,1, 0,1,1,0,1,0,0,1, 0,1,1,0,0,1,0,1, 0,1,1,0,1,1,0,1, 0,1,1,0,0,0,1,1};
int numzero=192;
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<numzero; i+=8){
    digitalWrite(9, LOW);
    digitalWrite(0,arrzero[i]);
    digitalWrite(1,arrzero[i+1]);
    digitalWrite(2,arrzero[i+2]);
    digitalWrite(3,arrzero[i+3]);
    digitalWrite(4,arrzero[i+4]);
    digitalWrite(5,arrzero[i+5]);
    digitalWrite(6,arrzero[i+6]);
    digitalWrite(7,arrzero[i+7]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void one(){
  byte oner[]={1,1,1,1, 1,1,1,0, 1,1,1,0, 1,1,0,1, 1,1,0,0, 1,0,1,1, 1,0,1,0, 1,0,0,1, 1,0,0,0, 0,1,1,1, 0,1,1,0};
byte onec[]={1,1,0,1, 1,0,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1, 1,1,0,1};
  digitalWrite(8, HIGH);
  for(unsigned char i=0; i<11*4; i+=4){
    digitalWrite(9, LOW);
    digitalWrite(3, oner[i]);
    digitalWrite(2, oner[i+1]);
    digitalWrite(1, oner[i+2]);
    digitalWrite(0, oner[i+3]);
    digitalWrite(7, onec[i+3]);
    digitalWrite(6, onec[i+2]);
    digitalWrite(5, onec[i+1]);
    digitalWrite(4, onec[i]);
    digitalWrite(9, HIGH);
    delay(100);
  }
}
void testRows(){
  for(char i=0; i<40; i+=4){
    digitalWrite(3, seq[i]);
    digitalWrite(2, seq[i+1]);
    digitalWrite(1, seq[i+2]);
    digitalWrite(0, seq[i+3]);
    digitalWrite(8, HIGH);
    for(int j=39; j>=0; j-=4){
      digitalWrite(7, seq[j-3]);
      digitalWrite(6, seq[j-2]);
      digitalWrite(5, seq[j-1]);
      digitalWrite(4, seq[j]);
    }
    delay(200);
    digitalWrite(8, LOW);
  }
}
void testcols(){
  for(char j=39; j>=0; j-=4){
      digitalWrite(7, seq[j-3]);
      digitalWrite(6, seq[j-2]);
      digitalWrite(5, seq[j-1]);
      digitalWrite(4, seq[j]);
      digitalWrite(8, HIGH);
      for(int i=0; i<40; i+=4){
        digitalWrite(3, seq[i]);
        digitalWrite(2, seq[i+1]);
        digitalWrite(1, seq[i+2]);
        digitalWrite(0, seq[i+3]);
      }
    delay(200);
    digitalWrite(8, LOW);
    }
}
