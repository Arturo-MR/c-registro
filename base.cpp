#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Funciones externas
#include <C:\Users\Arturo\Documents\GitHub\c-registro\admin.cpp>; //Carpeta temporar
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
{

		 system("PAUSE");	
  return 0;
} //LUIS ARTURO MENDOZA & DAVID TOD
