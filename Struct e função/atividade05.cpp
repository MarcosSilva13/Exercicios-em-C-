#include <iostream>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

#define quant 3

struct PESSOA {
    string nome;
    float altura;
    float peso;
    string cpf;
    char sexo;
};

void CadastraPessoa(PESSOA p[quant]){
    for(int i = 0; i < quant; i++){
        cout << "Nome: ";
        cin.ignore();
        getline(cin, p[i].nome);
        cout << "Altura: ";
        cin >> p[i].altura;
        cout << "Peso: ";
        cin >> p[i].peso;
        cout << "CPF: ";
        cin.ignore();
        getline(cin, p[i].cpf);
        cout << "Sexo(M/F): ";
        cin >> p[i].sexo;
        cout << "\n";
    }   
}

void Pesquisa(PESSOA p[quant], string cpf){
    float imc;
    string aux;
    for(int i = 0; i < quant; i++){
        if(p[i].cpf == cpf){
            aux = p[i].cpf;
            imc = p[i].peso / pow(p[i].altura,2);
            cout << setprecision(4) << "\nNome: " << p[i].nome << " IMC: " << imc << "\n\n";
        }
    }
    aux != cpf ? cout << "\nCPF Não encontrado!\n\n" : cout << "";  
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  PESSOA p[quant];
  int opcao = 0;
  string cpf;

  system("cls");

  do{
  cout << "1 - Cadastro\n2 - Pesquisa\n3 - Sair\nEscolha uma opção do menu: ";
  cin >> opcao;
  
  if(opcao == 1){         
    CadastraPessoa(p); 
  }

  if(opcao == 2){
    cout << "Informe um cpf: ";
    cin >> cpf;
    Pesquisa(p, cpf);
  }

  }while(opcao != 3);

  cout << endl << endl;
  system("pause");
  return 0;
}