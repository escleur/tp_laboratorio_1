#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;
Empleado* empleado_new();
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void empleado_delete(Empleado* this);

int empleado_setId(Empleado* this,int id);
int empleado_getId(Empleado* this,int* id);

int empleado_setNombre(Empleado* this,char* nombre);
int empleado_getNombre(Empleado* this,char* nombre);

int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int empleado_setSueldo(Empleado* this,int sueldo);
int empleado_getSueldo(Empleado* this,int* sueldo);
int compararPorNombre(void* e1, void* e2);

void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
