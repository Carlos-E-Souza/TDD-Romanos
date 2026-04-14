# TDD-Romanos
Repositorio para a materia de tecnicas de programação 2 do CIC-UNB

## Pré-requisitos

Para garantir que seja possível compilar o projeto e rodar todas as análises de qualidade de código (linter, check, vazamento de memória e cobertura), instale os pacotes e dependências abaixo (exemplo para o ambiente Linux/Ubuntu/Debian):

```bash
# Atualizar listas de dependências do SO
sudo apt update

# Instalar o compilador C++ (g++), a automação Make e o Debugger (gdb)
sudo apt install build-essential gdb

# Instalar o CppCheck para checagens de análise estática
sudo apt install cppcheck

# Instalar o Valgrind para checagens dinâmicas e de vazamento de memória
sudo apt install valgrind

# Instalar o CppLint (Verificador de padronização de código do Google) dependente de Python:
sudo apt install python3-pip pipx
pipx install cpplint
```

## Explorando o projeto (Comandos Makefile)

O projeto possui dezenas de magias internas automatizadas via `Makefile`. Para rodá-las, basta executar `make <comando>` neste diretório:

* **`make`** ou **`make all`**: Compila todo o código-fonte gerando os binários básicos e já executa a bateria de testes (`./testa_romanos`);
* **`make compile`**: Realiza apenas a compilação cruzada do `romanos.o` e do `testa_romanos` sem executá-lo no final;
* **`make test`**: Uma regra de atalho que unicamente invoca o executável de testes via comando `./testa_romanos`;
* **`make cpplint`**: Invoca o linter em Python `cpplint` para analisar se estão sendo cumpridas as diretrizes do "Google C++ Style Guide", ignorando frameworks de arquivos externos e validando espaçamento, metadados e design syntax em nossos arquivos fonte;
* **`make gcov`**: Compila com flags ativas de instrumentação de cobertura (`-fprofile-arcs -ftest-coverage`), roda os testes e após finalizar gera um relatório (.gcov) emitindo a porcentagem das linhas lógicas do `romanos.cpp` que os testes atingiram e englobaram (Test Coverage);
* **`make debug`**: Constrói o sistema utilizando sinais ou bibliotecas nativas de debugeamento por trás dos panos (`-g`) e roda a verificação paralela dentro do interativo GNU Debugger (`gdb`);
* **`make cppcheck`**: Roda uma análise estática restrita em nosso código local (`romanos.cpp` e `testa_romanos.cpp`) procurando construtores e variáveis esquecidas, semânticas sujas ou potenciais Null Pointers, ignorando estritamente problemas que sejam de bibliotecas ou frameworks alheios (`catch.hpp`);
* **`make valgrind`**: Executa nossos testes dentro da barreira dinâmica do "Valgrind", uma ferramenta de profiling poderosa que analisará e relatará detalhadamente vazamentos de memória (Memory leaks) e seg-faults dentro de um arquivo gerado em ambiente com o nome de `valgrind.rpt`;
* **`make clean`**: Regra essencial de limpeza de "cache" do repositório, efetuando o expurgo e formatação por exclusão (rm -rf) de todos os arquivos objeto (`*.o`), lixos de cobertura do gcov (`*.gcda`, `*.gcno`) e executáveis residuais criados ao longo dos workflows acima;


OBS: Utilize o `make clean` antes do `make`,`make all` ou `make compile`.