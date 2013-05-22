#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Estructuras
typedef struct Persona{
        
        char Nombre[31];
        char Apellido[31];
        long int Edad;
        char Direccion[50];
        int Telefono;
        int Id;
        int Activo;
        
    };
    //Variables
    FILE *Usuario;
    FILE *ID2;
    Persona RegUser;
    int id2;

void ModUsuario(){ //FUNCION
    system("cls");
    int opc,opc2,i,j;
    i=0;
    char Desea;
 	Usuario = fopen("Archivos\\Usuarios.dat","r+b");
 	system("cls");
    printf("Por favor ingrese la ID del usuario que deasea Modificar.\n");
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
                            scanf("%ld",&RegUser.Telefono);
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

void RegUsuarios(){
    system("cls");
    //VARIABLES
    char Desea;
    
    //INSTRUCCIONES
    Usuario = fopen("Archivos\\Usuarios.dat","a+b");
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
        scanf("%ld",&RegUser.Telefono);
        
        fflush(stdin);
		RegUser.Id = id2++;
		RegUser.Activo = 1;
		printf("La clave del Usuario %s es %d\n",RegUser.Nombre,RegUser.Id);
        system("PAUSE");
		//GUARDAR REGISTRO
		fflush(stdin);
        fwrite(&RegUser, sizeof(RegUser),1,Usuario);
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
    fclose(Usuario);
	fclose(ID2);
    
}
void CatalogoU(){
    Usuario = fopen("Archivos\\Usuarios.dat","rb");
    system("cls");
    printf("<Usuarios Registrados en iTicket>\n");
    fread(&RegUser, sizeof(RegUser),1,Usuario);
    printf("Nombre      Apellido      Edad   Direccion     Telefono     ID\n");
    while(!feof(Usuario)==1){
        if (RegUser.Activo == 1)
        {
            printf("%-10s  %-10s     %2d    %-10s    %-11ld %2d\n",RegUser.Nombre, RegUser.Apellido, RegUser.Edad, RegUser.Direccion, RegUser.Telefono, RegUser.Id );
        }
        fread(&RegUser, sizeof(RegUser),1,Usuario);
    }
     fclose(Usuario);
     system("PAUSE");

} 

void BajasU(){
    Usuario = fopen("Archivos\\Usuarios.dat","r+b");
    system("cls");
    int j,i;
    i=0;
    char Desea;
    printf("Ingresa el ID del Usuario a Eliminar");
    scanf("%d",&j); //ID POR USER
    fread(&RegUser, sizeof(RegUser),1,Usuario);
    while(!feof(Usuario)==1){
        fflush(stdin);
        if (i==j)
        {
            printf("Seguro que Desea Eliminar a %s\n (S/N)", RegUser.Nombre);
            scanf("%c",&Desea);
            if (Desea =='S' || Desea =='s')
            {
                fseek(Usuario, sizeof(RegUser)*(i),0);
                RegUser.Activo = 0;
                fwrite(&RegUser, sizeof(RegUser),1,Usuario);
                system("cls");
                printf("Usuario Eliminado\n");
                fflush(stdin);
                system("PAUSE");
                break;
            }else{
                system("cls");
                printf("Usuario NO Eliminado\n");
                system("PAUSE");
                break;
            }

        }//AcabaPrimerIF
        i++;
        fflush(stdin);
        fread(&RegUser, sizeof(RegUser),1,Usuario);
    }
    fclose(Usuario);
}

void Log(){
     int j,i,opc2,opc,n,m;
    
            system("cls");
            m=0;
            n=0;
            do
             {
              
            system("cls");
            if (m>0)
            {
                printf("<< EL USUARIO NO EXISTE INTENTA DE NUEVO >>\n");
            }
            printf("Ingresa Tu ID:");
            scanf("%d",&j);
            //Verifica
             Usuario = fopen("Archivos\\Usuarios.dat","rb");
             fread(&RegUser, sizeof(RegUser),1,Usuario);
             while(!feof(Usuario)==1){
             
             if (j==RegUser.Id)
             {
                if (RegUser.Id == j)
                {
                    n=1;
                }
                 
             }
             m++;
             fread(&RegUser, sizeof(RegUser),1,Usuario);
         }
            
            } while (n!=1);
          fclose(Usuario);

         //FIN VERIFICA
            do{
            system("cls");
            printf("1. MODIFICAR PERFIL \n");
            printf("2. VER PERFIL \n");
            printf("3. BUSCAR CONCIERTOS\n");
            printf("4. <- REGRESAR\n");
            printf("\nELIJA UNA OPCION: ");
            scanf("%d",&opc2);

        
        
        
        //SWITCH 2
        switch (opc2){
                
            case 1: //FUNCION MODIFICAR Usuario
                
        system("cls");
        int opc,opc2,i;
        i=0;
        char Desea;
        Usuario = fopen("Archivos\\Usuarios.dat","r+b");
        system("cls");
        fflush(stdin);
        fread(&RegUser, sizeof(RegUser),1,Usuario);
        while(!feof(Usuario)==1){
            fflush(stdin);
            
            if (i==j){
                printf("%s Seguro que deseas Modificar Tu Perfil ? (S/N)\n",RegUser.Nombre);
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
                            scanf("%ld",&RegUser.Telefono);
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
        //  printf("La Clave no existe\n");
        //  system("PAUSE");
        //  break;
        // }//Ultimo IF
        i++;
        fflush(stdin);
        fread(&RegUser, sizeof(RegUser),1,Usuario);
        
    }//Fin Whiles
    
    
    fclose(Usuario);
                
                break;
                
                
            case 2: //FUNCION VER PERFIL                              
        
        i=0;
        Usuario = fopen("Archivos\\Usuarios.dat","rb");
        system("cls");
        printf("<Usuarios Registrados en iTicket>\n");
        fread(&RegUser, sizeof(RegUser),1,Usuario);
        printf("Nombre      Apellido      Edad   Direccion     Telefono     ID\n");
        while(!feof(Usuario)==1){
            if (j==RegUser.Id)
            {
                if (RegUser.Activo == 1)
            {
                printf("%-10s  %-10s     %2d    %-10s    %-11ld %2d\n",RegUser.Nombre, RegUser.Apellido, RegUser.Edad, RegUser.Direccion, RegUser.Telefono, RegUser.Id );
                
                break;
            }
            }
            i++;
            fread(&RegUser, sizeof(RegUser),1,Usuario);
        }
         fclose(Usuario);
         
         system("PAUSE");
                
                break;

                case 3://FUNCION CATALOGO

                Catalogo();
                break;
        }
        
    }while (opc2!=4);
}
