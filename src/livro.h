#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include "autor.h"

class Livro {
private:
    int id;
    std::string titulo;
    Autor* autor;
    bool disponivel;
    std::string dataEmprestimo;

public:
    Livro(int id, std::string titulo, Autor* autorPtr);
    
    // Getters para acessar as informações
    int getId() const;
    std::string getTitulo() const;
    Autor* getAutor() const;

    // Exibe os dados formatados no console
    void exibirLinha() const;
    void setTitulo(std::string novoTitulo);
    void setAutor(Autor* novoAutor);

    bool isDisponivel() const;
    std::string getDataEmprestimo() const;

    void emprestar(std::string data);
    void devolver();
};

#endif