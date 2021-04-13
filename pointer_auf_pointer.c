#include <stdio.h>
#include <stdlib.h>

void funktion1(int *pointer);
void funktion2(int **pointer_pointer);
void funktion3(int *pointer, int **pointer_pointer);


void main(void){
    int value = 10;
    int *ptr = &value;
    printf("\nFUNKTION MAIN:\n");
    printf("Der Inhalt von value ist: %i\n", value);
    printf("Die Adresse von value ist: %u\n", &value);
    printf("Der Inhalt von ptr ist die Adresse von value: %u\n",ptr);
    printf("Der Inhalt von der Adresse auf die ptr zeigt ist: %u\n",*ptr);
    printf("Die Adresse von ptr ist: %u\n", &ptr);
    funktion1(ptr);
    funktion2(&ptr);
    funktion3(ptr,&ptr);
}

void funktion1(int *pointer){
    printf("\nFUNKTION1 uebergebene Adresse auf Zeiger:\n");
    printf("Der Inhalt von pointer ist die Adresse von value: %u\n", pointer);
    printf("Der Inhalt von der Adresse, auf die pointer zeigt ist der gleiche, wie von ptr: %i\n", *pointer);
    printf("Der pointer #pointer# hat die Adresse: %u\n", &pointer);          
}

void funktion2(int **pointer_pointer){
    printf("\nFUNKTION2 uebergebene Adresse auf Zeiger von Zeiger:\n");
    printf("Der Inhalt von pointer_pointer ist die Adresse von ptr: %u\n", pointer_pointer);
    printf("Der Inhalt von der Adresse, auf die pointer_pointer zeigt ist die Adresse von value: %i\n",*pointer_pointer);
    printf("Der Inhalt vom Inhalt des Zeigers ptr ist value: %i\n", **pointer_pointer);  
    printf("Der pointer #pointer_pointer# hat die Adresse %u\n",&pointer_pointer);  
}

void funktion3(int *pointer, int **pointer_pointer){
    printf("\nFUNKTION3 Beides in einem:\n");
    printf("Der Inhalt von pointer ist die Adresse von value: %u\n", pointer);
    printf("Der Inhalt von der Adresse, auf die pointer zeigt ist der gleiche, wie von ptr: %i\n", *pointer);
    printf("Der pointer #pointer# hat die Adresse: %u\n", &pointer);

    printf("Der Inhalt von pointer_pointer ist die Adresse von ptr: %u\n", pointer_pointer);
    printf("Der Inhalt von der Adresse, auf die pointer_pointer zeigt ist die Adresse von value: %i\n",*pointer_pointer);
    printf("Der Inhalt vom Inhalt des Zeigers ptr ist value: %i\n", **pointer_pointer);  
    printf("Der pointer #pointer_pointer# hat die Adresse %u\n",&pointer_pointer);  
}
