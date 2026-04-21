#include "livro.h"
#include <iostream>
#include <iomanip>

Livro::Livro(int id, std::string titulo, std::string autor) 
    : id(id), titulo(titulo), autor(autor) {}

int Livro::getId() const { return id; }
std::string Livro::getTitulo() const { return titulo; }
std::string Livro::getAutor() const { return autor; }

void Livro::exibirLinha() const {
    // limites para as colunas
    int limiteTitulo = 27; 
    int limiteAutor = 17;

    std::string tituloExibir = titulo;
    if (tituloExibir.length() > limiteTitulo) {
        tituloExibir = tituloExibir.substr(0, limiteTitulo - 3) + "...";
    }

    std::string autorExibir = autor;
    if (autorExibir.length() > limiteAutor) {
        autorExibir = autorExibir.substr(0, limiteAutor - 3) + "...";
    }

    std::cout << std::left << std::setw(5) << id 
              << std::setw(30) << tituloExibir 
              << std::setw(20) << autorExibir << std::endl;
}

void Livro::setTitulo(std::string novoTitulo) { titulo = novoTitulo; }
void Livro::setAutor(std::string novoAutor) { autor = novoAutor; }