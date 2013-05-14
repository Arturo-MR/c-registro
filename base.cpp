#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Funciones externas
#include "admin.cpp" //Carpeta temporar

//Estructuras (Todas Variables con MAYUSCULA INICIAL)
typedef struct Fecha
{
	int Dia;
	int Mes;
	int Ano;
};
typedef struct Conciertos {//Solo para conciertos
	char Titulo[51];
	Fecha RegFecha;//Revisar
	char Lugar[51];
	char Direccion[51];
	int Mayor18;
	float Precios;
	int Capacidad;
	int Estacionamiento;
};
typedef struct Usuarios {//Solo para Usuarios
	char Nombre[31];
	char Apellido[31];
	int Edad;
	int Telefono;
	char Direccion;
};
//FIN ESTRUCTURAS 
//VARIABLES GLOBALES

	Conciertos RegConciertos;
	Usuarios RegUsuarios;
//FIN VARIABLES GLOBALES
int main(int argc, char *argv[])
{       //variables
        int opc;
		printf("<Bienvenido a iTicket>\n");
        printf("____________\n");
        printf("| 1. Admin |\n");
        printf("| 2. User  |\n");
        printf("------------\n");
        printf("Opcion:");
        scanf("%d",&opc);
        Admin();
         
		 system("PAUSE");	
  return 0;
} //LUIS ARTURO MENDOZA & DAVID TOD
