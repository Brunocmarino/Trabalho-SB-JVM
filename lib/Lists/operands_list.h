/*
Universidade de Brasília - Software Básico
Grupo:
	Bruno Couto Marino 190011106
  Carlos Eduardo Taborda Lottermann 180041509
  Gabriel Henrique Souza de Melo 180136577
  Igor Laranja Borges Taquary 180122231
  Matheus Araujo Ferreira 180024892
  Bruno Murta Oliveira de Castro 160069742
*/

#ifndef OPERANDS_LIST_H
#define OPERANDS_LIST_H

#include <stdio.h>
#include <stdint.h>

// Definição dos tipos de inteiro sem sinal utilizados 
#ifndef TIPOS_U
#define TIPOS_U
typedef uint8_t u1;   
typedef uint16_t u2;  
typedef uint32_t u4;  
typedef uint64_t u8;  
#endif

// Definição dos tipos de inteiro com sinal utilizados 
#ifndef TIPOS_I
#define TIPOS_I
typedef int8_t i1;   
typedef int16_t i2;  
typedef int32_t i4; 
typedef int64_t i8;  
#endif


struct lista_operandos{
	i4 operando;                  	  // Se o operando for um valor, é armazenado nesta variável 
	void *referencia;    		          // Se o operando for uma referência, é armazenado nesta variável 
	u1 tipo_operando; 				        // Tipo do operando armazenado na estrutura
	struct lista_operandos *prox;  	  // Ponteiro de acesso ao próximo nó da lista
	struct lista_operandos *ant; 	    // Ponteiro de acesso ao nó anterior da lista 
};

// Definição do tipo lista de operandos
typedef struct lista_operandos lista_operandos;

enum tipos_operandos{
	BOOLEAN_OP = 1,
	BYTE_OP,
	CHAR_OP,
	SHORT_OP,
	INTEGER_OP,
	FLOAT_OP,
	LONG_OP,
	DOUBLE_OP,
	RETURN_ADDRESS_OP,
	REFERENCE_OP,
	REFERENCE_ARRAY_BOOLEAN_OP,
	REFERENCE_ARRAY_CHAR_OP,
	REFERENCE_ARRAY_FLOAT_OP,
	REFERENCE_ARRAY_DOUBLE_OP,
	REFERENCE_ARRAY_BYTE_OP,
	REFERENCE_ARRAY_SHORT_OP,
	REFERENCE_ARRAY_INT_OP,
	REFERENCE_ARRAY_LONG_OP,
	REFERENCE_STRING_OP,
};

// Definição do tipo tipos_operandos

typedef enum tipos_operandos tipos_operandos;

lista_operandos* CriarLista_operandos();

lista_operandos* InserirInicio_operandos(lista_operandos *lis, i4 operando, void *referencia, u1 tipo_operando);

lista_operandos* InserirFim_operandos(lista_operandos *lis, i4 operando, void *referencia, u1 tipo_operando);

lista_operandos* RemoverInicio_operandos(lista_operandos *lis);

lista_operandos* RemoverFim_operandos(lista_operandos *lis);

void ImprimirLista_operandos(lista_operandos *lis);

void LiberarLista_operandos(lista_operandos *lis);



// Não utilizadas

lista_operandos* RemoverElemento_operandos(lista_operandos *lis,i4 operando, u1 tipo_operando);

lista_operandos* BuscarElemento_operandos(lista_operandos *lis, i4 operando, u1 tipo_operando);

lista_operandos* BuscarPosicao_operandos(lista_operandos *lis, int posicao);

lista_operandos* InserirPosicao_operandos(lista_operandos *lis, i4 operando, u1 tipo_operando, int posicao);

lista_operandos* RemoverPosicao_operandos(lista_operandos *lis, int posicao);

#endif
