#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

#include "RegUsuarios.cpp";

#include "ModUsuarios.cpp";

//#include "Catalogo.cpp";







//PRINCIPAL
void User(){
    
    //VARIABLES
    int opc,opc2;
    
    //MENU PRINCIPAL USER
    
    printf("1. Registro\n");
    printf("2. Loguearse\n");
    printf("ELIJA UNA OPCION \n");
    scanf("%d",&opc);
    
    switch (opc){//Switch 1
           
           case 1:
                
           RegUsuarios();
                
                break;
           
           case 2:
           
           do{
        
        system("cls");
        printf("1. MODIFICAR PERFIL \n");
        printf("2. BUSCAR CONCIERTOS \n");
        printf("3. <- REGRESAR\n");
        printf("\nELIJA UNA OPCION: ");
        scanf("%d",&opc2);

        
        
        
        //SWITCH 2
        switch (opc2){
                
            case 1: //FUNCION MODIFICAR Usuario
                
                ModUsuario();
                
                break;
                
                
            case 2: //FUNCION CATALOGO                               
    
                //Catalogo();
                
                break;
        }
        
    }while (opc2!=3);
           
           break;
           
           }
           }
           
           //FIN SWITCH 2




     

    
    
    
    
    
    


