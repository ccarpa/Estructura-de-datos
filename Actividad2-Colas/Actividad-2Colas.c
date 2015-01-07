#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Estructura para llenar la Longitud y Altitud*/
typedef struct aux{
    int grados;
    int minutos;
    int segundos;
    char orientacion[2];
}aux1;

/*La cola de los datos del avion*/
typedef struct COLA{
    char avion[30];
    aux1 longitud;
    aux1 latitud;
    struct COLA *siguiente;
}tipo;

typedef tipo *Cola;

/*Funcion a utilizar*/
int introducirDato();
void menu();
void insertar(Cola *,Cola *,char [] ,int , int , int , char [],int ,int, int, char []);
int extraer(Cola *,Cola *);
void introducirDatosA(Cola *,Cola *);
void mostrarCola(Cola );
int introducirC(char []);
int identificarNS(char []);
int identificarEO(char []);
void visualizar(Cola *);

/*Funcion principal*/
int main()
{
    Cola cprimero=NULL,cultimo=NULL;
    int a=1;
    do{
       menu();

       switch(introducirDato())
       {
           case 1:
              system("CLS");
              introducirDatosA(&cprimero,&cultimo);
              printf("\n");
              system("PAUSE");
              system("CLS");
              break;
           case 2:
              system("CLS");
              if(extraer(&cprimero,&cultimo)==0)
              {
                  printf("Nota:\"No hay aviones\"\n");
              }
              printf("\n");
              system("PAUSE");
              system("CLS");
              break;
           case 3:
              system("CLS");
              visualizar(&cprimero);
              printf("\n\n");
              system("PAUSE");
              system("CLS");
              break;
           case 4:
              system("CLS");
              a=0;
              break;

       }
    }while(a==1);

    printf("Fin del programa...");
    fflush(stdin);
    getchar();

    return 0;

}

/*Comprobar caracteres alfanumerico*/
int introducirC(char a[30])
{
    int i=0;

    while(a[i]!='\0')
    {
        if(!((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')))
        {
            return 0;
            break;

        }
    i++;
    }

    return 1;
}

/*Comprobar N o S para la LONGITUD*/
int identificarNS(char a[4])
{
    int i=0;

    while(a[i]!='\0')
    {
        if(!((a[i]=='N')||(a[i]=='S')))
        {
            return 0;
            break;

        }
    i++;
    }

    return 1;
}

/*Comprobar E o O para ALTITUD*/
int identificarEO(char a[2])
{
    int i=0;

    while(a[i]!='\0')
    {
        if(!((a[i]=='E')||(a[i]=='O')))
        {
            return 0;
            break;

        }
    i++;
    }

    return 1;
}
/*Introduce todos los datos del Avión*/
void introducirDatosA(Cola *colaP,Cola *colaU)
{
    int a=1,gra1,min1,seg1,gra2,min2,seg2;
    char oriet1[2],oriet2[2],ident[30];

    printf("___________________________________\n");
    printf("          Datos del Avion\n");
    printf("-----------------------------------\n");
       do {
          printf("Identificar: ");
          fflush(stdin);
          scanf("%s",ident);
          }while(introducirC(ident)==0);
    printf("---------------------------------------------\n");
    printf("Nota:\"Para la Orientacion utilizamos:\"\n\n");

    printf("Longitud:\n");
    printf("---------------------------------------------\n\n");
    printf("Norte->N\n");
    printf("Sur->S\n\n");

    printf("Latitud:\n");
    printf("---------------------------------------------\n\n");
    printf("Este->E\n");
    printf("Oeste->O\n\n");
    printf("-----------------------------------\n");
    printf("Longitud:\n");
    printf("-----------------------------------\n");

    do{
    do{
       printf(" Grados: ");
       fflush(stdin);
       }while(!scanf("%d",&gra1));
    }while(!(gra1>=0&&gra1<=360));
    do{
     do{
       printf(" Minutos: ");
       fflush(stdin);
       }while(!scanf("%d",&min1));
    }while(!(min1>=0&&min1<=60));
    do{
    do{
       printf(" Segundos: ");
       fflush(stdin);
       }while(!scanf("%d",&seg1));
    }while(!(seg1>=0&&seg1<=60));
    do{
       printf(" Orientacion: ");
       fflush(stdin);
       scanf("%s",oriet1);
      }while(identificarNS(oriet1)==0);
    printf("-----------------------------------\n");
    printf("Latitud:\n");
    printf("-----------------------------------\n");
     do{
    do{
       printf(" Grados: ");
       fflush(stdin);
       }while(!scanf("%d",&gra2));
    }while(!(gra2>=0&&gra2<=360));
    do{
     do{
       printf(" Minutos: ");
       fflush(stdin);
       }while(!scanf("%d",&min2));
    }while(!(min2>=0&&min2<=60));
    do{
    do{
       printf(" Segundos: ");
       fflush(stdin);
       }while(!scanf("%d",&seg2));
    }while(!(seg2>=0&&seg2<=60));
    do{
       printf(" Orientacion: ");
       fflush(stdin);
       scanf("%s",oriet2);
      }while(identificarEO(oriet2)==0);

    insertar(&(*colaP),&(*colaU),ident,gra1,min1,seg1,oriet1,gra2,min2,seg2,oriet2);

}
/*Muestra el Avión a despegar*/
void mostrarCola(Cola a)
{
    printf("-------------------------------------------------------\n");
    printf("Avion a despegar:\n");
    printf("-------------------------------------------------------\n");
    printf("Identificador: %s\n",a->avion);
    printf("Destino: Longitud= %d %d'%d''%s,Latitud= %d %d'%d''%s\n",a->longitud.grados,a->longitud.minutos,a->longitud.segundos,a->longitud.orientacion,a->latitud.grados,a->latitud.minutos,a->longitud.segundos,a->latitud.orientacion);

}


/*Menu principal*/
void menu()
{
   printf("______________________________\n");
   printf("        Menu principal        \n");
   printf("Insertar Avion.............[1]\n");
   printf("Extraer Avion..............[2]\n");
   printf("Mostrar cola...............[3]\n");
   printf("Salir......................[4]\n");
   printf("______________________________\n");
}

/*Acepta solo numero del 1 al 4 para el menu*/
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

/*Insertar Datos en la cola*/
void insertar(Cola *colaP,Cola *colaU,char avi[30],int gra, int min, int seg, char oriet[2],int gra2,int min2, int seg2, char oriet2[2])
{
    Cola nuevo;
    nuevo=malloc(sizeof(tipo));
       strcpy(nuevo->avion,avi);
       nuevo->longitud.grados=gra;
       nuevo->longitud.minutos=min;
       nuevo->longitud.segundos=seg;
       strcpy(nuevo->longitud.orientacion,oriet);
       nuevo->latitud.grados=gra2;
       nuevo->latitud.minutos=min2;
       nuevo->latitud.segundos=seg2;
       strcpy(nuevo->latitud.orientacion,oriet2);

       nuevo->siguiente=NULL;

       if(*colaU)
       {
          (*colaU)->siguiente =nuevo;
       }
         *colaU=nuevo;

       if(!*colaP)
       {
          *colaP=nuevo;
       }
}

/*Estraer elementos de la cola*/
int extraer(Cola *colaP,Cola *colaU)
{
    Cola nuevo;
    nuevo = *colaP;
    if(!nuevo) return 0;

    *colaP=nuevo->siguiente;

    mostrarCola(nuevo);
    free(nuevo);

    if(!*colaP)
    *colaU =NULL;

}

/*Muestra toda la Cola*/
void visualizar(Cola *a)
{
    Cola aux;

    if(!*a)
    {
       printf("Nota:\"No Hay Aviones\"\n");
    }

    aux=*a;
    if(*a)
    {
       printf("-------------------------------------------------------\n");
       printf("Aviones en espera:\n");
       printf("-------------------------------------------------------\n");
    }
    while(aux)
    {
        printf("Identificador: %s\n",aux->avion);
        printf("Destino: Longitud= %d %d'%d''%s,Latitud= %d %d'%d''%s\n\n",aux->longitud.grados,aux->longitud.minutos,aux->longitud.segundos,aux->longitud.orientacion,aux->latitud.grados,aux->latitud.minutos,aux->latitud.segundos,aux->latitud.orientacion);


        aux=aux->siguiente;
    }
}
