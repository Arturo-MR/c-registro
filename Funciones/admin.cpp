#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "ConciertosA.cpp";


void Admin(){
	
	//Variables
	int pass,opc;
	//Contraseña es 71 (quitar comentario para usar)

		// do
		// {
		// system("cls");
		// printf("Pass:");
		// scanf("%d",&pass);

		// } while (pass != 71); 
	
	//Termina Contraseña
	
	do
	{
		system("cls");
		printf("1. Ir a conciertos \n");
		printf("2. Ir a Usuarios\n");
		printf("3. <-Regresar\n");
		scanf("%d",&opc);
		switch (opc){
			case 1:

				ConciertosA();

			break;

			case 2:

				// UserA();

			break;
		}
	} while (opc != 3);
	
}
