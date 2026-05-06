#ifndef AUTOR_H
#define AUTOR_H

#include <string>
#include <iostream>

class Autor {
private:
    int id;
    std::string nome;
    std::string nacionalidade;

public:
    Autor(int id, std::string nome, std::string nacionalidade);

    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getNacionalidade() const;

    // Setters
    void setNome(std::string novoNome);
    void setNacionalidade(std::string novaNacionalidade);
};

#endif