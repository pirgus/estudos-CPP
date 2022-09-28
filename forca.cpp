#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "funcoesforca.hpp"

using namespace std;

string plvSecreta;
map<char, bool> chutou;
vector<char> chutesErrados;


int main(){
    imprimeCabec();

    leArq();

    sorteiaPalavra();

    while(naoAcertou() && naoEnforcou()){
        imprimeErrados();

        imprimePlv();

        chuta();
    }
    cout << "Fim de jogo!" << endl;
    if(naoAcertou()){
        cout << "Voce perdeu, tente novamente!" << endl;
        cout << "A palavra era: " << plvSecreta << endl;
    }
    else{
        cout << "Parabens!! Voce acertou a palavra." << endl;
        cout << "A palavra era: " << plvSecreta << endl;
        cout << "Voce pode adicionar uma palavra nova " << endl;
        cout << "Digite (S) para adicionar ou (N) para ignorar." << endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adicionaPalavra();
        }
        else{
            cout << "Ate mais!" << endl;
        }
    }

}