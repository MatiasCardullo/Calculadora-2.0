#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void validar(char*);
int potencia(int,int);

int main(){
    int seguir=0;
    while(seguir!=27){
        system("mode con cols=60 lines=30");
        system("title Calculadora 2.0");
        char* puntero;
        char input[100];
        puntero=&input[0];
        int negativeFlag=0,numFlag=0,floatFlag=0;
        int numCounter=0,floatConter=0;
        float aux,auxNums[50];
        for(int i=0;i<=50;i++){auxNums[i]=0;}
        printf("____________________________________________________________\n");
        printf("\tIngrese la operacion:\n\n ");
        gets(puntero);
        validar(puntero);
        for(int i=0;i<100;i++){
            aux=*(puntero+i)-48;
            if(*(puntero+i)=='-'){
                if(numFlag){
                    numCounter++;
                    numFlag=0;
                }
                if(negativeFlag)
                    {negativeFlag=0;}
                else
                    {negativeFlag=1;}
            }else if(aux>=0&&aux<=9){
                //printf("numero %d\n",aux);
                if(floatFlag){
                    auxNums[numCounter]=auxNums[numCounter]+aux/potencia(10,floatConter);
                    printf("%.3f",auxNums[numCounter]);
                    floatConter++;
                }else{
                    auxNums[numCounter]=auxNums[numCounter]*10+aux;
                }numFlag=1;
            }else if(*(puntero+i)=='.'||*(puntero+i)==','){
                floatFlag=1;floatConter=1;
            }else{
                if(negativeFlag){
                    auxNums[numCounter]=0-auxNums[numCounter];
                    negativeFlag=0;
                }if(numFlag){
                    numCounter++;
                    numFlag=0;floatFlag=0;
                }
            }if(*(puntero+i)=='\0'){break;}
        }
        //system("pause");system("cls");
        float output=0;
        for(int i=0;i<5;i++){
            printf("\nNumero %d: %.3f\n",i+1,auxNums[i]);
            output=output+auxNums[i];
        }printf("\nEl resultado es %.3f\n",output);
        printf("____________________________________________________________\n");
        printf("\n\tenter para volver");
        seguir=getch();
        printf("%d",seguir);
    }return 0;
}
void validar(char* puntero){
    int index=0,flag=0;
    for(int i=0;i<100;i++){
        index=*(puntero+i);
        if(*(puntero+i)=='\0')
            {break;}
        if(!(index>39&&index<58)){
            if(flag==0){
                printf("Error, caracteres invalidos: %c",index);
                flag=1;
            }else{printf(", %c",index);}
        }
    }if(flag){printf("\n");system("pause");}
}

int potencia(int numero, int potencia){
    int resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }return resultado;
}
