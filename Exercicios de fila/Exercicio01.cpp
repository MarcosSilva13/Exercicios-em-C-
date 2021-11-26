#include <iostream>
#include <windows.h>
#include <time.h>

#define MAXTAM 10


using namespace std;

//PILHA
typedef struct {
    int Item[MAXTAM]; 
    int Topo;
} TPilha;

void TPilha_Inicializa(TPilha *p);
int TPilha_Vazia(TPilha *p);
int TPilha_Cheia(TPilha *p);
void TPilha_Empilha(TPilha *p, int x);
int TPilha_Desempilha(TPilha *p);


//FILA
typedef struct {
    int inicio, fim;
    int Fila[MAXTAM];
    int tamanho;
} TFila;

void TFila_Inicializa(TFila *f);
bool TFila_Vazia(TFila *f);
bool TFila_Cheia(TFila *f);
void TFila_Enfileira(TFila *f, int x);
int TFila_Desenfileira(TFila *f);
void TFila_Imprime(TFila *f);

void InverteFila(TFila *f, TPilha *p);

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
    TFila f;
    TPilha p;
    TFila_Inicializa(&f);
    TPilha_Inicializa(&p);

    srand(time(NULL));

    int num;
    for(int i = 0; i < MAXTAM; i++){
        num = rand() % 100;
        TFila_Enfileira(&f, num);
    } 
    
    cout << "Fila normal\n";
    TFila_Imprime(&f);
    
    InverteFila(&f, &p);
    
    cout << endl << endl;
    system("pause");
    return 0;
}

void TPilha_Inicializa(TPilha *p) {
    p->Topo = -1; // Indica que a pilha está inicializada e vazia
}

int TPilha_Vazia(TPilha *p) {
    if (p->Topo == -1) {
        return 1; // Retorno verdadeiro, a pilha está vazia
    } else {
        return 0; // Retorno falso, a pilha não está vazia
    }
}

int TPilha_Cheia(TPilha *p) {
    if (p->Topo == MAXTAM-1) {
        return 1; // Retorno verdadeiro, a pilha está cheia: 0 a 9 preenchidos
    } else {
        return 0; // Retorno falso, a pilha não está cheia
    }
}

void TPilha_Empilha(TPilha *p, int x) {
    if (TPilha_Cheia(p) == 1) {
        cout << "\nPilha cheia\n";
    } else {
        p->Topo++; 
        p->Item[p->Topo] = x;
        //cout << "Valor empilhado: " << x << endl;
    }
}

int TPilha_Desempilha(TPilha *p) {
   int aux; // Receber o valor da pilha que será desempilhado
   if (TPilha_Vazia(p) == 1) {
        cout << "\nImpossível desempilhar. Pilha vazia\n";
   } else {
        aux = p->Item[p->Topo];
        p->Topo--;
        return aux;
   }
}

void TFila_Inicializa(TFila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

bool TFila_Vazia(TFila *f) {
    if (f->inicio > f->fim) {   // 0 é maior que -1 no começo
        return true; // 1
    } else {
        return false; // 0 fila não vazia 
    }
}

bool TFila_Cheia(TFila *f) {
    if (f->fim == MAXTAM-1) {
        return true; // fila cheia
    } else {
        return false; // 0 fila não cheia
    }
}

void TFila_Enfileira(TFila *f, int x) {
    if (TFila_Cheia(f)) {
        cout << "\nFila Cheia.\n";
    } else {
        f->fim++;
        f->Fila[f->fim] = x;
        f->tamanho++;
        //cout << "Valor enfileirado: " << x << endl;
    }
}

int TFila_Desenfileira(TFila *f) {
    int aux;
    if (TFila_Vazia(f)) {
        cout << "Fila vazia.\n";
        
    } else {
        aux = f->Fila[f->inicio];
        f->inicio++;
        f->tamanho--;
        
        return aux;
        }       
    }

void TFila_Imprime(TFila *f) {
    if (TFila_Vazia(f)) { 
        cout << "Fila vazia.\n";
    } else {
        cout << "Fila: ";
        for (int i = f->inicio; i <= f->fim; i++) {
            cout << f->Fila[i] << " ";
        }
        cout << endl;
    }
}

void InverteFila(TFila *f, TPilha *p){
    TFila fAux;
    TFila_Inicializa(&fAux);

    int aux;
    
    while(!TFila_Vazia(f)){
        aux = TFila_Desenfileira(f);
        TPilha_Empilha(p, aux);
    }

    while(TPilha_Vazia(p) != 1){
        aux = TPilha_Desempilha(p);
        TFila_Enfileira(&fAux, aux);
    }

    cout << "Fila invertida\n";
    TFila_Imprime(&fAux); 
}