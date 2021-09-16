#include <iostream>
#include <windows.h>

using namespace std;

struct BANCO
{
    int num;
    char titular[35];
    float saldo;
};

void preencheContas(BANCO conta[5]){
    for (int i = 0; i < 5; i++)
    {
        cout << "Numero da conta: ";
        cin >> conta[i].num;
        cout << "Nome do titular: ";
        cin >> conta[i].titular;
        cout << "Saldo da conta: ";
        cin >> conta[i].saldo;
        cout << endl;
    }
}

void ContaSaldoMenor(BANCO contaMenor[5])
{
    float menor; 
    int num_conta_menor = 0;
    char dono_menor[35];

    for (int i = 0; i < 5; i++)
    {
        if(i == 0) {
            menor = contaMenor[i].saldo;
        }
        else if (contaMenor[i].saldo < menor)
        {
            menor = contaMenor[i].saldo;
            num_conta_menor = contaMenor[i].num;
            strcpy(dono_menor, contaMenor[i].titular);
        }
    }
    cout << "Conta com MENOR saldo\n";
    cout << "Numero: " << num_conta_menor << " Titular: " << dono_menor << " Saldo: " << menor << endl;
}

void ContaSaldoMaior(BANCO contaMaior[5])
{
    float maior; 
    int num_conta_maior = 0;
    char dono_maior[35];

    for (int i = 0; i < 5; i++)
    {
        if (i == 0){
            maior = contaMaior[i].saldo;
        }
        else if (contaMaior[i].saldo > maior)
        {
            maior = contaMaior[i].saldo;
            num_conta_maior = contaMaior[i].num;
            strcpy(dono_maior, contaMaior[i].titular);
        }
    }
    cout << "Conta com MAIOR saldo\n";
    cout << "Numero: " << num_conta_maior << " Titular: " << dono_maior << " Saldo: " << maior << endl;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    BANCO conta[5];

    system("cls");

    preencheContas(conta);
    ContaSaldoMenor(conta);
    ContaSaldoMaior(conta);

    cout << endl << endl;
    system("pause");
    return 0;
}