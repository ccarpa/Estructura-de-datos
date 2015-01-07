#include <stdio.h>

int suma(int);

int main()
{
    int numero,i=1,mayor,aux=0,a;
    printf("______________________________________________________________\n");
    printf("\t\tActividad N-1 RECURSIVIDAD\n");
    printf("______________________________________________________________\n");
    printf("Introduccir numeros(Presione -1 para finalizar)\n");
    do{
       do{
       printf("Introducir numero: ");
       fflush(stdin);
       if(!scanf("%d",&numero)||(numero<-1))
       {
           printf("Nota:\"Introducir solo numeros positivos\"\n");
           i=0;
       }
       }while((i==0)&&(numero>(-1)));

       mayor=suma(numero);
       if(mayor>=aux)
       {
           aux=mayor;
           a=numero;
       }

    }while(numero!=(-1));
    printf("--------------------------------------------------------------\n");
    printf("Entero con la suma de digitos mayor: %d\n",a);
    fflush(stdin);
    getchar();
    return 0;
}


int suma(int numero)
{
	if(numero < 10)
	{
	   return numero;
	}
	else
	{
	   return numero%10 + suma(numero/10);
	}
}
