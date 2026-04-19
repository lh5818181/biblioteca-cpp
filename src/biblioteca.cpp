#include "biblioteca.h"
#include <iostream>

Biblioteca::Biblioteca() : proximoId(1) {}

void Biblioteca::adicionarLivro(std::string titulo, std::string autor) {
    Livro novoLivro(proximoId++, titulo, autor);
    livros.push_back(novoLivro);
    std::cout << "Livro adicionado com sucesso!\n";
}

void Biblioteca::listarLivros() const {
    if (livros.empty()) {
        std::cout << "A biblioteca esta vazia.\n";
        return;
    }
    std::cout << "\n--- LISTA DE LIVROS ---\n";
    for (const auto& livro : livros) {
        livro.exibir();
    }
}