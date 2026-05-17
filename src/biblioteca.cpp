#include "biblioteca.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

Biblioteca::Biblioteca() : proximoIdLivro(1), proximoIdAutor(1) {}

Autor* Biblioteca::buscarOuCriarAutor(std::string nome, std::string nacionalidade) {
    for (auto& autor : autores) {
        if (autor.getNome() == nome) {
            if (autor.getNacionalidade() == "Desconhecida" && nacionalidade != "Desconhecida") {
                autor.setNacionalidade(nacionalidade);
            }
            return &autor;
        }
    }
    autores.emplace_back(proximoIdAutor++, nome, nacionalidade);
    return &autores.back();
}

void Biblioteca::adicionarLivro(std::string titulo, std::string nomeAutor, std::string nacionalidadeAutor) {
    Autor* autorPtr = buscarOuCriarAutor(nomeAutor, nacionalidadeAutor);
    livros.emplace_back(proximoIdLivro++, titulo, autorPtr);
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
              << std::setw(20) << "AUTOR"
              << std::setw(12) << "STATUS" << std::endl;
    std::cout << std::string(55, '-') << std::endl;

    for (const auto& livro : livros) {
        livro.exibirLinha();
    }
    std::cout << std::string(55, '-') << std::endl;
}

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

void Biblioteca::editarLivro(int id) {
    for (auto& livro : livros) {
        if (livro.getId() == id) {
            std::string novoTitulo, novoNomeAutor, novaNacionalidade;
            std::cout << "Novo Titulo: ";
            std::getline(std::cin >> std::ws, novoTitulo);
            std::cout << "Novo Autor: ";
            std::getline(std::cin >> std::ws, novoNomeAutor);
            std::cout << "Nacionalidade do Autor: ";
            std::getline(std::cin >> std::ws, novaNacionalidade);

            Autor* novoAutorPtr = buscarOuCriarAutor(novoNomeAutor, novaNacionalidade);
            livro.setTitulo(novoTitulo);
            livro.setAutor(novoAutorPtr);
            std::cout << "\n[OK] Livro atualizado com sucesso!" << std::endl;
            return;
        }
    }
    std::cout << "\n[!] Erro: Livro nao encontrado." << std::endl;
}

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

void Biblioteca::buscarPorAutor(std::string nomeAutor) const {
    bool encontrado = false;
    std::cout << "\n--- OBRAS DE: \"" << nomeAutor << "\" ---" << std::endl;
    for (const auto& livro : livros) {
        if (livro.getAutor() != nullptr && livro.getAutor()->getNome().find(nomeAutor) != std::string::npos) {
            livro.exibirLinha();
            encontrado = true;
        }
    }
    if (!encontrado) std::cout << "[!] Nada encontrado.\n";
}

// PERSISTÊNCIA RELACIONAL DUPLA (Salva tabelas separadas)
void Biblioteca::salvarParaArquivo(const std::string& nomeArquivoLivros) const {
    std::ofstream arquivoLivros(nomeArquivoLivros);
    if (arquivoLivros.is_open()) {
        for (const auto& livro : livros) {
            int idAutor = (livro.getAutor() != nullptr) ? livro.getAutor()->getId() : 0;
            arquivoLivros << livro.getId() << "," << livro.getTitulo() << "," << idAutor << "\n";
        }
        arquivoLivros.close();
    }

    std::ofstream arquivoAutores("data/autores.csv");
    if (arquivoAutores.is_open()) {
        for (const auto& autor : autores) {
            arquivoAutores << autor.getId() << "," << autor.getNome() << "," << autor.getNacionalidade() << "\n";
        }
        arquivoAutores.close();
    }
}

// LEITURA COMBINADA COM TRATAMENTO DE ERROS TRY-CATCH
void Biblioteca::carregarDeArquivo(const std::string& nomeArquivoLivros) {
    livros.clear();
    autores.clear();

    // 1. Carregar Autores
    std::ifstream arquivoAutores("data/autores.csv");
    int maiorIdAutor = 0;
    if (arquivoAutores.is_open()) {
        std::string linha;
        while (std::getline(arquivoAutores, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string idStr, nome, nacionalidade;
            std::getline(ss, idStr, ',');
            std::getline(ss, nome, ',');
            std::getline(ss, nacionalidade, ',');

            try {
                int id = std::stoi(idStr);
                autores.emplace_back(id, nome, nacionalidade);
                if (id > maiorIdAutor) maiorIdAutor = id;
            } catch (...) {
                // Captura erros se o CSV tiver dados corrompidos
            }
        }
        arquivoAutores.close();
    }
    proximoIdAutor = maiorIdAutor + 1;

    // 2. Carregar Livros
    std::ifstream arquivoLivros(nomeArquivoLivros);
    int maiorIdLivro = 0;
    if (arquivoLivros.is_open()) {
        std::string linha;
        while (std::getline(arquivoLivros, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string idStr, titulo, idAutorStr;
            std::getline(ss, idStr, ',');
            std::getline(ss, titulo, ',');
            std::getline(ss, idAutorStr, ',');

            try {
                int id = std::stoi(idStr);
                int idAutor = std::stoi(idAutorStr);

                Autor* autorPtr = nullptr;
                for (auto& autor : autores) {
                    if (autor.getId() == idAutor) {
                        autorPtr = &autor;
                        break;
                    }
                }
                livros.emplace_back(id, titulo, autorPtr);
                if (id > maiorIdLivro) maiorIdLivro = id;
            } catch (...) {
                // Evita crash caso o parsing numérico falhe
            }
        }
        arquivoLivros.close();
    }
    proximoIdLivro = maiorIdLivro + 1;
}

void Biblioteca::emprestarLivro(int id) {
    for (auto& livro : livros) {
        if (livro.getId() == id) {
            if (!livro.isDisponivel()) {
                std::cout << "\n[!] Erro: O livro \"" << livro.getTitulo() << "\" ja esta emprestado.\n";
                return;
            }
            
            std::string data;
            std::cout << "Digite a data de emprestimo (DD/MM/AAAA): ";
            std::getline(std::cin >> std::ws, data);
            
            livro.emprestar(data);
            std::cout << "\n[OK] Livro \"" << livro.getTitulo() << "\" emprestado com sucesso!\n";
            return;
        }
    }
    std::cout << "\n[!] Erro: Livro com ID " << id << " nao encontrado.\n";
}

void Biblioteca::devolverLivro(int id) {
    for (auto& livro : livros) {
        if (livro.getId() == id) {
            if (livro.isDisponivel()) {
                std::cout << "\n[!] Ops: O livro \"" << livro.getTitulo() << "\" ja esta na biblioteca (Disponivel).\n";
                return;
            }
            
            livro.devolver();
            std::cout << "\n[OK] Livro \"" << livro.getTitulo() << "\" devolvido com sucesso!\n";
            return;
        }
    }
    std::cout << "\n[!] Erro: Livro com ID " << id << " nao encontrado.\n";
}