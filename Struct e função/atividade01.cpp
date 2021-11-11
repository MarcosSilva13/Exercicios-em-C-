#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

struct PESSOA {
    string nome;
    string endereco;
    int idade;
};

PESSOA p;

void PreencheDados(){
    cout << "Nome: ";
    getline(cin, p.nome);
    cout << "Idade: ";
    cin >> p.idade;
    cout << "Endereco: ";
    cin.ignore();
    getline(cin, p.endereco);
}

void ExibeDados(){
    cout << "DADOS DA PESSOA\n";
    cout << "Nome: " << p.nome << "\n";
    cout << "Idade: " << p.idade << "\n";
    cout << "Endereco: " << p.endereco << "\n";
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  PreencheDados();
  system("cls");
  ExibeDados();
  
  cout << endl << endl;
  system("pause");
  return 0;
}