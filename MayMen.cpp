#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Universidad Teconologica Nacional
Facultad Regional de Tucuman

Sistemas de informacion

Algoritmo y Estructura de Datos.

Rivadeneira Bordón, Maximiliano Antonio - DNI: 41384334 - comision 1K5
rivadenneira@gmail.com.
Maximiliano.RivadeneiraBordon@alu.frt.utn.edu.ar

Rosconi Ignacio Federico - DNI: 44373769 - comision 1k5
Ignaciorosconi@gmail.com
Ignacio.Rosconi@alu.frt.utn.edu.ar

Ricardo Posse - DNI: 43567498  -  comision 1k5
possericardo@gmail.com
Ricardo.Posse@alu.frt.utn.edu.ar
*/





void intentos (int v1[100]);

main ()
{
	int v[100];		//Declaracion de variable.
	
	system("cls");
	
	printf("MayMen\n");
	printf("=======");
	
	printf ("\n\nEste juego consiste en adivinar un numero que esta entre 1 y 999 denominado numero secreto");
	
	printf ("\n\nEl numero secreto fue ingresado");
	intentos(v);
	//Empieza el juego
	
	
	printf ("\n\n");
	system ("pause");
}

void intentos (int v1[100])
{
	int i = 0;
	int s = 0;
	int c = 10;			//Declaración de variables.
	int men = 1;
	int may = 999;
	
	srand (time (0));
	s = rand()% 999;		//Obtención del numero secreto.
   
    for (i = 1; i <= 10; i++)
    {
    	printf ("\nIntento N %d: ", i);
    	scanf ("%d",&v1[i]);
    	
    	if (v1[i] > may || v1[i] < men)
    	{
    		//Si el número es negativo o mayor a 3 cifras.
    		printf ("\nEl numero ingresado esta fuera de los limites.Volver a ingresar: ");
    		scanf ("%d", &v1[i]);
		}
    	if (v1[i] == s)
    	{
    		//Si acierta el número.
   			printf("\nAcertaste! Puntaje obtenido: %d.",c);
   			i=10;
   			c++;	//Por si acierta en el ultimo intento no tome el mensaje del caso perdedor.
		}
		else
		{
			if (v1[i] > s)
			{
				//Si el numero ingresado es menor, se informa y se acorta el rango.
				may = v1[i] - 1;
				printf ("El numero ingresado es menor y se encuentra entre %d y %d.\n",men,may);
			}
			else
			{
				//Si el numero ingresado es mayor, se informa y se acorta el rango.
				men = v1[i] + 1;
				printf ("El numero ingresado es mayor y se encuentra entre %d y %d.\n",men,may);
			}
		}
		c=c-1;	//Contador de puntos;
	}
	
	if(c < 1){
		//Si el jugador pierde.
		printf("\nPerdiste! Tu puntuacion es: 0");
		printf ("\nEl numero secreto es: %d",s);
	}
	
}
