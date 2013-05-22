//Funcion para Administrar a los Usuarios
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "UserF.cpp"
//#include "RegUsuarios.cpp"
//#include "ModUsuarios.cpp"

//Funciones
//void EliminarU();
//Estructuras
typedef struct UsuariosT {//Solo para Usuarios
  	char Nombre[31];
  	char Apellido[31];
  	int Edad;
  	int Telefono;
  	char Direccion;
  	int Id;
  	int Activo;
  };
  //Variables y Archivos
 	FILE *Usuarios;
 	UsuariosT RegUs;
void UserA(){//principal

	int opc;
	do
	{
		system("cls");
		printf("1. Crear Usuario\n");
		printf("2. Eliminar Usuario\n");
		printf("3. Modificar Usuario\n");
		printf("4. Catalogo\n");
		printf("5. <- Regresar\n");
		printf("Opcion:");
		scanf("%d",&opc);
	switch (opc){
		case 1:
		//Funcion Crear(David)

			RegUsuarios();
		break;

		case 2:
		//Funcion Eliminar(Luis)
			BajasU();
		break;

		case 3:
		//Funcion Modificar(David)

		      ModUsuario();
		break;

		case 4:

			CatalogoU();

		break;
	}
	} while (opc !=5);
	

}

