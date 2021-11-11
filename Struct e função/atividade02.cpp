#include <iostream>
#include <windows.h>
#include <string.h>

#define quant 3

using namespace std;
 
struct ALUNO {
    string nome;
    int matricula;
    float nota1, nota2;
};

void PreencheDados(ALUNO alu[quant]){ 
    for(int i = 0; i < quant; i++){
        cout << "Nome: ";
        getline(cin, alu[i].nome);
        cout << "Matricula: ";
        cin >> alu[i].matricula;
        cout << "Nota1: ";
        cin >> alu[i].nota1;
        cout << "Nota2: ";
        cin >> alu[i].nota2;
        cout << endl;
        cin.ignore(); 
    }
}

void ImprimeDados(ALUNO alu[quant]){
    float media[quant];

    cout << "!DADOS DOS ALUNOS!\n";

    for(int i = 0; i < quant; i++){
        cout << "Matricula: " << alu[i].matricula << " ";
        cout << "Nome: " << alu[i].nome << " ";
        media[i] = (alu[i].nota1 + alu[i].nota2) / 2;
        cout << "Media: " << media[i] << " ";
        cout << endl;
    }
}

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  ALUNO alu[quant];

  PreencheDados(alu);
  system("cls");
  ImprimeDados(alu);

  cout << endl << endl;
  system("pause");
  return 0;
}