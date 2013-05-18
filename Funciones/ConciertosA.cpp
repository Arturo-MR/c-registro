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
		FILE *ID;
		ConciertosT RegConciertos;
		int id;	
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
	// printf("1. Crear Inicio de Agenda de Conciertos\n");
	printf("1. Crear Concierto\n");
	printf("2. Eliminar Concierto\n");
	printf("3. Modificar Concierto\n");
	printf("4. Catalogo\n");
	printf("5. <-Regresar\n");
	scanf("%d",&opc);
	
	//OPCIONES
	
		switch (opc){
		case 1:{

			CrearConcierto();
			
		break;
	    }

		case 2:

			EliminarConcierto();

		break;

		case 3:
			ModConcierto();

		break;

		case 4:
			Catalogo();
			
		break;
	}
	} while (opc !=5);
	

}


void CrearConcierto(){ //Corregir Clave
	system("cls");
	//Variables
	char Desea;
	int Cont=0,Lugar; //Num de conciertos
	Conciertos = fopen("Archivos\\Conciertos.dat","a+b");
	ID = fopen("Archivos\\ID.dat","r+b");
	fread(&id, sizeof(id), 1, ID);
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
		// printf("\nMax Estacionamiento:");
		// scanf("%d",&RegConciertos.Estacionamiento);
		fflush(stdin);
		RegConciertos.Clave = id++;
		fflush(stdin);
		// fread(&id, 1, 1, ID);
		RegConciertos.Activo = 1;
		system("cls");
		printf("La clave del Concierto %s es %d\n",RegConciertos.Titulo,RegConciertos.Clave );
		//Aca se guarda
		fflush(stdin);
		fwrite(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
		id = id*1;
		//Guardar ID en otro doc
		fseek(ID, sizeof(id)*0,0);
		 fwrite(&id, sizeof(id),1,ID);
		//FIN GUARDAR ID EN OTRO DOC (sobreescribir)
		printf("\nOtra alta? (S/N)\n");
		 scanf("%c",&Desea);
		fflush(stdin);
		fread(&id, sizeof(id), 0, ID);
	} while (Desea == 'S' || Desea=='s');
		fclose(Conciertos);
		fclose(ID);
}

void EliminarConcierto(){
	system("cls");
	int j,i; //Variable para clave concierto
	i=0;
	char Desea;
	printf("Ingresa la Clave del Concierto que deseas Eliminar\n");
	scanf("%d",&j);
	Conciertos = fopen("Archivos\\Conciertos.dat","r+b");
	fread(&RegConciertos, sizeof(RegConciertos), 1, Conciertos);
	while (!feof(Conciertos)==1){
		 fflush(stdin);
		if (i==j)
		{
			printf("Seguro Que Deseas Eliminar? (S/N) %s\n",RegConciertos.Titulo);
			scanf("%c",&Desea);
			
			if (Desea =='S' || Desea =='s'){ //REVISAR
				fseek(Conciertos, sizeof(RegConciertos)*(i),0);
				
				RegConciertos.Activo = 0;

				fwrite(&RegConciertos, sizeof(RegConciertos), 1, Conciertos);
				system("cls");
				printf("Archivo Eliminado\n");
				fflush(stdin);
				system("PAUSE");
				break;
			}else{
				system("cls");
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
 	Conciertos = fopen("Archivos\\Conciertos.dat","r+b");
 	system("cls");
 	 int opc,opc2,i,j;
 	 i=0;
 	 char Desea;
 	 printf("Por favor ingrese la clave del concierto que deasea Modificar.\n");
 	 scanf("%d",&j);
 	 fflush(stdin);
 	 fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
 	 while(!feof(Conciertos)==1){
 	 	fflush(stdin);

 	 	if (i==j){
 	 		printf("El concierto a Modificar es: %s ? (S/N)\n",RegConciertos.Titulo);
 	 		fflush(stdin);
			scanf("%c",&Desea);
			
			if (Desea =='S' || Desea =='s'){ //Entran los valores
				
					
				do
				{
				system("cls");
				printf("Por Favor seleccione el campo que desea modificar\n");
				printf("1. Titulo\n");
				printf("2. Fecha\n");
				printf("3. Lugar\n");
				printf("4. Direccion\n");
				printf("5. Edad Minima\n");
				printf("6. Precio\n");
				printf("7. Capacidad Max\n");
				printf("8. GUARDAR CAMBIOS O SALIR\n");
				fflush(stdin);
				scanf("%d",&opc2);
				

				switch (opc2){
					case 1: //Titulo
						fflush(stdin);
						system("cls");						
						printf("Nuevo Titulo:");
						gets(RegConciertos.Titulo);
						system("PAUSE");

					break;
					

					case 2://Fecha
						fflush(stdin);
						system("cls");						
						printf("Nueva Fecha:");
						printf(">\nDia:");
						scanf("%d",&RegConciertos.RegFecha.Dia);
						printf(">\nMes:");
						scanf("%d",&RegConciertos.RegFecha.Mes);
						printf(">\nAnio:");
						scanf("%d",&RegConciertos.RegFecha.Ano);
						system("PAUSE");

					break;
					

					case 3://Lugar
						fflush(stdin);
						system("cls");											
						printf("Nuevo Lugar:");
						gets(RegConciertos.Lugar);
						system("PAUSE");

					break;
					

					case 4://Direccion
						fflush(stdin);
						system("cls");										
						printf("Nuevo Direccion:");
						gets(RegConciertos.Direccion);
						system("PAUSE");

					break;
					

					case 5://EdadMinima
						fflush(stdin);
						system("cls");										
						printf("Nuevo Edad:");
						scanf("%d",&RegConciertos.Edad);
						system("PAUSE");
						
					break;
					

					case 6://Precio
						fflush(stdin);
						system("cls");											
						printf("Nuevo Precio:");
						scanf("%f",&RegConciertos.Precios);
						system("PAUSE");

					break;
					
					case 7://Capacidad Max
						fflush(stdin);
						system("cls");								
						printf("Nueva Capacidad:");
						scanf("%d",&RegConciertos.Capacidad);
						system("PAUSE");			

					break;
				
			}

				
			} while (opc2 !=8);
			fseek(Conciertos, sizeof(RegConciertos)*(j),0);		
				fwrite(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
				printf("Archivo Modificado\n");
				fflush(stdin);
				system("PAUSE");
				break;
		}else{
 	 	printf("El concierto %s NO se modifico\n",RegConciertos.Titulo);
 	 	system("PAUSE");
 	 	break;
 	 	
 	 	}
 	 }
 	 
 	 // if (i>opc)//Revisar
 	 // {
 	 // 	printf("La Clave no existe\n");
 	 // 	system("PAUSE");
 	 // 	break;
 	 // }//Ultimo IF
 	 i++;
 	 fflush(stdin);
 	 fread(&RegConciertos, sizeof(RegConciertos),1,Conciertos);
 	 
 	}//Fin Whiles


 	fclose(Conciertos);

 }//Fin funcion


void Catalogo(){
	Conciertos = fopen("Archivos\\Conciertos.dat","rb");
	system("cls");
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
