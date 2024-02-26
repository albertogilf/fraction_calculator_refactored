#include "es.h"

#include <stdio.h>

int menu() {
    int opcion;

    do {
        printf("\n");
        printf("1. Introducir fraccion\n");
        printf("2. Eliminar una fraccion\n");
        printf("3. Mostrar una fraccion\n");
        printf("4. Mostrar todas las fracciones almacenadas\n");
        printf("5. Mostrar valor real\n");
        printf("6. Simplificar fraccion\n");
        printf("7. Sumar fracciones\n");
        printf("8. Restar fracciones\n");
        printf("9. Multiplicar dos fracciones\n");
        printf("10. Dividir dos fracciones\n");
        printf("11. Salir\n");
        printf("Introduzca una opcion: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 11) {
            printf("Opcion incorrecta\n");
        }
    } while (opcion < 1 || opcion > 11);

    printf("\n");

    return opcion;
}

// NUEVO código refactorizado ALBERTO

fraccion getFraccionFromKeyboard() {
    // Aqui no se controlan errores, se asume que el usuario introduce valores adecuados.
    // Si queremos hacer comprobaciones de tipo, podemos usar una función getIntFromKeyboard donde se pide un valor hasta que el usuario introduce un valor numérico.
    fraccion f;

    printf("Introduce numerador: ");
    f.numerador = getIntFromKeyboard();
    printf("Introduce denominador diferente de 0: ");
    int denominador = 0;
    while(denominador == 0) {
        denominador = getIntFromKeyboard();
        if(denominador == 0) {
            printf("El denominador no puede ser 0. Introduce otro valor: ");
            denominador = getIntFromKeyboard();
        }
        else{
            f.denominador = denominador;
        }
    }
    return f;
}

int getIntFromKeyboard(){
    int n;
    char c; // para limpiar el buffer de entrada
    while (1) {
        printf("Please enter an integer: ");
        // intentamos convertir
        if (scanf("%d", &n) == 1) {
            // es un entero, lo devolvemos
            return n;
        } else {
            // no es un entero, lo volvemos a pedir

            while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
            printf("Invalid input. Please enter an integer.\n");
        }
    }
    return n;
}

void muestraFraccion(fraccion f) {
    printf("%d/%d\n", f.numerador, f.denominador);
}

void muestraFracciones(fraccion fracciones[], int nFracciones) {
    int i;

    for (i = 0; i < nFracciones; i++) {
        printf("Posicion %d: ", i);
        muestraFraccion(fracciones[i]);
    }
}


