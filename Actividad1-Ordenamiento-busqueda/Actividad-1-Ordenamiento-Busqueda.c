#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int N=2000;

void burbuja(int[]);
void seleccion(int[]);
void insercion(int[]);
void busqueda(int[],int);

int main()
{

   int num,encontrar;
   int i;
   int arreglo[N];
   int arreglo_seleccion[N];
   int arreglo_insercion[N];
   int n=20000;

   srand(time(NULL));

   for(i=0; i<N; i++)
   {
      num = rand() % (n+1);
      arreglo[i]=num;
      arreglo_insercion[i]=num;
      arreglo_seleccion[i]=num;
   }
   printf("________________________________________________________\n");
   printf("\tACTIVIDAD N 1 Ordenamiento y Buequedad\n");
   printf("________________________________________________________\n");
   printf("2,000 numeros aletorios\n");
   printf("--------------------------------------------------------\n\n");
   printf("Tiempos:\n\n");
   printf("--------------------------------------------------------\n");
   for(i=0;i<N;i++);

      burbuja(arreglo);
      seleccion(arreglo_seleccion);
      insercion(arreglo_insercion);
      system("PAUSE");

   for(i=0;i<N;i++)
      printf("%d\n",arreglo[i]);
      printf("--------------------------------------------------------\n");
      printf("\t\t     Buscar Numero\n");
      printf("--------------------------------------------------------\n");
      printf("Buscar Numero en el arreglo: ");
      scanf("%d",&encontrar);
      busqueda(arreglo,encontrar);

      printf("\n\n");
      system("pause");
return 0;
}

void burbuja(int arr[])
{
   int i,j;
   float temp;

   double inicio,final;

   inicio =clock();
   for(i=0;N-1>i;i++)
   {
      for(j=0;N-1-i>j;j++)
      {
         if(arr[j]>arr[j+1])
         {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
         }
      }
   }
   final=clock();

   printf("Tiempo Burbuja: %.4lf\n\n",(final-inicio)/1000);

}

void seleccion(int arr[])
{
   int i, indice,j;
   int temp;
   double inicio,final;

   inicio=clock();
   for(i=0; i<N-1; i++)
   {
      indice = i;
      for(j=i+1; j<N; j++)
         if(arr[j]<arr[indice])
            indice= j;
         if(i!= indice)
         {
            temp= arr[i];
            arr[i]= arr[indice];
            arr[indice]= temp;
         }
   }

   final=clock();
   printf("Tiempo Seleccion: %.4lf\n\n",(final-inicio)/1000);

}

void insercion(int arr[])
{
   int i,j;
   int temp;
   double inicio,final;
   inicio=clock();
   for(i=1;i<N;i++)
   {
      j=i;
      temp=arr[i];

      while(j>0 && temp < arr[j-1])
      {
         arr[j]=arr[j-1];
         j--;
      }
		 arr[j]=temp;
   }
   final=clock();
   printf("Tiempo Insercion: %.4lf\n\n",(final-inicio)/1000);
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
         printf("Numero encontrado\nposicion en memoria: %p ",&arr[centro]);
         a=1;
         break;
      }

   }
   if(a==0)
   printf("\nNota:\"Numero No encontrado\"\n");

}



