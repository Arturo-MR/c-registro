#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
// #include "RegUsuarios.cpp"
// #include "ModUsuarios.cpp"
//#include "Catalogo.cpp"

//#include "Catalogo.cpp";







//PRINCIPAL
void User(){
    
    //VARIABLES
    int opc,opc2,j;
    
    //MENU PRINCIPAL USER
    system("cls");
    printf("1. Registro\n");
    printf("2. Loguearse\n");
    printf("ELIJA UNA OPCION \n");
    scanf("%d",&opc);
    
    switch (opc){//Switch 1
           
           case 1:
                
           RegUsuarios();
                
          break;
           
           case 2:
           
           Log();
           
           break;
           
           }
          }
           
           //FIN SWITCH 2




     

    
    
    
    
    
    


