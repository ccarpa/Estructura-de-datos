#include<stdio.h>
#include<stdlib.h>

typedef struct COLA{
    char caracter;
    struct COLA *siguiente;

}tipo;

typedef tipo *pNODO;


void insertar(pNODO *, pNODO *, char);
char leer(pNODO *, pNODO *);
void visualizar(pNODO *);
int introducirDato();
char introducirC(pNODO *,pNODO *);
int buscar(pNODO *, char);

int main()
{
   pNODO cPrimero1=NULL;
   pNODO cSegundo1=NULL;
   pNODO cPrimero2=NULL;
   pNODO cSegundo2=NULL;

   int b;
   int fin=1;
   char caracter,car;

   do {
      menu();

      switch(introducirDato())
      {
          case 1:
             system("CLS");
             printf("Introducir caracteres(Finalizar con 1)\n");
             printf("________________________________________\n");

             introducirC(&cPrimero1,&cSegundo1);

             printf("\n       Elementos de la Cola-1\n");
             printf("______________________________________\n");

             visualizar(&cPrimero1);
             fflush(stdin);
             printf("\nPresione una tecla para continuar...");
             getchar();
             system("CLS");
             break;
          case 2:
             system("CLS");
             printf("\n       Elementos de la Cola-1\n");
             printf("______________________________________\n");
             visualizar(&cPrimero1);

             do{
                car=leer(&cPrimero1,&cSegundo1);
                if(buscar(&cPrimero2,car)==0)
                {
                   insertar(&cPrimero2,&cSegundo2,car);

                }
               }while(car!='\0');
             printf("\n       Elementos de la Cola-2\n");
             printf("______________________________________\n");
             visualizar(&cPrimero2);
             fflush(stdin);
             printf("\nPresione una tecla para continuar...");
             getchar();
             system("CLS");

             break;
          case 3:
             system("CLS");
             fin =0;
             fflush(stdin);
             break;
      }

   }while(fin==1);


   printf("\nPresione una tecla para Finalizar...");
   getchar();
   return 0;
}

void menu()
{
   printf("______________________________\n");
   printf("        Menu principal        \n");
   printf("Cola-1.....................[1]\n");
   printf("Impresion..................[2]\n");
   printf("Salir......................[3]\n");
   printf("______________________________\n");
}

int introducirDato()
{
   int a,b;
   do{
     do{
        b=0;
        printf("Accion a realizar: ");
        fflush(stdin);
        if(!scanf("%d",&a))
        {
            b=1;
            printf("Advertencia:\"Solo acepta los digitos del 1 al 4 Introducir de nuevo\"\n");
        }
       }while(b==1);
       if(!(a>=1&&a<=4))
       {
           printf("Advertencia:\"Solo acepta los digitos del 1 al 4 Introducir de nuevo\"\n");
       }

     }while(!(a>=1&&a<=4));

   return a;
}

char introducirC(pNODO *primero,pNODO *segundo)
{
    char a;
    do{
    do{
    printf("Introducir caracter: ");
    fflush(stdin);
    scanf("%c",&a);
    if(!((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a=='1')))
    {
        printf("Nota:\"Introducir solo caracteres del alfabeto vuelve a introducir caracter\"\n");
    }
    }while(!((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a=='1')));
    if(a!='1')
    {
        insertar(&primero,&segundo,a);
    }

    }while(a!='1');

    return a;
}

void insertar(pNODO *primero,pNODO *ultimo,char a)
{
    pNODO nuevo;
    nuevo=malloc(sizeof(tipo));
    nuevo->caracter=a;
    nuevo->siguiente=NULL;

    if(*ultimo)
    {
        (*ultimo)->siguiente =nuevo;
    }
     *ultimo=nuevo;



    if(!*primero)
    {
        *primero=nuevo;
    }

}

char leer(pNODO *primero,pNODO *ultimo)
{
    pNODO nuevo;
    char a;
    nuevo = *primero;
    if(!nuevo) return '\0';

    *primero=nuevo->siguiente;
    a=nuevo->caracter;
    free(nuevo);

    if(!*primero)
    *ultimo =NULL;

    return a;


}

void visualizar(pNODO *a)
{
    pNODO aux;

    if(!*a)
    {
       printf("Nota:\"No tiene elemento la cola\"\n");
    }

    aux=*a;

    while(aux)
    {
        printf("%c\n",aux->caracter);
        aux=aux->siguiente;
    }
}

int buscar(pNODO *dd, char a)
{

    pNODO aux;
    aux = *dd;
    if(!aux) return 0;

    while(aux)
    {
        if(aux->caracter == a)
        {
            return 1;
            break;
        }

     aux = aux->siguiente;
    }
    return 0;
}
