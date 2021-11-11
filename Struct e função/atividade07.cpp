#include <iostream>
#include <windows.h>
#include <time.h>
 
using namespace std;

struct partida {
  string naipe_sorteado[6];
  int cartas[6];
};

string Naipe(int num_naipe){
    string nome;
    switch (num_naipe){
        case 0: 
            nome = "Ouros";
            break;
        case 1:
            nome = "Copas";
            break;
        case 2:
            nome = "Paus";
            break;
        case 3:
            nome = "Espadas";
            break;
    }
    return nome;
}

string Carta(string naipe, int n){
    string carta;
    switch (n){
        case 0:
            if(naipe.compare("Paus") == 0){
               carta = "ZAP";
            } else {
               carta = "4 de " + naipe;
               break;
            }
        case 1:
            carta = "5 de " + naipe;
            break;
        case 2:
            carta = "6 de " + naipe;
            break;
        case 3:
            carta = "7 de " + naipe;
            break;
        case 4:
            carta = "Dama de " + naipe;
            break;
        case 5:
            carta = "Valete de " + naipe;
            break;
        case 6:
            carta = "Rei de " + naipe;
            break;
        case 7:
            if(naipe.compare("Espadas") == 0){
               carta = "Espadilha";
            } else {
               carta = "Ás de " + naipe;
               break;
            }
        case 8:
            carta = "2 de " + naipe;
            break;
        case 9:
            carta = "3 de " + naipe;
            break;
    }
    return carta;
}

void Imprimi(partida p){
    system("cls");
    string nome_carta;
    cout << "Jogador 1: " << endl;
    for(int i = 0; i < 3; i++){
        nome_carta = Carta(p.naipe_sorteado[i], p.cartas[i]);
        cout << nome_carta << endl;
    }
    cout << "\nJogador 2: " << endl;
    for(int i = 3; i < 6; i++){
        nome_carta = Carta(p.naipe_sorteado[i], p.cartas[i]);
        cout << nome_carta << endl;
    }
}
 
void Sorteia(){
    partida p;
    int i = 0, num_naipe, num_carta;
    bool repetido = false;
    srand(time(NULL));
    while(i < 6){
      num_naipe = rand () % 4;
      p.naipe_sorteado[i] = Naipe(num_naipe);

      num_carta = rand () % 10;
      p.cartas[i] = num_carta;
    
      for(int j = 0; j < i; j++){
          if(p.naipe_sorteado[i] == p.naipe_sorteado[j] && p.cartas[i] == p.cartas[j]){
             repetido = true;
          }
      }

      if(!repetido){
         i++;
      }
    }
    Imprimi(p);
}

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  
  Sorteia();
 
  cout << endl << endl;
  system("pause");
  return 0;
}