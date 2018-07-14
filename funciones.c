#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
#define F1 59
#define ESC 27
#define Enter 13
#define Atras 8
#define BIP 7

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

double potencia(double numero, double potencia){
    double resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }else if(potencia<0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado/numero;}
    }return resultado;
}

double* seteadorNumeros(char* puntero,int largo){
    int negativeFlag=0,numFlag=0,floatFlag=0;
    int numCounter=1,floatConter=0;
    double aux;
    static double auxNums[50];
    for(int i=0;i<50;i++){auxNums[i]=0;}
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
        }
    }auxNums[0]=numCounter-1;
    /*for(int i=0;i<50;i++){
        if(auxNums[i]!=0){printf("%f",auxNums[i]);}
    }system("pause");*/
    return auxNums;
}

double calculoSimple(char* puntero,int largo){
    double* pNumeros;
    pNumeros=seteadorNumeros(puntero,largo);
    //printf("\nCantidad de numeros: %.0f",*(pNumeros+0));
    double output=0;
    for(int i=1;i<=*(pNumeros+0);i++){
        //printf("\n Numero %d: %.2f",i,*(pNumeros+i));
        output=output+*(pNumeros+i);
    }return output;
}

double calculoTermino(char* puntero,int largo){
    double* pNumeros;
    pNumeros=seteadorNumeros(puntero,largo);
    //printf("\nCantidad de numeros: %.0f",*(pNumeros+0));
    double output,numAux;
    int flag=1;
    char operador;
    char *pAux2, *pAux1=puntero;
    //printf("\n Numero %d: %.2f",1,*(pNumeros+1));
    output=*(pNumeros+1);
    for(int i=2;i<=*(pNumeros+0);i++){
        if(flag){
            pAux2=strchr(pAux1,'*');
            if(pAux2!=NULL){
                flag=0;
                pAux1=pAux2+1;
                operador='*';
            }
        }if(flag){
            pAux2=strchr(pAux1,'/');
            if(pAux2!=NULL){
                flag=0;
                pAux1=pAux2+1;
                operador='/';
            }
        }if(flag){
            pAux2=strchr(pAux1,'^');
            if(pAux2!=NULL){
                flag=0;
                pAux1=pAux2+1;
                operador='^';
            }
        }
        //printf("\n Numero %d: %.2f",i,*(pNumeros+i));
        numAux=*(pNumeros+i);
        if(flag==0){
            if(operador=='*'){
                //printf("\n %.0f*%.0f",output,numAux);
                output=output*numAux;
            }if(operador=='/'){
                //printf("\n %.0f/%.0f",output,numAux);
                output=output/numAux;
            }if(operador=='^'){
                //printf("\n %.0f/%.0f",output,numAux);
                output=potencia(output,numAux);
            }flag=-1;
            //printf("=%.0f",output);
        }
    }return output;
}

int operacionCombinada(){
    int continuar=0;
    do{
        char* pString;
        char input[TAM];
        double output;
        pString=&input[0];
        system("mode con cols=66 lines=40");
        printf("__________________________________________________________________\n");
        printf("\tIngrese la operaci%cn:\n\n ",162);
        fflush(stdin);
        gets(pString);
        printf("__________________________________________________________________");
        if(validar(pString)<0)
            {printf("%c",BIP);}
        else if(validar(pString)>0){
            system("cls");
            printf("__________________________________________________________________\n");
            int largo;
            printf(" %s",pString);
            while(strchr(pString, '(')!=NULL){
                parentesis(pString);
                printf("\n\n %s",pString);
            }while(strchr(pString, '*')!=NULL||strchr(pString, '/')!=NULL||strchr(pString, '^')!=NULL){
                terminos(pString);
                printf("\n\n %s",pString);
            }largo=strlen(pString);
            output=calculoSimple(pString,largo);
            printf("=%0.2f\n\n",output);
        }
        else
            {printf("\n\t \\(o_o')/ %cy que se supone que haga?\n\n",168);}
        printf("__________________________________________________________________\n");
        printf("\tESC para salir - Retroceso para volver al menu\n");
        do{
            fflush(stdin);
            continuar=getch();
        }while(continuar!=ESC&&continuar!=Atras&&continuar==Enter);
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
        if(!(index>='('&&index<='9')&&index!='^'){      // todo lo q no sea ()*+,-./0123456789
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

void insertNumberInString(char* puntero,int largoInicio,double number,char*pFin){
    char auxNumber[50]={""};
    char auxString[1000]={""};
    strncpy(auxString, puntero,largoInicio);printf("\nstring%s\n",auxString);
    sprintf(auxNumber,"%.2f",number);
    strcat(auxString,auxNumber);printf("\nstring%s\n",auxString);
    strcat(auxString,pFin);printf("\nstring%s\n",auxString);
    strcpy(puntero,auxString);
}

int parentesis(char* puntero){
    int index,flag=-1,flagTermino;
    int largoInicio=0,largoParentesis=0;
    char *pAux, *pInicio, *pFin;
    double output;
    //do{
        flagTermino=0;
        for(int i=0;i<TAM;i++){
            pAux=puntero+i;
            index=*pAux;
            if(!flag){
                largoInicio++;
            }
            if(index==')'){
                flag=0;largoParentesis++;
                pFin=pAux+1;
                break;
            }
            if(flag)
                {largoParentesis++;}
            if(index=='('){
                pInicio=pAux;
                if(flag){
                    largoInicio=largoInicio+largoParentesis-1;
                    largoParentesis=0;
                }largoParentesis++;flag=1;
            }
            if(index=='*'||index=='/'||index=='^'){flagTermino=1;}
        }
        /*if(flagTermino){
            system("pause");
            terminos(pInicio+1);
            printf("\n\n %s",puntero);
        }
    }while(flagTermino);*/
    if(flag!=-1){
        output=calculoSimple(pInicio,largoParentesis);
        insertNumberInString(puntero,largoInicio,output,pFin);
    }
    return flag;
}

int terminos(char* puntero){
    int index,flag=-1;
    int largoInicio=0,largoTermino=0;
    char *pAux, *pInicio=puntero, *pFin;
    float output;
    for(int i=0;i<TAM;i++){
        pAux=puntero+i;
        index=*pAux;
        largoTermino++;
        if(index=='+'||index=='-'){
            if(largoTermino>0&&flag==1){
                if(!(*(pAux-1)=='*'||*(pAux-1)=='/'||*(pAux-1)=='^')){
                    pFin=pAux;
                    break;
                }
            }
            if(largoTermino>0&&flag!=1){
                largoInicio=largoInicio+largoTermino;
                largoTermino=0;
                pInicio=pAux+1;
            }
        }
        if(index=='*'||index=='/'||index=='^')
            {flag=1;}
        if(index=='\0'){
            pFin=pAux;
            break;
        }if(index==')'){
            pFin=pAux;
            break;
        }
    }
    if(flag!=-1){
        output=calculoTermino(pInicio,largoTermino);
        insertNumberInString(puntero,largoInicio,output,pFin);
    }
    return flag;
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
