#include "livro.h"
#include <iostream>
#include <iomanip>

Livro::Livro(int id, std::string titulo, Autor* autorPtr) 
    : id(id), titulo(titulo), autor(autorPtr) {}

int Livro::getId() const { return id; }
std::string Livro::getTitulo() const { return titulo; }
Autor* Livro::getAutor() const { return autor; }

void Livro::exibirLinha() const {
    int limiteTitulo = 27; 
    int limiteAutorInfo = 22; // Aumentamos um pouco para caber o "(Nacionalidade)"

    std::string tituloExibir = titulo;
    if (tituloExibir.length() > limiteTitulo) {
        tituloExibir = tituloExibir.substr(0, limiteTitulo - 3) + "...";
    }

    // Pega o nome e a nacionalidade do autor de forma segura
    std::string autorInfo = "Desconhecido";
    if (autor != nullptr) {
        autorInfo = autor->getNome();
        if (autor->getNacionalidade() != "Desconhecida") {
            autorInfo += " (" + autor->getNacionalidade() + ")"; // Exemplo: Chimamanda (Nigéria)
        }
    }

    if (autorInfo.length() > limiteAutorInfo) {
        autorInfo = autorInfo.substr(0, limiteAutorInfo - 3) + "...";
    }

    // Imprime na tela mantendo a formatação alinhada
    std::cout << std::left << std::setw(5) << id 
              << std::setw(30) << tituloExibir 
              << std::setw(25) << autorInfo << std::endl;
}

void Livro::setTitulo(std::string novoTitulo) { titulo = novoTitulo; }
void Livro::setAutor(Autor* novoAutor) { autor = novoAutor; }