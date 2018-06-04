#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main(){
    int seguir=0;
    system("mode con cols=60 lines=30");
    system("title Calculadora 2.0");
    while(seguir!=27){
        system("cls");
        char* pString;
        char input[200];
        int index;
        pString=&input[0];
        printf("____________________________________________________________\n");
        printf("\tIngrese la operacion:\n\n ");
        fflush(stdin);
        gets(pString);
        printf("____________________________________________________________\n");
        if(validar(pString)<0)
            {continue;}
        //else if(validar(pString)==0)
            //{terminos(pString);}
        else if(validar(pString)>0){
            printf("El resultado es: %s\n",parentesis(pString));
            system("pause");
        }
        float output=calculo1(pString,100);
        printf("El resultado es: %.3f\n",output);
        //system("pause");system("cls");
        printf("____________________________________________________________\n");
        printf("\tESC para salir\n");
        fflush(stdin);
        seguir=getch();
    }return 0;
}
