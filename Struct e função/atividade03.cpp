#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

#define quant 5

struct PESSOA {
  char nome[20];
  char endereco[50];
  char telefone[15];
};

PESSOA p[quant];
PESSOA aux;

void Cadatro(PESSOA p[quant]){
  cout << "Cadastro ";
  for(int i = 0; i < quant; i++){
      cout << "\nNome: ";
      gets(p[i].nome);
      cout << "Endereco: ";
      gets(p[i].endereco);
      cout << "Telefone: ";
      gets(p[i].telefone);
  }  
}

void Ordena(PESSOA p[quant]){
  int r;
  for(int i = 0; i < quant; i++){
    for(int j = i+1; j < quant; j++){
        r = strcmp(p[i].nome, p[j].nome);
        if(r > 0){
          aux = p[j];
          p[j] = p[i];
          p[i] = aux;
        }
    }
  }
}

void ImprimiDados(PESSOA p[quant]){
    cout << "\nDados Cadastrados:\n";
    for(int i = 0; i < quant; i++){
        cout << "Nome: " << p[i].nome << " Endereco: " << p[i].endereco << " Telefone: " << p[i].telefone;
        cout << endl;
    }
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  Cadatro(p);
  Ordena(p);
  system("cls");
  ImprimiDados(p);

  cout << endl << endl;
  system("pause");
  return 0;
}