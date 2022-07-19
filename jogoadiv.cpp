#include <iostream>
#include <cstdlib> // funcoes padroes de C
#include <ctime>
using namespace std;

int main()
{
    cout << "**********************************" << endl;
    cout << "Bem-vindos ao jogo da adivinhacao!" << endl;
    cout << "**********************************" << endl;

    cout << "Escolha o nivel de dificuldade: " << endl;
    cout << "Facil (f) Medio (m) Dificil (d)" << endl;

    char dificul;
    cin >> dificul;

    int nTentativas;
    if(dificul == 'f'){
        nTentativas = 15;
    }
    else if (dificul == 'm'){
        nTentativas = 10;
    }
    else if(dificul == 'd'){
        nTentativas = 5;
    }

    srand(time(NULL));
    const int NUMSECRETO = rand() % 100; // precisa inicializar pra ser "aleatorio" mesmo
    //cout << "O numero secreto eh " << numSecreto << ". Nao conte para ninguem." << endl;
    int chute;
    bool errado = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= nTentativas, errado; tentativas++){
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute? " << endl;
        cin >> chute;

        double lostPontos = abs(chute - NUMSECRETO)/2.0;
        pontos -= lostPontos;

        cout << "O valor do seu chute e: " << chute << endl;

        bool acertou = chute == NUMSECRETO;
        bool maior = chute > NUMSECRETO;
        
        if(acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            errado = false;
        }
        else if(maior)
            cout << "Seu chute foi maior do que o numero secreto!" << endl;
        else
            cout << "Seu chute foi menor do que o numero secreto!" << endl;
    }
    tentativas--;
    cout << "Fim de jogo!" << endl;
    if(errado){
        cout << "Voce perdeu, tente novamente." << endl;
    }
    else{
        cout << "Voce precisou de " << tentativas << " tentativas." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi: " << pontos << "." << endl;
    }
    
}