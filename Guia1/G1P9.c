/*
Desarrollar las funciones cargarMatText, imprimirMatText, y ordenarMatText.
cargarMatText: carga desde teclado una matriz de char de F x C pasada por
parámetro. Por cada fila carga un texto el cual debe contener el ‘\0’ al final de los
caracteres útiles (concepto de string). Para marcar el fin de las filas útiles deberá
agregar en la siguiente fila (a la última útil) un‘\0’( en la columna cero) [nota1].
imprimirMatText: Imprime la matriz de char de F x C pasada por parámetro.
ordenarMatText: recibe una matriz de char de F x C . La función deberá ordenar la
matriz en orden alfabético ascendente. Tener en cuenta que los contenidos de la matriz
pueden tener tanto letras mayúsculas como minúsculas.
Desarrollar el programa principal que cargue una matriz, luego la muestre en pantalla. A
continuación ordenar la matriz y luego volver a imprimirla para verificar el orden.
Nota1: (Método). Un ‘\0’ en una fila (y cualquier columna) determinará el fin de los
caracteres útiles de dicha fila. Y un ’\0’ en columna 0 (cero) en una fila cualquiera,
determinará el fin de las filas útiles de la matriz.
Este método (ad hoc) adoptado no permite identificar en la matriz cadena de caracteres
vacías (sólo la última).*/
