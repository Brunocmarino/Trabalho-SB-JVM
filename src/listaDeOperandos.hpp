/*
Universidade de Brasília (UNB) - Software Básico
Grupo:
Bruno Couto Marino 190011106​
Carlos Eduardo Taborda Lottermann 180041509
Gabriel Henrique Souza de Melo 180136577​
Igor Laranja Borges Taquary 180122231​
Matheus Araujo Ferreira 180024892​
Bruno Murta Oliveira de Castro 160069742
*/
#ifndef LISTA_DE_OPERANDOS_H
#define LISTA_DE_OPERANDOS_H

#include <stdio.h>
#include <stdint.h>

// Tipos de unsigned int utilizados 
#ifndef TIPOS_U
#define TIPOS_U
typedef uint8_t u1;	// unsigned int de 8 bits
typedef uint16_t u2;	// unsigned int de 16 bits
typedef uint32_t u4;	//unsigned int de 32 bits
typedef uint64_t u8;	// unsigned int de 64 bits
#endif

// Tipos de signed int utilizados
#ifndef TIPOS_I
#define TIPOS_I
typedef int8_t i1;   	// int de 8 bits
typedef int16_t i2; 	// int de 16 bits
typedef int32_t i4;  	// int de 32 bits
typedef int64_t i8;  	// int de 64 bits
#endif

//Referência utilizada para a construção das estruturas de dados:
// https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-2.html#jvms-2.6.2
 
struct lista_operandos{
	void *referencia;    				// Se operando for uma referência, é armazenado nesta variável 
	struct lista_operandos *prox;  		// Ponteiro para o próximo nó da lista
	struct lista_operandos *ant; 		// Ponteiro para o nó anterior da lista 
	i4 operando;               			// Se operando for um valor, é armazenado nesta variável 
	u1 tipo_operando; 					// Tipo do operando armazenado na estrutura. A lista de opções está definida na enumeração \c tipos_operandos
};

typedef struct lista_operandos lista_operandos;


// Tipos de Operandos suportados pela lista de operandos.
// É utilizado nas operações de armazenamento e acesso
// na lista de operandos, no momento de alocação de memória e
// impressões/acessos à posições específicas.
 
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

typedef enum tipos_operandos tipos_operandos;

//Cria uma lista de operandos sem valor e retorna o ponteiro para ela.
lista_operandos* CriarLista_operandos();


/*
 * Insere um operando (valor ou referencia) no início da lista de operandos.
 * Depois que o tipo de operando é checado, é alocado um espaço na memória correspondente, atribuindo ao operando enviado.
 * lis = Ponteiro para a lista de operandos
 * operando = Operando de valor direto a ser inserido na lista
 * referencia = Ponteiro para o operando de referência a ser inserido na lista
 * tipo_operando = Definição do tipo de operando a ser inserido
 */
lista_operandos* InserirInicio_operandos(lista_operandos *lis, i4 operando, void *referencia, u1 tipo_operando);

/**
 * @brief Insere um operando (valor ou referencia) no final da lista de operandos.
 * @details O tipo do operando é checado para que seja feita a inserção correta, e então
 * é alocado um espaço na memória correspondente, atribuindo ao operando enviado.
 * Apenas um tipo de operando deve ser enviado nesta função.
 *
 * @param lis Ponteiro para a lista de operandos
 * @param operando Operando de valor direto a ser inserido na lista
 * @param referencia Operando de referência a ser inserido na lista
 * @param tipo_operando Definição do tipo de operando a ser inserido
 * @return Ponteiro para a lista de operandos após a inserção do novo operando
 */
lista_operandos* InserirFim_operandos(lista_operandos *lis, i4 operando, void *referencia, u1 tipo_operando);
/**
 * @brief Remove o operando (valor ou referencia) que está no início da lista de operandos.
 * @details O primeiro operando da lista tem sua memória liberada, não fazendo a diferença
 * nesse momento o tipo de operando armazenado pois toda a estrutura é liberada.
 *
 * @param lis Ponteiro para a lista de operandos
 * @return Lista de operandos com o primeiro elemento removido
 */
lista_operandos* RemoverInicio_operandos(lista_operandos *lis);
/**
 * @brief Remove o operando (valor ou referencia) que está no final da lista de operandos.
 * @details O último operando da lista tem sua memória liberada, não fazendo a diferença
 * nesse momento o tipo de operando armazenado pois toda a estrutura é liberada.
 *
 * @param lis Ponteiro para a lista de operandos
 * @return Lista de operandos com o último elemento removido
 */
lista_operandos* RemoverFim_operandos(lista_operandos *lis);
/**
 * @brief Imprime na tela uma representação textual da lista de operandos.
 * @param lis Ponteiro para a lista de operandos a ser impressa
 */
void ImprimirLista_operandos(lista_operandos *lis);
/**
 * @brief Libera a memória utilizada por toda a lista de operandos passada por argumento.
 * @details A lista é iterada e cada elemento é liberado da memória com o comando \c free(p)
 *
 * @param lis Ponteiro para a lista de operandos a ser liberada
 */
void LiberarLista_operandos(lista_operandos *lis);



/** Não utilizadas */

lista_operandos* RemoverElemento_operandos(lista_operandos *lis,i4 operando, u1 tipo_operando);

lista_operandos* BuscarElemento_operandos(lista_operandos *lis, i4 operando, u1 tipo_operando);

lista_operandos* BuscarPosicao_operandos(lista_operandos *lis, int posicao);

lista_operandos* InserirPosicao_operandos(lista_operandos *lis, i4 operando, u1 tipo_operando, int posicao);

lista_operandos* RemoverPosicao_operandos(lista_operandos *lis, int posicao);

#endif
