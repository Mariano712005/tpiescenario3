#include "producto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void modificarProducto(Nodo* cabeza, int codigo) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->producto.codigo == codigo) {
            printf("Nuevo nombre: ");
            getchar();
            fgets(actual->producto.nombre, MAX_NOMBRE, stdin);
            actual->producto.nombre[strcspn(actual->producto.nombre, "\n")] = '\0';
            
            printf("Nuevo precio: ");
            scanf("%f", &actual->producto.precio);
            
            printf("Nuevo stock: ");
            scanf("%d", &actual->producto.stock);
            
            printf("Producto modificado.\n");
            return;
        }
        actual = actual->siguiente;
    }
    printf("Producto no encontrado.\n");
}
