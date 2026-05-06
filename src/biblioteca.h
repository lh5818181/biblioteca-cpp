#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include "livro.h"
#include "autor.h"

class Biblioteca {
private:
    std::vector<Livro> livros;
    std::vector<Autor> autores;
    int proximoIdLivro;
    int proximoIdAutor;

    // Método auxiliar para gerenciar os ponteiros de autores
    Autor* buscarOuCriarAutor(std::string nome);

public:
    Biblioteca();

    void adicionarLivro(std::string titulo, std::string nomeAutor);
    void listarLivros() const;
    void removerLivro(int id);
    void editarLivro(int id);
    
    void buscarPorTitulo(std::string termo) const;
    void buscarPorAutor(std::string nomeAutor) const;

    // Padronizando os nomes das funções de arquivo
    void salvarParaArquivo(const std::string& nomeArquivo) const;
    void carregarDeArquivo(const std::string& nomeArquivo);
};

#endif