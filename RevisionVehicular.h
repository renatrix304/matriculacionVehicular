#ifndef REVISION_VEHICULAR_H
#define REVISION_VEHICULAR_H

#define MAX_PLACA 10
#define MAX_TIPO 20
#define MAX_AVALUO 20
#define MAX_ANIO 5
#define MAX_CEDULA 11
#define NUM_REVISIONES 3
#define MAX_VEHICULOS 100
typedef struct {
	char placa[8];
	char cedula[11];
	char anio[5];
	char tipo[20];
	char avaluo[10];
	int revisiones[NUM_REVISIONES];
} Vehiculo;

void validarMatricula(Vehiculo *v);
float calcular_matricula_vehicular(const char tipo_vehiculo[], int cilindraje, int anio_fabricacion,
								   const char provincia[], float es_ecologico, float revision_obligatoria,
								   float multas_transito, int mes_pago, int ultimo_digito_placa);
void registrarRevisiones(int revisiones[NUM_REVISIONES]);
void mostrarEstadoRevisiones(const Vehiculo v);
void listarVehiculos(const Vehiculo vehiculos[], int cantidad);
int buscarVehiculoPorPlaca(const Vehiculo vehiculos[], int cantidad, const char* placa);
void limpiarBuffer();
void generarComprobanteTXT(const Vehiculo v);

int pantallaLogin();

#endif 
