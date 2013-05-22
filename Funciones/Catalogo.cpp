#include <windows.h>
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
		
void Catalogo(){
	Conciertos = fopen("Archivos\\Conciertos.dat","rb");
	system("cls");
	printf("<Conciertos Registrados>\n");
	printf("Titulo         Fecha        Lugar        EdadMIN   Precio   Capacidad  Clave\n");
	fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
	while(!feof(Conciertos)==1){
		
		 if(RegConciertos.Activo == 1){
   		printf("%-10s %5d/%2d/%4d    %-13s   %2d     %6.2f      %7d    %2d\n",RegConciertos.Titulo, RegConciertos.RegFecha.Dia,RegConciertos.RegFecha.Mes,RegConciertos.RegFecha.Ano,RegConciertos.Lugar,RegConciertos.Edad, RegConciertos.Precios,RegConciertos.Capacidad,RegConciertos.Clave);
		
		
	  }
	  fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
	}
	fclose(Conciertos);
	system("PAUSE");

}
