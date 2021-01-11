#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

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

const int TAMANO = 100;

typedef char cadena[TAMANO];


void Cuerpo(int numero){
	//Mensajes a mostrar cada vez que haya un error.
	switch (numero)
			{
				case 1: {
							printf("\nEstado del munieco: Cabeza");
							break;
				}
						
				case 2: {
							printf("\nEstado del munieco: Cabeza - Tronco");
							break;
				}
				
				case 3: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo");
							break;
				}
						
				case 4: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho");
							break;
				}
				
				case 5: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho - Pierna izquierda");
							break;
				}
				
				case 6: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho - Pierna izquierda - Pierna derecha");
							break;
				}
				
				case 7: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho - Pierna izquierda - Pierna derecha - Mano izquierda");
							break;
				}
				
				case 8: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho - Pierna izquierda - Pierna derecha - Mano izquierda - Mano derecha");
							break;
				}
				
				case 9: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho - Pierna izquierda - Pierna derecha - Mano izquierda - Mano derecha - Pie izquierdo");
							break;
				}
				
				case 10: {
							printf("\nEstado del munieco: Cabeza - Tronco - Brazo izquierdo - Brazo Derecho - Pierna izquierda - Pierna derecha - Mano izquierda - Mano derecha - Pie izquierdo - Pie derecho");
							break;
				}
			}
}


void LlenarArray(char vec[TAMANO], int n){
	
	for(int i = 0; i < n; i++){
		
		vec[i] = '-';
	}
}

int ObtenerPuntaje(int n){
	int puntaje = 0;
	
	puntaje = 50 - (2 * n);
}

void mainAhorcadito()
{
	cadena palabra;			//Cadena con la palabra a encontrar.
	cadena acertados;		//Mostramos los caracteres encontrados hasta el momento
	cadena noAcertados;		//Mostramos los caracteres no acertados hasta el momento
	char letra = ' ';

	
	int longitudPalabra = 0;
	int errores = 0; // contador de errores
	int restantes = 0; // contador de letras restantes por adivinar
	const int erroresPermitidos = 10; 
	int veces = 0; // cantidad de veces que la letra ingresada está en la palabra a adivinar
	int contador = 1;
	int bandera = 0;
	int puntaje = 0;
	
	system("cls");
	printf(" ============");
	printf("\n   AHORCADO \n");
	printf(" ============\n");
	
	
	printf("\n INICIO\n");
	
	printf("Palabra a adivinar: ");
	_flushall();
	gets(palabra);	//Introduccion de la palabra por parte del jugador.
	
	strupr(palabra);		//Cambiamos a mayuscula.
	
	longitudPalabra = strlen(palabra);		//Obtenemos la cantidad de caracteres de la cadena
	
	errores = 0;
	restantes = strlen(palabra);		//Cantidad de caracteres que faltan descubrir.
	
	
	_flushall();
	LlenarArray(acertados, longitudPalabra);		//Mostramos los caracteres encontrados hasta el momento
	
	_flushall();
	LlenarArray(noAcertados, erroresPermitidos);
	
	do
	{
		system("cls");
		
		printf("Palabra a adivinar: %s", acertados);
		printf("\nCaracteres ya descartados %s", noAcertados);
		
		
		printf("\n\nJUGADA #%d", contador);
		
		printf("\nIngrese una letra: ");
		_flushall();
		letra = toupper( getchar() );
	
		veces = 0;
	
		if(isalpha(letra)){
		
		
			bandera = 0;
			
			for (int i=0; i < longitudPalabra ;i++)
			{
				if(noAcertados[i] == letra || acertados[i] == letra){
					bandera = 1;
				}
				else if (palabra[i] == letra)
				{
					veces++;
					acertados[i] = palabra[i]; 
				}
			
			}
		
			if (veces == 0 && bandera == 0)
			{
				errores++;
				noAcertados[contador-1] = letra;
			
			}
			else
			{
				restantes = restantes - veces;
			}
		
			if (bandera == 1){
				printf("El caracter ya fue ingresado anteriormente.");
			}
		
			printf("\nRESULTADO JUGADA #%d", contador);
			printf("\nPalabra a adivinar: %s", acertados);
			Cuerpo(errores);


			printf("\n\n");
			system("pause");
		
			if(bandera == 0){
				
				contador++;
			}
		}
		else
		{
			printf("\nEROR! El caracter ingresado corresponde a una letra. Intente nuevamente\n\n");
		}
		
	} while ( (restantes > 0) && (errores <= erroresPermitidos) );
	
	printf("\n\n");
	
	puntaje = ObtenerPuntaje(errores);
	
	if (restantes == 0)
	{
		printf("\nADIVINASTE !");
		printf("\nEl puntaje obtenido es: %d", puntaje);
	}
	else
	{
		printf("\nAHORCADO.");
		printf("\nEl puntaje obtenido es: 0\n");
		printf("La palabra era: %s", palabra);
	}
}

