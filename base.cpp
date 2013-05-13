#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Funciones externas
#include "admin.cpp";
//Estructuras (Todas Variables con MAYUSCULA INICIAL)
typedef struct Conciertos //Solo para conciertos
	char Titulo[51];
	char Lugar[51];
	char Direccion[51];
	int Mayor18;
	float Precios;
	int Capacidad;
	int Estacionamiento;
typedef struct Usuarios //Solo para Usuarios
	char Nombre[31];
	char Apellido[31];
	int Edad;
	int Telefono;
	char Direccion;
//FIN ESTRUCTURAS 
	
int main(int argc, char *argv[])
{

		 system("PAUSE");	
  return 0;
} //LUIS ARTURO MENDOZA & DAVID TOD