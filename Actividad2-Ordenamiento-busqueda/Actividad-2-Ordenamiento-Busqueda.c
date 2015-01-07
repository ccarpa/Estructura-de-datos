#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void busqueda(int[],int);
void heapsort(int arreglo[]);
void swap(int *x,int *y);
void shell(int[]);
void quicksort( int *  arreglo, int first, int last );
int particion( int *  arreglo, int izquierda, int derecha );
void swap_qk( int *  ptr1, int *  ptr2 );

const int N=50000;

int main()
{

   int num,encontrar;
   int i;
   int arreglo[N];
   int arreglo_heap[N];
   int arreglo_shell[N];
   int n=20000;
   double inicio,fin;
   double tiempo;

   srand(time(NULL));

   for(i=0; i<N; i++)
   {
      num = (rand() % (n+1))/20000 + rand()%(n+1);
      arreglo[i]=num;
      arreglo_heap[i]=num;
      arreglo_shell[i]=num;
   }

   printf("________________________________________________________\n");
   printf("\tACTIVIDAD N 2 Ordenamiento y Buequedad\n");
   printf("________________________________________________________\n");
   printf("50,000 Numeros Aletorios\n");
   printf("--------------------------------------------------------\n\n");
   printf("Tiempos:\n\n");
   printf("--------------------------------------------------------\n");

   inicio=clock();
   heapsort(arreglo_heap);
   fin=clock();
   printf("Tiempo Heapsort: %.4lf\n",(fin-inicio)/1000);
   inicio=0,fin=0,tiempo=0;
   inicio=clock();
   shell(arreglo_shell);
   fin=clock();
   printf("Tiempo Shellsort: %.4lf\n",(fin-inicio)/1000);
   inicio=0,fin=0,tiempo=0;
   inicio=clock();
   quicksort(arreglo, 0, N-1);
   fin=clock();
   printf("Tiempo Quicksort: %.4lf\n",(fin-inicio)/1000);
   inicio=0,fin=0,tiempo=0;
   system("PAUSE");

   for(i=0;i<N;i++)printf("%d\n",arreglo_heap[i]);

   printf("--------------------------------------------------------\n");
   printf("\t\t     Buscar Numero\n");
   printf("--------------------------------------------------------\n");
   printf("Buscar Numero en el arreglo: ");
   scanf("%d",&encontrar);
   busqueda(arreglo_heap,encontrar);

   printf("\n\n");
   system("pause");
   return 0;
}


void busqueda(int arr[],int buscar)
{
   int izq=0;
   int der=N-1;
   int centro;
   int a=0;
   while (izq<= der)
   {
      centro = (izq + der) / 2;
      if (buscar < arr[centro])
         der = centro - 1;
      else if (buscar > arr[centro])
		     izq = centro + 1;
		   else
		   {
		      printf("Numero encontrado\nposicion en memoria %p ",&arr[centro]);
		      a=1;
		      break;
		   }
    }
    if(a==0)
    printf("\nNota:\"Numero no encontrado\"\n");
}

void heapsort(int arreglo[])
{
   int i,s,f;
   for(i=1;i< N;++i)
   {
      s=i;
      f=(s-1)/2;
      while(arreglo[f]< arreglo[s])
      {
         swap(&arreglo[f],&arreglo[s]);
         s=f;
         if(s==0)
            break;
         f=(s-1)/2;
      }
   }
   for(i=N-1;i>=1;--i)
   {
      swap(&arreglo[0],&arreglo[i]);
      f=0;
      s=1;
      if(i==1)
         break;
      if(i>2)
      if(arreglo[2]>arreglo[1])
         s=2;
      while( arreglo[f]<arreglo[s] )
      {
         swap(&arreglo[f],&arreglo[s]);
         f=s;
         s=2*f+1;
         if(i>s+1)
         if(arreglo[s+1]>arreglo[s])
            s=s+1;
         if(s>=i)
            break;
      }
    }
}

void swap(int *x,int *y)
{
   int aux;
   aux=*x;
   *x = *y;
   *y = aux;
}

void shell(int A[])
{
   int i, j, incrmnt;
   int temp;

   incrmnt = N/2;
   while(incrmnt > 0)
   {
      for(i=incrmnt; i < N; i++)
      {
         j = i;
         temp = A[i];
         while((j >= incrmnt) && (A[j-incrmnt] > temp))
         {
            A[j] = A[j - incrmnt];
            j = j - incrmnt;
		 }
         A[j] = temp;
      }
	  incrmnt=incrmnt / 2;
   }
}

void quicksort( int *  arreglo, int first, int last )
{
   int particion( int * , int, int );
   int posicionActual;
   if ( first >= last )
      return;
      posicionActual = particion( arreglo, first, last );
      quicksort( arreglo, first, posicionActual - 1 );
      quicksort( arreglo, posicionActual + 1, last );
}


int particion( int *  arreglo, int izquierda, int derecha )
{
   int posicion = izquierda;

   while(1)
   {
      while(arreglo[posicion] <= arreglo[derecha] && posicion != derecha)
      --derecha;

      if(posicion == derecha)
         return posicion;

      if(arreglo[posicion] > arreglo[derecha])
      {
         swap_qk( &arreglo[ posicion ], &arreglo[ derecha ] );
         posicion = derecha;
      }

      while ( arreglo[ izquierda ] <= arreglo[ posicion ] && izquierda != posicion )
         ++izquierda;

      if(posicion==izquierda)
         return posicion;

      if(arreglo[izquierda]>arreglo[posicion])
      {
         swap_qk( &arreglo[ posicion ], &arreglo[ izquierda ] );
         posicion = izquierda;
      }
   }
}


void swap_qk( int *  ptr1, int *  ptr2 )
{
  int aux;
  aux = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = aux;
}
