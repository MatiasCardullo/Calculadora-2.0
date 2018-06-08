#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar(char* puntero){
    int index,flag=1,errorSintax=0,errorParentesis=0,nada=1;
    for(int i=0;i<200;i++){
        index=*(puntero+i);
        if(index=='\0')
            {break;}
        nada=0;
        if(index=='('){
            errorParentesis++;
        }if(index==')'){
            if(errorParentesis<=0)
                {flag=-2;}
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
    if(nada)
        {flag=0;}
    return flag;
}

float potencia(float numero, float potencia){
    float resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }else if(potencia<0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado/numero;}
    }
    return resultado;
}

float calculoSimple(char* puntero,int largo){
    int negativeFlag=0,numFlag=0,floatFlag=0;
    int numCounter=0,floatConter=0;
    float aux, auxNums[50];
    for(int i=0;i<=50;i++){auxNums[i]=0;}
    for(int i=0;i<largo+1;i++){
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
            }
        }
    }
    float output=0;
    for(int i=0;i<numCounter;i++){
        //printf("Numero %d: %.3f\n",i+1,auxNums[i]);
        output=output+auxNums[i];
    }return output;
}

int parentesis(char* pStringInicio){
    int index,flag=-1;
    int largoInicio=0,largoParentesis=0;
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
                largoInicio=largoInicio+largoParentesis-1;
                largoParentesis=0;
            }largoParentesis++;flag=1;
        }
    }
    if(flag!=-1){
        char auxNumber[100]={""};
        char auxString[200]={""};
        strncpy(auxString, pStringInicio,largoInicio);//printf("%s\n",auxString);
        output=calculoSimple(pInicio,largoParentesis);
        sprintf(auxNumber,"%.3f",output);
        strcat(auxString,auxNumber);//printf("%s\n",auxString);
        strcat(auxString,pFin+1);//printf("%s\n",auxString);
        strcpy(pStringInicio,auxString);
    }
    return flag;
}

void terminos(char* puntero){
    for(int i=0;i<200;i++){

    }
}

int isFloat(float num){
    char* aux1;char* aux2;
    char num1[30]={""};
    char num2[30]={""};
    aux1=&num1;aux2=&num2;
    sprintf(aux1,"%f\n",num);
    sprintf(aux2,"%.5f0\n",num);
    if(strcmp(aux1,aux2)==0){
        printf("%s %d\n",aux1,strcmp(aux1,aux2));
        sprintf(aux1,"%.5f\n",num);
        sprintf(aux2,"%.4f0\n",num);
    }else if(strcmp(aux1,aux2)==0){
        sprintf(aux1,"%.4f\n",num);
        sprintf(aux2,"%.3f0\n",num);
    }else if(strcmp(aux1,aux2)==0){
        sprintf(aux1,"%.3f\n",num);
        sprintf(aux2,"%.2f0\n",num);
    }else if(strcmp(aux1,aux2)==0){
        sprintf(aux1,"%.2f\n",num);
        sprintf(aux2,"%.1f0\n",num);
    }else if(strcmp(aux1,aux2)==0){
        sprintf(aux1,"%.1f\n",num);
        sprintf(aux2,"%.0f0\n",num);
    }else if(strcmp(aux1,aux2)==0){
        sprintf(aux1,"%.0f\n",num);
    }
    printf("j%s\n",aux1);
    return 0;
}
