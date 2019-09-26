
int boton = 3;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;


void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  bool estado_pulsador = digitalRead(boton);
  if(estado_pulsador == false){
    if(digitalRead(greenPin) == false){
      for (int brillo = 0; brillo <= 122; brillo++) {
        setColor(0, brillo, brillo); // es esta combinación porque queremos el color aqua
        delay(30);
      }
      for(int brillo = 123; brillo <= 255; brillo++) {
        setColor(0, brillo, brillo);
        delay(5);
      }
  //    delay(250);
      Serial.println("encendido");
    }
    else{
      for (int brillo = 255; brillo >= 0; brillo--) {
        setColor(0, brillo, brillo); // es esta combinación porque queremos el color aqua
        delay(10);
      }
  //    delay(250);
      Serial.println("apagado");
    }
  }
}



void setColor(int red, int green,int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
