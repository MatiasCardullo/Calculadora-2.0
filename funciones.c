#include <stdio.h>
#include <stdlib.h>

int validar(char* puntero){
    int index,flag=0,errorSintax=0;
    int parentesis=0,errorParentesis=0;
    for(int i=0;i<200;i++){
        index=*(puntero+i);
        if(index=='\0')
            {break;}
        if(index=='('){
            parentesis++;
            errorParentesis++;
        }if(index==')'){
            if(parentesis<=0)
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
    else if(parentesis>0)
        {flag=parentesis;}
    return flag;
}

int potencia(int numero, int potencia){
    int resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }return resultado;
}

float calculo1(char* puntero,int largo){
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
        printf("Numero %d: %.3f\n",i+1,auxNums[i]);
        output=output+auxNums[i];
    }return output;
}

char* parentesis(char* puntero){
    int index,flag=0,largo=0;
    char* inicio;
    char* fin;
    for(int i=0;i<200;i++){
        index=*(puntero+i);
        if(index==')'){
            flag=0;largo++;
            fin=(puntero+i);
            break;
        }
        if(flag)
            {largo++;}
        if(index=='('){
            inicio=(puntero+i);
            if(flag)
                {largo=0;}
            largo++;flag=1;
        }
    }
    char outputS[20];
    float num=calculo1(inicio,largo);
    printf("%.3f\n",num);
    int decimal,entero=num;
    float aux;
    //printf("%d\n",entero);
    for(int i=0;i<10;i++){
        aux=(num-entero)*potencia(10,i);
        decimal=aux;
        if(aux-decimal==0){break;}
    }
    //printf("%d\n",decimal);
    sprintf(outputS,"%d.%d",entero,decimal);
    return &outputS;
}

float terminos(char* puntero){
    for(int i=0;i<200;i++){

    }
    return 0;
}
