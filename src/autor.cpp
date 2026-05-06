#include "autor.h"

Autor::Autor(int id, std::string nome, std::string nacionalidade) 
    : id(id), nome(nome), nacionalidade(nacionalidade) {}

int Autor::getId() const { return id; }
std::string Autor::getNome() const { return nome; }
std::string Autor::getNacionalidade() const { return nacionalidade; }

void Autor::setNome(std::string novoNome) { nome = novoNome; }
void Autor::setNacionalidade(std::string novaNacionalidade) { nacionalidade = novaNacionalidade; }