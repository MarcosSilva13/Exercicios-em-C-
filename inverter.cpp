#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int InverteNumero(int numero)
{
    int quant_numeros[5], i, j;

    for (i = 0; numero; i++)
    {
        quant_numeros[i] = numero % 10;
        numero /= 10;
    }

    for (j = 0; j < i; j++)
    {
        numero += (quant_numeros[j] * pow(10, (i - j - 1)));
    }

    return numero;
}

int main()
{

    int num, resultado;

    printf("Digite um numero: \n");
    scanf("%d", &num);

    resultado = InverteNumero(num);

    printf("Numero digitado: %d \nNumero invertido: %d ", num, resultado);

    system("pause");
    return 0;
}