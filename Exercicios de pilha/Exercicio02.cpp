#include <iostream>
#include <windows.h>
 
#define MAXTAM 3

using namespace std;

typedef struct TipoItem {
    int id;
} TipoItem;

typedef struct Pilha {
    TipoItem itens[MAXTAM];
    int topo;
} TipoPilha;

void FazPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaVazia(TipoPilha *pilha);
void Empilha(TipoPilha *pilha, TipoItem item);
void Desempilha(TipoPilha *pilha, TipoItem *item);
void ExibePilha(TipoPilha *pilha);
int Tamanho(TipoPilha *pilha);

bool Igual(TipoPilha *P1, TipoPilha *P2);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  TipoItem item;
  TipoPilha pilha1, pilha2;

  FazPilhaVazia(&pilha1);
  FazPilhaVazia(&pilha2);

  int num;  

  for(int i = 0; i < MAXTAM; i++){
      cout << "Digite um numero para a pilha 1: ";
      cin >> num;
      item.id = num;
      Empilha(&pilha1, item);

      cout << "Digite um numero para a pilha 2: ";
      cin >> num;
      item.id = num;
      Empilha(&pilha2, item);
  }

  cout << endl;

  Igual(&pilha1, &pilha2) == 0 ? cout << "As pilhas são diferentes\n": cout << "As pilhas são iguais\n";

  return 0;
}

void FazPilhaVazia(TipoPilha *pilha) {
   pilha->topo = 0;
}

bool VerificaPilhaVazia(TipoPilha *pilha) {
    if (pilha->topo == 0) {
        return true;
    } else return false;
}

void Empilha(TipoPilha *pilha, TipoItem item) {
    if (pilha->topo == MAXTAM) {
        cout << "\nPilha cheia\n";
    } else {
        pilha->itens[pilha->topo] = item;
        pilha->topo++;
        //cout << "\nItem empilhado com sucesso!\n";
    }
}

void ExibePilha(TipoPilha *pilha) { 
    for (int i=pilha->topo-1; i>=0; i--) {
        cout << pilha->itens[i].id << "\n";
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *item){
    if(VerificaPilhaVazia(pilha)){
        cout << "Pilha vazia!\n";
        return;
    } 
        pilha->topo--;
        *item = pilha->itens[pilha->topo];
    
}

int Tamanho(TipoPilha *pilha){
    return pilha->topo;
}

bool Igual(TipoPilha *P1, TipoPilha *P2){
    TipoItem item;

    if(Tamanho(P1) != Tamanho(P2)){
        return false;
    } else {
        while(!VerificaPilhaVazia(P1)){
            int valor1, valor2;
            Desempilha(P1, &item);
            valor1 = item.id;
            Desempilha(P2, &item);
            valor2 = item.id;
            if(valor1 != valor2){
                return false;
            }
        }
    }
    return true;
}