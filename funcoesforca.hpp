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

vector<string> leArq();
void sorteiaPalavra();
void salvaArq(vector<string> novaLista);
void adicionaPalavra();
bool naoEnforcou();
bool naoAcertou();
bool letraExiste(char chute);
void chuta();
void imprimePlv();
void imprimeErrados();
void imprimeCabec();

