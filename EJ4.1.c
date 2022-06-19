#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define dir "C:\\archivo.dat" //Escojo la dirección del disco C genérica para Windows. 


FILE*arch; //Puntero

char nombre[50]; 
char nombres[100]; 

int c; 

void carga_archivo()
{
    arch = fopen(dir,"w"); //Apertura del archivo

    if((arch) == NULL) printf("Error al abrir el archivo"); //Control de errores
    else
    {
        for (int i = 0; i < 5; i++)
        {
			//Los nombres estarán separados en el interior del archivo por un punto que aquí se concatena.
            printf("Ingrse nombre: ");
            scanf("%s",&nombre);
            strcat(nombres,nombre);
            strcat(nombres,".");
        }

        fwrite(&nombres, sizeof(nombres),1,arch);//Datos de los nombres
    }

    fclose(arch);//Clausura del archivo

    getch();

}

//Metodo para mostrar el contenido del archivo
void mostrar_archivo(){
    arch = fopen(dir,"r"); //Apertura(modo lectura)

    if(arch = NULL) printf("Error en la apertura del archivo"); 
    else{
        fread(&nombres,sizeof(nombres),1,arch); 

        c = strlen(nombres); 

        for (int i = 0; i < c; i++)
        {
            //Se muestran los datos. Se establece la condición de separarlos si se halla el punto

            if(nombres[i] == '.'){
                printf("\n");
            }
            else{
                printf("%c",nombres[i]);
            }
        }
    }

    fclose(arch); //Clausura del archivo

    getch();
}
int main(){

    carga_archivo();
    mostrar_archivo();

    getch();

}
