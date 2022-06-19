# TP_Archivos_LabI
La parte práctica del trabajo práctico de parcial de Archivos dado en Laboratorio 1 en la universidad. ¡Gracias a Robinson C. Suárez por el aporte de su código en el que se ha basado!

Ejercicio N° 4: Resolver los siguientes ejercicios
4.1: Diseñar un programa que permita generar un archivo de texto que permita cargar cinco
nombres separados por punto. Mostrar el contenido del archivo un nombre abajo del otro.
4.2Dado el siguiente programa, se pide:
i. Correr el programa y corregir los errores
ii. Agregar al programa , mostrar el contenido del archivo cargado previamente mediante el
siguiente formato
include<stdio.h>
#include<conio.h>
#include<string.h>
#define a "c:\\arch.dat"
struct registro
{
int cliente;
char nombre[20];
float saldo;
};
int main()
{
FILE *arch;
struct registro reg;
char seguir;
if ((arch=fopen(a,"wb"))==NULL)
printf("No se pudo abrir el archivo");
do
{
printf("\nIngrese numero de cliente: ");
scanf("%d",&reg.cliente);
printf("\nIngrese el nombre: ");
scanf("%s",&reg.nombre);
printf("\nIngrese el saldo: ");
scanf("%f",&reg.saldo);
fwrite(&reg,sizeof(reg),1,arch);
printf("desea terminar s/n: ");
scanf("\n%c",&seguir);
}
while(seguir=='n');
fclose(arch);
getch();
}
Ejercicio Nº 5
A partir de un archivo binario, generar el siguiente informe:
 Listado de Alumnos
4
DNI Apellido Nombre Nota
------------------------------------------------------------------------------------
……..
……..
Total de Alumnos:
Alumno con la nota más alta:
Alumno con la nota más baja:
Promedio general de los alumnos:
Cantidad de alumnos con nota mayor e igual a 6
Cantidad de alumnos con nota menor a 6
Porcentaje de alumnos con nota mayor e igual a 6
Promedio de alumnos con nota menor a 6
