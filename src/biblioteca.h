#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include <list> // Inclusão estratégica para corrigir o bug de memória
#include "livro.h"
#include "autor.h"

class Biblioteca {
private:
    std::vector<Livro> livros;
    std::list<Autor> autores; // Alterado de std::vector para std::list para estabilizar ponteiros
    int proximoIdLivro;
    int proximoIdAutor;

    // Método auxiliar atualizado para aceitar nacionalidade
    Autor* buscarOuCriarAutor(std::string nome, std::string nacionalidade = "Desconhecida");

public:
    Biblioteca();

    void adicionarLivro(std::string titulo, std::string nomeAutor, std::string nacionalidadeAutor);
    void listarLivros() const;
    void removerLivro(int id);
    void editarLivro(int id);

    void buscarPorTitulo(std::string termo) const;
    void buscarPorAutor(std::string nomeAutor) const;

    // Gerenciamento relacional de persistência
    void salvarParaArquivo(const std::string& nomeArquivoLivros) const;
    void carregarDeArquivo(const std::string& nomeArquivoLivros);

    void emprestarLivro(int id);
    void devolverLivro(int id);
};

#endif