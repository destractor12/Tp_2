#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    eEmployee list[TAM];
    int opcion;
    int auxcarga;
    int auxid;
    int r;

    auxcarga=initEmployees(list,TAM);
    do
    {
        fflush(stdin);
        opcion = mostrarMenu();



        switch(opcion)
        {
            case 1:if(auxcarga==0)
                    {
                        alta(list,TAM);
                    }
                    else
                    {
                        printf("No se inicializo el array de empleados");
                    }

            break;

            case 2:
            break;

            case 3:if(auxcarga==0)
                    {
                        printf("Ingrese el id del empleado que desea borrar: ");
                        scanf("%d",&auxid);
                        removeEmployee(list,TAM,auxid);
                    }
                    else
                    {
                        printf("No se inicializo el array de empleados");
                    }

            break;

            case 4:if(auxcarga==0)
                    {
                        r=printEmployees(list,TAM);
                        if(r==-1)
                        {
                            printEmployees("No se encontro nada para mostrar");
                        }
                    }
                    else
                    {
                        printf("No se inicializo el array de empleados");
                    }


            break;

            case 5: opcion=5;
            break;
        }
        system("\npause");
        system("cls");
    }while(opcion!=5);

    return 0;
}
