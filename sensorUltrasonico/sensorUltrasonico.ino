#define P_trig 2
#define P_echo 3

long duracion, distancia;

void setup() {

  Serial.begin(9600);
  pinMode(P_echo, INPUT);
  pinMode(P_trig, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(P_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(P_trig, HIGH);   //GENERA UN PULSO DE TRIGER POR 10ms
  delayMicroseconds(10);
  digitalWrite(P_trig, LOW);

  duracion = pulseIn(P_echo, HIGH);
  distancia = (duracion / 2) / 29;    //CALCULA LA DISTANCIA EN cm

  if (distancia >= 500 || distancia <= 0) { //SI DISTANCIA ES MAYOR A 500cm Y MENOR DE 0cm
    Serial.println("---");
  }
  else {
    Serial.print(distancia);  //ENTONCES SI DISTANCIA ES MENOR A 500cm Y MAYOR A 0cm
    Serial.println(" cm");    //NOS MOSTRARA EN EL MONITOR SERIAL LA DISTANCIA MEDIDA
    digitalWrite(13, LOW);    //EL LED PERMANECERA APAGADO
  }
  if (distancia <= 10 && distancia >= 1) {  //SI LA DISTANCIA ES MENOR A 10cm
    digitalWrite(13, HIGH);                 //ENCIENDE EL LED Y NOS MUESTRA UN MSG DE
    Serial.println("Alamra......");         //ALARMA
  }
  delay(100);
}