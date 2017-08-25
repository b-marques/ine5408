#include <stdio.h>


typedef struct registro_st {
	char nome[50];
	char endereco[100];
} registro;

void salvar_no_disco(registro r[], int len) {
	FILE* f = fopen("banco.txt", "w");

	int i;
	for (i = 0; i < len; i++) {
		fwrite(&r[i], 150, 1, f);
	}

	fclose(f);
}

int n_registros() {
	FILE* f = fopen("banco.txt", "r");

	fseek(f, 0, SEEK_END);
	long i = ftell(f);
	fclose(f);	

	return i/150;
}

void ler_registro(int indice) {
	// TODO Verificar se indice é válido
	FILE* f = fopen("banco.txt", "r");
	fseek(f, 150*indice, SEEK_SET);
	registro r;
	fread(&r, 150, 1, f);
	fclose(f);

	printf("Nome %s\t\tEnd: %s\n", r.nome, r.endereco);
}

int main () {
	// TODO Ler entrada a partir do usuário
	registro r[10] = {{"Joao", "End tal"}, {"a", "l"}, {"Shrek", "Amazonia"}}; 	
	salvar_no_disco(r, 3);

	printf("Temos %d registros\n", n_registros());

	ler_registro(2);
}
