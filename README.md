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

