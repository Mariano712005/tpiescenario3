# TPIEscenario3
Integrantes: Retamoso mariano José

Tema Numero 3: Inventario de Productos de un Comercio

Descripción:

En este Github se presentan 4 programas, pero en realidad son 2, 1 requiere que en la terminal se ejecute un comando que los una a los 3 para ser ejecutado, y el otro es una versión simplificada, en un solo programa. Primero vamos a empezar explicando el "triprograma" y como funciona este. Luego, explicaremos su versión individualizada y como funciona, para luego terminar comparandolos a los 2.

TRIPROGRAMA (O MODULAR):
- Agregar, eliminar y modificar productos (código, nombre, precio, stock)
- Búsquedas por código o nombre
- Visualización de productos ordenados por precio
- Almacenamiento persistente en archivo binario
- Interfaz intuitiva con validación de datos

VERSIÓN SIMPLIFICADA

Sencillez: Ideal para principiantes en C

Eficiencia: Menos sobrecarga que listas enlazadas

Persistencia: Datos sobreviven al cerrar el programa

Portabilidad: Solo 1 archivo fuente necesario

Ahrora vamos a ver a detalle como funcionan estos programas, empezando por la version Modular (TRIPROGRAMA)

Estructuras de Control e Iteradores
```c
// Ejemplo en main.c
do {
    mostrarMenu();
    // ... switch con 7 opciones
    while ((c = getchar()) != '\n' && c != EOF); // Limpieza de buffer
} while (opcion != 7);

// Uso de for/while en producto.c
for (Nodo* actual = cabeza; actual != NULL; actual = actual->siguiente) {
    // Procesamiento de nodos
}

Interacción con el Usuario
// Consola (main.c)
printf("Nombre: ");
fgets(nuevo.nombre, MAX_NOMBRE, stdin);

// Archivos (producto.c)
FILE* archivo = fopen(ARCHIVO_INVENTARIO, "wb");

Estructuras (struct)
// producto.h
typedef struct {
    int codigo;
    char nombre[MAX_NOMBRE];
    float precio;
    int stock;
} Producto;

Ordenamiento y Búsqueda
// Ordenamiento por precio (Bubble Sort)
void ordenarPorPrecio(Nodo * cabeza) {
    // Implementación completa en producto.c
}

// Búsqueda por código
Producto * buscarPorCodigo(Nodo * cabeza, int codigo) {
    while (cabeza) {
        if (cabeza->producto.codigo == codigo) 
            return &(cabeza->producto);
        cabeza = cabeza->siguiente;
    }
    return NULL;
}

Estructuras Dinámicas (Lista Enlazada)
// producto.h
typedef struct Nodo {
    Producto producto;
    struct Nodo * siguiente;
} Nodo;

// Operaciones implementadas:
Nodo * agregarProducto(Nodo * cabeza, Producto prod);
Nodo * eliminarProducto(Nodo * cabeza, int codigo);

Manejo de Archivos
// producto.c
void guardarInventario(Nodo * cabeza) {
    FILE * archivo = fopen(ARCHIVO_INVENTARIO, "wb");
    // Escritura binaria
}

Nodo * cargarInventario() {
    FILE* archivo = fopen(ARCHIVO_INVENTARIO, "rb");
    // Lectura binaria
}

 Funciones y Procedimientos
// Todas las funciones en español con responsabilidades claras:
void modificarProducto(Nodo * cabeza, int codigo);
void mostrarProductos(Nodo * cabeza);
void ordenarPorPrecio(Nodo * cabeza);

Instrucciones de Compilación y Ejecución
Windows
Instalar MinGW

Descargar los archivos del proyecto:

main.c

producto.h

producto.c

Abrir cmd en la carpeta del proyecto:
gcc -o inventario.exe main.c producto.c
inventario.exe

Linux
Instalar compilador GCC:
sudo apt install gcc

Descargar archivos del proyecto

En terminal:
gcc -o inventario main.c producto.c
./inventario

Nota: El inventario se guarda automáticamente en inventario.dat 





VERSIÓN SIMPLIFICADA:
Cumplimiento de Requisitos Técnicos

Estructuras de Control e Iteradores
```c
// Uso de switch para menú principal
switch (opcion) {
    case 1: agregarProducto(); break;
    // ... 7 opciones
}

// Bucles for para operaciones con arreglos
for (int i = 0; i < totalProductos; i++) {
    // Procesamiento de productos
}

Interacción con el Usuario
// Entrada por consola
printf("Precio: ");
scanf("%f", &p.precio);

// Archivos binarios
FILE * archivo = fopen(ARCHIVO_INVENTARIO, "wb");
fwrite(inventario, sizeof(Producto), totalProductos, archivo);

Estructuras (struct)
typedef struct {
    int codigo;
    char nombre[MAX_NOMBRE];
    float precio;
    int stock;
} Producto;  // Agrupa datos relacionados

Ordenamiento y Búsqueda
// Bubble Sort para ordenar por precio
void ordenarPorPrecio() {
    for (int i = 0; i < totalProductos - 1; i++) {
        for (int j = 0; j < totalProductos - i - 1; j++) {
            if (inventario[j].precio > inventario[j + 1].precio) {
                // Intercambio
            }
        }
    }
}

// Búsqueda secuencial por nombre
if (strstr(inventario[i].nombre, nombre) != NULL) {
    // Producto encontrado
}

Estructuras Dinámicas
// Aunque usa arreglo estático, implementa lógica dinámica:
Producto inventario[MAX_PRODUCTOS];  // Capacidad máxima
int totalProductos = 0;               // Contador dinámico

// Operaciones mantienen estado coherente:
void eliminarProducto() {
    // Desplaza elementos eliminados
    for (int j = i; j < totalProductos - 1; j++) {
        inventario[j] = inventario[j + 1];
    }
    totalProductos--;  // Actualiza contador
}

Manejo de Archivos
// Guardado binario eficiente
void guardarInventario() {
    fwrite(&totalProductos, sizeof(int), 1, archivo);
    fwrite(inventario, sizeof(Producto), totalProductos, archivo);
}

// Carga inicial automática
int main() {
    cargarInventario();  // Recupera datos al iniciar
}

Funciones y Procedimientos
// Modularización clara en español:
void agregarProducto();     // Añade nuevos items
void buscarPorNombre();      // Búsqueda parcial
void mostrarProductos();     // Listado completo


Instrucciones de Uso
Compilación (Windows/Linux)

gcc -o inventario inventario.c
./inventario

Flujo de trabajo
Agregar productos (Opción 1)

Buscar/modificar con opciones 4-5

Ordenar por precio (Opción 6)

Guardar automáticamente (Opción 8)

Nota: Los datos se guardan en inventario.dat 


 Estructura del Proyecto
Característica
                          Versión Simplificada	                  Versión Modular (3 archivos)
Organización	           1 archivo único (main.c)	                 3 archivos separados
Encapsulación             	Variables globales	               Estructuras y funciones encapsuladas
Reutilización	               Difícil reutilización	              producto.h reusable en otros proyectos


 Manejo de Datos
Característica
	                           Versión Simplificada             	Versión Modular (3 archivos)
Almacenamiento	        Arreglo estático fijo (100 productos)	          Lista enlazada dinámica (sin límite)
Inserción/Eliminación	     Desplazamiento manual de elementos	        Operaciones con punteros (más eficiente)
Memoria                       	Estática pre-asignada	                     Dinámica (malloc/free)


 Validación y Robustez
Característica	                Versión Simplificada	                   Versión Modular (3 archivos)
Validación entradas	             Básica	                           Completa (duplicados, valores negativos)
Manejo de errores	                    Básico	                   Avanzado (limpieza de buffer, mensajes detallados)
Nombres con espacios	             No soportado (scanf)	                    Soporte completo (fgets)


Funcionalidades Clave
Característica	                Versión Simplificada	                   Versión Modular (3 archivos)
Búsqueda por nombre	                Parcial (strstr)	                Completa (devuelve lista de resultados)
Ordenamiento	                 Bubble Sort sobre arreglo	                 Bubble Sort sobre lista enlazada
Gestión de memoria	             Automática (estática)	                 Manual (liberación explícita)


Ventajas y Desventajas
Versión Simplificada	                        Versión Modular
✅ Más fácil de entender para principiantes	✅ Arquitectura profesional
✅ Código compacto (230 líneas)	✅ Manejo de memoria más eficiente
❌ Límite fijo de productos	✅ Escalable (sin límite de productos)
❌ Sin validación avanzada	✅ Validación robusta de entradas
❌ No maneja nombres con espacios	✅ Soporte completo para nombres

Conclusión:
La versión simplificada es ideal para aprendizaje básico de C, mientras que la implementación modular cumple con estándares profesionales y requisitos avanzados del trabajo práctico. La versión modular demuestra mejor:

Gestión de memoria dinámica

Validación robusta de entradas

Organización de código profesional

Escalabilidad sin límites fijos

Cumplimiento completo de requisitos técnicos



