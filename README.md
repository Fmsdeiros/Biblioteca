Implementção:

Arquivos pertenecntes a implementação do programa:

01. src/main.cpp : Contém o código da função main.
02. src/menu.cpp : Código responsavel por imprimir o menu de opções ao usuário
03. src/usuario.cpp : Código da classe usuário e das funções cadastraUsuario e carregaUsuario
04. src/livro.cpp : Código da classe livro e da função livro criaLivro();
05. src/lista.cpp : Código da classe lista e da função carregaLista_Livro
06. src/listaEmprestimo.cpp : Código da classe listaEmp e da função carregaLista_Emprestimo
07. src/emprestimo.cpp : Código da classe Emprestimo e da função criaEmprestimo
08. src/data.cpp : Código da classe Data
09. include/menu.h : Contém as assinaturas das funções do arquivo menu.cpp.
10. include/usuario.h : Contém as assinaturas das funções do arquivo usuario.cpp.
11. include/livro.h : Contém as assinaturas das funções do arquivo livro.cpp.
12. include/lista.h : Contém as assinaturas das funções do arquivo lista.cpp.
13. include/listaEmprestimo.h : Contém as assinaturas das funções do arquivo listaEmprestimo.cpp.
14. include/emprestimo.h : Contém as assinaturas das funções do arquivo emprestimo.cpp.
15. include/data.h : Contém as assinaturas das funções do arquivo data.cpp.
16. bin/exe : executavel do código.
17. bin/emprestimos.txt : Arquivo que contém todos os emprestimos cadastrados.
18. bin/livros.txt : Arquivo que contém todos os livros cadastrados.
19. bin/emprestimosNum.txt : Arquivo usado para armazenar a quantidade de emprestimos salvos.
19. bin/livrosNum.txt : Arquivo usado para armazenar a quantidade de livros salvos.
20. makefile : Arquivo usado para compilar todo o código.
21. Doxygen : Arquivo de configuração para gerar a documentação do código com o doxygen.

Como compilar e executar:

Para compilar o código é indicado o compilador g++ pois esse foi o programa utilizado na compilação do codigo. para compilar basta usar o seguinte comando no terminal:

	g++ -std=c++11 -Wall -w -pedantic -O0 src/*.cpp -o bin/exe

Também pode ses utilizar o makefile, basta digitar o seguinte comando:

	make exe

Os arquivos sitados nos pontos 17,18,19 e 20 são deletados pelo sistema quando necessario. Isso faz parte do funcionamento do código.
