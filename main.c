#include <stdio.h>
#include <stdlib.h>

int potencia(int,int);

int main(){
    system("mode con cols=60 lines=30");
    system("title Calculadora 2.0");
    char* puntero;
    char input[100];
    puntero=&input[0];
    int negativeFlag=0,numFlag=0;
    int aux,numCounter=0;
    float auxNumbers[50];
    for(int i=0;i<=50;i++){auxNumbers[i]=0;}
    printf("____________________________________________________________\n");
    printf("\tIngrese la operacion:\n\n ");
    gets(puntero);
    for(int i=0;i<100;i++){
        aux=*(puntero+i)-48;
        if(*(puntero+i)=='-'){
            if(numFlag){
                numCounter++;numFlag=0;
            }if(negativeFlag){negativeFlag=0;}
            else{negativeFlag=1;}
        }else if(aux>=0&&aux<=9){
            //printf("numero %d\n",aux);
            auxNumbers[numCounter]=auxNumbers[numCounter]*10+aux;
            numFlag=1;
        }else{
            if(negativeFlag){
                auxNumbers[numCounter]=0-auxNumbers[numCounter];
                negativeFlag=0;
            }if(numFlag){
                numCounter++;numFlag=0;
            }
        }if(*(puntero+i)=='\0'){break;}
        //printf("char %c\n",*(puntero+i));
    }
    //system("pause");system("cls");
    float output=0;
    for(int i=0;i<=5;i++){
        printf("\nNumero %d: %.2f\n",i+1,auxNumbers[i]);
        output=output+auxNumbers[i];
    }printf("El resultado es %.2f\n",output);
    printf("__________________________________________\n ");
    system("pause");
    return 0;
}

int potencia(int numero, int potencia){
    int resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++){
            resultado=resultado*numero;
            printf("%d",resultado);
        }
    }
    return resultado;
}
