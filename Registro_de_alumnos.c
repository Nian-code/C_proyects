#include <stdio.h>
#include <string.h>
#define CAPACIDAD 10
#define NUMMAX 10

int search_alumno(), posicion;
int  delete_alumnos();
void imprimir_alumnos();
char ingresar_datos();

int main(){
    char alumnos[NUMMAX][CAPACIDAD] = {'\0'};//{"Jesus", "Alejandro","Nicoll", "Sebas"};
    int tamArreglo =  4;
    int bandera = 1, opcion;


    while(bandera==1){
        printf("\n");
		printf("1. Ingresar alumnos a la base \n");
        printf("2. Buscar un alumno en la base\n");
		printf("3. Listar alumnos\n");
		printf("4. Eliminar un alumno de la base\n");
		printf("9. salir\n");
        printf("ingrese una opcion: ");
		scanf("%d", &opcion);

	switch(opcion){

		case 1: 
            ingresar_datos(alumnos);
            break;
        case 2:    
            posicion = search_alumno(alumnos, tamArreglo);
            break;
        case 3:
            imprimir_alumnos(alumnos, tamArreglo);
            break;
        case 4:
            posicion = search_alumno(alumnos, tamArreglo);
            tamArreglo = delete_alumnos(alumnos, tamArreglo, posicion);
            break;
        case 9:
            bandera = 0;
            break;
        default:
                printf("Opción no valida");
    }}
    return 0;
}

char ingresar_datos(char array[][CAPACIDAD]){
    int elementos;
    printf("¿Cuántos alumnos vas a agregar?: ");
    scanf("%d", &elementos);
    int i = 0;
    for(i;i<elementos;i++){
        char alumno[CAPACIDAD];
        printf("Nombre del alumno: ");
        scanf("%s", &alumno);
        stpcpy(array[i], alumno);
        printf("Alumno número %d \n", i+1);
    }
    return array[elementos][CAPACIDAD];
}

int delete_alumnos(char array[NUMMAX][CAPACIDAD], int tamArreglo, int indice){
    printf("el alumno que será eliminado es %s \n", array[indice]);

    int i = indice;
    for(i; i < tamArreglo-1; i++){
        stpcpy(array[i], array[i+1]); //copia el contenido de n2 en n1

    };
    return tamArreglo -1;
}

void imprimir_alumnos(char array[NUMMAX][CAPACIDAD], int tamArreglo){
    int i = 0;
    for(i; i < tamArreglo; i++){
        printf("%s \n", array[i]);
    }

}


int search_alumno(char array[NUMMAX][CAPACIDAD], int tamArreglo){
    char alumno_nombre[10];
    printf("Ingrese el nombre de un alumno para buscarlo en la base: ");
    scanf("%s", &alumno_nombre);
    int i = 0;
    for(i; i < tamArreglo; i++){
        if(strcmp(array[i], alumno_nombre)==0){ //compara n1 con n2
            printf("ID del alumno %d en la posición \n",i);
            return i;
        }else if(i == tamArreglo-1){
            printf("El alumno no se encontró \n");
            return -1;

            }       
        };


}