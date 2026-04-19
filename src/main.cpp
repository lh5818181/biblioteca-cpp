#include <iostream>
#include <vector>
#include <string>
#include "livro.h"

void exibirMenu() {
    std::cout << "\n--- SISTEMA DE BIBLIOTECA ---" << std::endl;
    std::cout << "1. Adicionar Livro" << std::endl;
    std::cout << "2. Listar Livros" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    std::vector<Livro> biblioteca;
    int opcao = -1;
    int proximoId = 1;

    while (opcao != 0) {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer do teclado

        if (opcao == 1) {
            std::string titulo, autor;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Autor: ";
            std::getline(std::cin, autor);

            biblioteca.emplace_back(proximoId++, titulo, autor);
            std::cout << "Livro adicionado com sucesso!" << std::endl;

        } else if (opcao == 2) {
            std::cout << "\n--- LISTA DE LIVROS ---" << std::endl;
            if (biblioteca.empty()) {
                std::cout << "Nenhum livro cadastrado." << std::endl;
            } else {
                for (const auto& livro : biblioteca) {
                    livro.exibir();
                }
            }
        }
    }

    return 0;
}