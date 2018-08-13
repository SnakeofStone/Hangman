#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/** Juego de ahorcado
*/
// Almacenar las palabras a utilizar para el juego
char palabra0[] = {"perro"};
char palabra1[] = {"gato"};
char palabra2[] = {"pajaro"};
char palabra3[] = {"oxidado"};
char palabra4[] = {"hacha"};
char palabra5[] = {"cenicero"};
char palabra6[] = {"trofeo"};
char palabra7[] = {"mueble"};
char palabra8[] = {"mancha"};
char palabra9[] = {"yate"};

// Generar una matriz de pointers tipo char para los arreglos de las palabras
char *palabras[] = {palabra0, palabra1, palabra2, palabra3, palabra4,
                      palabra5, palabra6, palabra7, palabra8, palabra9};

// Definicion de funciones
void printHangman(int errores);
void checkLetter(char* palabra, char letra, int* aciertoLugar);

// Main function
int main()
{
    // Inicilizacion de variables
    int ran, errores = 1;
    int aciertoLugar[2] = {0, 0};      // Lugar 0 = Correcto o no; Lugar 1 = Lugar del acierto
    char guess; // Letra introducida

    //Random num from [0, 10)
    time_t T;
    srand((unsigned) time(&T));
    ran = rand() % 10;

    // Main loop
    while(errores < 7)
    {
        system("cls");
        printHangman(errores);
        printf("Introduzca una letra: ");
        scanf(" %c", &guess);
        checkLetter(palabras[ran], guess, &aciertoLugar);

        // Verificar si la letra se encuentra en la palabra o no
        if (aciertoLugar[0] == 0)
        {
            printf("La letra introducida no se encuentra dentro de la palabra\n");
            errores++;
        }
        else if (aciertoLugar[0] == 1)
        {
//            printf("Palabra correcta! \nPalabra: %s", palabras[ran]);
            printf("Letra correcta!\n");
            printf("Posición %d", aciertoLugar[1] + 1);
        }
    }

    // Imprimir la palabra correcta en caso de fallar 7 veces
    if(errores == 7)
    {
        system("cls");
        printHangman(errores);
        printf("La palabra correcta era %s", palabras[ran]);
    }

    return 0;
}

void printHangman(int errores)
{
    switch (errores)
    {
    case 1:
        printf("+---+\n");
        printf("|   |\n");
        printf("    |\n");
        printf("    |\n");
        printf("    |\n");
        printf("    |\n");
        printf("=========\n");
        break;

    case 2:
        printf("+---+\n");
        printf("|   |\n");
        printf("O   |\n");
        printf("    |\n");
        printf("    |\n");
        printf("    |\n");
        printf("=========\n");
        break;

    case 3:
        printf("+---+\n");
        printf("|   |\n");
        printf("O   |\n");
        printf("|   |\n");
        printf("    |\n");
        printf("    |\n");
        printf("=========\n");
        break;

    case 4:
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|   |\n");
        printf("     |\n");
        printf("     |\n");
        printf(" =========\n");
        break;

    case 5:
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("     |\n");
        printf("     |\n");
        printf(" =========\n");
        break;

    case 6:
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("/    |\n");
        printf("     |\n");
        printf(" =========\n");
        break;

    default:
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("/ \\  |\n");
        printf("     |\n");
        printf(" =========\n");
        break;
    }
}

void checkLetter(char* palabra, char letra, int* aciertoLugar)
{
    int i;
    for(i = 0; i < i + 1; i++)
    {
        if(palabra[i] == '\0')
        {
            aciertoLugar[0] = 0;
            aciertoLugar[1] = 0;
            break;
        }

        else if(letra == palabra[i])
        {
            *aciertoLugar = 1;
            *(aciertoLugar+1) = i;
            break;
        }
    }
}
