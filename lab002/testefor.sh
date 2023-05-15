#!/bin/sh

#echo nome do programa:
#read nomeProg
#echo nome do arquivo de teste:
#read arqTeste
#echo numero de testes:
#read numTestes

for((i=1;i<($1 + 1 );i=i+1))
do ./a.out < ins/$i.in > ins/saida$i.out;
	diff -b ins/$i.out ins/saida$i.out;
done
