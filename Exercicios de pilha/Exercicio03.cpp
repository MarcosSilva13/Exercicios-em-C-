#include <iostream>
#include <windows.h>
#include <time.h>

#define MAXTAM 5

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

void PreenchePilha(TipoPilha *pilha, int vet[]);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  TipoPilha pilha;

  FazPilhaVazia(&pilha);

  srand(time(NULL));

  int vetor[MAXTAM];
  
  for(int i = 0; i < MAXTAM; i++){
      vetor[i] = rand() % 100;
  }

  cout << "VETOR\n";  
  for(int i = 0; i < MAXTAM; i++){
      cout << vetor[i] << " ";
  }

  PreenchePilha(&pilha, vetor);

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

void PreenchePilha(TipoPilha *pilha, int vet[]){
    TipoItem item;

    for(int i = 0; i < MAXTAM; i++){
        item.id = vet[i];
        Empilha(pilha, item);
    }

    cout << "\n\nPilha preenchida\n";
    ExibePilha(pilha);
}