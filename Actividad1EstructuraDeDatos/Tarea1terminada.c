/*Tienda de articulos deportivos*/

#include<stdio.h>
#include<stdlib.h>


/* Estructura que tiene el contenido utilizado */
struct producto{

   int codigo; /* Es el dato del código del artículo*/
   int cantidad; /* Es el dato de la cantidad de dicho artículo*/
   int precio; /*Es el dato que nos indica el precio*/
   struct producto *next; /*Es el enlace con el siguiente nodo*/

};

typedef struct producto NODO; /*Definición de la estructura como tipo de dato*/
typedef NODO *pNODO; /*Tipo de dato que genera los nodos de la lista en cadenada*/

/* Funciones a utilizar*/

void insertar(pNODO*,int,int,int);
int eliminar(pNODO*, int);
void menu();
void imprimir(pNODO);
void imprimirFinal(pNODO,int);
pNODO buscar(pNODO*,int);
int verificacionNumero(char[]);
char introducirDato();
char introducirDato2();
int eliminar2(pNODO *);

/*Funcion main */
int main()
{

    pNODO lista = NULL;
    pNODO list = NULL;
    int aa=0;
    int pp=0;
    int aux1,aux2,aux3;
    char codigo1[30];
    char cantidad1[30];
    char precio1[30];
    char sal;


       do{
       menu();
       sal =introducirDato();
       switch(sal)
       {
           case '1':
             system("CLS");
             printf("\t  \"Producto\"\n");
             printf("______________________________\n");
              do{
                 printf("Codigo: ");
                 scanf("%s",codigo1);
              }while(verificacionNumero(codigo1)==0);

                 aux1 = atoi(codigo1);

              if((list=buscar(&lista,aux1))==NULL){
              do{
                 printf("Cantidad: ");
                 scanf("%s",cantidad1);
              }while(verificacionNumero(cantidad1)==0);

                 aux2 = atoi(cantidad1);

              do{
                 printf("Precio: ");
                 scanf("%s",precio1);
              }while(verificacionNumero(precio1)==0);
              printf("______________________________\n");
                 aux3 = atoi(precio1);

                       insertar(&lista,aux1,aux2,aux3);

              }
              else
              {
                 list->cantidad = list->cantidad+1;

              }
                 imprimir(lista);
                 system("PAUSE");
                 system("CLS");
              break;
           case '2':
              system("CLS");
              imprimir(lista);
              printf("\n\n\"Producto devuelto\"\n");
              printf("______________________________\n");
              printf("Modo de devolucion\n");
              printf("1.Una pieza.\n2.Completo\n");

              switch(introducirDato2())
              {
                  case '1':
                     if(lista != NULL)
                     {
                         do{
                            printf("Codigo: ");
                            scanf("%s",codigo1);
                            printf("______________________________\n");
                         }while(verificacionNumero(codigo1)==0);

                            aux1 = atoi(codigo1);

                            if((list=buscar(&lista,aux1))==NULL)
                            {
                                printf("\"El producto solicitado no esta en lista\"\n");
                            }
                            else{
                                list->cantidad = list->cantidad-1;

                                if((list->cantidad)==0)
                                {
                                    if(eliminar(&lista,aux1)){
                                       free(lista);
                                       lista = NULL;
                                    }
                                }
                            }

                     }
                     else{
                        printf("\"La Lista esta vacia\"\n");
                     }

                     imprimir(lista);

                     if(lista != NULL)
                     {
                        aa++;

                     }
                     system("PAUSE");
                     system("CLS");
                     break;

                  case '2':
                     if(lista!=NULL)
                     {
                         do{
                            printf("Codigo: ");
                            scanf("%s",codigo1);
                         }while(verificacionNumero(codigo1)==0);

                            aux1 = atoi(codigo1);

                            if((list=buscar(&lista,aux1))==NULL)
                            {
                                printf("\"El producto solicitado no esta en lista\"\n");
                            }
                            else
                               if(eliminar(&lista,aux1)){
                                   if(eliminar2(&lista)==0)
                                   {
                                      free(lista);
                                      lista = NULL;
                                   }

                               }

                          imprimir(lista);
                     }
                     else{
                        printf("\"La Lista esta vacia\"\n");
                     }
                     if(lista!=NULL)
                     {
                        aa= aa + list->cantidad;

                     }

                     system("PAUSE");
                     system("CLS");
                     break;

              }
              break;
           case '3':
              system("CLS");
              imprimirFinal(lista,aa);
              printf("\n");
              system("PAUSE");
              system("CLS");
              break;
           case '4':
              sal = '0';
              break;

       }
       }while(sal != '0');
}


/*Funcion para introducir el numero en el switch 1 del main*/
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

/*Funcion para introducir el numero en el switch*/

char introducirDato2()
{
   char ch;

   do{
      printf("\nIntroducir Modo: ");
      fflush(stdin);
      ch = getche();
      if(!(ch>='1'&& ch<='2'))
      {
         printf("\n\"Introducir digito correcto\"");
      }
      printf("\n");
   }while(!(ch>='1'&& ch<='2'));


   return ch;
}

/* Menu principal*/

void menu()
{
   printf("______________________________\n");
   printf("Tienda de articulos deportivos\n");
   printf("Venta......................[1]\n");
   printf("Devolucion.................[2]\n");
   printf("Reporte....................[3]\n");
   printf("Salir......................[4]\n");
   printf("______________________________\n");


}

/*Funcion para insertar nuevos productos*/

void insertar(pNODO *lista, int co, int ca, int pe)
{
    pNODO nuevo,pre,act;
    nuevo = malloc(sizeof(NODO));
    if(*lista == NULL)
    {
       if(nuevo != NULL)
       {
          nuevo->codigo = co;
          nuevo->cantidad = ca;
          nuevo->precio = pe;
          nuevo->next = NULL;
          nuevo->next = *lista;
          *lista = nuevo;
       }
    }
    else
    {
        nuevo->codigo = co;
        nuevo->cantidad = ca;
        nuevo->precio = pe;
        nuevo->next = NULL;

        act =*lista;
        pre = NULL;

        if(co < act->codigo)
        {
            nuevo->codigo = co;
            nuevo->cantidad = ca;
            nuevo->precio = pe;
            nuevo->next = NULL;
            nuevo->next = *lista;
            *lista = nuevo;
        }
        else {
            while(act != NULL && co > act->codigo)
            {
                  pre = act;
                  act = act->next;


            }
                  pre->next=nuevo;
                  nuevo->next=act;
    }
    }
}

/*Fucion para imprimir */

void imprimir(pNODO actual)
{
    int i=1;
    if(actual == NULL)
    {
    }
    else{
       printf("\nReporte: \n");
       while(actual != NULL)
       {
           printf("-----------------------------\n");
           printf("\nProducto #%d\n",i);
           printf("Codigo: %d\n",actual->codigo);
           printf("Cantidad: %d\n",actual->cantidad);
           printf("Presio: %d\n",actual->precio);
           printf("-----------------------------\n");
           actual=actual->next;
           i++;
       }
    }
}

/*Funcion para imprimir reporte final*/

void imprimirFinal(pNODO actual,int a)
{
    int i=1;
    int totalprecio = 0;
    int cantidadtotal = 0;
    if(actual == NULL)
    {
        printf("\"La Lista esta vacia \"\n\n");
    }
    else{
       printf("\nReporte: \n");
       while(actual != NULL)
       {
           printf("-----------------------------\n");
           printf("\nProducto #%d\n",i);
           printf("Codigo: %d\n",actual->codigo);
           printf("Cantidad: %d\n",actual->cantidad);
           printf("Precio: %d\n",actual->precio);
           printf("-----------------------------\n");

           totalprecio= totalprecio+(actual->precio * actual->cantidad);
           cantidadtotal = cantidadtotal + actual->cantidad;
           i++;

           actual=actual->next;
       }
    }
       printf("Cantidad De Productos Vendidos: %d\n",cantidadtotal + a);
       printf("El Precio Total: %d\n",totalprecio);
       printf("Cantidad de productos devueltos: %d\n",a);
}

/*Funcion que permite buscar un producto de la lista*/

pNODO buscar(pNODO *lista, int a)
{

    pNODO aux;
    aux = *lista;
    while(aux !=  NULL)
    {
        if(aux->codigo == a)
        {
            return aux;
            break;
        }

     aux = aux->next;
    }
    return NULL;
}

/*Funcion que permite eliminar un producto de lista*/

int eliminar(pNODO *auxi, int b)
{
    int a= 1;
    pNODO previo,actual,temporal;
    previo = NULL;
    previo = *auxi;
	actual = (*auxi) -> next;
	while (actual != NULL && actual -> codigo != b){
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

/*Funcion que te permite verificar una cadena cualquiera que sea puros digitos*/

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
