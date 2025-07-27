# Sistema de matriculación vehicular

## Escuela Poitécnica Nacional

## Programación I

## Grupo #2
Caiño James

Conza Felipe

Herrera Renato

Monge Matías



En nuestro proyecto se buscó crear un sistema  estructurado en lenuaje C que simule el proceso de matriculación vehicular, aplicando lógica algorítmica, principios de Clean Code, fundamentos estructurados y buenas prácticas con Git y Gitub.
## Requisitos Funcionales

- Registrar vehículos (placa, cédula, año, tipo, avalúo).
- Calcular el valor a pagar por matrícula con reglas de negocio (recargos, descuentos, multas).
- Registrar cumplimiento de revisiones técnicas (3 anuales).
- Generar comprobante en pantalla y archivo `.txt`.
- Buscar vehículo por placa.
- Listar vehículos matriculados.
- Guardar y recuperar información usando archivos.
- Validar entradas y manejar errores comunes (simulación de excepciones).

## Login.c

Este archivo contiene la lógica de un sencillo sistema de login en C, el cual permite:

- Registrar usuarios con validación de datos.

- Iniciar sesión verificando credenciales desde un archivo.

- Validar contraseñas.

- Usar un menú interactivo.

## 📌 Explicación de funciones 

 `int pantallaLogin()`

Muestra un menú principal con las opciones:

-Registrarse

-Iniciar sesión

-Salir

Permite al usuario interactuar hasta que se cierre el programa o se inicie sesión correctamente.

Retorna 1 si el inicio de sesión es exitoso; si no, continúa en bucle.

`int registrarUsuario()`

Permite registrar un nuevo usuario.

Solicita:

Un nombre de usuario (solo letras).

Una contraseña de exactamente 6 caracteres alfanuméricos.

Valida ambos datos antes de guardarlos.

Guarda el usuario y la contraseña en usuarios.txt en formato usuario,contrasena.

Retorna 1 si el registro fue exitoso; de lo contrario, 0.

`int iniciarSesion()`

Solicita al usuario y la contraseña.

Abre el archivo usuarios.txt y busca una coincidencia exacta con los datos ingresados.

Si encuentra un match, retorna 1, indicando que el inicio de sesión fue exitoso.

Si no encuentra coincidencias, retorna 0.

`int validarContrasena(const char *contrasena)`

Valida que la contraseña:

Tenga exactamente 6 caracteres.

Esté compuesta únicamente por caracteres alfanuméricos (letras y números).

Retorna 1 si es válida, 0 si no.

## 📎 Requisitos para los usuarios
- El nombre de usuario solo puede contener letras (sin números, espacios ni caracteres especiales).

- La contraseña debe tener exactamente 6 caracteres alfanuméricos.

## RevisionVehicularDefinitiva.c

Este archivo contiene las funciones utilizadas en nuestro programa.

- `void limpiarBuffer()`

Esta función limpia el búfer de entrada del teclado. Es decir, descarta cualquier carácter que haya quedado pendiente en la entrada (stdin), hasta que encuentre un salto de línea ('\n') o el final del archivo (EOF).

- `void validarCadena(const char *mensaje, char *destino, int tam)`

Esta función solicita al usuario que ingrese una cadena (texto), y valida que esa cadena contenga solo letras y espacios. Repite la solicitud hasta que la entrada sea válida.

- `void validarNumero(const char *mensaje, char *destino, int tam)`

Solicita al usuario un número y valida que tenga exactamente 4 dígitos, asegurándose además de que no haya letras ni símbolos.

- `void validarMatricula(Vehiculo *v)`

Esta función permite registrar un nuevo vehículo, solicitando y validando todos los datos necesarios antes de guardarlos en la estructura Vehiculo. Cada entrada es validada cuidadosamente para asegurar que la información sea correcta y coherente.


1. Ingreso de placa del vehículo

Pide una placa en el formato: 3 letras seguidas de 4 números

Verifica que tenga exactamente 7 caracteres: los tres primeros deben ser letras y los cuatro últimos dígitos.

Si el formato es incorrecto, vuelve a pedirla.

2. Ingreso de cédula del propietario

Pide una cédula de exactamente 10 dígitos numéricos.

Verifica que todos los caracteres sean números.

Si no cumple el formato, vuelve a solicitarla.

3. Ingreso del año de fabricación del vehículo

Pide un año de 4 dígitos.

Debe estar dentro del rango 1940 a 2025.

Solo se aceptan números. Si no cumple el rango o el formato, vuelve a pedirlo.

4. Selección del tipo de vehículo

Muestra un menú con tres opciones:

Pesado

Liviano

Moto

El usuario debe seleccionar una opción válida (1-3).

Asigna automáticamente el texto "pesado", "liviano" o "moto" según la opción.

5. Ingreso del avalúo del vehículo

Solicita un valor numérico de entre 4 y 6 dígitos

Verifica que todos los caracteres sean dígitos y que la longitud esté dentro del rango permitido.

6. Inicializa las revisiones técnicas

Establece en 0 todas las posiciones del arreglo v->revisiones, indicando que aún no se han realizado revisiones.

7. Opción de generar comprobante de registro

Al final, pregunta si el usuario desea imprimir un comprobante de registro.

Si responde "si", se llama a la función generarComprobanteTXT(*v) para crear un archivo con los datos del vehículo.

- `void generarComprobanteTXT(const Vehiculo v)`

Esta función se encarga de generar un comprobante en formato de texto (.txt) con los datos de un vehículo que ha sido registrado. Este archivo funciona como un documento de respaldo para el usuario.

1. Crea el archivo de comprobante

Abre (o crea) un archivo llamado comprobante_vehicular.txt en modo escritura ("w").

Si ocurre un error al abrir el archivo, muestra un mensaje de error y sale de la función.

2. Escribe los datos del vehículo

Imprime en el archivo los siguientes campos, que provienen de la estructura Vehiculo:

Placa

Cédula

Año de fabricación

Tipo de vehículo

Avalúo

Agrega líneas decorativas para el encabezado y el cierre.

3. Agrega un mensaje final

El archivo incluye un mensaje de agradecimiento y confirma que el comprobante es una constancia oficial de inscripción.

4. Cierra el archivo

Usa fclose() para guardar y cerrar correctamente el archivo.

- `int buscarVehiculoPorPlaca(const Vehiculo vehiculos[], int cantidad, const char* placa)`

Esta función busca un vehículo específico en un arreglo de estructuras Vehiculo, comparando las placas una por una.

1. Recibe tres parámetros:

vehiculos[]: un arreglo de estructuras Vehiculo previamente cargado.

cantidad: número de vehículos que hay en el arreglo.

placa: una cadena con la placa que se quiere buscar.

2. Recorre el arreglo:

Utiliza un bucle for que va desde i = 0 hasta i < cantidad.

3. Compara placas:

Usa strcmp() para comparar la placa de cada vehículo con la placa buscada.

Si encuentra una coincidencia exacta, retorna el índice (i) donde se encuentra ese vehículo.

4. Si no encuentra la placa:

Retorna -1, lo que indica que el vehículo no está registrado en el arreglo.

- `void registrarRevisiones(int revisiones[NUM_REVISIONES])`

Esta función permite registrar los resultados de las revisiones técnicas de un vehículo, solicitándolos uno por uno desde el teclado y almacenándolos en un arreglo de enteros.

1. Muestra un encabezado informativo:

--- REGISTRO DE REVISIONES TECNICAS ---

2. Solicita los resultados de cada revisión técnica:

Recorre el arreglo revisiones[] usando un bucle for.

Para cada revisión, pide al usuario que ingrese 1 si fue aprobada o 0 si no fue aprobada.

3. Guarda cada resultado:

El valor ingresado por el usuario se guarda en la posición correspondiente del arreglo.

4. Limpia el búfer después de cada entrada:

Llama a limpiarBuffer() para evitar errores de lectura en futuras entradas.

5. Confirma el registro:

Muestra el mensaje: "Revisiones registradas correctamente."

- `void mostrarEstadoRevisiones(const Vehiculo v)`

Esta función muestra el resultado de cada revisión técnica realizada a un vehículo específico, usando los datos almacenados previamente en el campo revisiones[] de la estructura Vehiculo.

1. Muestra un encabezado con la placa del vehículo

2. Recorre el arreglo v.revisiones

Utiliza un bucle for para recorrer cada revisión registrada.

Asume que cada revisión contiene un 1 si fue aprobada, o un 0 si fue no aprobada.

3. Imprime el estado de cada revisión

- `void listarVehiculos(const Vehiculo vehiculos[], int cantidad)`

1. Muestra un título informativo

2. Recorre el arreglo de vehículos:

Usa un bucle for para recorrer desde 0 hasta cantidad - 1.

En cada iteración, accede a los datos de un vehículo y los muestra en consola.

3. Imprime la información de cada vehículo:
Para cada vehículo muestra:

Número (índice + 1)

Placa

Cédula del propietario

Año de fabricación

Tipo de vehículo (pesado, liviano, moto)

Avalúo
- `float calcular_matricula_vehicular(...)`

Esta función calcula el valor total que un propietario debe pagar por la matrícula vehicular, considerando varios factores como tipo de vehículo, año de fabricación, multas, y si pasó la revisión obligatoria.

1. Define una base según el tipo de vehículo:

Vehículo pesado: $200.00

Vehículo liviano: $25.00

Moto: $25.00

2. Calcula un valor por antigüedad:

Se multiplica la cantidad de años que tiene el vehículo por $5.00.

3. Suma multas de tránsito:

Se añade el valor de multas_transito al total.

Penaliza si no pasó la revisión obligatoria:

Si el valor de revision_obligatoria es 0, se añade una multa de $50.00.

4. Devuelve el total:

La función retorna el valor total de matrícula a pagar

## RevisionVeicular.h

1. Definición de constantes

Definimos varias constantes

#define MAX_PLACA 10

#define MAX_TIPO 20

#define MAX_AVALUO 20

#define MAX_ANIO 5

#define MAX_CEDULA 11

#define NUM_REVISIONES 3

#define MAX_VEHICULOS 100 

2. Definición del struct 

Este struct define un vehículo registrado con los siguientes campos:

placa[8]: Placa del vehículo (hasta 7 caracteres + \0).

cedula[11]: Cédula del propietario (10 números + \0).

anio[5]: Año de fabricación (hasta 4 cifras).

tipo[20]: Tipo de vehículo (por ejemplo: "liviano", "pesado", etc.).

avaluo[10]: Valor del vehículo en texto.

revisiones[3]: Arreglo que guarda resultados de 3 revisiones.

3. Funciones

Plasmamos nuestras funciones antes creadas.
