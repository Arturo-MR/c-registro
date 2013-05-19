//
//  main.c
//  User
//
//  Created by Davixx Tod on 18/05/13.
//  Copyright (c) 2013 David Soto. All rights reserved.
//

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>


//FUNCIONES
void RegUsuarios();
void Catalogo();



//ESTRUCTURAS

typedef struct Persona{
    
    char Nombre[31];
    char Apellido[31];
    int Edad;
    char Direccion[50];
    int Telefono;
    int Clave;
    int Activo;
    
};

//VARIABLES
Persona RegUser;
FILE *Usuarios;




//PRINCIPAL
int main(){
    
    //VARIABLES
    int opc;
    
    //MENU PRINCIPAL USER
    
    do{
        
        system("cls");
        printf("1. REGRISTRO \n");
        printf("2. BUSCAR CONCIERTOS\n");
        printf("3. SALIR\n");
        printf("\nELIJA UNA OPCION: ");
        scanf("%d",&opc);
        //system("cls");
        
        
        
        //SWITCH
        switch (opc){
                
                
                
            case 1: //REGISTRO
                
                RegUsuarios();
                
                break;
                
                
            case 2: //BUSCAR CONCIERTOS
                
                Catalogo();
                
                
                break;
        }
        
    }while (opc!=3);
    
}






//FUNCION REGISTRAR USUARIOS

void RegUsuarios(){
    
    //VARIABLES
    char Desea;
    
    //INSTRUCCIONES
    Usuarios= fopen("C:\\Users\\David Tod\\Documents\\GitHub\\c-registro\\Archivos\\Usuarios.dat","r+b");
    
    
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
        
        //GUARDAR ARCHIVO
        fwrite(&RegUser, sizeof(RegUser),1,Usuarios);
        
        system("cls");
        printf("DESEA PROCESAR OTRO USUARIO (s/n)?: \n");
        fflush(stdin);
        Desea=getchar();
    }while (Desea == 's');
    fclose(Usuarios);
    
}

//FUNCION CATALOGO

void Catalogo(){
     

    
    
    
    
    
    
}

