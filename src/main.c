/*!
 *	Experimento 1 EA869 - Contador de Palavras
 *	Autor: Guilherme Pupio, Ra168958
 */


#include <stdio.h>

int ehPalavra (char *text);
int ehNumero (char *text);
int ehPonto_flutuante (char *text);
int i;

int main (void) {
	
	char text[10000]; // arrumar um jeito pra deixar isso mais bonito
	int num_words = 0; 


	scanf("%[^\n]s", text);	// readind the text

	i = 0;
	while (text[i]!= '\0'){
		if(ehPalavra(text) || ehNumero(text)) { // se temos um numero ou letra, certamente teremos uma palavra. Logo Oi123 eh uma palavra, por exemplo..
			num_words++;
			while (ehPonto_flutuante(text) || ehPalavra(text) || ehNumero(text))
				i++;
		} else 
			i++;
	}

	printf("%d\n", num_words);
	return 0;
}

/*!
 * 	Verifica se o caractere em questao eh uma palavra
 */

int ehPalavra (char *text){
	if (((text[i]>'A'-1) && (text[i]<'Z'+1)) || ((text[i]>'a'-1) && (text[i]<'z'+1))){
		return 1;
	}
	else return 0;

}

/*!
 * 	Verifica se o caractere em questao eh um numero
 */

int ehNumero (char *text){
	if (((text[i]>'0'-1) && (text[i]<'9'+1))){
		return 1;
	}
	else return 0;

}

/*!
 * 	Verifica se o caractere em questao eh um numero ponto flutuante
 */

int ehPonto_flutuante(char *text){
	if (ehNumero(text) && (((text[i+1]=='.') || (text[i+1]==','))) && (((text[i+2]>'0'-1) && (text[i+2]<'9'+1)))){
		i++;
		return 1;
	}
	else return 0;
}

