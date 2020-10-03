#include <stdio.h>
#include <stdlib.h>
#include "sEmployees.h"
#include "menu.h"

#define SIZE 1000

int main()
{
    int position;
    int answer;
    int idNumber=0;
    sEmployee employees[SIZE];/*={{1,"juan","gimenez",1001,1,0},{4,"juan","lopez",2500,3,0},
                              {3,"juan","lopez",500,1,0},{2,"marco","lopez",700,2,0},
                              {5,"pipo","zarate",3300,2,0},{6,"german","almada",300,1,0},
                              {7,"lucas","pratto",512,2,0}};*/

    initEmployees(employees,SIZE);
    menuInputOutput(employees,SIZE,idNumber,&idNumber);

}



