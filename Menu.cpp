#include <stdio.h>
#include <stdlib.h>
#include "MayMen.h"
#include "WairCoin.h"
#include "Adivinium.h"
#include "Ahorcadito.h"

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

main(){
	
	int juego = 0;		//Declaración de variable.
	
	do{
	
		system("cls");
		
		printf("Eliga un Juego: \n");
		printf("1 - MayMen\n");
		printf("2 - Adivinium\n");
		printf("3 - WairCoin\n");			//Opciones en pantalla de los juegos
		printf("4 - Ahorcado\n");
		printf("0 - Salir\n");
		printf("\nOpcion: ");
		scanf("%d", &juego);		//Ingreso de la opción por parte del jugador.
		
		switch(juego){
			
			case 1:{
						mainMayMen();
						break;
			}
			case 2:{
						mainWairCoin();
						break;
			}
			case 3:{
						mainAdivinium();
						break;
			}
			case 4:{
						mainAhorcadito();
						break;
			}
		}
		
	}while(juego != 0);	//Mientras no ingrese el valor 0, se sigue ejecutando.
	
	printf("\n\nGracias por jugar con nosotros! ;)");
}
