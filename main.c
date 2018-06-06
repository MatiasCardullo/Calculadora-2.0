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
        char input[500];
        pString=&input[0];
        printf("____________________________________________________________\n");
        printf("\tIngrese la operacion:\n\n ");
        fflush(stdin);
        gets(pString);
        printf("____________________________________________________________\n");
        if(validar(pString)<0)
            {continue;}
        else if(validar(pString)>0){
            int flag=0,largo=strlen(pString);
            while(strchr(pString, '(')!=NULL){
                if(!flag)
                    {printf("%s",pString);}
                flag=1;
                parentesis(pString);
                printf("\n%s",pString);
            }if(!flag)
                {printf("%s",pString);}
            printf("=%.3f\n",calculoSimple(pString,largo));
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
