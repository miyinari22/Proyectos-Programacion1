# Conversor de Fecha a Texto

Este programa en C permite al usuario ingresar una fecha (día, mes y año) en formato numérico y muestra esa fecha en formato de texto, utilizando el nombre del mes en lugar del número y mostrando el año.

## Instrucciones de Uso
El programa solicitará al usuario que ingrese tres números enteros correspondientes al día, mes y año de una fecha.

Luego, el programa convertirá el número del mes ingresado en su nombre correspondiente utilizando un switch.

Verifica si la fecha ingresada es válida, comprobando si el día está dentro del rango válido para cada mes, incluyendo el caso especial de febrero en años bisiestos.

Si la fecha es válida, muestra la fecha en pantalla utilizando el formato: "Día de Mes del año Año".

Detalles del Código
El código utiliza un switch para asignar el nombre del mes correspondiente al número ingresado. Luego, realiza verificaciones para garantizar que la fecha ingresada sea válida, verificando los límites del día y del mes, especialmente para febrero.

Finalmente, si la fecha es válida, muestra la fecha en el formato requerido.