/*
 cargar alumnos ---> cargar notas alumno ---> 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUM 5
#define MAX_MAT 3

typedef struct
{
    char nombre[100];
    int legajo, materias[30];
} t_alumno;

typedef struct
{
    char nombre[100];
    int codigo;
} t_materia;

typedef struct
{
    int legajo_alumno;
    int cod_materia,nota;
} t_nota;



