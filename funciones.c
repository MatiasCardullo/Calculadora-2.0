#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar(char* puntero){
    int index,flag=1,errorSintax=0,errorParentesis=0,nada=0;
    for(int i=0;i<200;i++){
        index=*(puntero+i);
        if(index=='\0')
            {break;}
        nada=1;
        if(index=='('){
            errorParentesis++;
        }if(index==')'){
            if(errorParentesis<=0)
                {flag=-2;break;}
            errorParentesis--;
        }
        if(index=='*'||index=='/'){
            errorSintax++;
            if(errorSintax>1){
                if(flag!=-3){
                    printf("\n Error de sintaxsis: \"%c%c\"",*(puntero+i-1),index);
                    flag=-3;
                }else{printf(", \"%c%c\"",*(puntero+i-1),index);}
            }
        }else{errorSintax=0;}
        if(!(index>39&&index<58)){      // todo lo q no sea ()*+,-./0123456789
            if(flag!=-1){
                printf("\n Error, caracteres invalidos: %c",index);
                flag=-1;
            }else{printf(", %c",index);}
        }
    }
    if(errorParentesis!=0||flag==-2)
            {printf("\n Error, faltan o sobran parentesis");flag=-2;}
    if(flag<0)
        {printf("\n\n ");system("pause");}
    if(!nada)
        {flag=0;}
    return flag;
}

int potencia(int numero, int potencia){
    int resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }return resultado;
}

float calculo2(char* puntero,int largo){
    int negativeFlag=0,numFlag=0,floatFlag=0;
    int numCounter=0,floatConter=0;
    float aux, auxNums[50];
    for(int i=0;i<=50;i++){auxNums[i]=0;}
    for(int i=0;i<largo;i++){
        aux=*(puntero+i)-48;
        if(*(puntero+i)=='-'){                                             //marca negativos
            if(negativeFlag&&numFlag){
                continue;
            }else{
                if(!negativeFlag&&numFlag){
                    numCounter++;
                    numFlag=0;floatFlag=0;
                    negativeFlag=1;
                }else if(!negativeFlag&&!numFlag){
                    negativeFlag=1;
                }
            }
        }
        else{
            if(aux>=0&&aux<=9){                                        //toma numeros
                if(floatFlag){
                    auxNums[numCounter]=auxNums[numCounter]+aux/potencia(10,floatConter);
                    floatConter++;
                }else{
                    //printf("leo numero\n");
                    auxNums[numCounter]=auxNums[numCounter]*10+aux;
                }numFlag=1;
            }else if(*(puntero+i)=='.'||*(puntero+i)==','){     //marca decimales
                floatFlag=1;floatConter=1;
            }else{                                                       //setea negativos y numeros
                if(negativeFlag&&numFlag){
                    auxNums[numCounter]=0-auxNums[numCounter];
                    negativeFlag=0;
                }if(numFlag){
                    numCounter++;
                    numFlag=0;floatFlag=0;
                }
            }if(*(puntero+i)=='\0'){break;}                   //termina la lectura
        }
    }
    float output=0;
    for(int i=0;i<numCounter;i++){
        //printf("Numero %d: %.3f\n",i+1,auxNums[i]);
        output=output+auxNums[i];
    }return output;
}

void parentesis(char* pStringInicio){
    int index,flag=0,largoParentesis=0;
    int largoInicio=0;
    char* pInicio,* pFin;
    float output;
    for(int i=0;i<200;i++){
        index=*(pStringInicio+i);
        if(!flag){
            largoInicio++;
        }
        if(index==')'){
            flag=0;largoParentesis++;
            pFin=(pStringInicio+i);
            break;
        }
        if(flag)
            {largoParentesis++;}
        if(index=='('){
            pInicio=(pStringInicio+i);
            if(flag){
                largoInicio=largoInicio+largoParentesis;
                largoParentesis=0;
            }largoParentesis++;flag=1;
        }
    }
    //printf("%c%.3f%c",*pInicio,output,*pFin);system("pause");
    char aux[100]={""};
    char inicio[200]={""};
    for(int i=0;i<largoInicio-1;i++){
        sprintf(aux,"%c",*(pStringInicio+i));
        //printf("%s",aux);system("pause");
        strcat(inicio,aux);
        //printf("%s",inicio);system("pause");
    }
    output=calculo2(pInicio,largoParentesis);
    sprintf(aux,"%.3f",output);
    strcat(inicio,aux);
    for(int i=1;i<200;i++){
        if(*(pFin+i)=='\0')
            {break;}
        sprintf(aux,"%c",*(pFin+i));
        //printf("%s",aux);system("pause");
        strcat(inicio,aux);
        //printf("%s",inicio);system("pause");
    }
    strcpy(pStringInicio,inicio);
}

float terminos(char* puntero){
    for(int i=0;i<200;i++){

    }
    return 0;
}
