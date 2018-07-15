#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#ifdef __linux__
#define CLEAN "CLEAR"
#endif

#ifdef __WIN32__
#define CLEAN "CLS"
#endif

char menu();

int operacionCombinada();

int validar(char*);

double potencia(double,double);

double *seteadorNumeros(char*,int);

void insertNumberInString(char*,int,double,char*);

double calculoSimple(char*,int);

double calculoTermino(char*,int);

int parentesis(char*);

int terminos(char*);

int isFloat(float);

#endif // FUNCIONES_H_INCLUDED
