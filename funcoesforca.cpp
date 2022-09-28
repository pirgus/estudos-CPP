//
// Created by jaque on 28/09/2022.
//

#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

extern string plvSecreta;
extern vector<char> chutesErrados;
extern map<char, bool> chutou;

vector<string> leArq(){
    ifstream file; // input file stream
    file.open("palavras.txt");
    if(file.is_open()){
        int qtdPlv;
        file >> qtdPlv;

        vector<string> arqPlvs;

        for(int i = 0; i < qtdPlv; i++){
            string plvLida;
            file >> plvLida;
            arqPlvs.push_back(plvLida);
        }

        file.close();
        return arqPlvs;
    }
    else{
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(1);
    }
}

void sorteiaPalavra(){
    vector<string> palavras = leArq();

    srand(time(NULL));
    int index = rand() % palavras.size();

    plvSecreta = palavras[index];
}

void salvaArq(vector<string> novaLista){
    ofstream file;
    file.open("palavras.txt");
    if(file.is_open()){
        file << novaLista.size() << endl;
        for(string word : novaLista){
            file << word << endl;
        }

        file.close();
    }
    else{
        cout << "Nao foi possivel abrir o arquivo." << endl;
        exit(1);
    }
}

void adicionaPalavra(){
    cout << "Digite a nova palavra (em letras maiusculas)" << endl;
    string novaPalavra;
    cin >> novaPalavra;

    vector<string> listaPalavras = leArq();
    listaPalavras.push_back(novaPalavra);

    salvaArq(listaPalavras);
}

bool naoEnforcou(){
    return chutesErrados.size() < 5;
}

bool naoAcertou(){
    for(char letra : plvSecreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool letraExiste(char chute){
    for(char letra : plvSecreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

void chuta(){
    cout << "Seu chute >> ";
    char chute;
    cin >> chute;

    chutou[chute] = true;
    if(letraExiste(chute)){
        cout << "Seu chute esta na palavra" << endl;
    }
    else{
        chutesErrados.push_back(chute); // joga o chute no FINAL do vetor ==> "push_back"
        cout << "Seu chute nao esta na palavra" << endl;
    }
    cout << endl;
}

void imprimePlv(){
    for(char letra : plvSecreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void imprimeErrados(){
    cout << "Chutes errados: ";
    for(char letra : chutesErrados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprimeCabec(){
    cout << "*******************" << endl;
    cout << "** Jogo da Forca **" << endl;
    cout << "*******************" << endl;
    cout << endl;
}