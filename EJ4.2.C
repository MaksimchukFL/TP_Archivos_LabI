#include<stdio.h> //Se corrige el símbolo faltante
#include<conio.h>
#include<string.h>
#define dir "C:\\archivo.dat" 

struct registro
{
    int cliente;
    char nombre[20];
    float saldo;
};

FILE*arch;
//Se añaden punteros
struct registro reg;
char seguir;
int i;
//Se modifica la carga de datos para que se halle en un método.
void carga_archivo(){
    arch = fopen(dir,"wb"); 
    if(arch == NULL) printf("No se pudo abrir el archivo"); 
    do
    {
        printf("\nIngrese numero de cliente: ");
        scanf("%d",&reg.cliente);
        printf("\nIngrese el nombre: ");
        scanf("%s",&reg.nombre);
        printf("\nIngrese el saldo: ");
        scanf("%f",&reg.saldo);
        printf("\ndesea terminar s/n: ");
        scanf("%s",&seguir);
        fwrite(&reg,sizeof(reg),1,arch);
    }
    while(seguir=='n');
    fclose(arch);
    getch();
}

void mostrar_archivo(){
    int total_cliente;
    float total_saldo;
    arch=fopen(dir,"rb"); 
    if (arch==NULL) printf("Error al abrir el archivo"); 
    total_cliente = 0; total_saldo = 0;
    //Si bien el trabajo no especifica un formato, se le dá uno similar al del ejercicio 5.
    printf("\nID Cliente     Nombre          Saldo");
    while(!feof(arch))
	{
		i=fread(&reg,sizeof(registro),1,arch);
		if(i!=1)
		{
			if(feof(arch)) break;
			else
			{
				printf("Error");
				break;
			}
		}
		printf("\n%d\t\t%s\t\t%.2f",reg.cliente,reg.nombre,reg.saldo);
        total_cliente++; total_saldo += reg.saldo;
	}
	fclose(arch);
    printf("\n\nTotal clientes: %d", total_cliente);
    printf("\nTotal saldos: %.2f",total_saldo);
    getch();
}
int main()
{
    carga_archivo();
    mostrar_archivo();	
}
