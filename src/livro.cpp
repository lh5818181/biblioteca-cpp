#include "livro.h"
#include <iostream>
#include <iomanip>

Livro::Livro(int id, std::string titulo, std::string autor) 
    : id(id), titulo(titulo), autor(autor) {}

int Livro::getId() const { return id; }
std::string Livro::getTitulo() const { return titulo; }
std::string Livro::getAutor() const { return autor; }

void Livro::exibirLinha() const {
    std::cout << std::left << std::setw(5) << id 
              << std::setw(30) << titulo 
              << std::setw(20) << autor << std::endl;
}