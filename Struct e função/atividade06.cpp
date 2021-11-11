#include <iostream>
#include <windows.h>
#include <string.h>
#include <iomanip>

using namespace std;

#define quant 3 

struct PRODUTOS{
    string nome;
    string codigo;
    float preco;
};

void Cadastrar(PRODUTOS prod[quant]){
    for (int i = 0; i < quant; i++){
        cout << "Nome: ";
        cin.ignore();
        getline(cin, prod[i].nome);
        cout << "Codigo: ";
        getline(cin, prod[i].codigo);
        cout << "Preço: ";
        cin >> prod[i].preco;
        cout << "\n";
    }
}

void Imprimir(PRODUTOS prod[quant]){
    for (int i = 0; i < quant; i++){
        cout << "Codigo: " << prod[i].codigo << "\n";
        cout << "Nome: " << prod[i].nome << "\n";
        cout << "\n";
    }
}

void Consultar(PRODUTOS prod[quant], string cod){
    string nome_p, cod_p;
    float preco_p = 0;

    for (int i = 0; i < quant; i++){
        if (prod[i].codigo == cod){
            cod_p = prod[i].codigo;
            nome_p = prod[i].nome;
            preco_p = prod[i].preco;
        }
    }
    cod_p != cod ? cout << "\nProduto não encontrado!\n\n" : 
    cout << setprecision(4) << "\nNome: " << nome_p << " Codigo: " << cod_p << " Preço: " << preco_p << "\n\n";
}

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    PRODUTOS prod[quant];

    int opcao = 0;
    string cod;

    system("cls");

    do{
        cout << "1 - Cadastrar produtos\n2 - Imprimir lista\n3 - Consultar preço\n4 - Sair\n\n";
        cout << "Escolha uma opção do menu: ";
        cin >> opcao;

        if (opcao == 1){
            Cadastrar(prod);
        }

        if (opcao == 2){
            Imprimir(prod);
        }

        if (opcao == 3){
            cout << "Informe o codigo de um produto: ";
            cin >> cod;
            Consultar(prod, cod);
        }

    } while (opcao != 4);

    cout << endl << endl;
    system("pause");
    return 0;
}