#include "sEmployees.h"
#include "validations.h"

#define EMPTY 1
#define FULL 0

int initEmployees(sEmployee employees[],int size)//funciona
{
    int i;
    for(i=0;i<size;i++)///arreglar
    {
        employees[i].id     =0;
        strcpy(employees[i].name,"EMPTY");
        strcpy(employees[i].lastName,"EMPTY");
        employees[i].salary =0;
        employees[i].sector =0;
        employees[i].isEmpty=EMPTY;

    }
    return 0;
}
void menuInputOutput(sEmployee employees[],int size,int value,int*idNumber)
{
    char string[5];//por la validacion de tamaño
    int option;
    int flag=0;
    int id=0;

    id=value;
    do
    {

        printf("1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n10.SALIR\n");
        ggets(string,5);
        sizeValidation(string,5);
        while (!isStringInteger(string))
        {
            printf("Valor invalido, reingrese un numero");
            ggets(string,5);
            sizeValidation(string,5);
        }
        stringToInteger(string,&option);
        switch(option)
        {
            case 1:
                system("cls");
                addEmployees(employees,size,id,&id);
                *idNumber=id;
                system("cls");
            break;
            case 2:
                if(id==0)
                {
                    printf("Aun no se ha ingresado ningun empleado, ingrese a la opcion nro 1");
                    getch();
                    break;
                }
                else
                {
                    system("cls");
                    modifyEmployees(employees,size);
                    system("cls");
                }
            break;
            case 3:
                 if(id==0)
                {
                    printf("Aun no se ha ingresado ningun empleado, ingrese a la opcion nro 1");
                    getch();
                    break;
                }
                else
                {
                system("cls");
                removeEmployee(employees,size);
                system("cls");
                }
            break;
            case 4:
                 if(id==0)
                {
                    printf("Aun no se ha ingresado ningun empleado, ingrese a la opcion nro 1");
                    getch();
                    break;
                }
                else
                {
                system("cls");
                inform(employees,size);
                system("cls");
                }
            break;
            case 10:
                system("cls");
                system("cls");
            break;
            default:
                printf("Valor invalido, reingrese la opcion\n");
            break;

        }
    }while(option!=10);

return option;
}
int searchIsEmpty(sEmployee employeeList[],int size)//posicion -1 = no hay EMPTY //funciona
{
    int i;
    int aux;
    int position = -1;

    for(i=0;i<size;i++)
    {
        aux=isEmpty(employeeList,i);
        if (aux == EMPTY)// 1= esa posicion esta empty
        {
            position=i;
            break;
        }
    }
    return position;
}

int isEmpty(sEmployee employee[],int position)// 0=FALSE 1=TRUE
{
    int answer = 0;
    if (employee[position].isEmpty == 1)
    {
        answer = 1;
    }
    return answer;
}
int idGenerator(int value,int *idNumber)
{
    int answer = 1;
    int aux = value++;
    *idNumber = value;
    return answer;
}
sEmployee addAnEmployee(int value,int *idNumber)
{
    int i;
    sEmployee employee;
    char stringLastName[51];
    char stringName[51];
    char stringSalary[10];
    char stringSector[5];

    printf("INGRESE APELLIDO: ");
    ggets(stringLastName,51);
    sizeValidation(stringLastName,51);
    while(!isStringLetters(stringLastName))
    {
        printf("ERROR, REINGRESE APELLIDO: \n");
        ggets(stringLastName,51);
        sizeValidation(stringLastName,51);
    }
    for(i=0; i < 51; i++)
    {
        if (i == 0)
        {
            stringLastName[i] = toupper(stringLastName[i]);
        }
        else
        {
            if (stringLastName[i] == ' ')
            {
                stringLastName[i+1] = toupper (stringLastName[i+1]);
            }
        }
    }
    strcpy(employee.lastName,stringLastName);

    printf("INGRESE NOMBRE: ");
    ggets(stringName,51);
    sizeValidation(stringName,51);
    while(!isStringLetters(stringName))
    {
        printf("ERROR, REINGRESE NOMBRE: \n");
        ggets(stringName,51);
        sizeValidation(stringName,51);
    }
    for(i=0; i < 51; i++)
    {
        if (i == 0)
        {
            stringName[i] = toupper(stringName[i]);
        }
        else
        {
            if (stringName[i] == ' ')
            {
                stringName[i+1] = toupper (stringName[i+1]);
            }
        }
    }
    strcpy(employee.name,stringName);

    printf("INGRESE SALARIO: "); //arreglar los negativos!!!!!!!
    ggets(stringSalary,10);
    sizeValidation(stringSalary,10);
        while (!isStringFloat(stringSalary))///arreglarlo usando una condicion en el while
        {
            printf("Valor invalido, reingrese un numero:\n");
            ggets(stringSalary,10);
            sizeValidation(stringSalary,10);
        }
    stringToFloat(stringSalary,&employee.salary);

    printf("INGRESE SECTOR: "); //arreglar los negativos!!!!!!!
    ggets(stringSector,5);
    sizeValidation(stringSector,5);
        while (!isStringInteger(stringSector))///arreglarlo usando una condicion en el while
        {
            printf("Valor invalido, reingrese un numero:\n");
            ggets(stringSector,5);
            sizeValidation(stringSector,5);
        }
    stringToInteger(stringSector,&employee.sector);

    int id=value;
    idGenerator(id,&id);
    *idNumber=id;
    employee.id=id;
    employee.isEmpty=FULL;

    return employee;
}
int addEmployees(sEmployee employeeList[],int size,int value,int*idNumber) //por ahora funciona
{
    int i;
    int option;
    int id;
    id=value;
    do
    {
        i = searchIsEmpty(employeeList,size);

        if (i != -1)
        {
            employeeList[i]=addAnEmployee(id,&id);
            *idNumber=id;
        }
        else
        {
            printf("Falta de espacio, no es posible ingresar otro empleado\n");
        }
        printf("Precione '1' para ingresar otro empleado.\n");
        scanf("%d",&option);
    }while (option==1);

    return -1;
}
int findEmployeeId(sEmployee employeeList[],int size,int idNumber,int *position)//funciona
{
    int i;
    int answer = -1;
    for(i=0;i<size;i++)
    {
        if (idNumber==employeeList[i].id)
        {
            *position=i;
            answer = 0;
        }
    }
    return answer;
}
int modifyLastName(sEmployee employeeList[],int size,int position)//funciona
{
    char stringLastName[51];

    printf("INGRESE APELLIDO: \n");
    ggets(stringLastName,51);
    sizeValidation(stringLastName,51);
    while(!isStringLetters(stringLastName))
    {
        printf("ERROR, REINGRESE APELLIDO: \n");
        ggets(stringLastName,51);
        sizeValidation(stringLastName,51);
    }
    int i;
    for(i=0; i < 51; i++)
    {
        if (i == 0)
        {
            stringLastName[i] = toupper(stringLastName[i]);
        }
        else
        {
            if (stringLastName[i] == ' ')
            {
                stringLastName[i+1] = toupper (stringLastName[i+1]);
            }
        }
    }
    strcpy(employeeList[position].lastName,stringLastName);

    return 0;

}
int modifyName(sEmployee employeeList[],int size,int position)//funciona
{
    char stringName[51];

    printf("INGRESE NOMBRE: \n");
    ggets(stringName,51);
    sizeValidation(stringName,51);
    while(!isStringLetters(stringName))
    {
        printf("ERROR, REINGRESE NOMBRE: \n");
        ggets(stringName,51);
        sizeValidation(stringName,51);
    }
    int i;
    for(i=0; i < 51; i++)
    {
        if (i == 0)
        {
            stringName[i] = toupper(stringName[i]);
        }
        else
        {
            if (stringName[i] == ' ')
            {
                stringName[i+1] = toupper (stringName[i+1]);
            }
        }
    }
    strcpy(employeeList[position].name,stringName);

    return 0;

}
int modifySalary(sEmployee employeeList[],int size,int position)
{
    char stringSalary[10];
    float salary;

    printf("INGRESE SALARIO: "); //arreglar los negativos!!!!!!!
    ggets(stringSalary,10);
    sizeValidation(stringSalary,10);
        while (!isStringFloat(stringSalary))///arreglarlo usando una condicion en el while
        {
            printf("Valor invalido, reingrese un numero: ");
            ggets(stringSalary,10);
            sizeValidation(stringSalary,10);
        }
    stringToFloat(stringSalary,&salary);
    employeeList[position].salary=salary;

    return 0;
}
int modifySector(sEmployee employeeList[],int size, int position)
{
    char stringSector[5];
    int sector;

    printf("INGRESE SECTOR: "); //arreglar los negativos!!!!!!!
    ggets(stringSector,5);
    sizeValidation(stringSector,5);
        while (!isStringInteger(stringSector))///arreglarlo usando una condicion en el while
        {
            printf("Valor invalido, reingrese un numero: ");
            ggets(stringSector,5);
            sizeValidation(stringSector,5);
        }
    stringToInteger(stringSector,&sector);
    employeeList[position].sector=sector;
}
int modifyFields(sEmployee employeeList[],int size,int position)
{
    char string[4];//por la validacion de tamaño
    int option;

    do
    {

        printf("1.MODIFICAR APELLIDO\n2.MODIFICAR NOMBRE\n3.MODIFICAR SALARIO\n4.MODIFICAR SECTOR\n10.SALIR\n");
        ggets(string,5);
        sizeValidation(string,5);
        while (!isStringInteger(string))
        {
            printf("Valor invalido, reingrese un numero");
            ggets(string,5);
            sizeValidation(string,5);
        }
        stringToInteger(string,&option);
        switch(option)
        {
            case 1:
                system("cls");
                modifyLastName(employeeList,size,position);
                system("cls");
            break;
            case 2:
                system("cls");
                modifyName(employeeList,size,position);
                system("cls");
            break;
            case 3:
                system("cls");
                modifySalary(employeeList,size,position);
                system("cls");
            break;
            case 4:
                system("cls");
                modifySector(employeeList,size,position);
                system("cls");
            break;
            default:
                printf("Valor invalido, reingrese la opcion\n");
            break;
            case 10:
                system("cls");
            break;

        }
    }while(option!=10);

}
int modifyEmployees(sEmployee employeeList[],int size)
{
    char string[10];//por la validacion de tamaño
    char stringOption[5];
    int option;
    int idNumber;
    int answer;
    int position;
    do
    {
        printf("1.MODIFICAR\n10.SALIR\n");
        ggets(stringOption,5);
        sizeValidation(stringOption,5);
        while (!isStringInteger(stringOption))
        {
            printf("Valor invalido, reingrese un numero\n");
            ggets(stringOption,5);
            sizeValidation(stringOption,5);
        }
        stringToInteger(stringOption,&option);
        switch(option)
        {
            case 1:
                printf("INGRESE NUMERO DE 'ID'\n");
                ggets(string,10);
                sizeValidation(string,10);
                while (!isStringInteger(string))
                {
                    printf("Valor invalido, reingrese un numero\n");
                    ggets(string,10);
                    sizeValidation(string,10);
                }
                stringToInteger(string,&idNumber);
                answer=findEmployeeId(employeeList,size,idNumber,&position);
                if(answer)
                {
                    printf("No se encontro ningun empleado con ese numero de ID\n");
                }
                else
                {
                    modifyFields(employeeList,size,position);
                }
            break;
            default:
               printf("Opcion invalida\n");
            break;
            case 10:
                system("cls");
            break;
        }
    }
    while(option!=10);

    return 0;
}
int removeEmployee(sEmployee employeeList[],int size)
{
    char string[10];
    char stringOption[5];
    int option;
    int idNumber;
    int answer;
    int position;
    do
    {
        printf("1.ELIMINAR EMPLEADO\n10.SALIR\n");
        ggets(stringOption,5);
        sizeValidation(stringOption,5);
        while (!isStringInteger(stringOption))
        {
            printf("Valor invalido, reingrese un numero\n");
            ggets(stringOption,5);
            sizeValidation(stringOption,5);
        }
        stringToInteger(stringOption,&option);
        switch(option)
        {
            case 1:
                printf("INGRESE NUMERO DE 'ID'");
                ggets(string,10);
                sizeValidation(string,10);
                while (!isStringInteger(string))
                {
                    printf("Valor invalido, reingrese un numero\n");
                    ggets(string,10);
                    sizeValidation(string,10);
                }
                stringToInteger(string,&idNumber);
                answer=findEmployeeId(employeeList,size,idNumber,&position);
                if(answer)
                {
                    printf("No se encontro ningun empleado con ese numero de ID\n");
                }
                else
                {
                    removeAnEmployee(employeeList,position);
                }
            break;
            default:
               printf("Opcion invalida");
            break;
            case 10:
                system("cls");
            break;
        }
    }
    while(option!=10);

    return 0;
}
int removeAnEmployee(sEmployee employeeList[],int position)
{
    employeeList[position].id=0;
    strcpy(employeeList[position].lastName,"EMPTY");
    strcpy(employeeList[position].name,"EMPTY");
    employeeList[position].salary=0;
    employeeList[position].sector=0;
    employeeList[position].isEmpty=1;

    return 0;
}

int sortEmployees(sEmployee employeeList[],int size,int isUP)
{
    int i;
    int j;
    int auxInt;
    float auxFloat;
    char auxString[100];

    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if (isUP==1)
            {
                if(strcmp(employeeList[i].lastName,employeeList[j].lastName) > 0)//(employeeList[i].sector > employeeList[j].sector))
                {
                    auxFloat = employeeList[i].salary;
                    employeeList[i].salary = employeeList[j].salary;
                    employeeList[j].salary = auxFloat;

                    auxInt = employeeList[i].id;
                    employeeList[i].id = employeeList[j].id;
                    employeeList[j].id = auxInt;

                    auxInt = employeeList[i].sector;
                    employeeList[i].sector = employeeList[j].sector;
                    employeeList[j].sector = auxInt;

                    auxInt = employeeList[i].isEmpty;
                    employeeList[i].isEmpty = employeeList[j].isEmpty;
                    employeeList[j].isEmpty = auxInt;

                    strcpy(auxString,employeeList[i].lastName);
                    strcpy(employeeList[i].lastName, employeeList[j].lastName);
                    strcpy(employeeList[j].lastName,auxString);

                    strcpy(auxString,employeeList[i].name);
                    strcpy(employeeList[i].name, employeeList[j].name);
                    strcpy(employeeList[j].name,auxString);

                }
            }
            else
            {
                if(strcmp(employeeList[j].lastName,employeeList[i].lastName) > 0)//(employeeList[i].sector > employeeList[j].sector))
                {
                    auxFloat = employeeList[i].salary;
                    employeeList[i].salary = employeeList[j].salary;
                    employeeList[j].salary = auxFloat;

                    auxInt = employeeList[i].id;
                    employeeList[i].id = employeeList[j].id;
                    employeeList[j].id = auxInt;

                    auxInt = employeeList[i].sector;
                    employeeList[i].sector = employeeList[j].sector;
                    employeeList[j].sector = auxInt;

                    auxInt = employeeList[i].isEmpty;
                    employeeList[i].isEmpty = employeeList[j].isEmpty;
                    employeeList[j].isEmpty = auxInt;

                    strcpy(auxString,employeeList[i].lastName);
                    strcpy(employeeList[i].lastName, employeeList[j].lastName);
                    strcpy(employeeList[j].lastName,auxString);

                    strcpy(auxString,employeeList[i].name);
                    strcpy(employeeList[i].name, employeeList[j].name);
                    strcpy(employeeList[j].name,auxString);

                }
            }
        }
    }
}

int informData(sEmployee employeeList[],int size)
{
    int i;
    int employeeCounter=0;
    int overAverageSalaryCounter=0;
    float totalSalary;
    float averageSalary;


    for(i=0;i<size;i++)
    {
        if(employeeList[i].isEmpty==0)
        {
            totalSalary=totalSalary+employeeList[i].salary;
            employeeCounter++;
        }
    }
    averageSalary=totalSalary/employeeCounter;
    for(i=0;i<size;i++)
    {
        if(employeeList[i].salary > averageSalary)
        {
            overAverageSalaryCounter++;
        }
    }
    printf("SALARIO TOTAL || SALARIO PROMEDIO || EMPLEADOS QUE SUPERAN LA MEDIA\n");
    printf("%-20.2f %-20.2f" "%-30d\n",totalSalary,averageSalary,overAverageSalaryCounter);
    getch();
    system("cls");
    return 0;
}
int inform(sEmployee employeeList[],int size)
{
    int optionUP;
    int option;
    do{
        printf("1.ORDENAR ALFABETICAMENTE\n2.INFORME\n10.SALIR\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                system("cls");
                do{
                    printf("1.ASCENDETE\n2.DESCENDENTE\n10.SALIR\n");
                    scanf("%d",&optionUP);
                    switch(optionUP)
                    {
                        case 1:
                            sortEmployees(employeeList,size,optionUP);
                            printEmployees(employeeList,size);

                        break;
                        case 2:
                            sortEmployees(employeeList,size,optionUP);
                            printEmployees(employeeList,size);
                        break;
                        case 10:
                        break;
                        default:
                            system("cls");
                            printf("Opcion invalida\n");
                        break;
                    }
                }while(optionUP!=10);

            break;
            case 2:
                system("cls");
                informData(employeeList,size);
            break;
            default:
                system("cls");
                printf("Opcion invalida\n");

            break;
            case 10:
                system("cls");
            break;

        }
    }while(option !=10);
    return 0;

}
int printEmployees(sEmployee employeeList[],int size)
{
    int i;
    system("cls");
     printf("APELLIDO ------NOMBRE-------SALARIO-------SECTOR------ID-----\n");
    for(i=0;i<size;i++)
    {
        if(!employeeList[i].isEmpty)
        {
            printf("%-15s %-11s %-15.2f %-10d%-10d\n",employeeList[i].lastName,employeeList[i].name,employeeList[i].salary,employeeList[i].id,employeeList[i].id);

        }
    }
    getch();
    system("cls");
    return 0;
}
