#include "funciones.h"

int main(){
    int seguir=0;
    system("title § Calculadora 2.0 §");
    while(seguir!=ESC){
        switch(menu()){
            case '1':
                seguir=operacionCombinada();
                break;
            case '2':
                //seguir=ecuacion();
                break;
            case F1: case 'h': case 'H':
                system(CLEAN);
                printf("________________________________________________________________________________\n");
                printf("  Este progama resuelve cualquier operacion matematica que el usuario desee.\n\n");
                printf("  Caracteres validos ()*+,-./0123456789^\n\n");
                printf("  Use ESC para salir y Retroceso o 'b' para volver al menu anterior\n");
                printf("________________________________________________________________________________\n");
                do{
                    setbuf(stdin, NULL);
                    seguir=getch();
                }while(seguir!=ESC&&seguir!=Atras&&seguir!='B'&&seguir!='b');
                break;
            case ESC:
                seguir=ESC;
        }
    }return 0;
}
