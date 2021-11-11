#include <iostream>
#include <windows.h>

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

int maiorElemento(TipoPilha *pilha, TipoItem item);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  TipoItem item;
  TipoPilha pilha;

  int retorno, valor;

  FazPilhaVazia(&pilha);

    cout << "Digite 5 numeros:\n";
    for(int i = 0; i < MAXTAM; i++){
        cin >> valor;
        item.id = valor;
        Empilha(&pilha, item);
    }
    
    system("cls");
    ExibePilha(&pilha);
    
    cout << endl;
    retorno = maiorElemento(&pilha, item);

    cout << "O Maior elemento é: " << retorno;
  
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

int maiorElemento(TipoPilha *pilha, TipoItem item){
    int maior, aux;
    maior = item.id;

    while(!VerificaPilhaVazia(pilha)){
        aux = item.id;
        Desempilha(pilha, &item);
        if(aux >= maior){
            maior = aux;
        }
    }
    return maior;
}