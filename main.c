#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
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

// Generar una matriz de pointers tipo char para los arreglos de las palabras con longitudes distintas
char *palabras[] = {palabra0, palabra1, palabra2, palabra3, palabra4,
                      palabra5, palabra6, palabra7, palabra8, palabra9};

// Definicion de funciones
void printHangman(int errores);
void checkLetter(char* palabra, char letra, int *acierto, int lugares[10]);

// Identifier para el vector de aciertos
const int LUGARES_IDENTIFIER = 255;

// Main function
int main()
{
    // Inicilizacion de variables
    int ran, errores = 1, palLen;
    int acierto = 0, lugares[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //int aciertoLugar[2] = {0, 0};      // Índice 0 = Número de aciertos; Índice 1 = Lugar del acierto
    char guess; // Letra introducida

    //Random num from [0, 10)
    time_t T;
    srand((unsigned) time(&T));
    ran = rand() % 10;

    // Almacenar el largo de la palabra a elegir
    palLen = strlen(palabras[ran]);

    // Vector para almacenar las letras introducidas en el indice correcto
    char palIntro[palLen];

    // Almacenar guiones bajos en todo el arreglo
    int i;
    for(i = 0; i < palLen; i++)
    {
        palIntro[i] = '_';
    }

    // Main loop
    while(errores < 7)
    {
        //system("cls");
        printHangman(errores);
        printf("Letras: ");
        puts(palIntro);
        printf("Numero de errores: %d\n", errores-1);
        printf("Introduzca una letra: ");
        scanf(" %c", &guess);
        checkLetter(palabras[ran], guess, &acierto, lugares);

        // Verificar si la letra se encuentra en la palabra o no
        if (acierto == 0)
        {
            system("cls");
            printf("La letra \"%c\" introducida no se encuentra dentro de la palabra\n", guess);
            errores++;
        }
        else if (acierto != 0)
        {
//            printf("Palabra correcta! \nPalabra: %s", palabras[ran]);
            int j = 0;
            system("cls");
            do
            {
                palIntro[lugares[j]] = guess;
                printf("Letra correcta!\n");
                printf("Posicion %d\n", lugares[j]);
                j++;
            }while(lugares[j] != LUGARES_IDENTIFIER);

            // Ver si acertó la palabra o nel
            if(strcmp(palIntro, palabras[ran]) == 0)
            {
                system("cls");
                printf("Correcto! Haz adivinado la palabra!\n");
                printf("La palabra era %s", palabras[ran]);
                break;
            }
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

void checkLetter(char* palabra, char letra, int *acierto, int lugares[10])
{
    int i, lugarIndex = 0;

    *acierto = 0;
    // Declarar el numero de aciertos de esta iteración como 0

    // Evaluación si existe o no esa letra en el arreglo
    // de la palabra a descubrir
    for(i = 0; i < i + 1; i++)
    {
        if(palabra[i] == '\0')
        {
            break;
        }

        else if(letra == palabra[i])
        {
            *acierto = 1;
            lugares[lugarIndex] = i;
            lugarIndex++;
        }
    }
    lugares[lugarIndex] = LUGARES_IDENTIFIER;
}
