#include <iostream>
#include <math.h>

using namespace std;

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

    cout << "Digite um numero: ";
    cin >> num;

    resultado = InverteNumero(num);

    cout << "Numero digitado: " << num << " Numero invertido: " << resultado << endl;

    system("pause");
    return 0;
}