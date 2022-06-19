/*
 ============================================================================
 Name        : tp_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

typedef struct{
	int id;
	char nombre[20];
	char sexo;
	int edad;
}eMascota;

eMascota* mascota_new();
eMascota* mascota_newParametrosStr(char* idStr, char* nombreStr, char* sexoStr, char* edadStr);
void mascota_delete(eMascota* pMascota);

int mascota_setId(eMascota* pMascota, int id);
int mascota_getId(eMascota* pMascota, int* id);
int mascota_setNombre(eMascota* this,char* nombre);
int mascota_getNombre(eMascota* this,char* nombre);
int mascota_setSexo(eMascota* this, char sexo);
int mascota_getSexo(eMascota* this, char* sexo);
int mascota_setEdad(eMascota* this, int edad);
int mascota_getEdad(eMascota* this, int* edad);
int mascota_mostrarMascota(eMascota* this);
int mascota_listarMascotas(LinkedList* pArray);
int mascota_loadFromText(LinkedList* pArray, char* path);

int mascotas_criterio(void* pAuxiliary1, void* pAuxiliary2);

char strToCh(char* string);

int main(void) {
	setbuf(stdout, NULL);
	puts("*******************************");
	puts("Trabajo practico 4: LinkedList");
	puts("*******************************\n");
	puts("ll_newLinkedList(): crea una lista en la memoria dinamica y devuelve un puntero de tipo Linkedlist con la direccion de la lista.");
	puts("Se crea la LinkedList de Mascotas\n");

	LinkedList* mascotas = ll_newLinkedList();
	if(mascotas == NULL){
		exit(1);
	}
	puts("*ll_len: devuelve el tamaño de la lista, es decir la cantidad de elementos en ella.");
	printf("hacemos ll_len(mascotas) y da lo siguiente. Tamaño: %d\n", ll_len(mascotas));
	puts("En este caso es 0, porque aun no se cargo ningun elemento en ella.\n");

	puts("*ll_add: agrega al final de la lista los elementos que le pasemos");
	puts("En este caso voy a agregar elementos que seran levantados de un archivo csv que contiene");
	puts("una lista de mascatos. (id, nombre, sexo, edad)");
	FILE* pFile;
	pFile = fopen("data.csv","r");
	if(pFile == NULL) {
		exit(1);
	}
	char id[10];
	char nombre[10];
	char sexo[10];
	char edad[10];

	eMascota* pMascota;

	while(!feof(pFile)){
		if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, sexo, edad) == 4){
			pMascota = mascota_newParametrosStr(id, nombre, sexo, edad);
			if(pMascota != NULL){
				printf("se agrega mascota: id: %3s - nombre: %10s - sexo: %2s - edad: %3s\n", id, nombre, sexo, edad);
				ll_add(mascotas, pMascota);
				//ret++;
			}
		}
	}
	fclose(pFile);
	puts("Con la siguiente funcion se puede mostrar los elementos agregados a la LinkedList");
	printf("\n\n");
	puts("*ll_get: devuelve un puntero al elemento en la linkedlist cuyo indice fue especificado en la funcion.");
	puts("En este caso se utiliza para realizar un listado por pantalla de todos los elementos de la lista");
	puts("Se recorre la lista con un for, y por cada indice de la lista se levanta un elemento con ll_get a un puntero de tipo");
	puts("mascota y se muestra\n");
	mascota_listarMascotas(mascotas);

	puts("*ll_set: Inserta un elemente en una LinkedList en el indice indicado y pisa al elemento que estaba en esa posicion");
	puts("Se crea la siguiente mascota en la memoria dinamica: id: 11, nombre: Tobi, sexo: m, edad: 12");
	eMascota* pMascotaAux = mascota_newParametrosStr("11", "Tobi", "m", "12");
	puts("Listado previo ll_set");
	mascota_listarMascotas(mascotas);
	ll_set(mascotas, 0, pMascotaAux);
	puts("Listado postarior a ll_set");
	mascota_listarMascotas(mascotas);
	printf("\n\n");

	puts("*ll_remove: Elimina de la lista el elemento que en la posicione que se le indique");
	puts("Por ejemplo, se elimina el elemento de la posicion indice 1, ll_remove(mascotas, 1)");
	ll_remove(mascotas, 1);
	mascota_listarMascotas(mascotas);
	printf("\n\n");

	puts("*ll_isEmpty: dice si la lista esta vacia (1) o si tiene elementos (0)");
	printf("ll_isEmpty(mascotas): %d\n", ll_isEmpty(mascotas));
	printf("\n\n");

	puts("*ll_push: inserta un elemento en la posicion indice especificad desplazando todos los elementos un lugar");
	puts("Se crea la siguiente mascota en la memoria dinamica: id: 12, nombre: Morron, sexo: m, edad: 7 y se la ubica en el indice 3" );
	pMascotaAux = mascota_newParametrosStr("12", "Morron", "m", "7");
	puts("\nSe muestra las mascotas previo al ll_push");
	mascota_listarMascotas(mascotas);
	ll_push(mascotas, 3, pMascotaAux);
	puts("\nSe muestra las mascotas luedo del ll_push");
	mascota_listarMascotas(mascotas);

	printf("\n\n");
	puts("*ll_pop: devuelve en un puntero la direccion de un elemento especificado por su indice y lo elimina de la lista");
	puts("Por ejemplo se hace pMascotaAux = ll_pop(mascotas, 5)");
	pMascotaAux = ll_pop(mascotas, 5);
	puts("\nLa mascota en el puntero pMascotaAux\n");
	printf("  Id      Nombre   Sexo    Edad\n");
	printf("***********************************\n");
	mascota_mostrarMascota(pMascotaAux);

	puts("\nListado luego de ll_pop\n");
	mascota_listarMascotas(mascotas);
	printf("\n\n");

	puts("*ll_contains: Dice si el elemento que le pasamos a la funcion de encuentra en la lista especificada. 1 si lo encuentra, 0 si no");
	puts("Por ejemplo se puede utilizar el elemento que previamente retiramos con la funcion ll_pop.");
	puts("Se hace ll_contains(mascotas, pMascotasAux)");
	printf("Resultado de ll_contains: %d\n\n", ll_contains(mascotas, pMascotaAux));

	puts("*ll_containsALL: dice si todos los elementos de una lista especificada se ecuentran en otra.");
	puts("Para comprobar lo anteriro se va a utilizar primero la funcion ll_subList");
	puts("*ll_subList: crea una lista con los elementos especificados pertenencientes a otra lista");
	puts("Por ejemplo: Se le especifica de que lista se quiere los elementos y desde que indice hasta que otro indice");
	puts("se declara LinkedList* mascotas2 = ll_subList(mascotas, 3, 7)");
	puts("se dijo que se haga una sub lista de los elementos del indice 3 al indice 7\n");
	LinkedList* mascotas2 = ll_subList(mascotas, 3, 7);
	mascota_listarMascotas(mascotas2);
	puts("Ahora se puede utilizar esta sub lista para comprobar ll_containsALL");
	puts("Se hace ll_containsALL(mascotas, mascotas2). Si la contiene retorna 1 si no 0");
	printf("Resultado de ll_containsALL: %d\n", ll_containsAll(mascotas, mascotas2));

	printf("\n\n");
	puts("ll_clone: hace una copia de una lista especificada");
	puts("Se hace LinkedList* mascotasClon = ll_clone(mascotas)");
	LinkedList* mascotasClon = ll_clone(mascotas);
	puts("Lista clonada: \n");
	mascota_listarMascotas(mascotasClon);

	printf("\n\n");
	puts("*ll_sort: ordena los elementos de una lista segun el resultado que devuelva la funcion criterio que se pasa como parametro y");
	puts("el parametro order que dira si se hara el orden de forma descendente o ascendente.");
	puts("Para ordenara, por ejemplo por nombre, se hizo una funcion criterio que es la que se le va a pasar a ll_sort y de acuero a");
	puts("lo que retorne se hara o no el burbujeo.");
	puts("Se muestra la funcion previo al ordenamiento: ");
	mascota_listarMascotas(mascotas);
	puts("la funcion sort quedaria expresada asi: ll_sort(mascotas, mascota_criterio, 1);");
	puts("Se muestra la funcion luego del ordenamiento: ");
	ll_sort(mascotas, mascotas_criterio, 1);
	mascota_listarMascotas(mascotas);

	puts("*ll_indexOf: se le pasa una lista y un elemento y si el mismo se encuentra en la lista devuelve el indice de su primera aparicion.");
	puts("Se hace un ll_get de un elemento de la lista mascota2 y lo buscamos en la lista mascota.");
	puts("pMascota = ll_get(mascotas, 5)");
	pMascota = ll_get(mascotas, 3);
	mascota_listarMascotas(mascotas);
	mascota_listarMascotas(mascotas2);
	printf("Resultado de indexOf: %d\n", ll_indexOf(mascotas2, pMascota));
	puts("Morena de la lista mascota, se encuentra en el indice 2 de mascotas2");

	printf("\n\n");
	puts("*ll_remove: elimina un elemento de la lista segun el indice especificado");
	puts("se hace ll_remove(mascotas,ll_indexOf(mascotas, pMascota))");
	mascota_listarMascotas(mascotas);
	ll_remove(mascotas,ll_indexOf(mascotas, pMascota));
	mascota_listarMascotas(mascotas);

	printf("\n\n");
	puts("*ll_clear: elimina todos los elementos de la lista");
	puts("ll_clear(mascotas)");
	ll_clear(mascotas);
	printf("Se corrobora con ll_isEmpty. Resultado: %d. La lista esta vacia.\n", ll_isEmpty(mascotas));

	printf("\n\n");
	puts("ll_deleteLinkedList: Elimina la lista especificada.");
	printf("ll_deleteLinkedList(mascotas): %d. Funciono correctamente ", ll_deleteLinkedList(mascotas));









	return EXIT_SUCCESS;
}
//--------------------------
eMascota* mascota_new(){
	eMascota* newPassenger = NULL;

	return newPassenger = (eMascota*)malloc(sizeof(eMascota));
}
eMascota* mascota_newParametrosStr(char* idStr, char* nombreStr, char* sexoStr, char* edadStr){
	eMascota* pMascota= mascota_new();
	if(pMascota != NULL){
		if(mascota_setId(pMascota, atoi(idStr)) ||
			mascota_setNombre(pMascota, nombreStr) ||
			mascota_setSexo(pMascota, strToCh(sexoStr)) ||
			mascota_setEdad(pMascota, atoi(edadStr))){

			mascota_delete(pMascota);
			pMascota= NULL;
		}
	}

	return pMascota;
}
void mascota_delete(eMascota* this){
	free(this);
}

int mascota_setId(eMascota* this, int id){
	int ret = -1;
	if(this != NULL && id > 0){
		this->id = id;
		ret = 0;
	}

	return ret;
}
int mascota_getId(eMascota* this, int* id){
	int ret = -1;
	if(this!= NULL && id != NULL){
		*id = this->id;
		ret = 0;
	}
	return ret;
}
int mascota_setNombre(eMascota* this,char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}
int mascota_getNombre(eMascota* this,char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}
int mascota_setSexo(eMascota* this, char sexo){
	int ret = -1;
	if(this != NULL && (sexo == 'f' || sexo == 'm')){
		this->sexo = sexo;
		ret = 0;
	}
	return ret;
}
int mascota_getSexo(eMascota* this, char* sexo){
	int ret = -1;
	if(this!= NULL && sexo != NULL){
		*sexo = this->sexo;
		ret = 0;
	}
	return ret;
}
int mascota_setEdad(eMascota* this, int edad){
	int ret = -1;
	if(this != NULL && edad> 0){
		this->edad = edad;
		ret = 0;
	}
	return ret;

}
int mascota_getEdad(eMascota* this, int* edad){
	int ret = -1;
	if(this != NULL && edad != NULL){
		*edad = this->edad;
		ret = 0;
	}
	return ret;
}
int mascota_mostrarMascota(eMascota* this){
	int ret = -1;
	if(this != NULL){
		int id;
		char nombre[20];
		char sexo;
		int edad;


		mascota_getId(this, &id);
		mascota_getNombre(this, nombre);
		mascota_getSexo(this, &sexo);
		mascota_getId(this, &edad);

		printf("||%4d||%10s||%4c||%4d||\n",id, nombre, sexo, edad);
		ret = 0;
	}
	return ret;
}
int mascota_listarMascotas(LinkedList* pArray){
	int ret = -1;
	if(pArray != NULL){
		eMascota* mascotaAux;
		int len = ll_len(pArray);
		printf("***********************************\n");
		printf("  Id      Nombre   Sexo    Edad\n");
		printf("***********************************\n");
		for(int i = 0; i < len; i++){
			mascotaAux = ll_get(pArray, i);
			mascota_mostrarMascota(mascotaAux);

		}
		ret = 0;
	}
	return ret;
}
//------------------------------
char strToCh(char* string){
	char returnAux = string[0];
	return returnAux;
}
int mascota_parser(FILE* pFile , LinkedList* pArray)
{
	int ret = -1;
	if(pFile != NULL && pArray != NULL){
		ret = 0;

		char id[10];
		char nombre[10];
		char sexo[10];
		char edad[10];

		eMascota* pMascota;

		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, sexo, edad) == 4){
				pMascota = mascota_newParametrosStr(id, nombre, sexo, edad);
				if(pMascota != NULL){
					ll_add(pArray, pMascota);
					ret++;
				}
			}
		}
	}
    return ret;
}
int mascota_loadFromText(LinkedList* pArray, char* path)
{
	int returnAux = -1;
	if(pArray != NULL){
		returnAux = 0;
		FILE* pFile;
		pFile = fopen(path,"r");
		if(pFile != NULL) {

			returnAux = mascota_parser(pFile, pArray);
			fclose(pFile);
		}
	}
	return returnAux;
}

int mascotas_criterio(void* pAuxiliary1, void* pAuxiliary2)
{
	int compare = 0;
	if(pAuxiliary1 != NULL && pAuxiliary2 != NULL){

		eMascota* pAux1;
		eMascota* pAux2;
		pAux1 = (eMascota*)pAuxiliary1;
		pAux2 = (eMascota*)pAuxiliary2;

		char pAux1Name[10];
		char pAux2Name[10];
		mascota_getNombre(pAux1, pAux1Name);
		mascota_getNombre(pAux2, pAux2Name);

		if(pAux1!=NULL && pAux2!=NULL)
		{
			compare = strcmp(pAux1Name,pAux2Name);
		}
	}
	return compare;
}
