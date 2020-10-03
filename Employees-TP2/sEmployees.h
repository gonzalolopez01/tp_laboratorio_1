#ifndef SEMPLOYEES_H_INCLUDED
#define SEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;


int initEmployees(sEmployee employees[],int size);
void menuInputOutput(sEmployee employess[], int size, int value,int*idNumber);
int idGenerator(int value,int *idNumber);
int isEmpty(sEmployee employee[],int position);
int searchIsEmpty(sEmployee employeeList[],int size);
sEmployee addAnEmployee(int value,int*idNumber);
int addEmployees(sEmployee employeeList[],int size,int value,int*idNumber);
int findEmployeeId(sEmployee employeeList[],int size,int idNumber,int *position);
int modifyLastName(sEmployee employeeList[],int size,int position);
int modifyName(sEmployee employeeList[],int size,int position);
int modifySalary(sEmployee employeeList[],int size,int position);
int modifySector(sEmployee employeeList[],int size, int position);
int modifyFields(sEmployee employeeList[],int size,int position);
//int modifyEmployees(sEmployee employeeList[],int size);
//int removeEmployee(sEmployee employeeList[],int size);
int removeAnEmployee(sEmployee employeeList[],int position);
int informData(sEmployee employeeList[],int size);
int sortEmployees(sEmployee employeeList[],int size,int isUP);
int inform(sEmployee employeeList[],int size);
int removeEmployee(sEmployee employeeList[],int size);

#endif // SEMPLOYEES_H_INCLUDED
