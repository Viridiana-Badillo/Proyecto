#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *entrada;
	char caracteres[50];

	// Abrimos el archivo para lectura
	entrada = fopen("hola.txt","r");

	// Verificamos que hayamos podido acceder
	if(entrada != NULL) {
		// Leemos línea por línea hasta el final del archivo (EOF)
		while(feof(entrada) == 0) {
			fgets(caracteres, 50, entrada); //Obtenemos la línea

			float entradas[4]; // Arreglo donde se guarden entradas 
			int i = 0;
			char* token;

			// Separamos por comas
			char * ap = caracteres;
			while((token = strsep(&ap, ",")) != NULL) {
				// Convertimos a float y guardamos entrada
				entradas[i] = atof(token);
				i++;
			}

			switch(i - 1) {
				case 1: // Lineal
					printf("Es una lineal, a: %f, b: %f\n", entradas[0], entradas[1]);
					break;
				case 2: // Cuadrática
					printf("Es una cuadrática, a: %f, b: %f, c: %f\n", entradas[0], entradas[1], entradas[2]);
					break;
				case 3: // Cúbica
					printf("Es una cúbica, a: %f, b: %f, c: %f, d: %f\n", entradas[0], entradas[1], entradas[2], entradas[3]);
					break;
				default:
					printf("Qué madres es esto!!!!\n");
					break;
			}
			
		}
		fclose(entrada);

	} else {
		printf("Error al acceder al archivo.");
	}

	return(0);
}