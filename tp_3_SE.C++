/*
int Electrovanne = 13;
int Resistance = 12;
int Moteur_R = 11;
int Moteur_L = 10;
int Moteur_GV = 9;
int Pompe = 8;
volatile int eau = 30;
int temp = A0;
int niv;

void setup()
{
  Serial.begin(9600);
  pinMode(Electrovanne, OUTPUT);
  pinMode(Resistance, OUTPUT);
  pinMode(Moteur_R, OUTPUT);
  pinMode(Moteur_L, OUTPUT);
  pinMode(Moteur_GV, OUTPUT);
  pinMode(Pompe, OUTPUT);
  pinMode(eau, INPUT);
  pinMode(temp, INPUT);

  digitalWrite(Electrovanne, HIGH);
  eau=digitalRead(30);

  while (eau != 1)
  {
    eau=digitalRead(30);
    digitalWrite(Electrovanne, HIGH);
    
  }
  digitalWrite(Electrovanne, LOW);

  
  digitalWrite(Resistance, HIGH);

  while (temp < 1000)
  {
    temp = analogRead(A0);
    delay(100);
    Serial.println("temperature:");
    Serial.println(temp);
    
  }
  digitalWrite(Resistance, LOW);


  for (int i = 0; i < 3; i++)
  {
    digitalWrite(Moteur_R, HIGH);
    digitalWrite(Moteur_L, LOW);
    delay(2000);
    digitalWrite(Moteur_R, LOW);
    digitalWrite(Moteur_L, HIGH);
    delay(1000);
    digitalWrite(Moteur_R, LOW);
    digitalWrite(Moteur_L, HIGH);
    delay(2000);
    digitalWrite(Moteur_R, LOW);
    digitalWrite(Moteur_L, LOW);
  }
  digitalWrite(Pompe, HIGH);
  delay(2000);
  digitalWrite(Pompe, LOW);
 
  eau=digitalRead(30);
  
  while (eau != 1)
  {
    eau=digitalRead(30);
    digitalWrite(Electrovanne, HIGH);
    //if(eau ==HIGH){break;}
  }
  digitalWrite(Electrovanne, LOW);


  
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(Moteur_R, HIGH);
    digitalWrite(Moteur_L, LOW);
    delay(2000);
    digitalWrite(Moteur_R, LOW);
    digitalWrite(Moteur_L, LOW);
    delay(1000);
    digitalWrite(Moteur_R, LOW);
    digitalWrite(Moteur_L, HIGH);
    delay(2000);
    digitalWrite(Moteur_R, LOW);
    digitalWrite(Moteur_L, LOW);
  }
  digitalWrite(Moteur_GV, HIGH);
  digitalWrite(Pompe, HIGH);
  delay(8000);
  digitalWrite(Pompe, LOW);
  digitalWrite(Moteur_GV, LOW);

}

void loop(){}

*/


int debut=13;
int verain_1_o=12;
int verain_2_o=11;
int verain_3_o=10;

int verain_1_f=A4;
int verain_2_f=A3;
int verain_3_f=A5;


int pack5=2;
int pack20=A0;

int capteur1=9;
int capteur2=8;
int capteur3=7;
int capteur4=6;
int capteur5=5;
int capteur6=4;
int capteur7=3;

int capt1=0;
int capt2=0; 
int capt3=0; 
int capt4=0; 
int capt5=0; 
int capt6=0; 
int capt7=0; 


int comptepack5=0;
int comptepack20=0;
bool debut_loop=false;

void setup()
{
  Serial.begin(9600);
  
  pinMode(debut, OUTPUT);
  pinMode(verain_1_o, OUTPUT);
  pinMode(verain_2_o, OUTPUT);
  pinMode(verain_3_o, OUTPUT);
  
  pinMode(verain_1_f, OUTPUT);
  pinMode(verain_2_f, OUTPUT);
  pinMode(verain_3_f, OUTPUT);
  
  pinMode(pack5, OUTPUT);
  pinMode(pack20, OUTPUT);
  
  pinMode(capteur1, INPUT);
  pinMode(capteur2, INPUT);
  pinMode(capteur3, INPUT);
  pinMode(capteur4, INPUT);
  pinMode(capteur5, INPUT);
  pinMode(capteur6, INPUT);
  pinMode(capteur7, INPUT);
  
}
  
 
void loop(){
 capt1=digitalRead(capteur1);
 capt2=digitalRead(capteur2);
 capt3=digitalRead(capteur3);
 capt4=digitalRead(capteur4);
 capt5=digitalRead(capteur5);
 capt6=digitalRead(capteur6);
 capt7=digitalRead(capteur7);
  
  while(debut_loop==false){
    capt1=digitalRead(capteur1);
  if(capt1==1){
    Serial.println("debut high");
  digitalWrite(debut,HIGH);
    debut_loop=true;
  }
  }
  delay(500);
  digitalWrite(debut,LOW);
  
  //capt2 debut verain 1 
  while(comptepack5<10){
     capt2=digitalRead(capteur2);
     capt3=digitalRead(capteur3);
  if(capt2==1){
    Serial.println("verain 1 high");
  digitalWrite(verain_1_o,HIGH);
  digitalWrite(verain_1_f,LOW);
    comptepack5++;
    delay(1000);
  }
  if(capt3==1){
    Serial.println("verain 1 low");
  digitalWrite(verain_1_o,LOW);  
  digitalWrite(verain_1_f,HIGH); 
    comptepack5++;
    delay(1000);
  }
    
  }
  digitalWrite(verain_1_o,LOW);  
  digitalWrite(verain_1_f,LOW);
  
  while(comptepack20<8){
    capt4=digitalRead(capteur4);
    capt5=digitalRead(capteur5);
  if(capt4==1){
    Serial.println("verain 2 high");
  digitalWrite(verain_2_o,HIGH);
  digitalWrite(verain_2_f,LOW); 
  comptepack20++;
  delay(1000);
  }
  if(capt5==1){ 
    Serial.println("verain 2 low");
  digitalWrite(verain_2_o,LOW);
  digitalWrite(verain_2_f,HIGH); 
  comptepack20++;
  delay(1000);  
  }
  }
  digitalWrite(verain_2_o,LOW);
  digitalWrite(verain_2_f,LOW); 
  
  
  
  if(capt6==1){
  digitalWrite(verain_3_o,HIGH);
  digitalWrite(verain_3_f,LOW); 
   }

  if(capt7==1){ 
  digitalWrite(verain_3_o,LOW);
  digitalWrite(verain_3_f,HIGH);
  delay(2000);
  digitalWrite(verain_3_o,LOW); 
  digitalWrite(verain_3_f,LOW); 
  }
  
  
}