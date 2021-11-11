#include <iostream>
#include <windows.h>

#define MAXTAM 5

using namespace std;

typedef struct TipoItem {
    float id;
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

void InverterPilha(TipoPilha *pilha, TipoItem item);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  
  TipoItem item;
  TipoPilha pilha;
 

  FazPilhaVazia(&pilha);
  
  float valor;

  cout << "Digite 5 valores reais:\n";
  for(int i = 0; i < MAXTAM; i++){
      cin >> valor;
      item.id = valor;
      Empilha(&pilha, item);
  }

  system("cls");

  cout << "Pilha normal\n";
  ExibePilha(&pilha);

  InverterPilha(&pilha, item);

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

void InverterPilha(TipoPilha *pilha, TipoItem item){
    TipoPilha pilhaAux;
    FazPilhaVazia(&pilhaAux);

    for(int i = 0; i < MAXTAM; i++){
        Desempilha(pilha, &item);
        Empilha(&pilhaAux, item);
    }

    cout << "\nPilha invertida\n";
    ExibePilha(&pilhaAux);
}