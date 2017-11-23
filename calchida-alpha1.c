#include <stdio.h>

float * entrada(int nTerminos) {
	/* Función encargada de la entrada de datos por término
		de ecuaciones de n orden (hasta tercer orden)
		Argumentos: 
			nTerminos (int): Número de términos de la ecuación, que se calcula
			como orden + 1

		Devuelve:
			Arreglo de flotantes que contiene cada término

		Ejemplo:
			float * primer = entrada(2) -> de primer orden x
			float * segundo = entrada(3) -> de segundo orden x²
			float * tercer = entrada(4) -> de tercer orden x³
	*/

	// Para poder darle estética a las preguntas de los términos
	char nT[4][14] = {"primero", "segundo", "tercero", "independiente"};
	char eqs[4][4] = {"", "x", "x²", "x³"};
	char let[4] = {'a', 'b', 'c', 'd'};

	// Ciclo que pregunta por cada término y lo guarda en un arreglo. 
	// Ejemplo de mensaje: "Ingresa el término segundo [bx²]:"
	static float datos[4];
	for(int i = nTerminos; i > 0; i--) {
		int j = nTerminos - i; // Número del término en el que vamos
		int k = (i == 1) ? 3 : j; // Evaluamos si estamos o no en la independiente
		printf("Ingresa el término %s [%c%s]: ", nT[k], let[j], eqs[i - 1]);
		scanf("%f", &datos[j]);
	}

	// Devolvemos como dato el arreglo (como apuntador)
	return datos;
}

void graficar(int tipo, float* terminos) {
	/* Procedimiento que crea un archivo de comunicación
		y ejecuta el programa de graficación
		Argumentos:
			tipo (entero): Tipo de ecuación (1: lineal, 2: cúbica
				3: cuadrática)
			terminos (flotante *): Arreglo que contiene a los términos
		
		Ejemplo:
			float terminos[4] = {4, 5, 6, 7};
			graficar(3, terminos);
	*/
	FILE *comunicacion;

	// Abrimos el archivo de comunicación
	comunicacion = fopen("comunicacion.txt","w+");
	if(comunicacion != NULL) {
		// Escribimos cada término
		for(int i = 0; i < (tipo + 1); i++) {
			// Separamos por comas
			if(i == 0) {
				fprintf(comunicacion, "%f", terminos[i]);
			} else {
				fprintf(comunicacion, ",%f", terminos[i]);
			}
		}
	} else {
		printf("Error al acceder al archivo.");
		exit();
	}
	// Cerramos el archivo
	fclose(comunicacion);

	// Ejecutamos el programa
	system("python graficar.py");
}



int menu() {
	/* Función que muestra el menú del programa para después devolver la opción
		seleccionada. Incluye validación de la opción entrada.
		Argumentos:
			No tiene

		Devuelve:
			Identificador (int) de la opción seleccionada
	*/
	int m;

	// Muestra el texto del menú
	printf("Programa que calcula las raíces de ecuaciones hasta tercer orden\n");
	printf("----------------------------------------------------------------\n");
	printf("Opciones:\n");
	printf("[1] - Ecuaciones de la forma ax + b = 0\n");
	printf("[2] - Ecuaciones de la forma ax² + bx + c = 0\n");
	printf("[3] - Ecuaciones de la forma ax³ + bx² + cx + d = 0\n");
	printf("[4] - Entrada de datos por medio de archivos\n");
	printf("----------------------------------------------------------------\n");
	printf("Ingresa el número de la opción: ");

	// Entrada y validación de la opción entrada
	while(1) {
		scanf("%d", &m);
		if((m >= 1)&&(m <= 4))
			break;
		else {
			printf("Opción no encontrada, ingrese otro número: ");
		}
	}

	// Devolución del identificador de la opción mostrada
	return m;
}

int main() {

	// Mostramos el menú
	int opc = menu();

	// Según la opción seleccionada, pedimos la entrada de datos
	// Se llama a la función entrada() para ello
	float * terminos;
	switch(opc) {
		case 1:
			terminos = entrada(2);
			printf("Ecuación entrada: ");
			printf("%fx", terminos[0]);
			printf(" + %f = 0\n", terminos[1]);
			break;
		case 2:
			terminos = entrada(3);
			printf("Ecuación entrada: ");
			printf("%fx²", terminos[0]);
			printf(" + %fx", terminos[1]);
			printf(" + %f = 0\n", terminos[2]);
			break;
		case 3:
			terminos = entrada(4);
			printf("Ecuación entrada: ");
			printf("%fx³", terminos[0]);
			printf(" + %fx²", terminos[1]);
			printf(" + %fx", terminos[2]);
			printf(" + %f = 0\n", terminos[3]);
			break;
		case 4:
			printf("Holi!\n");
			break;
	}
}