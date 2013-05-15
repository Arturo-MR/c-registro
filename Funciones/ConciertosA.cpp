#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct Fecha
{
	int Dia;
	int Mes;
	int Ano;
};
typedef struct ConciertosT {//Solo para conciertos
	char Titulo[51];
	Fecha RegFecha;//Revisar
	char Lugar[51];
	char Direccion[51];
	int Edad;
	float Precios;
	int Capacidad;
	int Estacionamiento;
	int Clave;
	int Activo;

};
		FILE *Conciertos;
		ConciertosT RegConciertos;
//Esta Funcion la lee el Admin y es la que se encarga de todo en los Conciertos
//Se Leen Funciones 
void Catalogo();
void CrearConcierto();
void EliminarConcierto();
void ModConcierto();
//FIN Leer Funciones
//Empieza la funcion central Conciertos
void ConciertosA(){
	//Variables
	
	int opc;
	do{
	system("cls");
	printf("1. Crear Concierto\n");
	printf("2. Eliminar Concierto\n");
	printf("3. Modificar Concierto\n");
	printf("4. Catalogo\n");
	printf("5. Salir\n");
	scanf("%d",&opc);
	
	//OPCIONES
	
		switch (opc){
		case 1:
			CrearConcierto();
			Catalogo();
		break;

		case 2:

			EliminarConcierto();

		break;

		case 3:
			ModConcierto();

		break;

		case 4:
			Catalogo();
			system("PAUSE");
		break;
	}
	} while (opc !=5);
	

}

void CrearConcierto(){
	system("cls");
	//Variables
	char Desea;
	int Cont=0; //Num de conciertos
	RegConciertos.Clave = 0;
	Conciertos = fopen("Archivos//Conciertos.dat","a+b");
	printf("[CREAR CONCIERTO]\n" );
	do
	{
		system("cls");
		fflush(stdin);
		printf("Titulo:");
		gets(RegConciertos.Titulo);
		printf("\nFecha:");
		fflush(stdin);
		printf("\n>Dia:");
		scanf("%d",&RegConciertos.RegFecha.Dia);
		printf("\n>Mes:");
		scanf("%d",&RegConciertos.RegFecha.Mes);
		printf("\n>Anio:");
		scanf("%d",&RegConciertos.RegFecha.Ano);
		fflush(stdin);
		printf("\nLugar:");
		gets(RegConciertos.Lugar);
		printf("\nDireccion:");
		fflush(stdin);
		gets(RegConciertos.Direccion);
		printf("\nEdad Minima:");
		scanf("%d",&RegConciertos.Edad);
		printf("\nPrecio:");
		scanf("%f",&RegConciertos.Precios);
		printf("\nCapacidad Max Personas:");
		scanf("%d",&RegConciertos.Capacidad);
		printf("\nMax Estacionamiento:");
		scanf("%d",&RegConciertos.Estacionamiento);
		fflush(stdin);
		RegConciertos.Clave++;
		fflush(stdin);
		RegConciertos.Activo = 1;
		//Aca se guarda
		fwrite(&RegConciertos, sizeof(RegConciertos), 1, Conciertos);
		
		// Cont++;
		printf("\nOtra alta? (S/N)\n");
		 scanf("%c",&Desea);
		 // Desea = getchar();
		 // Desea= toupper(Desea);
		fflush(stdin);
	} while (Desea == 'S' || Desea=='s');
		fclose(Conciertos);
		
	
}

void EliminarConcierto(){
	system("cls");
	int j,i; //Variable para clave concierto
	i=0;
	char Desea;
	printf("Ingresa la Clave del Concierto que deseas Eliminar\n");
	scanf("%d",&j);
	Conciertos = fopen("Archivos//Conciertos.dat","a+b");
	fread(&RegConciertos, sizeof(RegConciertos), 1, Conciertos);
	while (!feof(Conciertos)==1){
		 fflush(stdin);
		if (i==j)
		{
			printf("Seguro Que Deseas Eliminar? (S/N) %s\n",RegConciertos.Titulo);
			scanf("%c",&Desea);
			
			if (Desea =='S' || Desea =='s'){
				 //fseek(Conciertos, sizeof(RegConciertos)*(j-1),0);
				
				RegConciertos.Activo = 0;

				fwrite(&RegConciertos, sizeof(RegConciertos), 1, Conciertos);
				printf("Archivo Eliminado\n");
				system("PAUSE");
			}else{
				printf("Archivo NO Eliminado\n");
				system("PAUSE");
			}
		}
		 // else{
		 // 		printf("No entre\n");
		 // 		system("PAUSE");
		 // 	}
		i++;
		fflush(stdin);
		fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
		
	}
	fclose(Conciertos);
}

void ModConcierto(){
	system("cls");

}
//Solo para pruebas podria mejorarse y utilizarse
void Catalogo(){
	Conciertos = fopen("Archivos//Conciertos.dat","r+b");
	printf("Titulo     Fecha     Lugar     Precio Clave\n");
	fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
	while(!feof(Conciertos)==1){
		fflush(stdin);
		if(RegConciertos.Activo == 1){
		printf("%-5s %5d %-5s %5.2f %d\n",RegConciertos.Titulo,RegConciertos.RegFecha.Mes,RegConciertos.Lugar,RegConciertos.Precios,RegConciertos.Activo );
		fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
		fflush(stdin);
	 }
	}
	fclose(Conciertos);

}
