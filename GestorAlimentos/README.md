# Gestor de Información de Alimentos

### Este fue ejercicio de un examen en mis primeros semestres de la carrera en Ing. en Ciencias de la Computación. ###

Este es un programa en C que gestiona información sobre alimentos, como nombre, precio y calorías. El código se organiza en diferentes funciones para realizar diversas operaciones en los datos ingresados por el usuario. A continuación, se describe cada parte del programa:

## Estructura `alimento`

Se define una estructura llamada `alimento` que contiene tres arreglos para almacenar información sobre los alimentos: `nombre`, `precio` y `calorias`. Cada arreglo tiene espacio para 10 elementos.

## Función `rellenarStruct`

Esta función permite al usuario ingresar información sobre los alimentos. Itera sobre los 10 elementos de la estructura `alimento` y solicita el nombre, precio, calorias y si el alimento es natural o procesado. También cuenta cuántos alimentos son naturales y cuántos son procesados.

## Función `comparaciones`

Esta función realiza comparaciones en los datos para encontrar el alimento con más calorías (`maxCal` y su índice `mCal`) y el alimento más barato (`precioEco` y su índice `pEco`).

## Función `ordenamiento`

Esta función ordena los alimentos alfabéticamente según sus nombres utilizando el algoritmo de selección.

## Función `impresion`

Esta función imprime varios resultados, incluyendo:
- El total de alimentos naturales y procesados.
- El alimento más barato y el alimento con más calorías.
- Una lista de todos los alimentos ordenados alfabéticamente con sus nombres, precios y calorías.

## Función `main`

La función `main` es la entrada principal del programa. Inicializa variables, llama a las funciones en el siguiente orden y muestra los resultados.

1. `rellenarStruct` para ingresar datos sobre los alimentos.
2. `comparaciones` para encontrar el alimento más barato y con más calorías.
3. `ordenamiento` para ordenar los alimentos alfabéticamente.
4. Finalmente, llama a `impresion` para imprimir los resultados.
