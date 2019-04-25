//Pines de conexión del driver
int MotorTa = 13;
int MotorTb = 12;
int ENA = 6;
int Dir_A = 10;
int Dir_B = 11;

int tiempo=0;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(MotorTa, OUTPUT);
  pinMode(MotorTb, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(Dir_A, OUTPUT);
  pinMode(Dir_B, OUTPUT);

}

void loop() {
  analogWrite(ENA, 100);
  if (Serial.available()) {
     char dato= Serial.read();
   switch (dato) {
    case '1':
      Adelante();
      
      break;
    case '2':
          Retro();
          break;
    case '3':
          Izquierda();
          break;
     case '4':
          Derecha();
          break;
     case '5':
          Parar();
          break;
    default:
      Adelante();
  }
  
 // delay(1); //pasusa de 1ms por ciclo
}  
}

void Adelante()
{
  digitalWrite (MotorTa, HIGH);
  digitalWrite (MotorTb, LOW);
}
void Retro()
{
  digitalWrite (MotorTa,LOW );
  digitalWrite (MotorTb,HIGH );
}
void Derecha()
{
  digitalWrite (Dir_A,LOW );
  digitalWrite (Dir_B,HIGH );
  delay(500);
  digitalWrite (Dir_A,LOW);
  digitalWrite (Dir_B,LOW);
}
void Izquierda()
{
  digitalWrite (Dir_A,HIGH);
  digitalWrite (Dir_B,LOW);
  delay(500);
  digitalWrite (Dir_A,LOW );
  digitalWrite (Dir_B,LOW );
  
}
void Parar()
{
  digitalWrite (MotorTa, LOW);
  digitalWrite (MotorTb, LOW);
  digitalWrite (Dir_A, LOW);
  digitalWrite (Dir_B, LOW);
}
