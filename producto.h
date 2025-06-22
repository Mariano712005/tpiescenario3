#ifndef PRODUCTO_H
#define PRODUCTO_H

#define MAX_NOMBRE 50
#define ARCHIVO_INVENTARIO "inventario.dat"

typedef struct {
    int codigo;
    char nombre[MAX_NOMBRE];
    float precio;
    int stock;
} Producto;

typedef struct Nodo {
    Producto producto;
    struct Nodo * siguiente;
} Nodo;

Nodo * agregarProducto(Nodo * cabeza, Producto prod);
Nodo * eliminarProducto(Nodo * cabeza, int codigo);
void modificarProducto(Nodo * cabeza, int codigo);
Producto * buscarPorCodigo(Nodo * cabeza, int codigo);
Nodo * buscarPorNombre(Nodo * cabeza, const char * nombre);
void mostrarProductos(Nodo * cabeza);
void mostrarProducto(Producto prod);
void ordenarPorPrecio(Nodo * cabeza);
void guardarInventario(Nodo * cabeza);
Nodo * cargarInventario();

#endif
