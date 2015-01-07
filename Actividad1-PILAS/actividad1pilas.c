#include <stdlib.h>
#include <stdio.h>

typedef struct PILA {
   int valor;
   struct PILA *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;


void Push(Pila *);
int Pop(Pila *);
void menu();
void menupila1();
char introducirDato();
char introducirDato2();
int verificacionNumero(char []);
void imprimir(Pila );
int mezclarpilas(Pila , Pila, Pila *);




int main()
{
   Pila pila = NULL;
   Pila pila2 = NULL;
   Pila pila3 = NULL;

   int a=1;
   int b,num;

   do{
      menu();
      switch (introducirDato())
      {
          case '1':
             b=1;
             do{
                system("CLS");
                printf("______________________________\n");
                printf("           Pila-1             \n");
                menupila1();
                switch(introducirDato2())
                {
                   case '1':
                      Push(&pila);
                      break;

                   case '2':
                      Pop(&pila);

                      break;

                   case '3':
                      printf("Elementos Pila-1\n");
                      imprimir(pila);
                      b=0;
                      break;

                 }
                 }while(b==1);
             printf("\n");
             system("PAUSE");
             system("CLS");

             break;

          case '2':
             b=1;
             do{
                system("CLS");
                printf("______________________________\n");
                printf("           Pila-2             \n");
                menupila1();
                switch(introducirDato2())
                {
                   case '1':
                      Push(&pila2);
                      break;

                   case '2':
                      Pop(&pila2);

                      break;

                   case '3':
                      printf("Elementos Pila-2\n");
                      imprimir(pila2);
                      b=0;
                      break;

                 }
                 }while(b==1);
                 printf("\n");
                 system("PAUSE");
                 system("CLS");

             break;

          case '3':
             system("CLS");
             printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
             printf("Elementos Pila-1\n");
             printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
             imprimir(pila);
             printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
             printf("Elementos Pila-2\n");
             printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
             imprimir(pila2);
             num = mezclarpilas(pila,pila2,&pila3);
             printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
             printf("Elementos Pila-3\n");
             printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
             imprimir(pila3);
             printf("\n\nNumero de Elementos en la Pila-3: %d\n",num);
             pila=NULL;
             pila2=NULL;
             pila3=NULL;

             printf("\n");
             system("PAUSE");
             system("CLS");
             break;


          case '4':
             system("CLS");
             a=0;
             break;

      }

   }while(a==1);



   return 0;
}

void menu()
{
   printf("______________________________\n");
   printf("        Menu principal        \n");
   printf("Pila-1.....................[1]\n");
   printf("Pila-2.....................[2]\n");
   printf("Impresion..................[3]\n");
   printf("Salir......................[4]\n");
   printf("______________________________\n");

}

void menupila1()
{
   printf("Agregar....................[1]\n");
   printf("Eliminar...................[2]\n");
   printf("Regresar...................[3]\n");
   printf("______________________________\n");

}


char introducirDato()
{
   char ch;

   do{

      printf("\nAccion a realizar: ");
      fflush(stdin);
      ch = getche();
      if(!(ch>='1'&& ch<='4'))
      {
          printf("Nota: \n\"Inserte un digito correcto\"");
      }
      printf("\n");

   }while(!(ch>='1'&& ch<='4'));

   return ch;
}

char introducirDato2()
{
   char ch;

   do{

      printf("\nAccion a realizar: ");
      fflush(stdin);
      ch = getche();
      if(!(ch>='1'&& ch<='3'))
      {
          printf("Nota: \n\"Inserte un digito correcto\"");
      }
      printf("\n");

   }while(!(ch>='1'&& ch<='3'));

   return ch;
}

int verificacionNumero(char a[10])
{
    int i=0;
    while(a[i]!= '\0')
    {
        if(a[i]>='0' && a[i]<='9')
        {
        }
        else
        {
            return 0; break;
        }
        i++;
    }
    return 1;
}

void Push(Pila *pila)
{
   pNodo nuevo;
   char elemento[20];
   int numero;

   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   if(nuevo!=NULL)
   {
      do {
         printf("Introducir elemento: ");
         scanf("%s",elemento);
        }while(verificacionNumero(elemento)==0);

   numero=atoi(elemento);
   nuevo->valor= numero;
   nuevo->siguiente = *pila;
   *pila = nuevo;

   }

}

int Pop(Pila *pila)
{
   int a;
   pNodo nodo;

   nodo = *pila;
   if(!nodo)
      return 0;

   *pila = nodo->siguiente;
   a = nodo->valor;
   free(nodo);

   return a;
}

int mezclarpilas(Pila pila1, Pila pila2, Pila *pila3)
{
    int a=0,aux1,aux2;
    if(pila1==NULL&&pila2==NULL)
    {
        printf("Nota: \"La pila esta vacia\"");
    }
    else{
        while((pila1!=NULL)||(pila2!=NULL))
        {
            if(pila1!=NULL)
            {
                  pNodo nuevo;
                  nuevo = (pNodo)malloc(sizeof(tipoNodo));
                  nuevo->siguiente = *pila3;
                  *pila3 = nuevo;
                  nuevo->valor= Pop(&pila1);
                  aux1=nuevo->valor;
                  a++;
            }

            if(pila2!=NULL)
            {
                  if((aux1)!=(aux2=Pop(&pila2)))
                  {
                     pNodo nuevo;
                     nuevo = (pNodo)malloc(sizeof(tipoNodo));
                     nuevo->siguiente = *pila3;
                     *pila3 = nuevo;
                     nuevo->valor=aux2;
                     a++;
                  }
            }

        }

    }
    return a;

}

void imprimir(Pila pila)
{
    int i=1;
    if (pila == NULL)
    {
		printf("Nota: \"La Pila no tiene elementos\"\n");
    }
    else
    {
       while(pila != NULL)
       {
          printf("\nElemento %d: %d",i , pila->valor);
          i++;
          pila = pila->siguiente;
       }
    }

}
