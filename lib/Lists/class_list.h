/*
Universidade de Brasília - 2/2021
Software Básico - Turma A
JVM

Alunos:
				
*/

/*
 * Arquivo: lista_classes.h
 * Desc: Arquivo cabecalho que contem a estrutura para armazenar a lista de classes carregadas
 *       e assinatura das funcoes em lista_classes.c
 */

#ifndef LISTA_CLASSES_H
#define LISTA_CLASSES_H

#include <stdio.h>
#include "classfile.h"

/* Estrutura de dados da lista de classes carregadas no programa.
   Ver: classFileStruct.h
 */
struct classesCarregadas
{
	Classfile *arquivoClass; 			   /* Ponteiro para estrutura do tipo Classfile */
	struct classesCarregadas *proximo;	 /* Ponteiro de acesso ao próximo nó da lista */
	struct classesCarregadas *anterior;	 /* Ponteiro de acesso ao nó anterior da lista*/
};
typedef struct classesCarregadas classesCarregadas;

/* Função para criar uma lista nula */
classesCarregadas* criarLista();

/*
 * Função para inserir um elemento no fim da lista.
 *
 * P-1:  Ponteiro apontando para o início da lista de classes carregadas.
 * P-2:  Ponteiro para o classfile que deve ser inserido na lista.
 *
 * A função retorna o ponteiro para o início da lista, com a lista atualizada.
 *
 */
classesCarregadas* inserirFim(classesCarregadas *, Classfile *);

/**
 * Função para remover um elemento do fim da lista
 *
 * p1: Ponteiro apontando para o início da lista
 * A função retorna o ponteiro para o início da lista, com a lista atualizada
 */
classesCarregadas* removerFim(classesCarregadas *);

/**
 * Função para remover um elemento da lista
 *
 * p1: Ponteiro apontando para o início da lista
 * p2: Nome da classe que será buscado, e então a classe será removida da lista
 * A função retorna o ponteiro para o início da lista, com a lista atualizada
 */
classesCarregadas* remover(classesCarregadas *, char *);

/**
 * Funçao para buscar um elemento na lista
 *
 * p1: Ponteiro apontando para o início da lista
 * p2: Nome da classe que será buscada na lista
 *
 * A função retorna o ponteiro para o elemento encontrado, ou um ponteiro nulo, caso o elemento não seja encontrado
 */
classesCarregadas* buscar(classesCarregadas *, char *);

/**
 * Função que retorna a pool de constantes da classe corrente, passada como parâmetro
 *
 * p1: Ponteiro apontando para o início da lista
 * p2: Nome da classe cuja constant pool deve ser retornada
 *
 * Retorna um ponteiro do tipo cp_info que é a constant pool da classe passada como parâmetro
 */
Cp_info* buscarCPClasseCorrente(classesCarregadas *, char *);

/**
 * Função para buscar um método da classe corrente, passada como parâmetro
 *
 * p1: Ponteiro apontando para o início da lista
 * p2: Nome da classe que contém o método que será buscado
 * p3: Nome do método que deve ser buscado na classe corrente
 * Retorna estrutura method_info do método buscado
 */
Method_info* buscarMethodClasseCorrente(classesCarregadas *, char *, char *);

/**
 * Função para imprimir os elementos da lista de classes
 *
 * p1: Ponteiro apontando para o início da lista
 */
void imprimirLista(classesCarregadas *);

/**
 * Função para liberar uma lista da memória
 *
 * p1: Ponteiro apontando para o início da lista
 */
void liberarLista(classesCarregadas *);
/**
 * Função para buscar um field da classe passada como parâmetro
 *
 * p1: Ponteiro apontando para o início da lista
 * p2: nomeClasse Nome da classe que deve ter o field buscado
 * p3: nomeField Nome do field que deve ser buscado na classe
 * Retrona estrutura do field que foi buscado na classe
 */
Field_info* buscarFieldClasseCorrente(classesCarregadas *, char *, char *);

#endif