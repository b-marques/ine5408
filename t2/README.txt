Copyright Bruno Marques Do Nascimento e Salom�o Rodrigues Jacinto

Os arquivos abaixo:
	-FileNoAVL.hpp
	-lexicalIgnored.txt
	-main.cpp

Devem estar localizados todos no mesmo diret�rio. Al�m disso, os arquivos com extens�o "txt" que possuem os conte�dos das manpages, devem estar dentro de um diret�rio nomeado "ManPages" junto com os arquivos acima.

Exemplo de retorno do comando "ls" na pasta com os arquivos:

FileNoAVL.hpp lexicalIgnored.txt main.cpp ManPages


LINHA DE COMANDO PARA COMPILA��O:

g++ -o main  *.cpp -g -lm -lutil -std=c++11 -Wall -Werror

LINHA DE COMANDO PARA EXECU��O:

./main ManPages/*.txt