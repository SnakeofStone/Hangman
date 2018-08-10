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
void checkWord(char* palabra, char letra, int* aciertoLugar);

// Main function
int main()
{
    // Inicilización de variables
    int ran, palabrasLen, errores = 1;
    int aciertoLugar[2] = {0, 0};
    char guess;

    // Largo del arreglo palabras
    palabrasLen = sizeof(palabras)/sizeof(palabras[0]);

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
        checkWord(palabras[ran], guess, &aciertoLugar);

        if (aciertoLugar[0] == 0)
        {
            printf("La letra introducida no se encuentra dentro de la palabra\n");
            errores++;
        }
        else if (aciertoLugar[1] == 1)
        {
            printf("Palabra correcta! \nPalabra: %s", palabras[ran]);
            errores = 8;
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

void checkWord(char* palabra, char letra, int* aciertoLugar)
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

        else
        {
            if(letra == palabra[i])
            {
                aciertoLugar[0] = 1;
                aciertoLugar[1] = i;
                break;
            }
        }
    }
}
