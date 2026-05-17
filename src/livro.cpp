#include "livro.h"
#include <iostream>
#include <iomanip>

Livro::Livro(int id, std::string titulo, Autor* autorPtr)
    : id(id), titulo(titulo), autor(autorPtr), disponivel(true), dataEmprestimo("") {}

int Livro::getId() const { return id; }
std::string Livro::getTitulo() const { return titulo; }
Autor* Livro::getAutor() const { return autor; }

bool Livro::isDisponivel() const { return disponivel; }
std::string Livro::getDataEmprestimo() const { return dataEmprestimo; }

void Livro::emprestar(std::string data) {
    disponivel = false;
    dataEmprestimo = data;
}

void Livro::devolver() {
    disponivel = true;
    dataEmprestimo = "";
}

void Livro::exibirLinha() const {
    int limiteTitulo = 25; 
    int limiteAutorInfo = 20; 

    std::string tituloExibir = titulo;
    if (tituloExibir.length() > limiteTitulo) {
        tituloExibir = tituloExibir.substr(0, limiteTitulo - 3) + "...";
    }

    std::string autorInfo = "Desconhecido";
    if (autor != nullptr) {
        autorInfo = autor->getNome();
        if (autor->getNacionalidade() != "Desconhecida") {
            autorInfo += " (" + autor->getNacionalidade() + ")";
        }
    }

    if (autorInfo.length() > limiteAutorInfo) {
        autorInfo = autorInfo.substr(0, limiteAutorInfo - 3) + "...";
    }

    std::string statusStr = disponivel ? "Disponivel" : "Emprestado";

    // Layout atualizado com coluna de status
    std::cout << std::left << std::setw(5) << id 
              << std::setw(28) << tituloExibir 
              << std::setw(25) << autorInfo 
              << std::setw(12) << statusStr << std::endl;
}

void Livro::setTitulo(std::string novoTitulo) { titulo = novoTitulo; }
void Livro::setAutor(Autor* novoAutor) { autor = novoAutor; }