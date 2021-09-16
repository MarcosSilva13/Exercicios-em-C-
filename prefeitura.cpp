#include <iostream>
#include <windows.h>
#include <iomanip>
 
using namespace std;

#define tot_pessoas 20
 
struct PESSOA {
    float salario;
    int idade, num_filhos;
    char sexo;
};

void MediaSalario(PESSOA p[tot_pessoas]){
    float media_salario, tot_salario = 0;
    
    for(int i = 0; i < tot_pessoas; i++){
        tot_salario += p[i].salario;
    }

    media_salario = tot_salario / tot_pessoas;

    cout << "A media de salario da população é: R$ " << media_salario << endl;
}

void MediaNumFilhos(PESSOA p[tot_pessoas]){ 
    int media_filhos, tot_filhos = 0;

    for(int i = 0; i < tot_pessoas; i++){
        tot_filhos += p[i].num_filhos;
    }

    media_filhos = tot_filhos / tot_pessoas;

    cout << "A media do numero de filhos é: " << media_filhos << endl;
}

void MaiorSalario(PESSOA p[tot_pessoas]){
    float maior_salario;

    for(int i = 0; i < tot_pessoas; i++){
        if(p[i].salario > maior_salario){
            maior_salario = p[i].salario;
        }
    }

    cout << "O maior salario é: R$ " << maior_salario << endl;
}

void MulheresSalario_1000(float maior_1000, float tot_m){
    float percentual;

    percentual = (maior_1000 / tot_m) * 100;

    if(tot_m > 0){
        cout << setprecision(3) << "O percentual de mulheres com salario superior a R$ 1000.00 é: " << percentual << "%" << endl;
    } else {
        cout << "Não foi cadastrado nenhuma mulher !!!" << endl;
    }
}

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
    PESSOA p[tot_pessoas];

    float mulheres_maior_1000 = 0, tot_mulheres = 0;

    system("cls");
    for(int i = 0; i < tot_pessoas; i++){
        cout << "Digite o salario: ";
        cin >> p[i].salario;
        cout << "Digite a idade: ";
        cin >> p[i].idade;
        cout << "Digite o numero de filhos: ";
        cin >> p[i].num_filhos;
        cout << "Digite o sexo(M/F): ";
        cin >> p[i].sexo;

      if(p[i].sexo == 'F'){
          tot_mulheres++;
      }

      if(p[i].sexo == 'F' && p[i].salario > 1000){
          mulheres_maior_1000++;
      }
      cout << endl;
    }

  MediaSalario(p);

  MediaNumFilhos(p);

  MaiorSalario(p);

  MulheresSalario_1000(mulheres_maior_1000, tot_mulheres);
 
  cout << endl << endl;
  system("pause");
  return 0;
}