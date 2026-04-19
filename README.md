# 📚 Sistema de Biblioteca em C++

Projeto prático desenvolvido para consolidar conhecimentos em C++ e Programação Orientada a Objetos (POO). O sistema consiste em um CRUD (Create, Read, Update, Delete) de livros operando via console.

## 🚀 Status do Projeto: Semana 1 (Em Desenvolvimento)

Atualmente o projeto está na fase de **Estrutura Base e Arquitetura**, com as funcionalidades de cadastro e listagem em memória já implementadas.

## 🛠️ Funcionalidades Atuais

- [x] Cadastro de novos livros (ID automático, Título e Autor).
- [x] Listagem formatada em tabela no console.
- [x] Gerenciamento através de classe controladora (`Biblioteca`).
- [ ] Persistência de dados em CSV (Semana 2).
- [ ] Busca e filtros avançados (Semana 3).

## 📁 Estrutura de Pastas

- `src/`: Código-fonte (`.cpp` e `.h`).
- `data/`: Local reservado para o banco de dados em CSV.
- `docs/`: Documentação e roadmaps do projeto.

## 💻 Como Executar

Certifique-se de ter um compilador C++ instalado (como o GCC).

1. Clone o repositório:
   ```bash
   git clone https://github.com/lh5818181/biblioteca-cpp.git
   ```

2. Acesse a pasta do projeto:
   ```bash
   cd biblioteca-cpp
   ```

3. Compile o projeto:
   ```bash
   g++ src/main.cpp src/livro.cpp src/biblioteca.cpp -o sistema.exe
   ```

4. Execute:
   ```bash
   ./sistema.exe
   ```

## 📅 Roadmap de Aprendizado

Este projeto segue um cronograma de 6 semanas:

1. **Semana 1:** Setup e Classes Base *(Concluído)*
2. **Semana 2:** CRUD Completo e Persistência (CSV)
3. **Semana 3:** Relacionamentos e Buscas
4. **Semana 4:** Lógica de Empréstimos e Relatórios
5. **Semana 5:** Refatoração e Testes
6. **Semana 6:** Documentação Final e Publicação

---

Desenvolvido por Luís Henrique 🚀