#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 100
#define ARCHIVO_INVENTARIO "inventario.dat"

typedef struct {
	int codigo;
	char nombre[MAX_NOMBRE];
	float precio;
	int stock;
} Producto;

Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;

// ================== FUNCIONES BÁSICAS ==================
void agregarProducto() {
	if (totalProductos >= MAX_PRODUCTOS) {
		printf("Inventario lleno.\n");
		return;
	}
	Producto p;
	printf("Codigo: "); scanf("%d", &p.codigo);
	printf("Nombre: "); scanf("%s", p.nombre);
	printf("Precio: "); scanf("%f", &p.precio);
	printf("Stock: "); scanf("%d", &p.stock);
	
	inventario[totalProductos] = p;
	totalProductos++;
	printf("Producto agregado.\n");
}

void eliminarProducto() {
	int codigo;
	printf("Codigo a eliminar: ");
	scanf("%d", &codigo);
	
	for (int i = 0; i < totalProductos; i++) {
		if (inventario[i].codigo == codigo) {
			// Mover últimos elementos
			for (int j = i; j < totalProductos - 1; j++) {
				inventario[j] = inventario[j + 1];
			}
			totalProductos--;
			printf("Producto eliminado.\n");
			return;
		}
	}
	printf("Producto no encontrado.\n");
}

void modificarProducto() {
	int codigo;
	printf("Codigo a modificar: ");
	scanf("%d", &codigo);
	
	for (int i = 0; i < totalProductos; i++) {
		if (inventario[i].codigo == codigo) {
			printf("Nuevo nombre [%s]: ", inventario[i].nombre);
			scanf("%s", inventario[i].nombre);
			printf("Nuevo precio [%.2f]: ", inventario[i].precio);
			scanf("%f", &inventario[i].precio);
			printf("Nuevo stock [%d]: ", inventario[i].stock);
			scanf("%d", &inventario[i].stock);
			printf("Producto actualizado.\n");
			return;
		}
	}
	printf("Producto no encontrado.\n");
}

// ================== BÚSQUEDAS ==================
void buscarPorCodigo() {
	int codigo;
	printf("Codigo: ");
	scanf("%d", &codigo);
	
	for (int i = 0; i < totalProductos; i++) {
		if (inventario[i].codigo == codigo) {
			printf(">> Encontrado: %s - $%.2f\n", 
				   inventario[i].nombre, inventario[i].precio);
			return;
		}
	}
	printf("No encontrado.\n");
}

void buscarPorNombre() {
	char nombre[MAX_NOMBRE];
	printf("Nombre (o parte): ");
	scanf("%s", nombre);
	
	int encontrados = 0;
	for (int i = 0; i < totalProductos; i++) {
		if (strstr(inventario[i].nombre, nombre) != NULL) {
			printf("[%d] %s - $%.2f\n", 
				   inventario[i].codigo, inventario[i].nombre, inventario[i].precio);
			encontrados++;
		}
	}
	if (!encontrados) printf("No hay coincidencias.\n");
}

// ================== ORDENAMIENTO ==================
void ordenarPorPrecio() {
	// Algoritmo: Bubble Sort
	for (int i = 0; i < totalProductos - 1; i++) {
		for (int j = 0; j < totalProductos - i - 1; j++) {
			if (inventario[j].precio > inventario[j + 1].precio) {
				// Intercambiar
				Producto temp = inventario[j];
				inventario[j] = inventario[j + 1];
				inventario[j + 1] = temp;
			}
		}
	}
	printf("Productos ordenados por precio.\n");
}

// ================== ARCHIVOS ==================
void guardarInventario() {
	FILE *archivo = fopen(ARCHIVO_INVENTARIO, "wb");
	if (!archivo) {
		perror("Error al guardar");
		return;
	}
	fwrite(&totalProductos, sizeof(int), 1, archivo); // Guardar cantidad
	fwrite(inventario, sizeof(Producto), totalProductos, archivo);
	fclose(archivo);
	printf("Datos guardados en %s\n", ARCHIVO_INVENTARIO);
}

void cargarInventario() {
	FILE *archivo = fopen(ARCHIVO_INVENTARIO, "rb");
	if (!archivo) return;
	
	fread(&totalProductos, sizeof(int), 1, archivo); // Leer cantidad
	fread(inventario, sizeof(Producto), totalProductos, archivo);
	fclose(archivo);
	printf("Datos cargados desde %s\n", ARCHIVO_INVENTARIO);
}

// ================== MENÚ PRINCIPAL ==================
void mostrarMenu() {
	printf("\n=== INVENTARIO DE PRODUCTOS ===\n");
	printf("1. Agregar producto\n");
	printf("2. Eliminar producto\n");
	printf("3. Modificar producto\n");
	printf("4. Buscar por codigo\n");
	printf("5. Buscar por nombre\n");
	printf("6. Ordenar por precio\n");
	printf("7. Mostrar todos\n");
	printf("8. Guardar y salir\n");
	printf("Seleccione: ");
}

void mostrarProductos() {
	if (totalProductos == 0) {
		printf("No hay productos.\n");
		return;
	}
	printf("\n=== LISTA DE PRODUCTOS ===\n");
	for (int i = 0; i < totalProductos; i++) {
		printf("%d. [%d] %s - $%.2f (Stock: %d)\n", 
			   i + 1, inventario[i].codigo, inventario[i].nombre, 
			   inventario[i].precio, inventario[i].stock);
	}
}

int main() {
	cargarInventario();
	
	int opcion;
	do {
		mostrarMenu();
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1: agregarProducto(); break;
		case 2: eliminarProducto(); break;
		case 3: modificarProducto(); break;
		case 4: buscarPorCodigo(); break;
		case 5: buscarPorNombre(); break;
		case 6: ordenarPorPrecio(); break;
		case 7: mostrarProductos(); break;
		case 8: guardarInventario(); printf("¡Adios!\n"); break;
		default: printf("Opción inválida.\n");
		}
	} while (opcion != 8);
	
	return 0;
}
