#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "RevisionVehicular.h"

int pantallaLogin();

Vehiculo vehiculos[MAX_VEHICULOS];
int cantidadVehiculos = 0;

void menuPrincipal();
void mostrarVehiculo(const Vehiculo v);

int main() {
	while (1) {
		if (pantallaLogin()) {
			menuPrincipal();
		}
	}
	return 0;
}

void mostrarVehiculo(const Vehiculo v) {
	printf("\n--- DATOS DEL VEHICULO ---\n");
	printf("Placa: %s\n", v.placa);
	printf("Cedula: %s\n", v.cedula);
	printf("Anio: %s\n", v.anio);
	printf("Tipo: %s\n", v.tipo);
	printf("Avaluo: %s\n", v.avaluo);
}

void menuPrincipal() {
	int opcion;
	char input[10];
	char placaBuscada[8];
	
	do {
		printf("\n===== SISTEMA DE MATRICULACION VEHICULAR =====\n");
		printf("1. Registrar vehiculo\n");
		printf("2. Registrar revisiones tecnicas\n");
		printf("3. Calcular valor matricula\n");
		printf("4. Mostrar estado de revisiones\n");
		printf("5. Buscar vehiculo por placa\n");
		printf("6. Listar vehiculos matriculados\n");
		printf("7. Generar comprobante de registro\n");
		printf("8. Cerrar sesion\n");
		printf("9. Salir completamente\n");
		printf("Seleccione una opcion: ");
		
		fgets(input, sizeof(input), stdin);
		if (sscanf(input, "%d", &opcion) != 1) {
			opcion = 0;
		}
		
		switch (opcion) {
		case 1:
			if (cantidadVehiculos < MAX_VEHICULOS) {
				validarMatricula(&vehiculos[cantidadVehiculos]);
				cantidadVehiculos++;
			} else {
				printf("No se puede registrar mas vehiculos.\n");
			}
			break;
		case 2:
			printf("Ingrese placa del vehiculo: ");
			fgets(placaBuscada, sizeof(placaBuscada), stdin);
			placaBuscada[strcspn(placaBuscada, "\n")] = '\0';
			{
				int idx = buscarVehiculoPorPlaca(vehiculos, cantidadVehiculos, placaBuscada);
				if (idx != -1) {
					registrarRevisiones(vehiculos[idx].revisiones);
				} else {
					printf("Vehiculo no encontrado.\n");
				}
			}
			break;
		case 3:
			if (cantidadVehiculos == 0) {
				printf("Debe registrar al menos un vehiculo.\n");
				break;
			}
			printf("Ingrese placa del vehiculo para calcular matricula: ");
			fgets(placaBuscada, sizeof(placaBuscada), stdin);
			placaBuscada[strcspn(placaBuscada, "\n")] = '\0';
			{
				int index = buscarVehiculoPorPlaca(vehiculos, cantidadVehiculos, placaBuscada);
				if (index != -1) {
					Vehiculo v = vehiculos[index];
					float total = calcular_matricula_vehicular(
															   v.tipo, 1600, atoi(v.anio), "Quito", 0.0f, 1.0f, 40.0f, 4, v.placa[6] - '0');
					printf("Total matricula calculado: $%.2f\n", total);
				} else {
					printf("Vehiculo no encontrado.\n");
				}
			}
			break;
		case 4:
			printf("Ingrese placa del vehiculo: ");
			fgets(placaBuscada, sizeof(placaBuscada), stdin);
			placaBuscada[strcspn(placaBuscada, "\n")] = '\0';
			{
				int idy = buscarVehiculoPorPlaca(vehiculos, cantidadVehiculos, placaBuscada);
				if (idy != -1) {
					mostrarEstadoRevisiones(vehiculos[idy]);
				} else {
					printf("Vehiculo no encontrado.\n");
				}
			}
			break;
		case 5:
			printf("Ingrese placa del vehiculo a buscar: ");
			fgets(placaBuscada, sizeof(placaBuscada), stdin);
			placaBuscada[strcspn(placaBuscada, "\n")] = '\0';
			{
				int encontrado = buscarVehiculoPorPlaca(vehiculos, cantidadVehiculos, placaBuscada);
				if (encontrado != -1) {
					mostrarVehiculo(vehiculos[encontrado]);
				} else {
					printf("Vehiculo no encontrado.\n");
				}
			}
			break;
		case 6:
			listarVehiculos(vehiculos, cantidadVehiculos);
			break;
		case 7:
			printf("Ingrese placa del vehiculo para generar comprobante: ");
			fgets(placaBuscada, sizeof(placaBuscada), stdin);
			placaBuscada[strcspn(placaBuscada, "\n")] = '\0';
			{
				int idx = buscarVehiculoPorPlaca(vehiculos, cantidadVehiculos, placaBuscada);
				if (idx != -1) {
					generarComprobanteTXT(vehiculos[idx]);
					printf("Comprobante generado correctamente.\n");
				} else {
					printf("Vehiculo no encontrado.\n");
				}
			}
			break;
		case 8:
			printf("Cerrando sesion...\n");
			return; 
		case 9:
			printf("Gracias por usar el sistema.\n");
			exit(0);
		default:
			printf("Opcion no valida. Debe ser un numero entre 1 y 9.\n");
		}
		
		if (opcion != 9 && opcion != 8) {
			printf("\nPresione Enter para continuar...");
			while (getchar() != '\n');
		}
	} while (opcion != 9);
}
