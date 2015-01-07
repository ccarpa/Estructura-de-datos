/* Registro de un hotel */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Estructura que tiene el contenido utilizado*/

struct cliente{

   char nombreCliente[30];
   int habitacion;
   struct cliente *next;

};

/*Creacion del nodo*/

typedef struct cliente NODO;
typedef NODO *pNODO;

/* Funciones utilizadas en el programa */

void insertar(pNODO*,char* ,int);
int eliminar(pNODO*, int);
void menu();
void imprimir(pNODO);
pNODO buscar(pNODO*, int);
int verificacionNumero(char[]);
char introducirDato();
int eliminar2(pNODO*);

/*Funcion main*/

int main()
{
   pNODO lista = NULL;
   pNODO list = NULL;
   int aux1,lis;
   char a;
   char habit[30];
   char cliente[30];

   do
   {
       menu();
       a = introducirDato();
       switch(a)
       {

           case '1':
              system("CLS");
              printf("     \"Registro de Cliente\"\n");
              printf("______________________________\n");


                 printf("Nombre del Cliente: ");
                 gets(cliente);
              do{
                printf("Habitacion: ");
                scanf("%s",habit);
                }while(verificacionNumero(habit)==0);

               aux1 = atoi(habit);

              if((list=buscar(&lista,aux1))==NULL){
                  insertar(&lista,cliente,aux1);
              }
              else{
                  printf("\nNota: \"La habitacion ya esta ocupada por favor vuelva a registrar\"\n");
              }

              system("PAUSE");
              system("CLS");
              break;
           case '2':
               system("CLS");

               if(lista==NULL)
               {
                   printf("Nota:\"La lista esta vacia\"\n");
               }
               else
               {
               imprimir(lista);
               printf("______________________________\n");
               printf("       Eliminar Habitacion    \n");
               printf("------------------------------\n");
               do{
                  printf("Habitacion: ");
                  scanf("%s",habit);
                 }while(verificacionNumero(habit)==0);

               aux1 = atoi(habit);

               if((list=buscar(&lista,aux1))==NULL)
               {
                  printf("\nNota: \"La habitacion solicitada no esta en lista\"\n");
               }
               else{
                   if(eliminar(&lista,aux1)){
                       if(eliminar2(&lista)==0)
                       {
                               free(lista);
                               lista =NULL;
                       }
                            }
                   printf("\nNota: \"Habitacion %d fue eliminada de la lista\"\n",aux1);

               }
               }
              system("PAUSE");
              system("CLS");
              break;
           case '3':

                  imprimir(lista);
                  system("PAUSE");
                  system("CLS");

              break;
           case '4':
              a = '0';
              printf("\"Fin del programa\"");
              break;
       }
   }while(a !='0');

}

/*Menu principal*/

void menu()
{
   printf("______________________________\n");
   printf("       Registro del hotel     \n");
   printf("Registrar Cliente..........[1]\n");
   printf("Eliminar Cliente...........[2]\n");
   printf("Lista de Clientes..........[3]\n");
   printf("Salir......................[4]\n");
   printf("______________________________\n");

}

/* Funcion para insertar nuevo registro*/

void insertar(pNODO *lista, char* valor,int a)
{
    pNODO nuevo,pre;
    pre=*lista;
    nuevo = malloc(sizeof(NODO));
        if (nuevo != NULL)
        {
            if(pre==NULL)
            {
                strcpy((nuevo->nombreCliente),valor);
                nuevo->habitacion = a;
                nuevo->next = NULL;
                *lista = nuevo;
            }
            else
            {
                strcpy((nuevo->nombreCliente),valor);
                nuevo->habitacion = a;
                nuevo->next = NULL;
                nuevo -> next = *lista;
                *lista = nuevo;
            }
}
}

/*Funcion para introducir dato en el menu principal*/

char introducirDato()
{
   char ch;

   do{

      printf("\nAccion a realizar: ");
      fflush(stdin);
      ch = getche();
      if(!(ch>='1'&& ch<='5'))
      {
          printf("Nota: \n\"Inserte un digito correcto\"");
      }
      printf("\n");

   }while(!(ch>='1'&& ch<='5'));


   return ch;
}

/*Funcion para imprimir los registros*/

void imprimir(pNODO actual)
{
	pNODO aux,pre;
    NODO c;
    int i=1;

    system("cls");

	if (actual == NULL)

		printf("Nota: \"La lista no tiene Registros\"\n\n");

	else
	{

	    aux = actual;
	    while( aux != NULL )
	    {
          pre = actual;

	      while( pre!=NULL )
	      {
	        if(strcmpi(aux->nombreCliente,pre->nombreCliente)<0)
            {

            strcpy((c.nombreCliente),(aux->nombreCliente));
            c.habitacion = aux->habitacion;
            strcpy(aux->nombreCliente,pre->nombreCliente);
            aux->habitacion = pre->habitacion;
            strcpy(pre->nombreCliente,c.nombreCliente);
            pre->habitacion = c.habitacion;

            }

	        pre=pre->next;

	      }

	      aux=aux->next;

	    }

	    system("cls");
	    printf("______________________________\n");
		printf("Lista de Registros: \n\n");

        printf("Clientes:\tHabitaciones:\n");
		while (actual != NULL) {
		printf("------------------------------\n");
		printf("Registro #%d\n",i);
        printf("  %s\t\t%d\n",actual->nombreCliente,actual->habitacion);
        actual = actual -> next;
        printf("------------------------------\n");
        i++;
		}
	}

}

/*Verificar que un cadena de caracteres sea puros numeros*/

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

/*Elimina registros*/

int eliminar(pNODO *auxi, int b)
{
    int a= 1;
    pNODO previo,actual,temporal;
    previo = NULL;
    previo = *auxi;
	actual = (*auxi) -> next;
	while (actual != NULL && actual -> habitacion != b){
		previo = actual;
		actual = actual -> next;
	}
	if (actual != NULL) {
		temporal = actual;
		previo -> next = actual -> next;
		free(temporal);
		a=0;
		return a;
	}
	if(a=0){}
	else{
	return 1;}
}

/*Funcion para buscar un registro en la lista*/

pNODO buscar(pNODO *lista, int a)
{

    pNODO aux;
    aux = *lista;
    while(aux !=  NULL)
    {
        if(aux->habitacion == a)
        {
            return aux;
            break;
        }

     aux = aux->next;
    }
    return NULL;
}

/*Funcion para eliminar al principio de la lista*/

int eliminar2(pNODO *lista)
{
 pNODO temporal,previo;

	previo= (*lista)-> next;
	if (previo != NULL) {
		temporal = *lista;
		*lista = (*lista) -> next;
		free(temporal);
		return 1;
	}
	return 0;
}

