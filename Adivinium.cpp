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


int NumeroSecreto(){
	
	/*Declaración de variables.*/
	int numero = 0;
	int bandera = 0;
	
	int unidad = 0;	
	int decena = 0;
	int centena = 0;
	int unidadMil = 0;
	
	
	while(bandera == 0){
	
		/*Con este ciclo repetitivo nos aseguramos de obtener un numero aleatorio entre 1000 y 9999.*/
		do{
		
			numero = rand() % 10000;
		
		}while(numero < 1000 || numero > 9999);
	
	
		unidad = numero % 10;		//Operacion para obtener el valor de la unidad.
	
		decena = ((numero % 100) - unidad) / 10;  //Operacion para obtener el valor de la decena.
	
		centena = ((numero % 1000) - decena - unidad) /100;		//Operacion para obtener el valor de la centena.

		unidadMil = ((numero % 10000) - centena - decena - unidad) /1000;		//Operacion para obtener el valor de la unidad de mil.
		
		
		
		/*Si los 4 digitos son distintos le asignamos el valor 1 a la bandera para que termine el ciclo. */
		if((unidad != decena) && (unidad != centena) && (unidad != unidadMil) && (decena != centena) && (decena != unidadMil) && (centena != unidadMil)){
			
			bandera = 1;
		}
		/*Con esta condición nos aseguramos que el numero no va a tener ninguna cifra con valor 0.*/
		if(unidad == 0 || decena == 0 || centena == 0 || unidadMil == 0){
			
			bandera = 0;
		}
	}
		return numero;
}

void obtenerCifras(int v[10], int numero){
	
	int i = 0;
	
	
	/*Recorremos el vector y le asignamos el valor de cada cifra en una posicion diferente.*/
	while(numero > 0){
		
		v[i] = numero % 10;
		numero = numero / 10;
		i++;
	}
}

int CantidadMP(int vUno[10],int vDos[10], int numeroUno, int numeroDos){
	
	int contador= 0;
	int bandera = 0;
	
	
	/*Recorremos los vectores con las cifras del numero secreto y el numero ingresado por el jugador,
	 si en la misma posicion los valores son iguales, aumenta el contador en una unidad*/
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i != j){
				if(vDos[i] != vDos[j]){			//Codigo de prueba.
					bandera = 1;
				}else{
					printf("");
				}
			}
		}
		if(vUno[i] == vDos[i] && bandera == 1){
			
			contador++;
		}
	}
	return contador;	
}

int cantidadDP(int vUno[10],int vDos[10], int numeroUno, int numeroDos){
	int contador = 0;
	
	
	for(int i = 0; i <4; i++){ 		//Con esta estructura recorremos el primer vector.
		for(int j = 0; j < 4; j++){		//Con esta el segundo vector.
			
			/*Siempre y cuando sean posiciones diferentes, comparamos si los valores son iguales,
			 de ser asi aumentamos el contador.*/
			if(i != j){
				if(vUno[i] == vDos[j]){
					contador++;
				}
			}
		}
	}
	
	return contador;
}





int main() {
	
	srand(unsigned(time(NULL)));		//Inicializamos la semilla.
	
	
	/*Declaración de variables.*/
	int numSecreto = 0;
	int numIngresado = 0;
	int contador = 1;
	int bandera = 0;
	int puntaje = 0;
	int cantidadMismaPos = 0;
	int cantidadDistintaPos = 0;
	int cifrasNS[10];			//Arreglo que va a guardar las cifras del Numero secreto.
	int cifrasNI[10];			//Arreglo que va a guardar las cifras del Numero ingresado por el jugador.

	system("cls");
	
	numSecreto = NumeroSecreto();		//Obtenemos el numero secreto mediante la función.
	
	printf("=============\n");
	printf("  Adivinium  ");			//Titulo.
	printf("\n=============\n");

	
	printf("\nJugaremos con numeros de 4 cifras.\n\n");
	
	obtenerCifras(cifrasNS, numSecreto);		//Guardamos las cifras del numero secreto en un arreglo.
	
	puntaje = 10;		//Puntaje con el que empieza el jugador.
	
	
	while(contador <= 10 && bandera == 0){		//La estructura repetitiva se ejecuta hasta que el contador llegue a 10 o la bandera cambie de valor.	
		
		
		/*Ingreso del número por parte del cliente. Si el número no es de 4 cifras se muestra un mensaje de error. El ciclo se repite
		hasta que el jugador ingrese un número de 4 cifras.*/
		do{
		
			printf("\nintento N%d: ", contador);
			scanf("%d", &numIngresado);
		
		if(numIngresado < 1000 || numIngresado > 9999){
			
			printf("El numero debe tener 4 cifras. Vuelva a intentarlo.");
		}
		
		}while(numIngresado < 1000 || numIngresado > 9999);
		
		
		
		/*Una vez finalizado el ciclo, guardamos las cifras del número ingresado en un arreglo y aumentamos
		 el contador de intentos en 1.*/
		obtenerCifras(cifrasNI, numIngresado);
		contador++;
		
		

		/*Se hace el llamado a las funciones para obtener la cantidad de cifras en la posicion correcta y la cantidad de cifras 
		en una posición distinta.*/
		cantidadMismaPos = CantidadMP(cifrasNS, cifrasNI, numSecreto, numIngresado);
		cantidadDistintaPos = cantidadDP(cifrasNS, cifrasNI, numSecreto, numIngresado);
		
		
		
		/* Si el número ingresado no es el mismo que el número secreto se muestra el mensaje, que dice cuantas cifras se encuentran 
		en la posición correcta y cuantas en una posición distinta. */
		if(numIngresado != numSecreto){
			
			printf("Cantidad misma posicion: %d - Cantidad distina posicion: %d\n", cantidadMismaPos, cantidadDistintaPos);
		}
		
		
		
		/*Si el numero ingresado por el jugador es el mismo que el numero secreto, se muestra un mensaje de que gano el juego
		 y se le asigna a la variable bandera el valor "1" para que termine la estructura repetitiva y así también el juego.*/
		if(numIngresado == numSecreto){
			
			printf("Felicitaciones! Acertaste el numero. Puntaje obtenido: %d.", puntaje);
			bandera = 1;
		}
		
		
		
		//Al final de cada intento se resta un punto del puntaje.
		puntaje--;
		
	}
	
	if(puntaje < 1){
		printf("\n\nPerdiste... \n");
		printf("El numero secreto a adivinar era: %d", numSecreto);
	}
	
	printf("\n\n");
	system("pause");

}
