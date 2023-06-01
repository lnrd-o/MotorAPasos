// Definición de los pines del ULN2003A
const int pin1 = 8;   // IN1
const int pin2 = 9;   // IN2
const int pin3 = 10;  // IN3
const int pin4 = 11;  // IN4
#define pasosPorVuelta 96
// Definición de la secuencia de pasos para el motor
const int numSteps = 8;
int steps[numSteps][4] = {
  { HIGH, LOW, LOW, LOW },
  { HIGH, HIGH, LOW, LOW },
  { LOW, HIGH, LOW, LOW },
  { LOW, HIGH, HIGH, LOW },
  { LOW, LOW, HIGH, LOW },
  { LOW, LOW, HIGH, HIGH },
  { LOW, LOW, LOW, HIGH },
  { HIGH, LOW, LOW, HIGH }
};

// Variables de control
int currentStep = 0;


void activar() {
  pinMode(0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void desactivar() {
  digitalWrite(pin1, 0);
  digitalWrite(pin2, 0);
  digitalWrite(pin3, 0);
  digitalWrite(pin4, 0);
  digitalWrite(0,0);
}
void giraPasos(int pasos,int direction) {
  
  for (int i = 0; i < pasos; i++) {
    digitalWrite(pin1, steps[currentStep][0]);
    digitalWrite(pin2, steps[currentStep][1]);
    digitalWrite(pin3, steps[currentStep][2]);
    digitalWrite(pin4, steps[currentStep][3]);
    digitalWrite(0,1);
    delay(8);  // Retardo entre cada paso (mayor velocidad menor torque) 4 - 50
    currentStep += direction;
    // Asegurarse de que el índice del paso se encuentre dentro del rango
    if (currentStep >= numSteps) {
      currentStep = 0;
    } else if (currentStep < 0) {
      currentStep = numSteps - 1;
    }
    desactivar();
    
  }
}

void setup() {
  // Configurar los pines del ULN2003A como salidas
  activar();
}

void loop() {
  // Realizar un paso
  giraPasos(pasosPorVuelta,1);

  delay(10000);
}
