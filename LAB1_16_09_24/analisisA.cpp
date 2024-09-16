//solo texto

/*
- Se tiene una matriz `A[MAX][MAX]` y dos vectores `x[MAX]` y `y[MAX]`.
- En ambos bucles se está realizando una multiplicación de la matriz `A` 
    por el vector `x`, y el resultado se almacena en `y`.

*/

/*

Recorro índice de filas `i` y luego las columnas `j`, sigue un orden coherente

*/

for (int i = 0; i < MAX; i++) 
{
    for (int j = 0; j < MAX; j++) 
    {
           y[i] += A[i][j] * x[j];
    }
}


/*
Se invierte el orden, recorriendo primero las columnas `j` y luego las filas `i`
En este caso como no está en orden, se tiene accesos más dispersos a memoria

*/

for (int j = 0; j < MAX; j++) 
{
   for (int i = 0; i < MAX; i++) 
   {
           y[i] += A[i][j] * x[j];
    }
}