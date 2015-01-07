/*Estructura De Datos*/
/*Actividad 4 Listas Doblemente Encadenadas*/

/*Jaime Arturo Acosta Jacinto*/
#include <stdio.h>
#include <stdlib.h>

/*Estructura que tiene el contenido*/

typedef struct DEncadenada {
   char elemento;
   struct DEncadenada *next;
   struct DEncadenada *back;
}grupo;

typedef grupo *pNodo;
typedef grupo *Lista;

/* Funciones con listas: */
void insertar(Lista *, char);
void eliminar(Lista *, char);
void mostrarLista(Lista);

/*Funciones utilizadas*/
void menu();
char introducirDato();

/*Funcion main*/
int main()
{
   Lista lista = NULL;
   char a,b,c;

   do
   {
       menu();
       a = introducirDato();

       switch(a)
       {
            case '1':
                system("CLS");
                printf("_____________________________________\n");
                printf("         \"Insertar Elemento\"\n\n");
                printf("Introducir elemento: ");
                scanf("%c",&b);

                insertar(&lista,b);
                mostrarLista(lista);
                system("PAUSE");
                system("CLS");
                break;

            case '2':
                system("CLS");

                if(lista!=NULL)
                {
                   printf("_____________________________________\n");
                   printf("         \"Eliminar Elemento\"\n\n");
                   mostrarLista(lista);
                   printf("\n");
                   printf("Eliminar elemento: ");
                   scanf("%c",&c);

                   eliminar(&lista,c);
                   printf("\n");

                }

                mostrarLista(lista);

                system("PAUSE");
                system("CLS");
                break;

            case '3':
                system("CLS");
                mostrarLista(lista);
                system("PAUSE");
                system("CLS");
                break;

            case '4':
                system("CLS");
                printf("        \"Fin del programa\"\n");
                printf("_____________________________________\n");

                a='\0';

                break;
       }
   }while(a!='\0');

   return 0;

}

/*Función de Menu de opciones*/

void menu()
{
    printf("   \"Listas Doblemente Encadenadas\"  \n");
    printf("_____________________________________\n");
    printf("Insertar Elemento.................[1]\n");
    printf("Eliminar Elemento.................[2]\n");
    printf("Mostrar Lista.....................[3]\n");
    printf("Salir.............................[4]\n");
    printf("_____________________________________\n");
}

/*Introducir el numero de inicio*/

char introducirDato()
{
   char ch;

   do{

      printf("\nAccion a realizar: ");
      fflush(stdin);
      ch=getche();
      if(!(ch>='1'&& ch<='4'))
      {
          printf("\n\"Inserte un digito correcto\"");
      }
      printf("\n");

   }while(!(ch>='1'&& ch<='4'));


   return ch;
}


/*Funcion para insertar elementos en la lista*/

void insertar(Lista *lista, char v)
{
   pNodo nuevo, actual;

   nuevo = (pNodo)malloc(sizeof(grupo));
   nuevo->elemento = v;
   actual = *lista;

   if(actual)
   {
        while(actual->back)
        {
            actual = actual->back;
        }
   }
   if(!actual || actual->elemento > v) {
      nuevo->next = actual;
      nuevo->back = NULL;

      if(actual)
      {
            actual->back = nuevo;
      }

      if(!*lista)
      {
            *lista = nuevo;
      }
   }
   else {
      while(actual->next &&actual->next->elemento <= v)
      {
            actual = actual->next;
      }

      nuevo->next = actual->next;
      actual->next = nuevo;
      nuevo->back = actual;

      if(nuevo->next)
      {
          nuevo->next->back = nuevo;
      }
   }
}

/*Funcion para eliminar elemento en la lista*/

void eliminar(Lista *lista, char v)
{
   pNodo nodo;

   nodo = *lista;

   while(nodo && nodo->elemento < v)
   {
       nodo = nodo->next;
   }

   while(nodo && nodo->elemento > v)
   {
       nodo = nodo->back;
   }

   if(!nodo || nodo->elemento != v)
   {
       return;
   }

   if(nodo == *lista)
   {
        if(nodo->back)
        {
            *lista = nodo->back;
        }
        else
        {
            *lista = nodo->next;
        }

   }

   if(nodo->back)
   {
      nodo->back->next = nodo->next;
   }

   if(nodo->next)
   {
      nodo->next->back = nodo->back;
   }

   free(nodo);
}

/*Funcion para mostrar la lista*/

void mostrarLista(Lista lista)
{
   pNodo nodo = lista;

   if(!lista)
   {
        printf("\"La Lista esta Vacia\"");
   }
   else{
      while(nodo->back)
      {

            nodo = nodo->back;
      }
      printf("\n     \"Elementos de la Lista\"      \n");
      printf("_____________________________________\n");
      while(nodo)
      {
         printf("-> %c", nodo->elemento);
         nodo = nodo->next;
      }

   }

   printf("\n");
}
