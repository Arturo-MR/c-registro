//Funcion para Administrar a los Usuarios
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Funciones
void ModificarU();
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
 	UsuariosT RegUsuarios;
void EliminarU(){//principal

	int opc;
	printf("1. Crear Usuario\n");
	printf("2. Eliminar Usuario\n");
	printf("3. Modificar Usuario\n");
	printf("4. <- Regresar\n");
	printf("Opcion:");
	scanf("%d",&opc);
	switch (opc){
		case 1:
		//Funcion Crear(David)

		break;

		case 2:
		//Funcion Eliminar(Luis)
			EliminarU();
		break;

		case 3:
		//Funcion Modificar(David)

		break;
	}

}


 void EliminarU(){
 	system("cls");
 	printf("ID:");
 	scanf("%d",&j);
 	while(!feof(Conciertos)==1){

 		fflush(stdin);
 		if (j==RegUsuarios.Id)
 		{
 			printf("Seguro Que Deseas Eliminar al Usuario %s? (S/N)\n",RegConciertos.Titulo);
			scanf("%c",&Desea);
			
			if (Desea =='S' || Desea =='s'){

				//Esperando Funcion David
				fseek(Usuarios, sizeof(Regusuarios)*(j),0);
				
				RegUsuarios.Activo = 0;

				fwrite(&RegUsuarios, sizeof(RegUsuarios), 1, Usuarios);
				system("cls");
				printf("Usuario Eliminado\n");
				fflush(stdin);
				system("PAUSE");
				break;
			}else{
				system("cls");
				printf("Usuario NO Eliminado\n");
				system("PAUSE");
				}

 		}

 	}

 }