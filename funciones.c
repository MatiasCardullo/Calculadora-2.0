#include <stdio.h>
#include <stdlib.h>

int validar(char* puntero){
    int index=0,flag=0,errorParentesis=0,errorSintax=0;
    for(int i=0;i<100;i++){
        index=*(puntero+i);
        if(index=='\0')
            {break;}
        if(index=='(')
            {errorParentesis++;}
        if(index==')')
            {errorParentesis--;}
        if(index=='*'||index=='/'){
            errorSintax++;
            if(errorSintax>1){
                if(flag!=-3){
                    printf("Error de sintaxsis: \"%c%c\"",*(puntero+i-1),index);
                    flag=-3;
                }else{printf(", \"%c%c\"",*(puntero+i-1),index);}
            }
        }else{errorSintax=0;}
        if(!(index>39&&index<58)){
            if(flag!=-1){
                printf("Error, caracteres invalidos: %c",index);
                flag=-1;
            }else{printf(", %c",index);}
        }
    }
    if(errorParentesis!=0)
            {printf("Error, faltan o sobran parentesis");flag=-2;}
    if(flag<0)
        {printf("\n\n");system("pause");}
    return flag;
}

int potencia(int numero, int potencia){
    int resultado=1;
    if(potencia>0){
        for(int i=0;i<potencia;i++)
            {resultado=resultado*numero;}
    }return resultado;
}
