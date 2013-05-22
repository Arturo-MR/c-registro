#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

 struct Fecha
{
	int Dia;
	int Mes;
	int Ano;
};
 struct ConciertosT {//Solo para conciertos
	char Titulo[51];
	struct Fecha RegFecha;//Revisar
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
		struct ConciertosT RegConciertos;

		
void Catalogo(){
	Conciertos = fopen("Archivos\\Conciertos.dat","rb");
	int mes;
	system("cls");
	printf("En que Mes deseas Buscar?\n");
	printf("1.  Enero\n");
	printf("2.  Febrero\n");
	printf("3.  Marzo\n");
	printf("4.  Abril\n");
	printf("5.  Mayo\n");
	printf("6.  Junio\n");
	printf("7.  Julio\n");
	printf("8.  Agosto\n");
	printf("9.  Septiembre\n");
	printf("10. Octubre\n");
	printf("11. Noviembre\n");
	printf("12. Diciembre\n");
	printf("Opc:");
	scanf("%d",&mes);
	system("cls");
	printf("<Conciertos Registrados>\n");
	printf("Titulo         Fecha        Lugar        EdadMIN   Precio   Capacidad  Clave\n");
	fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
	while(!feof(Conciertos)==1){
		if (RegConciertos.RegFecha.Mes == mes)
		{
			if(RegConciertos.Activo == 1){
   		printf("%-10s %5d/%2d/%4d    %-13s   %2d     %6.2f      %7d    %2d\n",RegConciertos.Titulo, RegConciertos.RegFecha.Dia,RegConciertos.RegFecha.Mes,RegConciertos.RegFecha.Ano,RegConciertos.Lugar,RegConciertos.Edad, RegConciertos.Precios,RegConciertos.Capacidad,RegConciertos.Clave);
		
		
	 	 }
			}
		 
	  fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
	}
	fclose(Conciertos);
	system("PAUSE");

}
