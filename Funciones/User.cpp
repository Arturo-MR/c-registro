#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Funciones
void Catalogo();




void User(){

     
     //Estructuras
 typedef struct Fecha
 {
 	int Dia;
 	int Mes;
 	int Ano;
 };
 
         
 typedef struct RegistroUser {
 	char Nombre[31];
 	Fecha RegFecha;
 	char Direccion[51];
 	int Edad;
    int Clave;
	int Activo;

 };
	//Variables
	int opc;
	
	do{
	system("cls");
	printf("1. Registrarse\n");
	printf("2. Buscar concierto\n");
	scanf("%d",&opc);
	
	}while(opc!=3);
	
	//OPCIONES
	
		switch (opc){
               
		case 1:


		break;

		case 2:
             

        system("PAUSE");
		break;


	
}
}

void Registro(){
     
    char Desea;
	system("cls");
	do
	{
		system("cls");
		fflush(stdin);
		printf("Elige una clave: ");
		scanf("%d",&RegistroUser.Clave);
		printf("Nombre: ");
		gets(RegistroUser.Nombre);
		printf("\nFecha de Nacimiento:");
		fflush(stdin);
		printf("\n>Dia: ");
		scanf("%d",&RegistroUser.RegFecha.Dia);
		printf("\n>Mes: ");
		scanf("%d",&RegistroUser.RegFecha.Mes);
		printf("\n>Anio: ");
		scanf("%d",&RegistroUser.RegFecha.Ano);
		fflush(stdin);
		printf("\nDireccion: ");
		fflush(stdin);
		gets(RegistroUser.Direccion);
		fflush(stdin);
		RegistroUser.Clave++;
		fflush(stdin);
		RegistroUser.Activo = 1;

		printf("\nOtra alta? (S/N): \n");
	    scanf("%c",&Desea);
	    Desea = getchar();
		fflush(stdin);
	    }while(Desea == 'S' || Desea=='s');
     

     
