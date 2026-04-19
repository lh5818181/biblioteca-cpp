#include "biblioteca.h"
#include <iostream>
#include <iomanip>

Biblioteca::Biblioteca() : proximoId(1) {}

void Biblioteca::adicionarLivro(std::string titulo, std::string autor) {
    Livro novoLivro(proximoId++, titulo, autor);
    livros.push_back(novoLivro);
    std::cout << "Livro adicionado com sucesso!\n";
}

void Biblioteca::listarLivros() const {
    if (livros.empty()) {
        std::cout << "\n[!] A biblioteca esta vazia." << std::endl;
        return;
    }

    std::cout << "\n" << std::string(55, '-') << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(30) << "TITULO" 
              << std::setw(20) << "AUTOR" << std::endl;
    std::cout << std::string(55, '-') << std::endl;

    for (const auto& livro : livros) {
        livro.exibirLinha();
    }
    std::cout << std::string(55, '-') << std::endl;
}