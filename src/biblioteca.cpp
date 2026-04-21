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

void Biblioteca::removerLivro(int id) {
    bool encontrado = false;

    // Percorre o vetor procurando pelo ID
    for (auto it = livros.begin(); it != livros.end(); ++it) {
        if (it->getId() == id) {
            livros.erase(it); // Remove o livro da memória
            encontrado = true;
            std::cout << "\n[OK] Livro com ID " << id << " removido com sucesso!" << std::endl;
            break; 
        }
    }

    if (!encontrado) {
        std::cout << "\n[!] Erro: Livro com ID " << id << " nao encontrado." << std::endl;
    }
}

void Biblioteca::editarLivro(int id) {
    for (auto& livro : livros) {
        if (livro.getId() == id) {
            std::string novoTitulo, novoAutor;
            std::cout << "Novo Titulo (atual: " << livro.getTitulo() << "): ";
            std::getline(std::cin >> std::ws, novoTitulo);
            std::cout << "Novo Autor (atual: " << livro.getAutor() << "): ";
            std::getline(std::cin >> std::ws, novoAutor);

            livro.setTitulo(novoTitulo);
            livro.setAutor(novoAutor);
            std::cout << "\n[OK] Livro atualizado com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "\n[!] Livro com ID " << id << " nao encontrado." << std::endl;
}