#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

#define quant 10

struct ALUNOS {
    string nome;
    int matricula;
    float media_final;
};

void PreencheDados(ALUNOS alu[quant]){
    for(int i = 0; i < quant; i++){
        cout << "Nome: ";
        getline(cin, alu[i].nome);
        cout << "Matricula: ";
        cin >> alu[i].matricula;
        cout << "Media final: ";
        cin >> alu[i].media_final;
        cout << "\n";
        cin.ignore();
    }
}
void ExibeAprovados(ALUNOS alu[quant], ALUNOS alu_apro[quant]){
    cout << "ALUNOS APROVADOS\n";

    for(int i = 0; i < quant; i++){
        if(alu[i].media_final >= 6.0){
            alu_apro[i].nome = alu[i].nome;
            alu_apro[i].matricula = alu[i].matricula;
            alu_apro[i].media_final = alu[i].media_final;
        }

        if(alu_apro[i].nome != "" && alu_apro[i].matricula != NULL && alu_apro[i].media_final != NULL){
            cout << "Nome: " << alu_apro[i].nome << " ";
            cout << "Matricula: " << alu_apro[i].matricula << " ";
            cout << "Media final: " << alu_apro[i].media_final << " ";
            cout << "\n";
        }
    }
}

void ExibeReprovados(ALUNOS alu[quant], ALUNOS alu_repro[quant]){
    cout << "ALUNOS REPROVADOS\n";

    for(int i = 0; i < quant; i++){
        if(alu[i].media_final < 6.0){
            alu_repro[i].nome = alu[i].nome;
            alu_repro[i].matricula = alu[i].matricula;
            alu_repro[i].media_final = alu[i].media_final;
        }

        if(alu_repro[i].nome != "" && alu_repro[i].matricula != NULL && alu_repro[i].media_final != NULL){
            cout << "Nome: " << alu_repro[i].nome << " ";
            cout << "Matricula: " << alu_repro[i].matricula << " ";
            cout << "Media final: " << alu_repro[i].media_final << " ";
            cout << "\n";
        } 
    }
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  ALUNOS alu[quant], alu1[quant], alu2[quant];
  
  PreencheDados(alu);
  system("cls");
  ExibeAprovados(alu,alu1);
  cout << "\n";
  ExibeReprovados(alu,alu2);
 
  cout << endl << endl;
  system("pause");
  return 0;
}