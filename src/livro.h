#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro {
private:
    int id;
    std::string titulo;
    std::string autor;

public:
    Livro(int id, std::string titulo, std::string autor);
    
    // Getters para acessar as informações
    int getId() const;
    std::string getTitulo() const;
    std::string getAutor() const;

    // Exibe os dados formatados no console
    void exibirLinha() const;
};

#endif