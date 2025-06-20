#include <stdio.h>

int sumaPares(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {

        return (2 * n) + sumaPares(n - 1);
    }
}

int main()
{
    int n;

    printf("Ingrese la cantidad de números pares a sumar: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("El número debe ser positivo.\n");
    }
    else
    {
        int resultado = sumaPares(n);
        printf("La suma de los primeros %d números pares es: %d\n", n, resultado);
    }

    return 0;
}