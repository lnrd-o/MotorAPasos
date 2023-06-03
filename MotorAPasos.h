/*  MotorAPasos.h - 
  v0.1
  Libreria para el motor a pasos de robot RB-4/EV de la marca Elettronica Veneta, a través de un ULN2003
  https://arduino-info.wikispaces.com/SmallSteppers

  Libreria escrita por Leonardo Rodriguez, 6/2023

  Utiliza la secuencia de 8 pasos: A-AB-B-BC-C-CD-D-DA

*/


#ifndef MotorAPasos_H
#define MotorAPasos_H

#include <arduino.h>

class MotorAPasos
{
  public:
    MotorAPasos(int pin1,int pin2,int pin3, int pin4); //constructor: se indican los pines al que el controlador del motor (ULN2003A) estará conectado.
    void activar();
    void desactivar();
    void giraPasos(int pasos, int direccion);
    void setTotalSteps (int numSteps) { totalSteps = numSteps; } // permite configurar el numero de pasos del motor usado
  private:
    int _pin1,_pin2,_pin3,_pin4;
};

#endif