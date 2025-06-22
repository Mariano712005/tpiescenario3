#include "producto.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarMenu() {
    printf("\n=== INVENTARIO DE PRODUCTOS ===\n");
    printf("1. Agregar producto\n");
    printf("2. Eliminar producto\n");
    printf("3. Modificar producto\n");
    printf("4. Buscar por codigo\n");
    printf("5. Buscar por nombre\n");
    printf("6. Mostrar todos (ordenados por precio)\n");
    printf("7. Guardar y salir\n");
    printf("Seleccione: ");
}


void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Nodo* inventario = cargarInventario();
    int opcion, codigo;
    char nombre[MAX_NOMBRE];
    
    do {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida. Intente nuevamente.\n");
            limpiarBuffer();
            continue;
        }
        
        switch (opcion) {
            case 1: {
                Producto nuevo;
                printf("Codigo: ");
                if (scanf("%d", &nuevo.codigo) != 1) {
                    printf("Codigo invalido!\n");
                    limpiarBuffer();
                    break;
                }
                
                
                if (buscarPorCodigo(inventario, nuevo.codigo)) {
                    printf("Error: Codigo duplicado!\n");
                    break;
                }
                
                printf("Nombre: ");
                limpiarBuffer();
                fgets(nuevo.nombre, MAX_NOMBRE, stdin);
                nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';
                
                printf("Precio: ");
                if (scanf("%f", &nuevo.precio) != 1 || nuevo.precio < 0) {
                    printf("Precio invalido!\n");
                    limpiarBuffer();
                    break;
                }
                
                printf("Stock: ");
                if (scanf("%d", &nuevo.stock) != 1 || nuevo.stock < 0) {
                    printf("Stock invalido!\n");
                    limpiarBuffer();
                    break;
                }
                
                inventario = agregarProducto(inventario, nuevo);
                break;
            }
                
            case 2: {
                printf("Codigo a eliminar: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido!\n");
                    limpiarBuffer();
                    break;
                }
                inventario = eliminarProducto(inventario, codigo);
                break;
            }
                
            case 3: {
                printf("Codigo a modificar: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido!\n");
                    limpiarBuffer();
                    break;
                }
                modificarProducto(inventario, codigo);
                break;
            }
                
            case 4: {
                printf("Codigo: ");
                if (scanf("%d", &codigo) != 1) {
                    printf("Codigo invalido!\n");
                    limpiarBuffer();
                    break;
                }
                Producto* encontrado = buscarPorCodigo(inventario, codigo);
                if (encontrado) mostrarProducto(*encontrado);
                else printf("No encontrado.\n");
                break;
            }
                
            case 5: {
                printf("Nombre: ");
                limpiarBuffer();
                fgets(nombre, MAX_NOMBRE, stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                
                Nodo* resultados = buscarPorNombre(inventario, nombre);
                mostrarProductos(resultados);
                
                
                Nodo* temp;
                while (resultados) {
                    temp = resultados;
                    resultados = resultados->siguiente;
                    free(temp);
                }
                break;
            }
                
            case 6: {
                ordenarPorPrecio(&inventario);
                mostrarProductos(inventario);
                break;
            }
                
            case 7: {
                guardarInventario(inventario);
                printf("Inventario guardado. Hasta luego!\n");
                break;
            }
                
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 7);
    
    
    Nodo* actual = inventario;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    
    return 0;
}
