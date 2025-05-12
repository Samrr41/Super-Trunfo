#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// Classe para representar uma carta
class Carta {
public:
    string nome;
    int velocidade;
    int potencia;
    int peso;
    bool superTrunfo;

    Carta(string n, int v, int p, int pe, bool st) : 
        nome(n), velocidade(v), potencia(p), peso(pe), superTrunfo(st) {}
};

// Função para comparar cartas
string compararCartas(Carta jogador, Carta computador, string atributo) {
    if (jogador.superTrunfo) return "Jogador vence (Super Trunfo)!";
    if (computador.superTrunfo) return "Computador vence (Super Trunfo)!";

    if (atributo == "velocidade") {
        if (jogador.velocidade > computador.velocidade) return "Jogador vence!";
        else return "Computador vence!";
    }
    else if (atributo == "potencia") {
        if (jogador.potencia > computador.potencia) return "Jogador vence!";
        else return "Computador vence!";
    }
    else if (atributo == "peso") {
        if (jogador.peso < computador.peso) return "Jogador vence!"; // Menor peso vence
        else return "Computador vence!";
    }
    return "Empate!";
}

int main() {
    srand(time(0));

    // Criando o baralho
    vector<Carta> baralho = {
        Carta("Fusca", 80, 50, 900, false),
        Carta("Ferrari", 300, 500, 1200, false),
        Carta("Caminhão", 100, 800, 5000, false),
        Carta("Super Jato", 1000, 1000, 2000, true) // Super Trunfo
    };

    // Distribuindo cartas (simplificado)
    Carta jogador = baralho[rand() % baralho.size()];
    Carta computador = baralho[rand() % baralho.size()];

    // Rodada
    string atributoEscolhido;
    cout << "Escolha um atributo (velocidade, potencia, peso): ";
    cin >> atributoEscolhido;

    string resultado = compararCartas(jogador, computador, atributoEscolhido);
    cout << resultado << endl;

    return 0;
}