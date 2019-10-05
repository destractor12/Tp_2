#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int initEmployees(eEmployee* list, int len)
{
    int r=-1;
    int i;
    if( list != NULL )
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = 0;

        }

        r=0;
    }

    return r;
}

int mostrarMenu()
{
    int opcion;

    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    opcion=validarEntero(opcion,"una opcion: ",1,5);

    return opcion;

}

void alta(eEmployee list[], int len)
{
    int retorno;
    char lastname[51];
    char name[51];
    int sector;
    char auxsector[20];
    float salary;
    int indice;
    int id;
    if(list!=NULL && len >0)
    {

        indice= buscarEspacio(list,len);
        if(indice>=0)
        {
            id=idIncrementado(list,len);
            while(!getStringLetras("Ingrese nombre: ",name))
            {
                printf("\nERROR. Reingrese nombre: ");
            }
            while(!getStringLetras("\nIngrese apellido: ",lastname))
            {
                printf("\nERROR. Reingrese apellido: ");
            }
            while(!getStringNumeros("\nIngrese sector: ",auxsector))
            {
                printf("\nERROR. Solo puede ingresar numeros.\nReingrese Sector: ");
            }
            sector=atoi(auxsector);
            salary=getFloat("Ingrese salario: ");

            retorno=addEmployee(list,len,id,name,lastname,salary,sector);
            if(retorno==0)
            {
                printf("Usuario ingresado");
            }

        }

        if(indice<0)
        {
            printf("\nOpcion incorrecta. \tReintente nuevamente");
        }
    }

}

int findEmployeeById(eEmployee* list, int len, int id)
{
    int retorno=-1;
    int i;

    if(list!=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int removeEmployee(eEmployee* list, int len, int id)
{
    int i;
    int auxindice;
    int r=-1;

    if(list!=NULL)
    {
        printf("\n Ingrese el id que desea borrar: ");
        scanf("%d",&id);
        auxindice=findEmployeeById(list, len, id);

        if(list[auxindice].isEmpty==1)
        {
            printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");

            mostrarEmpleado(list, auxindice);
        }
        for( i=0; i<len; i++)
        {
            if(auxindice >= 0)
            {
                printf("\n La baja se ha concretado exitosamente.\n");
                list[auxindice].isEmpty = 0;
                break;
            }

            else
            {
                printf("\n El id no ha sido encontrado.\n");
                break;
            }

            r=0;
        }
    }

    return r;
}


int mostrarEmpleado(eEmployee* list, int indice)
{
    int retorno=-1;
    if(list!=NULL)
    {
        if(list[indice].isEmpty == 0)
        {
            printf("%d\t    %s\t    %s\t    %f\t    %d \n",list[indice].id, list[indice].name, list[indice].lastName, list[indice].salary, list[indice].sector);
            retorno=0;
        }

    }
    return retorno;
}

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    eEmployee auxEmployee;
    int indice;
    int r=-1;

    indice=buscarEspacio(list,len);


    if(list!=NULL)
    {
        if (indice != -1)
        {
            if(name!=NULL && lastName!=NULL  && salary >0 )
            {
                strcpy(auxEmployee.name, name);
                strcpy(auxEmployee.lastName, lastName);
                auxEmployee.salary=salary;
                auxEmployee.sector=sector;
                auxEmployee.id=generarId();
                auxEmployee.isEmpty = 1;
                list[indice]=auxEmployee;
            }
            r=0;
        }



    }

    return r;
}
    int buscarEspacio (eEmployee* list, int len)
    {
        int indice = -1;
        int i;

        for (i=0; i<len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }


        return indice;
    }


    eEmployee cargarEmployee()
    {
        eEmployee miEmployee;

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(miEmployee.name);

        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(miEmployee.lastName);

        printf("Ingrese el salario: ");
        scanf("%f", &miEmployee.salary);

        printf("Ingrese el sector: ");
        scanf("%d", &miEmployee.sector);

        miEmployee.isEmpty = 1;

        return miEmployee;

    }


    int validarEntero(int numero,char texto[],int min,int max)
    {
        while(numero<min || numero>max)
        {

            printf("\nReingrese %s",texto);
            scanf("%d",&numero);
        }
        return numero;
    }

    int generarId()
    {
        int id = 0;

        id ++;

        return id;
    }


    int idIncrementado(eEmployee* list,int len)
    {
        int i;
        int id;

        i=buscarEspacio(list,len);

        if(i>=0)
        {
            id=i+1015;
        }

        return id;
    }

    int getStringLetras(char mensaje[],char input[])
    {
        char aux[256];
        getString(mensaje,aux);
        if(esSoloLetras(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        return 0;
    }

    int getStringNumeros(char mensaje[],char input[])
    {
        char aux[256];
        getString(mensaje,aux);
        if(esNumerico(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        return 0;
    }

    int esNumerico(char str[])
    {
        int i=0;
        while(str[i] != '\0')
        {
            if(str[i] < '0' || str[i] > '9')
                return 0;
            i++;
        }
        return 1;
    }

    int esSoloLetras(char str[])
    {
        int i=0;
        while(str[i] != '\0')
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
                return 0;
            i++;
        }
        return 1;
    }

    void getString(char mensaje[],char input[])
    {
        printf("%s",mensaje);
        scanf ("%s", input);
    }

    float getFloat(char mensaje[])
    {
        float auxiliar;
        printf("%s",mensaje);
        scanf("%f",&auxiliar);

        return auxiliar;
    }


int printEmployees(eEmployee* list, int length)
{
    int retorno=-1;
    int i;
        for(i=0;i<length;i++)
        {
            if(list!=NULL)
            {
                if(list[i].isEmpty == 1)
                {
                    printf("%d\t    %s\t    %s\t    %f\t    %d \n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
                    retorno=0;
                }

            }
        }
    return retorno;
}

