#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>


void RegUsuarios(){
    
    typedef struct Persona{
        
        char Nombre[31];
        char Apellido[31];
        int Edad;
        char Direccion[50];
        int Telefono;
        int Id;
        int Activo;
        
    };
    
    //VARIABLES
    Persona RegUser;
    FILE *Usuarios;
    FILE *ID2;
    int id2;
    
    //VARIABLES
    char Desea;
    
    //INSTRUCCIONES
    Usuarios = fopen("Archivos\\Usuarios.dat","a+b");
    ID2 = fopen("Archivos\\ID2.dat","r+b");
	fread(&id2, sizeof(id2), 1, ID2);
    
    
    do{
        
        system("cls");
        printf("REGISTRO\n");
        printf("\nNombre: ");
        fflush(stdin);
        gets(RegUser.Nombre);
        printf("\nApellido: ");
        gets(RegUser.Apellido);
        printf("\nEdad: ");
        scanf("%d",&RegUser.Edad);
        printf("\nDireccion: ");
        fflush(stdin);
        gets(RegUser.Direccion);
        printf("\nTelefono: ");
        scanf("%d",&RegUser.Telefono);
        
        fflush(stdin);
		RegUser.Id = id2++;
		RegUser.Activo = 1;
		printf("La clave del Usuario %s es %d\n",RegUser.Nombre,RegUser.Id);
        system("PAUSE");
		//GUARDAR REGISTRO
		fflush(stdin);
        fwrite(&RegUser, sizeof(RegUser),1,Usuarios);
		id2 = id2*1;
		//Guardar ID
		fseek(ID2, sizeof(id2)*0,0);
        fwrite(&id2, sizeof(id2),1,ID2);
        
        //GUARDAR ARCHIVO
        
        system("cls");
        printf("DESEA PROCESAR OTRO USUARIO (s/n)?: \n");
        fflush(stdin);
        Desea=getchar();
        fread(&id2, sizeof(id2), 0, ID2);
    }while (Desea == 's');
    fclose(Usuarios);
	fclose(ID2);
    
}
