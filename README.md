# 📚 Sistema de Biblioteca em C++

Projeto prático desenvolvido para consolidar conhecimentos avançados em C++ e Programação Orientada a Objetos (POO), explorando relacionamentos complexos de memória e integridade de dados.

## 🚀 Status do Projeto: Semana 4 (Em progresso)

O projeto avançou significativamente, superando a barreira de um CRUD simples. O sistema agora opera com uma **Arquitetura Relacional Dinâmica** e um sistema completo de **Controle de Estados** para circulação de livros.

## 🛠️ Funcionalidades Atuais

- **Gerenciamento Relacional de Objetos:** Separação entre as entidades `Livro` e `Autor`. O sistema utiliza associações por ponteiros (`Autor*`) para vincular múltiplos livros ao mesmo autor na memória sem redundância de dados.
- **Persistência Relacional Dupla:** Os dados são normalizados e salvos de forma independente na pasta `data/` em arquivos CSV separados (`livros.csv` e `autores.csv`), interligados através de chaves (IDs).
- **Mecanismo de Empréstimos e Devoluções:** Fluxo completo de alteração de estado das obras em tempo real, contendo travas de segurança defensivas (evita empréstimos de livros indisponíveis ou devoluções incoerentes).
- **Filtros de Busca Avançada:** Algoritmos de busca parcial por substrings, permitindo localizar registros por trechos de títulos ou nomes de autores.
- **Interface UI/UX Otimizada:** Exibição de dados formatada em tabelas com espaçamento fixo, monitoramento de status e **truncamento inteligente** de strings para manter o layout estável no terminal.
- **Robustez de Código:** Implementação de tratamento de exceções (`try-catch`) nas rotinas de parsing de arquivos para blindar a aplicação contra falhas ou arquivos corrompidos.

## 📁 Estrutura de Pastas

- `src/`: Código-fonte (`.cpp` e `.h`) contendo a separação modular das classes.
- `data/`: Banco de dados relacional simulado em arquivos CSV.
- `docs/`: Roadmaps e documentação de planejamento.

## 💻 Como Compilar e Executar

Certifique-se de ter um compilador C++ configurado (como o GCC/MinGW).

1. Clone o repositório:

```bash
git clone https://github.com/lh5818181/biblioteca-cpp.git
```

2. Acesse a pasta do projeto:

```bash
cd biblioteca-cpp
```

3. Compile todas as classes unificadas:

```bash
g++ src/main.cpp src/livro.cpp src/biblioteca.cpp src/autor.cpp -o sistema.exe
```

4. Execute o sistema:

```bash
./sistema.exe
```

## 📅 Roadmap de Aprendizado

Este projeto é desenvolvido seguindo um cronograma focado em evolução contínua:

1. **Semana 1:** Setup e Classes Base ✅
2. **Semana 2:** CRUD Completo e Persistência Inicial ✅
3. **Semana 3:** Relacionamentos (Ponteiros) e Buscas Parciais ✅
4. **Semana 4:** Lógica de Empréstimos, Relatórios e Estados 🔄
5. **Semana 5:** Refatoração, Tratamento de Erros e Comentários Técnicos
6. **Semana 6:** Documentação Final e Apresentação do Portfólio

---

Desenvolvido por **Luís Henrique** 🚀