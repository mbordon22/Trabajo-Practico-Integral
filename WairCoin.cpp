#include <stdio.h>
#include <stdlib.h>
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

int numeroPilas(){
	int numeroPilas = 0;
	
	do{
		
		numeroPilas = rand()%100;  //Obtenemos un numero aleatorio menor a 100.
		
	}while(numeroPilas < 10 || numeroPilas > 50);	//Repetimos la secuencia hasta que encontremos un valor entre 10 y 50.
	
	return numeroPilas;		//Retornamos el valor.
}


void elegirPrimerJugador(int &jugadorInicial){
	
	int primerJugador = 0;
	
	primerJugador = rand() % 10;		//Le asignamos un valor aleatorio a la variable.

	//jugadorInicial = 1;
	
	if(primerJugador % 2 == 0){		//Si el valor es par.
		
		printf("====================================\n");
		printf("   Inicia la partida el usuario.    ");
		printf("\n====================================");
		jugadorInicial = 1;
		
	}else{		//Si es impar.
		
		printf("====================================\n");
		printf("  Inicia la partida la computadora. ");
		printf("\n====================================");
		jugadorInicial = 0;
	}
	
}

void juego(int &jugadorInicial, int &cantidadMaximaRetirar, int &cantidadMinimaRetirar, int &cantidadPilas, int &cantidadARetirar){
	
	srand(unsigned(time(NULL)));
	int bandera = 0;
	int ganador = 0;
	
	while(bandera == 0){		//Mientras la bandera sea igual a 0 se ejecuta la estructura repetitiva.
	
	
		//Si inicia la partida el usuario.
		if(jugadorInicial == 1){
			
			if(cantidadPilas < cantidadMinimaRetirar && bandera == 0){
			
					printf("\n\n");
					printf("\n==================================================\n");
					printf("  LA COMPUTADORA GANO!!! Puntaje obtenido = 0.  ");		//Mensaje a mostrar si gana la computadora.
					printf("\n==================================================");
					bandera = 1;		//Asignamos el valor 1 a la variable bandera, asi el la estructura repetitiva termine.
					
			}
			else if (cantidadPilas >= cantidadMinimaRetirar){
				
				do{	
				
					printf("\n* Ingrese la cantidad de monedas a eliminar: ");		//Ingresa la cantidad de monedas a retirar.
					scanf("%d", &cantidadARetirar);
			
					if(cantidadPilas - cantidadARetirar < 0){
					//Asignamos esta condición asi no quede un resultado negativo en la cantidad de monedas en la pila.
						
						printf("* Ingrese un numero mayor a %d y menor a %d\n", cantidadMinimaRetirar, cantidadPilas);
					}
			
					if(cantidadARetirar < cantidadMinimaRetirar || cantidadARetirar > cantidadMaximaRetirar){
					//Si la cantidad de monedas no esta entre lo indicado anteriorimente por el usuario, marca un error y pide que ingrese nuevamente.
				
						printf("* ERROR!! intente de nuevo, puede retirar entre %d y %d", cantidadMinimaRetirar, cantidadMaximaRetirar);
					}
				
			
				}while(cantidadARetirar < cantidadMinimaRetirar || cantidadARetirar > cantidadMaximaRetirar || cantidadPilas - cantidadARetirar < 0);
				//Mientras el usuario no quite una cantidad correcta de monedas, se va a seguir repitiendo el ciclo.
			
			
				cantidadPilas = cantidadPilas - cantidadARetirar;	//Restamos la cantidad de monedas de la pila.
				printf("* Quedan %d monedas.\n", cantidadPilas);	//Mostramos en pantalla la cantidad de monedas que quedan en la pila.
				
			}
			
			if(cantidadPilas < cantidadMinimaRetirar && bandera == 0){
					
					printf("\n\n");
					printf("\n==================================================\n");
					printf("     EL USUARIO GANO!!! Puntaje obtenido = 5.       ");	//Mensaje a mostrar si gana el usuario.
					printf("\n==================================================");
					bandera = 1;		//Asignamos el valor 1 a la variable bandera, asi el la estructura repetitiva termine.
					
			}
			else if (cantidadPilas >= cantidadMinimaRetirar){
				
				do{
		
					cantidadARetirar = rand()%10;		//Obtenemos un numero al azar.
					
					
					if(cantidadARetirar >= cantidadMinimaRetirar && cantidadARetirar <= cantidadMaximaRetirar && cantidadPilas - cantidadARetirar >= 0 ){
				
						printf("\n- La computadora saco %d monedas de la pila.", cantidadARetirar);
					}
			
				}while(cantidadARetirar < cantidadMinimaRetirar || cantidadARetirar > cantidadMaximaRetirar || cantidadPilas - cantidadARetirar < 0);
		
				cantidadPilas = cantidadPilas - cantidadARetirar;
				printf("\n- Quedan %d monedas.\n", cantidadPilas);
				
			}
		}
	
	
		//Si inicia la partida la computadora.
		else if (jugadorInicial == 0){
		
			if(cantidadPilas < cantidadMinimaRetirar && bandera == 0){
					
					printf("\n\n");
					printf("\n==================================================\n");
					printf("     EL USUARIO GANO!!! Puntaje obtenido = 5        ");	//Mensaje a mostrar si gana el usuario.
					printf("\n==================================================");
					bandera = 1;		//Asignamos el valor 1 a la variable bandera, asi el la estructura repetitiva termine.
					
			}
			else if (cantidadPilas >= cantidadMinimaRetirar){
				
				do{
		
					cantidadARetirar = rand()%10;		//Obtenemos un numero al azar.
					
					
					if(cantidadARetirar >= cantidadMinimaRetirar && cantidadARetirar <= cantidadMaximaRetirar && cantidadPilas - cantidadARetirar >= 0 ){
				
						printf("\n- La computadora saco %d monedas de la pila.", cantidadARetirar);
					}
			
				}while(cantidadARetirar < cantidadMinimaRetirar || cantidadARetirar > cantidadMaximaRetirar || cantidadPilas - cantidadARetirar < 0);
		
				cantidadPilas = cantidadPilas - cantidadARetirar;
				printf("\n- Quedan %d monedas.\n", cantidadPilas);
				
			}
			
			
			if(cantidadPilas < cantidadMinimaRetirar && bandera == 0){
			
					printf("\n\n");
					printf("\n==================================================\n");
					printf("    LA COMPUTADORA GANO!!! Puntaje obtenido = 0.    ");		//Mensaje a mostrar si gana la computadora.
					printf("\n==================================================");
					bandera = 1;		//Asignamos el valor 1 a la variable bandera, asi el la estructura repetitiva termine.
					
			}
			else if (cantidadPilas >= cantidadMinimaRetirar){
				
				do{	
				
					printf("\n* Ingrese la cantidad de monedas a eliminar: ");		//Ingresa la cantidad de monedas a retirar.
					scanf("%d", &cantidadARetirar);
			
					if(cantidadPilas - cantidadARetirar < 0){
					//Asignamos esta condición asi no quede un resultado negativo en la cantidad de monedas en la pila.
						
						printf("* Ingrese un numero mayor a %d y menor a %d\n", cantidadMinimaRetirar, cantidadPilas);
					}
			
					if(cantidadARetirar < cantidadMinimaRetirar || cantidadARetirar > cantidadMaximaRetirar){
					//Si la cantidad de monedas no esta entre lo indicado anteriorimente por el usuario, marca un error y pide que ingrese nuevamente.
				
						printf("* ERROR!! intente de nuevo, puede retirar entre %d y %d", cantidadMinimaRetirar, cantidadMaximaRetirar);
					}
				
			
				}while(cantidadARetirar < cantidadMinimaRetirar || cantidadARetirar > cantidadMaximaRetirar || cantidadPilas - cantidadARetirar < 0);
				//Mientras el usuario no quite una cantidad correcta de monedas, se va a seguir repitiendo el ciclo.
			
			
				cantidadPilas = cantidadPilas - cantidadARetirar;	//Restamos la cantidad de monedas de la pila.
				printf("* Quedan %d monedas.\n", cantidadPilas);	//Mostramos en pantalla la cantidad de monedas que quedan en la pila.
				
			}
		}
	}
}

int main() {
	
	srand(unsigned(time(NULL)));

	int cantidadPilas = 0;
	int cantidadMaximaRetirar = 0;			//Declaración de variables.
	int cantidadMinimaRetirar = 0;
	int jugadorInicial = 0;
	int cantidadARetirar = 0;

	system("cls");
	
	printf("=========\n");
	printf("WairCoin\n");
	printf("=========\n");
	
	printf("\nIngresa la cantidad minima de monedas que se pueden retirar: ");		//Cantidad minima de pilas a retirar.
	scanf("%d", &cantidadMinimaRetirar);
	printf("Ingresa la cantidad maxima de monedas que se pueden retirar: ");		//Cantidad maxima de pilas a retirar.
	scanf("%d", &cantidadMaximaRetirar);
	
	cantidadPilas = numeroPilas();		//Llamamos a la función para obtener el número de pilas inicial de la partida.
	
	printf("La cantidad inicial de monedas en la pila: %d", cantidadPilas);	//Mostramos la cantidad inicial de pilas.
	
	printf("\n\n\n");
	printf("\n\n\n");
	
	elegirPrimerJugador(jugadorInicial);		//Función para obtener quien empieza la partida.
	
	
	printf("\n\n\n");
	
	juego(jugadorInicial, cantidadMaximaRetirar, cantidadMinimaRetirar, cantidadPilas, cantidadARetirar);
	//LLamado a la función que contiene el algoritmo del juego.
	
	
	printf("\n\n");
	system("pause");

}
