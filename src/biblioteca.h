#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "livro.h"
#include <fstream>

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
    void editarLivro(int id);
    void salvarParaArquivo(const std::string& nomeArquivo) const;
    void carregarDeArquivo(const std::string& nomeArquivo);
};

#endif