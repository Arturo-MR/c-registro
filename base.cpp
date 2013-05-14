#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Funciones externas
#include "Funciones\admin.cpp";
#include "Funciones\User.cpp";

//Estructuras (Todas Variables con MAYUSCULA INICIAL)
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
	int Mayor18;
	float Precios;
	int Capacidad;
	int Estacionamiento;
};
typedef struct UsuariosT {//Solo para Usuarios
	char Nombre[31];
	char Apellido[31];
	int Edad;
	int Telefono;
	char Direccion;
};
//FIN ESTRUCTURAS 
//ARCHIVOS & VARIABLES GLOBALES 
	FILE *Conciertos;
	FILE *Usuarios;
	ConciertosT RegConciertos;
	UsuariosT RegUsuarios;
//FIN VARIABLES GLOBALES
int main(int argc, char *argv[])
{       //variables
        int opc;
		printf("<Bienvenido a iTicket>\n");
        printf("-----------\n");
        printf("  1. Admin \n");
        printf("  2. User  \n");
        printf("-----------\n");
        printf("Opcion:");
        scanf("%d",&opc);
        switch (opc){
        	case 1:
        		Admin();
        	break;

        	case 2:
                 User();

        	break;
        }
         
		 system("PAUSE");	
  return 0;
} //LUIS ARTURO MENDOZA & DAVID TOD
