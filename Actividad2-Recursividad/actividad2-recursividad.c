#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Funciones a utilizar
float Determinante (float **, int);
void Adjunta (float **, float **, int, int);

//Funcion princila
int main()
{
    int num, i, f, c;
    float **matriz;
    char com;

    do{
       printf("_____________________________________________________________________\n");
       printf("                     Actividad-2 RECURSIVIDAD\n");
       printf("_____________________________________________________________________\n");
       printf("              Calculo de la determinante de una matriz m*n\n\n");
       printf("Nota:\"Este programa utiliza una funcion recursiva.\nPrecaucion: Al introducir matrices de orden elevado(mayor de 10)\"\n");

    do{

    printf("\nNumero de elementos de la matriz: ");
    fflush(stdin);
    }while((!scanf("%d", &num))&&(num<1));

    matriz=(float**)calloc(num, sizeof(float*));
    if(matriz==NULL)
    printf("ERROR");
    else
    {
    for(i=0; i<num; i++)
        matriz[i]=(float*)calloc(num, sizeof(float));

    for(f=0; f<num; f++)
        for(c=0; c<num; c++)
            {
             printf("\nIntroduce el elemento %d de la fila %d:", c+1, f+1);
             scanf("%f", &matriz[f][c]);
            }

    system("cls");
    f=0;
         while(f<num)
         {
            for(c=0; c<num; c++)
                printf("%12.1f ", matriz[f][c]);

            printf("\n");
            f++;
         }
     printf("\nDeterminante:");
     printf("\n%.1f\n", Determinante(matriz, num));

     free(matriz);

     }
     printf("Enter para calcular otro determinante, S para SALIR");
     fflush(stdin);
     com=getchar();
     system("CLS");
     }while(com!='s' && com!='S');

     return 0;

}


/*Calculo de la determinante*/
float Determinante (float **matriz, int o)
{
    float deter;
    int i;

    float **aux;

    if(o<=2)
    {
       if(o==2)
          deter=matriz[0][0]*matriz[1][1]-(matriz[1][0]*matriz[0][1]);

       else
          deter=matriz[0][0];
    }
    else
    {
       aux=(float**)calloc(o-1, sizeof(float*));
       for(i=0; i<o-1; i++)
          aux[i]=(float*)calloc(o-1, sizeof(float));

       deter=0;

       for(i=0; i<o; i++)
       {
          Adjunta(matriz, aux, o, i);
          deter+=pow(-1, i)*matriz[i][0]*Determinante(aux, o-1);
       }
          free(aux);
    }

    return(deter);
}

/*Funcion auxiliar para el calculo de la determinante*/
void Adjunta (float **matriz, float **aux, int o, int pos)
{
    int f, col, j, i;

    for(j=0, f=0; f<o-1; j++, f++)
    {
       if(j==pos)
         f--;
       else
         for(i=1, col=0; col<o-1; i++, col++)
            aux[f][col]=matriz[j][i];

         }
}

