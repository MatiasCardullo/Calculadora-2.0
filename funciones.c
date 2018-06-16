#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
#define ESC 27
#define F1 59
#define Atras 8

char menu(){
    char seguir=0;
    system("mode con cols=48 lines=11");
    printf("________________________________________________\n");
    printf("\t\tF1 para ayuda\n");
    printf("________________________________________________\n");
    printf("  1 - Realizar una operaci%cn combinada\n",162);
    printf("  2 - Realizar una ecuaci%cn\n",162);
    printf("________________________________________________\n");
    do{
        fflush(stdin);
        seguir=getch();
    }while(seguir!=ESC&&seguir!=F1&&!(seguir>'0'&&seguir<'3'));
    return seguir;
}

float potencia(float numero, float potencia){
    float resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }else if(potencia<0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado/numero;}
    }return resultado;
}

double calculoSimple(char* puntero,int largo){
    int negativeFlag=0,numFlag=0,floatFlag=0;
    int numCounter=0,floatConter=0;
    double aux, auxNums[50];
    for(int i=0;i<=50;i++){auxNums[i]=0;}
    for(int i=0;i<largo+1;i++){
        aux=*(puntero+i)-48;
        if(*(puntero+i)=='-'){                                             //marca negativos
            if(negativeFlag&&numFlag){
                auxNums[numCounter]=0-auxNums[numCounter];
                numCounter++;
                numFlag=0;floatFlag=0;
            }else if(!negativeFlag&&numFlag){
                numCounter++;negativeFlag=1;
                numFlag=0;floatFlag=0;
            }else if(!negativeFlag&&!numFlag){
                negativeFlag=1;
            }else{negativeFlag=0;}
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
            }else{                                                        //setea negativos y numeros
                if(negativeFlag&&numFlag){
                    auxNums[numCounter]=0-auxNums[numCounter];
                    negativeFlag=0;
                }if(numFlag){
                    numCounter++;
                    numFlag=0;floatFlag=0;
                }
            }
        }if(*(puntero+i)=='\0'){break;}
    }
    double output=0;
    for(int i=0;i<numCounter;i++){
        //printf("Numero %d: %.2f\n",i+1,auxNums[i]);
        output=output+auxNums[i];
    }return output;
}

int operacionCombinada(){
    int continuar;
    do{
        char* pString;
        char input[TAM];
        pString=&input[0];
        system("mode con cols=66 lines=11");
        printf("__________________________________________________________________\n");
        printf("\tIngrese la operaci%cn:\n\n ",162);
        fflush(stdin);
        gets(pString);
        printf("__________________________________________________________________\n");
        if(validar(pString)<0)
            {}
        else if(validar(pString)>0){
            system("mode con cols=63 lines=39");
            printf("__________________________________________________________________\n");
            int largo=strlen(pString);
            printf(" %s",pString);
            while(strchr(pString, '(')!=NULL){
                parentesis(pString);
                printf("\n %s",pString);
            }
            double output=calculoSimple(pString,largo);
            printf("=%0.2f\n\n",output);
        }else
            {printf("\t \\(o_o')/ %cy que se supone que haga?\n\n",168);}
        printf("_______________________________________________________________\n");
        printf("\tESC para salir - Retroceso para volver al menu\n");
        do{
            fflush(stdin);
            continuar=getch();
            fflush(stdin);
        }while(continuar==13);
    }while(continuar!=ESC&&continuar!=Atras);
    return continuar;
}

int validar(char* puntero){
    int index,flag=1,flagParentesis=0,errorSintax=0,errorParentesis=0,nada=1;
    for(int i=0;i<TAM;i++){
        index=*(puntero+i);
        if(index=='\0')
            {break;}
        nada=0;
        if(index=='('){
            errorParentesis++;
        }if(index==')'){
            if(errorParentesis<=0)
                {flagParentesis=1;}
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
            if(index==' ')
                {nada=1;continue;}
            if(flag!=-1){
                printf("\n Error, caracteres invalidos: %c",index);
                flag=-1;
            }else{printf(", %c",index);}
        }
    }
    if(errorParentesis!=0||flagParentesis)
            {printf("\n Error, faltan o sobran parentesis");flag=-2;}
    if(flag<0)
        {printf("\n");}
    if(nada&&flag)
        {flag=0;}
    return flag;
}

int parentesis(char* puntero){
    int index,flag=-1;
    int largoInicio=0,largoParentesis=0;
    char* pInicio,* pFin;
    float output;
    for(int i=0;i<TAM;i++){
        index=*(puntero+i);
        if(!flag){
            largoInicio++;
        }
        if(index==')'){
            flag=0;largoParentesis++;
            pFin=(puntero+i);
            break;
        }
        if(flag)
            {largoParentesis++;}
        if(index=='('){
            pInicio=(puntero+i);
            if(flag){
                largoInicio=largoInicio+largoParentesis-1;
                largoParentesis=0;
            }largoParentesis++;flag=1;
        }
    }
    if(flag!=-1){
        char auxNumber[100]={""};
        char auxString[200]={""};
        strncpy(auxString, puntero,largoInicio);//printf("%s\n",auxString);
        output=calculoSimple(pInicio,largoParentesis);
        sprintf(auxNumber,"%.2f",output);
        strcat(auxString,auxNumber);//printf("%s\n",auxString);
        strcat(auxString,pFin+1);//printf("%s\n",auxString);
        strcpy(puntero,auxString);
    }
    return flag;
}

void terminos(char* puntero){
    char* pFin,* pInicio=puntero;
    for(int i=0;i<TAM;i++){
        if(*(puntero+i)=='+'||*(puntero+i)=='-'){
            if(*(puntero+i+1)=='+'||*(puntero+i+1)=='-'){
                pFin=puntero+i;
            }
        }

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
