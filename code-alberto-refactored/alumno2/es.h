#ifndef ES_H
#define ES_H
#include "fracciones.h"


// codigo que vamos eliminando (comentado) y nuevo código que lo sustituye (sin comentar)
int menu(); // descriptivo, se queda como esta
// int pideNumerador();
// int pideDenominador();
fraccion getFraccionFromKeyboard();
int getIntFromKeyboard();

// void muestraResultadoCorrecto(); // no hace falta, es un printf
//void muestraResultadoIncorrecto(); // no hace falta, es un printf
// int pidePosicion(int nFracciones); // no hace falta, ya hay un pedir entero
// void muestraFraccion(int posicion, int numeradores[], int denominadores[]);
void muestraFraccion(fraccion f);
// void muestraFracciones(int numeradores[], int denominadores[], int nFracciones);
void muestraFracciones(fraccion fracciones[], int nFracciones);
// void muestraValor(float valor); no hace falta, es un printf


#endif

  