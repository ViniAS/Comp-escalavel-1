# Computação Escalavel, Primeira Entrega
 
## Como compilar e executar

Primeiro é preciso que você tenha instalado o [CMake](https://cmake.org/) (versão mínima 3.11) em seu sistema.

É recomendável criar uma nova pasta para a compilação do projeto, para isso, execute o seguinte comando:

```bash
mkdir build
cd build
```

Agora, dentro da pasta build, execute o seguinte comando para gerar os arquivos de compilação:

```bash
cmake ..
```

Por fim, execute o seguinte comando para compilar o projeto:

```bash
make
```

Se a compilação for bem sucedida, um executável será criado. Para  rodar o arquivo, basta usar o comando:

```bash
./A2PAA
```

Um arquivo chamado "results.csv" vai ser criado no repositório principal com o resultados do programa.
