#ifndef FRACCIONES_H
#define FRACCIONES_H

typedef struct Fraccion
{
    int numerador;
    int denominador;
} fraccion;
 
float valorReal(fraccion f);
fraccion simplifica(fraccion f);
fraccion sumaFracciones(fraccion f1, fraccion f2);
fraccion restaFracciones(fraccion f1, fraccion f2);
fraccion multiplicaFracciones(fraccion f1, fraccion f2);
fraccion divideFracciones(fraccion f1, fraccion f2);

#endif

