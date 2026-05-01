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
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    Biblioteca minhaBiblioteca;
    minhaBiblioteca.carregarDeArquivo("data/livros.csv"); // Carrega ao iniciar
    
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
        } else if (opcao == 3) {
            int idParaRemover;
            std::cout << "Digite o ID do livro que deseja remover: ";
            std::cin >> idParaRemover;
            minhaBiblioteca.removerLivro(idParaRemover);
        } else if (opcao == 4) {
            int idParaEditar;
            std::cout << "Digite o ID do livro que deseja editar: ";
            std::cin >> idParaEditar;
            minhaBiblioteca.editarLivro(idParaEditar);
        } else if (opcao == 0) {
            minhaBiblioteca.salvarParaArquivo("data/livros.csv");
            std::cout << "Saindo e salvando dados..." << std::endl;
        } else if (opcao == 5) {
            std::string termo;
            std::cout << "Digite o titulo (ou parte dele) para buscar: ";
            std::getline(std::cin >> std::ws, termo);
            minhaBiblioteca.buscarPorTitulo(termo);
        }
                
    }
    return 0;
}