#include <iostream>
#include <windows.h>

#define MAXTAM 20

using namespace std;

 typedef struct {
    int idade;
    bool gestante;
 } Cliente;

 typedef struct {
    Cliente Fila[MAXTAM];
    int inicio, fim;
    int quantidade;
 } TFila;

void TFila_Inicializa(TFila *f);
bool TFila_Vazia(TFila *f);
bool TFila_Cheia(TFila *f);
void TFila_Enfileira(TFila *f, Cliente cli);
void TFila_Desenfileira(TFila *f, Cliente *cli);
void TFila_Imprime(TFila *f);

void ComparacaoFila(TFila *f, Cliente cli);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
    TFila fila;
    Cliente cli;

    TFila_Inicializa(&fila);
    int opcao;
    for(int i = 0; i < MAXTAM; i++){
        cout << "Digite a idade: ";
        cin >> cli.idade;
        cout << "É gestante ?: 1-Sim 2-Não\n";
        cin >> opcao;
        if(opcao == 1){
            cli.gestante = true;
        } else {
            cli.gestante = false;
        }
        TFila_Enfileira(&fila, cli);
    }
    
    ComparacaoFila(&fila, cli);
    
    cout << endl << endl;
    system("pause");
    return 0;
}

void TFila_Inicializa(TFila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
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

void TFila_Enfileira(TFila *f, Cliente cli) {
    if (TFila_Cheia(f)) {
        cout << "\nFila Cheia.\n";
    } else {
        f->fim++;
        f->Fila[f->fim] = cli;
        f->quantidade++;
        //cout << "Valor enfileirado: " << x << endl;
    }
}

void TFila_Desenfileira(TFila *f, Cliente *cli) {
    int aux;
    if (TFila_Vazia(f)) {
        cout << "Fila vazia.\n";
        
    } else {
        *cli = f->Fila[f->inicio];
        f->inicio++;
        f->quantidade--;
               
    }
}

void TFila_Imprime(TFila *f) {
    if (TFila_Vazia(f)) { 
        cout << "Fila vazia.\n";
    } else {
        //cout << "Fila: ";
        for (int i = f->inicio; i <= f->fim; i++) {
            cout << f->Fila[i].idade << " Ano(s) | ";
            if(f->Fila[i].gestante == 1){
                cout << "Gestante \n";
            } else {
                cout << "Não gestante \n";
            }
        }
        cout << endl;
    }
}

void ComparacaoFila(TFila *f, Cliente cli){

    TFila fila_prioritaria, filaAux;

    TFila_Inicializa(&fila_prioritaria);
    TFila_Inicializa(&filaAux);

    for(int i = f->inicio; i <= f->fim; i++){
        if(f->Fila[i].idade >= 60 || f->Fila[i].gestante == 1){
            TFila_Desenfileira(f, &cli);
            TFila_Enfileira(&fila_prioritaria, cli);
        } else {
            TFila_Desenfileira(f, &cli);
            TFila_Enfileira(&filaAux, cli);
        }
    }
    cout << "\nFila normal\n";
    TFila_Imprime(&filaAux);
    cout << "\nFila prioritaria\n";
    TFila_Imprime(&fila_prioritaria);
}