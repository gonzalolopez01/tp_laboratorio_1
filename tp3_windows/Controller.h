#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include  "inputs.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int*id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

void controller_editMenu(LinkedList* pArrayListEmployee, Employee* pAux, int index);
void controller_sortMenu(LinkedList* pArrayListEmployee);
int controller_getIndexByID(LinkedList* pArrayListEmployee,int ID);

int controller_loadID(char* path, int *id);
int controller_saveID(char* path , int id);

void controller_Menu(LinkedList* pArrayListEmployee);
#endif //CONTROLLER_H_INCLUDED
