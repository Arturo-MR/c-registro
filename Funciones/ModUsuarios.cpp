#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <string.h>

//FUNCION MODIFCAR USUARIO
void ModUsuario(){
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
    FILE *Usuario;
    int opc,opc2,i,j;
    
    Persona RegUser;
    
    //ESTRUCTURAS
     i=0;
    char Desea;
    
 	Usuario = fopen("Archivos\\Usuarios.dat","r+b");
 	system("cls");
    
    printf("Por favor ingrese la clave del usuario que deasea Modificar.\n");
    scanf("%d",&j);
    fflush(stdin);
    fread(&RegUser, sizeof(RegUser),1,Usuario);
    while(!feof(Usuario)==1){
 	 	fflush(stdin);
        
 	 	if (i==j){
 	 		printf("El nombre del usuario a Modificar es: %s ? (S/N)\n",RegUser.Nombre);
 	 		fflush(stdin);
			scanf("%c",&Desea);
			
			if (Desea =='S' || Desea =='s'){ //Entran los valores
				
                
				do
				{
                    system("cls");
                    printf("<Por Favor seleccione el campo que desea modificar>\n");
                    printf("------------------------\n");
                    printf("  1. Nombre             \n");
                    printf("  2. Apellido           \n");
                    printf("  3. Edad               \n");
                    printf("  4. Direccion          \n");
                    printf("  5. Telefono           \n");
                    printf("  6. <GUARDAR CAMBIOS>  \n");
                    printf("------------------------\n");
                    printf("Opcion:");
                    fflush(stdin);
                    scanf("%d",&opc2);
                    
                    
                    switch (opc2){
                        case 1: //Nombre
                            fflush(stdin);
                            system("cls");
                            printf("Nuevo Nombre:");
                            gets(RegUser.Nombre);
                            system("PAUSE");
                            
                            break;
                            
                            
                        case 2://Apellido
                            fflush(stdin);
                            system("cls");
                            printf("Nuevo Apellido: ");
                            gets(RegUser.Apellido);
                            system("PAUSE");
                            
                            break;
                            
                            
                        case 3://Edad
                            fflush(stdin);
                            system("cls");
                            printf("Nueva Edad:");
                            scanf("%d",&RegUser.Edad);
                            system("PAUSE");
                            
                            break;
                            
                            
                        case 4://Direccion
                            fflush(stdin);
                            system("cls");
                            printf("Nuevo Direccion:");
                            gets(RegUser.Direccion);
                            system("PAUSE");
                            
                            break;
                            
                            
                        case 5://Telefono
                            fflush(stdin);
                            system("cls");										
                            printf("Nuevo Telefono:");
                            scanf("%d",&RegUser.Telefono);
                            system("PAUSE");
                            
                            break;
                            
                    }
                    
                    
                } while (opc2 !=6);
                fseek(Usuario, sizeof(RegUser)*(j),0);
				fwrite(&RegUser, sizeof(RegUser),1,Usuario);
				printf("Archivo Modificado\n");
				fflush(stdin);
				system("PAUSE");
				break;
            }else{
                printf("El Nombre %s NO se modifico\n",RegUser.Nombre);
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
        fread(&RegUser, sizeof(RegUser),1,Usuario);
        
 	}//Fin Whiles
    
    
 	fclose(Usuario);
    
}//Fin funcion
