#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "livro.h"

class Biblioteca {
private:
    std::vector<Livro> livros;
    int proximoId;

public:
    Biblioteca();
    
    
    // Métodos da Semana 1
    void adicionarLivro(std::string titulo, std::string autor);
    void listarLivros() const;
    void removerLivro(int id);
};

#endif