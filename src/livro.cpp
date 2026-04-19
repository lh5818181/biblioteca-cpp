#include "livro.h"
#include <iostream>

Livro::Livro(int id, std::string titulo, std::string autor) 
    : id(id), titulo(titulo), autor(autor) {}

int Livro::getId() const { return id; }
std::string Livro::getTitulo() const { return titulo; }
std::string Livro::getAutor() const { return autor; }

void Livro::exibir() const {
    std::cout << "[" << id << "] " << titulo << " - Autor: " << autor << std::endl;
}