/*Evaluar expresion postfija*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 40

/*Pila*/
struct PILA1{
    char elemento;
    struct PILA1*sig;
};

typedef struct PILA1 PILA;
typedef PILA *NODO;

/*Declaración de funciones*/
void push(NODO*, char);
int pop(NODO*);

/*Función principal*/
int main(){
    NODO pila=NULL;

    char pp[M]={""};
    int i=0;
    char AUX1,AUX2,a=0;
    printf("___________________________________________________________\n");
    printf("\t      Evaluar una expresion posfija\n");
    printf("___________________________________________________________\n");
    printf("Solo acepta estas letras:\n");
    printf("a=1\nb=2\nc=3\nd=4\ne=5\n");
    printf("Introduccir Expresion postfija (Solo en notacion postfija): \n");

    gets(pp);

   while(pp[i] != '\0')
   {
       if(!ispunct(pp[i]))
       {
          push(&pila, pp[i]);
       }
       else
       {
          AUX1=pop(&pila);

          switch(AUX1)
          {
              case 'a':
                 AUX1=1;
                 break;
              case 'b':
                 AUX1=2;
                 break;
              case 'c':
                 AUX1=3;
                 break;
              case 'd':
                 AUX1=4;
                 break;
              case 'e':
                 AUX1=5;
                 break;
              default:
                 break;
          }

            AUX2=pop(&pila);
            switch(AUX2)
            {
                case 'a':
                   AUX2=1;
                   break;
                case 'b':
                   AUX2=2;
                   break;
                case 'c':
                   AUX2=3;
                   break;
                case 'd':
                   AUX2=4;
                   break;
                case 'e':
                   AUX2=5;
                   break;
                default:
                   break;
            }

        if(pp[i]=='^')
        {
           a=pow(AUX2,AUX1);
        }

        if(pp[i]=='*')
           a=AUX1*AUX2;
        if(pp[i]=='/')
           a=AUX2/AUX1;
        if(pp[i]=='+')
           a=AUX1+AUX2;
        if(pp[i]=='-')
           a=AUX2-AUX1;



        push(&pila, a);
    }
       i++;
    }
    printf("Resultado: %d\n", a);
    printf("___________________________________________________________\n");
    return 0;
}

/*Insertar elemento en la pila*/
void push(NODO*pila, char valor)
{
    NODO nuevo;
    nuevo = malloc(sizeof(PILA));
    if(nuevo!=NULL)
    {
        nuevo->elemento=valor;
        nuevo->sig=NULL;
        nuevo->sig=*pila;
        *pila=nuevo;
    }
}


/*Eliminar elemento de la pila*/
int pop(NODO *pila)
{
    char a;
    NODO temp, pre;
    pre=(*pila)->sig;
    if(pre!=NULL)
    {
        temp=*pila;
        a=(*pila)->elemento;
        *pila=(*pila)->sig;
        free(temp);
        return a;
    }
        pre=(*pila);
        if(pre!=NULL)
        {
           temp=*pila;
           a=(*pila)->elemento;
           *pila=(*pila)->sig;
           free(temp);
           return a;
        }
        return '\0';
}
