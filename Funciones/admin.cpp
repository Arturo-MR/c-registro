#include "ConciertosA.cpp"

void Admin(){
	
	//Variables
	int pass,opc;
	//Contraseña es 71
	do
	{
	system("cls");
	printf("Pass:");
	scanf("%d",&pass);

	} while (pass != 71); 
	//Termina Contraseña
	system("cls");
	printf("1. Ir a conciertos \n");
	printf("2. Ir a Usuarios\n");
	scanf("%d",&opc);
	switch (opc){
		case 1:

			ConciertosA();

		break;

		case 2:

			// UserA();

		break;
	}
}
