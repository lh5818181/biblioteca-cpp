#include <iostream>
#include <string>
#include "biblioteca.h"

void exibirMenu() {
    std::cout << "\n--- SISTEMA DE BIBLIOTECA ---" << std::endl;
    std::cout << "1. Adicionar Livro" << std::endl;
    std::cout << "2. Listar Livros" << std::endl;
    std::cout << "3. Remover Livro" << std::endl;
    std::cout << "4. Editar Livro" << std::endl;
    std::cout << "5. Buscar por Titulo" << std::endl;
    std::cout << "6. Buscar por Autor" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    Biblioteca minhaBiblioteca;
    minhaBiblioteca.carregarDeArquivo("data/livros.csv");

    int opcao = -1;

    while (opcao != 0) {
        exibirMenu();
        if (!(std::cin >> opcao)) {
            std::cout << "\n[!] Entrada invalida. Digite um numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore();

        if (opcao == 1) {
            std::string titulo, autor, nacionalidade;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Autor: ";
            std::getline(std::cin, autor);
            std::cout << "Nacionalidade do Autor: ";
            std::getline(std::cin, nacionalidade);
            minhaBiblioteca.adicionarLivro(titulo, autor, nacionalidade);

        } else if (opcao == 2) {
            minhaBiblioteca.listarLivros();
        } else if (opcao == 3) {
            int idParaRemover;
            std::cout << "Digite o ID do livro que deseja remover: ";
            if (std::cin >> idParaRemover) {
                minhaBiblioteca.removerLivro(idParaRemover);
            } else {
                std::cout << "\n[!] ID invalido." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        } else if (opcao == 4) {
            int idParaEditar;
            std::cout << "Digite o ID do livro que deseja editar: ";
            if (std::cin >> idParaEditar) {
                minhaBiblioteca.editarLivro(idParaEditar);
            } else {
                std::cout << "\n[!] ID invalido." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        } else if (opcao == 5) {
            std::string termo;
            std::cout << "Digite o titulo (ou parte dele) para buscar: ";
            std::getline(std::cin >> std::ws, termo);
            minhaBiblioteca.buscarPorTitulo(termo);
        } else if (opcao == 6) {
            std::string autor;
            std::cout << "Digite o nome do autor para buscar: ";
            std::getline(std::cin >> std::ws, autor);
            minhaBiblioteca.buscarPorAutor(autor);
        } else if (opcao == 0) {
            minhaBiblioteca.salvarParaArquivo("data/livros.csv");
            std::cout << "Saindo e salvando dados..." << std::endl;
        }
    }
    return 0;
}