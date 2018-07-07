#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27
#define F1 59
#include "funciones.h"

int main(){
    int seguir=0;
    system("title § Calculadora 2.0 §");
    while(seguir!=ESC){
        switch(menu()){
            case '1':
                seguir=operacionCombinada();
                break;
            case F1:
                printf("ayuda\n");
                break;
            case ESC:
                seguir=ESC;
        }
    }return 0;
}
