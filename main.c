#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        pString=&input[0];
        printf("____________________________________________________________\n");
        printf("\tIngrese la operacion:\n\n ");
        fflush(stdin);
        gets(pString);
        printf("____________________________________________________________\n");
        if(validar(pString)<0)
            {continue;}
        else if(validar(pString)>0){
            float output=calculo2(pString,100);
            parentesis(pString);
            printf("%s",pString);
            system("pause");
        }else
            {printf("\t \\(o_o')/ y que se supone que haga?\n");}

        //printf("El resultado es: %.3f\n",output);
        //system("pause");system("cls");
        printf("____________________________________________________________\n");
        printf("\tESC para salir\n");
        fflush(stdin);
        seguir=getch();
    }return 0;
}
