#include "fracciones.h"

#include <stdio.h>



/// @brief 
/// @param f 
/// @return 
float valorReal(fraccion f) {
    return (float) f.numerador / (float) f.denominador; 
}

/// @brief 
/// @param f 
/// @return 
fraccion simplifica(fraccion f) {
    int i;
    int primero;

    int numeradorParcial = f.numerador;
    int denominadorParcial = f.denominador;

    if (numeradorParcial < denominadorParcial) {
        primero = numeradorParcial;
    } else {
        primero = denominadorParcial;
    }

    for (i = primero; i > 1; i--) {
        if (numeradorParcial % i == 0 && denominadorParcial % i == 0) {
            numeradorParcial = numeradorParcial / i;
            denominadorParcial = denominadorParcial / i;
        }
    }
    fraccion fResultado;
    fResultado.numerador = numeradorParcial;
    fResultado.denominador = denominadorParcial;
    return fResultado;
}

fraccion sumaFracciones(fraccion f1, fraccion f2){

    fraccion fResultado;
    fResultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    fResultado.denominador = f1.denominador * f2.denominador;
    // si queremos simplificar, llamar a la funcion simplificar
    simplifica(fResultado);
    return fResultado;
}

fraccion restaFracciones(fraccion f1, fraccion f2) {
    fraccion fResultado;
    fResultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    fResultado.denominador = f1.denominador * f2.denominador;
    // si queremos simplificar, llamar a la funcion simplificar
    simplifica(fResultado);
    return fResultado;
}

fraccion multiplicaFracciones(fraccion f1, fraccion f2){
    fraccion fResultado;
    fResultado.numerador = f1.numerador * f2.numerador;
    fResultado.denominador = f1.denominador * f2.denominador;
    // si queremos simplificar, llamar a la funcion simplificar
    simplifica(fResultado);
    return fResultado;
}

fraccion divideFracciones(fraccion f1, fraccion f2){
    fraccion fResultado;
    fResultado.numerador = f1.numerador * f2.denominador;
    fResultado.denominador = f2.numerador * f1.denominador;
    // si queremos simplificar, llamar a la funcion simplificar
    simplifica(fResultado);
    return fResultado;
}




