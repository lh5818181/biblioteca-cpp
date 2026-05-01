# 📚 Sistema de Biblioteca em C++

Projeto prático desenvolvido para consolidar conhecimentos em C++ e Programação Orientada a Objetos (POO). O sistema consiste em um CRUD (Create, Read, Update, Delete) de livros operando via console.

## 🚀 Status do Projeto: Semana 2 (Em progresso)

O projeto avançou para a fase de **Manipulação de Dados**. A lógica de CRUD (Create, Read, Update, Delete) em memória foi totalmente implementada, permitindo a gestão completa do acervo durante a execução.

## 🛠️ Funcionalidades Atuais

- [x] Cadastro de novos livros (ID automático).
- [x] Listagem formatada em tabela com **truncamento inteligente** para nomes longos.
- [x] Edição completa (Update) de registros.
- [x] Remoção (Delete) por ID.
- [x] **Persistência de Dados:** Salvamento e carregamento automático via arquivos CSV.
- [x] Gerenciamento através de classe controladora (`Biblioteca`).

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
2. **Semana 2:** CRUD Completo e Persistência (CSV) *(Concluído)*
3. **Semana 3:** Relacionamentos e Buscas *(Concluído)*
4. **Semana 4:** Lógica de Empréstimos e Relatórios
5. **Semana 5:** Refatoração e Testes
6. **Semana 6:** Documentação Final e Publicação

---

Desenvolvido por Luís Henrique 🚀