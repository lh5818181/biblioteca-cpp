#include "biblioteca.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

// Construtor
Biblioteca::Biblioteca() : proximoIdLivro(1), proximoIdAutor(1) {}

// Método Auxiliar
Autor* Biblioteca::buscarOuCriarAutor(std::string nome) {
    for (auto& autor : autores) {
        if (autor.getNome() == nome) return &autor;
    }
    autores.emplace_back(proximoIdAutor++, nome, "Desconhecida");
    return &autores.back();
}

// 1. Adicionar
void Biblioteca::adicionarLivro(std::string titulo, std::string nomeAutor) {
    Autor* autorPtr = buscarOuCriarAutor(nomeAutor);
    livros.emplace_back(proximoIdLivro++, titulo, autorPtr);
    std::cout << "Livro adicionado com sucesso!\n";
}

// 2. Listar (O Linker reclamou desta)
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

// 3. Remover (O Linker reclamou desta)
void Biblioteca::removerLivro(int id) {
    bool encontrado = false;
    for (auto it = livros.begin(); it != livros.end(); ++it) {
        if (it->getId() == id) {
            livros.erase(it);
            encontrado = true;
            std::cout << "\n[OK] Livro com ID " << id << " removido com sucesso!" << std::endl;
            break; 
        }
    }
    if (!encontrado) std::cout << "\n[!] Erro: Livro nao encontrado." << std::endl;
}

// 4. Editar
void Biblioteca::editarLivro(int id) {
    for (auto& livro : livros) {
        if (livro.getId() == id) {
            std::string novoTitulo, novoNomeAutor;
            std::cout << "Novo Titulo: ";
            std::getline(std::cin >> std::ws, novoTitulo);
            std::cout << "Novo Autor: ";
            std::getline(std::cin >> std::ws, novoNomeAutor);

            Autor* novoAutorPtr = buscarOuCriarAutor(novoNomeAutor);
            livro.setTitulo(novoTitulo);
            livro.setAutor(novoAutorPtr);
            std::cout << "\n[OK] Livro atualizado com sucesso!" << std::endl;
            return;
        }
    }
}

// 5. Buscar por Titulo (O Linker reclamou desta)
void Biblioteca::buscarPorTitulo(std::string termo) const {
    bool encontrado = false;
    std::cout << "\n--- BUSCA: \"" << termo << "\" ---" << std::endl;
    for (const auto& livro : livros) {
        if (livro.getTitulo().find(termo) != std::string::npos) {
            livro.exibirLinha();
            encontrado = true;
        }
    }
    if (!encontrado) std::cout << "[!] Nada encontrado.\n";
}

// 6. Buscar por Autor (O Linker reclamou desta)
void Biblioteca::buscarPorAutor(std::string nomeAutor) const {
    bool encontrado = false;
    std::cout << "\n--- OBRAS DE: \"" << nomeAutor << "\" ---" << std::endl;
    for (const auto& livro : livros) {
        if (livro.getAutor()->getNome().find(nomeAutor) != std::string::npos) {
            livro.exibirLinha();
            encontrado = true;
        }
    }
    if (!encontrado) std::cout << "[!] Nada encontrado.\n";
}

// Persistência
void Biblioteca::salvarParaArquivo(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return;
    for (const auto& livro : livros) {
        arquivo << livro.getId() << "," << livro.getTitulo() << "," << livro.getAutor()->getNome() << "\n";
    }
    arquivo.close();
}

void Biblioteca::carregarDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return;
    livros.clear();
    autores.clear();
    std::string linha;
    int maiorId = 0;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::stringstream ss(linha);
        std::string idStr, titulo, nomeAutor;
        std::getline(ss, idStr, ',');
        std::getline(ss, titulo, ',');
        std::getline(ss, nomeAutor, ',');
        int id = std::stoi(idStr);
        Autor* autorPtr = buscarOuCriarAutor(nomeAutor);
        livros.emplace_back(id, titulo, autorPtr);
        if (id > maiorId) maiorId = id;
    }
    proximoIdLivro = maiorId + 1;
    arquivo.close();
}