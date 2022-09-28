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

extern std::string plvSecreta;
extern std::vector<char> chutesErrados;
extern std::map<char, bool> chutou;

std::vector<string> leArq(){
    ifstream file; // input file stream
    file.open("palavras.txt");
    if(file.is_open()){
        int qtdPlv;
        file >> qtdPlv;

        std::vector<string> arqPlvs;

        for(int i = 0; i < qtdPlv; i++){
            std::string plvLida;
            file >> plvLida;
            arqPlvs.push_back(plvLida);
        }

        file.close();
        return arqPlvs;
    }
    else{
        std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
        exit(1);
    }
}

void sorteiaPalavra(){
    std::vector<string> palavras = leArq();

    srand(time(NULL));
    int index = rand() % palavras.size();

    plvSecreta = palavras[index];
}

void salvaArq(std::vector<string> novaLista){
    ofstream file;
    file.open("palavras.txt");
    if(file.is_open()){
        file << novaLista.size() << endl;
        for(std::string word : novaLista){
            file << word << endl;
        }

        file.close();
    }
    else{
        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
        exit(1);
    }
}

void adicionaPalavra(){
    std::cout << "Digite a nova palavra (em letras maiusculas)" << std::endl;
    std::string novaPalavra;
    std::cin >> novaPalavra;

    std::vector<string> listaPalavras = leArq();
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
    std::cout << "Seu chute >> ";
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if(letraExiste(chute)){
        std::cout << "Seu chute esta na palavra" << std::endl;
    }
    else{
        chutesErrados.push_back(chute); // joga o chute no FINAL do vetor ==> "push_back"
        std::cout << "Seu chute nao esta na palavra" << std::endl;
    }
    std::cout << std::endl;
}

void imprimePlv(){
    for(char letra : plvSecreta){
        if(chutou[letra]){
            std::cout << letra << " ";
        }
        else{
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

void imprimeErrados(){
    std::cout << "Chutes errados: ";
    for(char letra : chutesErrados){
        std::cout << letra << " ";
    }
    std::cout << std::endl;
}

void imprimeCabec(){
    std::cout << "*******************" << std::endl;
    std::cout << "** Jogo da Forca **" << std::endl;
    std::cout << "*******************" << std::endl;
    std::cout << std::endl;
}