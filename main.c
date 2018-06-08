#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

int main(){
    int seguir=0;
    system("mode con cols=60 lines=30");
    system("title Calculadora 2.0");
    char* pString;
    char input[500];
    pString=&input[0];
    while(seguir!=27){
        system("cls");
        printf("____________________________________________________________\n");
        printf("\tIngrese la operacion:\n\n ");
        fflush(stdin);
        gets(pString);
        printf("____________________________________________________________\n");
        if(validar(pString)<0)
            {continue;}
        else if(validar(pString)>0){
            int largo=strlen(pString);
            printf("%s",pString);
            while(strchr(pString, '(')!=NULL){
                parentesis(pString);
                printf("\n%s",pString);
            }
            float output=calculoSimple(pString,largo);
            printf("=%0.3f\n",output);
            //printf("%d",isFloat(output));
        }else
            {printf("\t \\(o_o')/ y que se supone que haga?\n");}
        printf("____________________________________________________________\n");
        printf("\tESC para salir\n");
        fflush(stdin);
        seguir=getch();
    }return 0;
}
