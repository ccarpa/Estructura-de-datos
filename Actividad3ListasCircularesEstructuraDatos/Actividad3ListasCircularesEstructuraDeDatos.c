/*Estructura De Datos*/
/*Actividad 3 Listas Circulaes*/

/*Jaime Arturo Acosta Jacinto*/

#include <stdlib.h>
#include <stdio.h>


/*Estructura que tiene el contenido utilizado*/
typedef struct Circular {
   char elemento;
   struct Circular *next;
} grupo;

typedef grupo *ptrNodo;
typedef grupo *Lista;

// Funciones con listas.
void insertar(Lista *, char );
void eliminar(Lista *, char );
void mostrar(Lista );


//Funcionea utilizadas.
void menu();
char introducirDato();

/*Función main*/
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
                printf("_______________________________\n");
                printf("      \"Insertar Elemento\"\n\n");
                printf("Introducir elemento: ");
                scanf("%c",&b);

                insertar(&lista,b);

                system("PAUSE");
                system("CLS");
                break;

            case '2':
                system("CLS");

                if(lista!=NULL)
                {
                   printf("_______________________________\n");
                   printf("      \"Eliminar Elemento\"\n\n");
                   mostrar(lista);
                   printf("\n");
                   printf("Elemento a Eliminar: ");
                   scanf("%c",&c);

                   eliminar(&lista,c);
                   printf("\n");

                }

                mostrar(lista);

                system("PAUSE");
                system("CLS");
                break;

            case '3':
                system("CLS");
                mostrar(lista);
                system("PAUSE");
                system("CLS");
                break;

            case '4':
                system("CLS");
                printf("      \"Fin del programa\"\n");
                printf("_______________________________");

                a='\0';

                break;
       }
   }while(a!='\0');

   return 0;

}

void menu()
{
    printf("      \"Listas Circules\"      \n");
    printf("_______________________________\n");
    printf("Insertar Elemento...........[1]\n");
    printf("Eliminar Elemento...........[2]\n");
    printf("Mostrar Lista...............[3]\n");
    printf("Salir.......................[4]\n");
    printf("_______________________________\n");
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


/*Función que te permite insertar elementoa wn la lista*/
void insertar(Lista *lista, char d)
{
   ptrNodo nuevo;

   nuevo = (ptrNodo)malloc(sizeof(grupo));
   nuevo->elemento = d;

   if(!(*lista))
   {
        *lista = nuevo;
   }
   else
   {
        nuevo->next = (*lista)->next;
   }

   (*lista)->next = nuevo;
}

/*Funcion para eliminar elementos de la lista*/

void eliminar(Lista *lista, char d)
{
   ptrNodo nuevo;

   nuevo = *lista;
   if(!nuevo)
   {
       printf("\"La Lista esta Vacia\"");
   }
   else
   {
   do {

      if((*lista)->next->elemento != d)
        *lista = (*lista)->next;

      }while((*lista)->next->elemento != d && *lista != nuevo);

   if((*lista)->next->elemento == d)
   {
      if(*lista == (*lista)->next)
      {
         free(*lista);
         *lista = NULL;
      }
      else
      {
         nuevo = (*lista)->next;
         (*lista)->next = nuevo->next;
         free(nuevo);
      }
   }
   }
}

/*Función para mostrar los elementoss de la lista en pantalla*/

void mostrar(Lista lista)
{
   ptrNodo nuevo = lista;
   if(!nuevo)
   {
       printf("\"Lista vacia\"");
   }
   else
   {
      printf("_______________________________\n");
      printf("      \"Elementos de Lista\"\n\n");
      do {
        printf(" -> %c", nuevo->elemento);
        nuevo = nuevo->next;
      }while(nuevo != lista);
   }
   printf("\n");
}

