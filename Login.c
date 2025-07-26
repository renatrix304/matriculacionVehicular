#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIO 30
#define MAX_CONTRASENA 30

int registrarUsuario();
int iniciarSesion();
int validarContrasena(const char *contrasena);

int pantallaLogin() {
	int opcion;
	char input[10];
	
	while (1) {
		system("cls"); 
		printf("===== BIENVENIDO AL SISTEMA DE MATRICULACION =====\n");
		printf("1. Registrarse\n");
		printf("2. Iniciar sesion\n");
		printf("3. Salir\n");
		printf("Seleccione una opcion: ");
		fgets(input, sizeof(input), stdin);
		if (sscanf(input, "%d", &opcion) != 1) opcion = 0;
		
		switch(opcion) {
		case 1:
			if (registrarUsuario()) {
				printf("Registro exitoso.\n");
			}
			break;
		case 2:
			if (iniciarSesion()) {
				return 1; 
			} else {
				printf("Fallo en inicio de sesion.\n");
			}
			break;
		case 3:
			exit(0);
		default:
			printf("Opcion invalida. Intente de nuevo.\n");
		}
		printf("\nPresione Enter para continuar...");
		while (getchar() != '\n');
	}
}

int registrarUsuario() {
	char usuario[MAX_USUARIO], contrasena[MAX_CONTRASENA];
	FILE *f = fopen("usuarios.txt", "a");
	if (f == NULL) {
		printf("Error al abrir archivo de usuarios.\n");
		return 0;
	}
	
	printf("Ingrese nombre de usuario (solo letras): ");
	fgets(usuario, sizeof(usuario), stdin);
	usuario[strcspn(usuario, "\n")] = '\0';
	
	if (strlen(usuario) == 0) {
		printf("Usuario vacio no permitido.\n");
		fclose(f);
		return 0;
	}
	
	for (int i = 0; i < strlen(usuario); i++) {
		if (!isalpha(usuario[i])) {
			printf("Usuario invalido. Solo letras permitidas.\n");
			fclose(f);
			return 0;
		}
	}
	
	do {
		printf("Ingrese contrasena (6 caracteres alfanumericos): ");
		fgets(contrasena, sizeof(contrasena), stdin);
		contrasena[strcspn(contrasena, "\n")] = '\0';
		
		if (!validarContrasena(contrasena)) {
			printf("Contrasena invalida. Debe tener 6 caracteres alfanumericos.\n");
		}
	} while (!validarContrasena(contrasena));
	
	fprintf(f, "%s,%s\n", usuario, contrasena);
	fclose(f);
	return 1;
}

int iniciarSesion() {
	char usuario[MAX_USUARIO], contrasena[MAX_CONTRASENA];
	char archivoUsuario[MAX_USUARIO], archivoContrasena[MAX_CONTRASENA];
	char linea[100];
	FILE *f = fopen("usuarios.txt", "r");
	if (f == NULL) {
		printf("Debe registrarse primero.\n");
		return 0;
	}
	
	printf("Usuario: ");
	fgets(usuario, sizeof(usuario), stdin);
	usuario[strcspn(usuario, "\n")] = '\0';
	
	printf("Contrasena: ");
	fgets(contrasena, sizeof(contrasena), stdin);
	contrasena[strcspn(contrasena, "\n")] = '\0';
	
	while (fgets(linea, sizeof(linea), f)) {
		sscanf(linea, "%[^,],%s", archivoUsuario, archivoContrasena);
		if (strcmp(usuario, archivoUsuario) == 0 && strcmp(contrasena, archivoContrasena) == 0) {
			fclose(f);
			return 1; 
		}
	}
	fclose(f);
	return 0;
}

int validarContrasena(const char *contrasena) {
	if (strlen(contrasena) != 6) return 0;
	for (int i = 0; i < 6; i++) {
		if (!isalnum(contrasena[i])) return 0;
	}
	return 1;
}
