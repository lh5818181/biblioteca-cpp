#include <iostream>
#include <string>
#include "biblioteca.h"

void exibirMenu() {
    std::cout << "\n--- SISTEMA DE BIBLIOTECA ---" << std::endl;
    std::cout << "1. Adicionar Livro" << std::endl;
    std::cout << "2. Listar Livros" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    Biblioteca minhaBiblioteca;
    int opcao = -1;

    while (opcao != 0) {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore();

        if (opcao == 1) {
            std::string titulo, autor;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Autor: ";
            std::getline(std::cin, autor);
            minhaBiblioteca.adicionarLivro(titulo, autor);

        } else if (opcao == 2) {
            minhaBiblioteca.listarLivros();
        }
    }
    return 0;
}