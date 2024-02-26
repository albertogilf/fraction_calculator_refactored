#include <stdio.h>
#include "es.h"
#include "fracciones.h"

#define MAX_FRACCIONES 50

int hayEspacio(int nFracciones);
int hayFracciones(int nFracciones);

int hayEspacio(int nFracciones) {
    return nFracciones < MAX_FRACCIONES;
}

int hayFracciones(int nFracciones) {
    return nFracciones > 0;
}

int main() {
    fraccion fracciones[MAX_FRACCIONES];
    int nFracciones;
    int opcion;

    nFracciones = 0;

    do {
        opcion = menu();

        if (opcion == 1) {
            // pasa a no tener función propia
            // Aniadar una fraccion es pedirla por teclado y ponerla en su lugar correspondiente. 

            if (nFracciones<MAX_FRACCIONES) {
                fraccion f = getFraccionFromKeyboard();
                fracciones[nFracciones] = f;
                nFracciones++;
                printf("Fracción introducida: %d/%d\n", f.numerador, f.denominador);
            } else {
                printf("La memoria de fracciones está llena. \n");
            }
        } else if (opcion == 2) {
            // pasa a no tener funcion propia. 
            // se imprimen funciones con el indice, se pide indice y se elimina si el indice es correcto. 
            if (nFracciones > 0) {
                // imprimir fracciones con indice. Creamos función en es.h
                muestraFracciones(fracciones, nFracciones);
                // pedimos un valor y lo eliminamos si existe, en caso contrario, ir al menu principal
                printf("Introduce la posición de la fracción a eliminar: ");
                int posicion = getIntFromKeyboard();
                if(posicion >= 0 && posicion < nFracciones) {
                    fraccion f = fracciones[posicion];
                    printf("Fracción a eliminar: %d/%d\n", f.numerador, f.denominador);
                    for (int i = posicion; i < nFracciones - 1; i++) {
                        fracciones[i] = fracciones[i + 1];
                    }
                    nFracciones--;
                    printf("Fracción eliminada\n");
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para eliminar. \n");
            }

        } else if (opcion == 3) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción a mostrar: ");
                int posicion = getIntFromKeyboard();
                if(posicion >= 0 && posicion < nFracciones) {
                    fraccion f = fracciones[posicion];
                    printf("Fracción a mostrar: %d/%d\n", f.numerador, f.denominador);
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para mostrar. \n");
            }
        } else if (opcion == 4) {
            muestraFracciones(fracciones, nFracciones);
        } else if (opcion == 5) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción a calcular el valor real: ");
                int posicion = getIntFromKeyboard();
                if(posicion >= 0 && posicion < nFracciones) {
                    fraccion f = fracciones[posicion];
                    float valorRealF1 = valorReal(f);
                    printf("valor real: %f\n", valorRealF1);
                    
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para calcular el valor real. \n");
            }
        } else if (opcion == 6) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción a simplificar: ");
                int posicion = getIntFromKeyboard();
                if(posicion >= 0 && posicion < nFracciones) {
                    fraccion f = fracciones[posicion];
                    fraccion fSimplificada = simplifica(f);
                    printf("valor real: ");
                    muestraFraccion(fSimplificada);
                    
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para simplificar. \n");
            }
        } else if (opcion == 7) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción 1 a sumar: ");
                int posicionFraccion1 = getIntFromKeyboard();
                printf("Introduce la posición de la fracción 2 a sumar: ");
                int posicionFraccion2 = getIntFromKeyboard();
                if(posicionFraccion1 >= 0 && posicionFraccion1 < nFracciones && posicionFraccion2 >= 0 && posicionFraccion2 < nFracciones) {
                    fraccion f1 = fracciones[posicionFraccion1];
                    fraccion f2 = fracciones[posicionFraccion2];
                    fraccion fSuma = sumaFracciones(f1,f2);
                    printf("Suma fracciones f1 y f2: ");
                    muestraFraccion(fSuma);
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para sumar. \n");
            }
        } else if (opcion == 8) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción 1 a restar: ");
                int posicionFraccion1 = getIntFromKeyboard();
                printf("Introduce la posición de la fracción 2 a restar: ");
                int posicionFraccion2 = getIntFromKeyboard();
                if(posicionFraccion1 >= 0 && posicionFraccion1 < nFracciones && posicionFraccion2 >= 0 && posicionFraccion2 < nFracciones) {
                    fraccion f1 = fracciones[posicionFraccion1];
                    fraccion f2 = fracciones[posicionFraccion2];
                    fraccion fSuma = restaFracciones(f1,f2);
                    printf("Suma fracciones f1 y f2: ");
                    muestraFraccion(fSuma);
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para restar. \n");
            }
        } else if (opcion == 9) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción 1 a multiplicar: ");
                int posicionFraccion1 = getIntFromKeyboard();
                printf("Introduce la posición de la fracción 2 a multiplicar: ");
                int posicionFraccion2 = getIntFromKeyboard();
                if(posicionFraccion1 >= 0 && posicionFraccion1 < nFracciones && posicionFraccion2 >= 0 && posicionFraccion2 < nFracciones) {
                    fraccion f1 = fracciones[posicionFraccion1];
                    fraccion f2 = fracciones[posicionFraccion2];
                    fraccion fSuma = multiplicaFracciones(f1,f2);
                    printf("Suma fracciones f1 y f2: ");
                    muestraFraccion(fSuma);
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para multiplicar. \n");
            }
        } else if (opcion == 10) {
            if (nFracciones > 0) {
                muestraFracciones(fracciones, nFracciones);
                printf("Introduce la posición de la fracción 1 a dividir: ");
                int posicionFraccion1 = getIntFromKeyboard();
                printf("Introduce la posición de la fracción 2 a dividir: ");
                int posicionFraccion2 = getIntFromKeyboard();
                if(posicionFraccion1 >= 0 && posicionFraccion1 < nFracciones && posicionFraccion2 >= 0 && posicionFraccion2 < nFracciones) {
                    fraccion f1 = fracciones[posicionFraccion1];
                    fraccion f2 = fracciones[posicionFraccion2];
                    fraccion fSuma = divideFracciones(f1,f2);
                    printf("Suma fracciones f1 y f2: ");
                    muestraFraccion(fSuma);
                } else {
                    printf("Posición incorrecta. \n");
                }
            } else {
                printf("No hay fracciones para dividir. \n");
            }
        }

    } while (opcion != 11);

    return 0;
}

