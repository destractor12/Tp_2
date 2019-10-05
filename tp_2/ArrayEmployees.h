typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;


int initEmployees(eEmployee* , int );
int mostrarMenu();
int addEmployee(eEmployee*, int, int, char[],char[],float,int );
int validarEntero(int,char[],int,int);
eEmployee cargarEmployee();
int buscarEspacio (eEmployee* ,int);
void alta(eEmployee[], int);
int idIncrementado(eEmployee* ,int);
int getStringLetras(char[],char[]);
int getStringNumeros(char[],char[]);
void getString(char[],char[]);
int esSoloLetras(char[]);
int esNumerico(char[]);
float getFloat(char[]);
int mostrarEmpleado(eEmployee*, int);
int removeEmployee(eEmployee*, int, int);
int findEmployeeById(eEmployee*, int, int);
int generarId();
