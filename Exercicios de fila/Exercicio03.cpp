#include <iostream>
#include <windows.h>
 
#define MAXTAM 20

using namespace std;

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
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    TFila f;
    TFila_Inicializa(&f); 
    //Escolhi usar a FILA porque achei mais facil para manipular a saida na impressão,
    //e também porque ja enfilera os numeros na sequencia.

    int n, d = 2;

    cout << "Digite um numero: ";
    cin >> n;

    while(n > 1){
        if(n % d == 0){
          n = n / d;
          TFila_Enfileira(&f, d); 
        } else {
          d++;
        }
    }

    TFila_Imprime(&f);
 
    cout << endl << endl;
    system("pause");
    return 0;
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
            cout << f->Fila[i];
            if(i <= f->fim - 1){
                cout << " * ";
            }
        }
        cout << endl;
    }
}