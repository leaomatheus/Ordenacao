#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii, ii>
#define vvi vector<vi>
#define MAXN 100005
#define MAXE 100005

#define FOR(x,n) for(int x = 0; x < n; x++)
#define FOR1e(x,n) for(int x = 1; x <= n; x++)

int vetor[MAXN];

void BubbleSort(int t) {
	int aux;

	for(int i = t; i > 0; i--) {
		for(int j = 1; j < i; j++) {
			//Criterio de comparacao
			if(vetor[j] < vetor[j-1]) {
				//Troca os dois valores de posicao
				aux = vetor[j];
				vetor[j] = vetor[j-1];
				vetor[j-1] = aux;

				//Visualizacao de passos
				for(int k = 0; k < t; k++) {
					if(k == j || k == j-1)
						printf("[--] ");
					else
						printf("[%2d] ", k);
				}
				printf("\n");
				for(int k = 0; k < t; k++) {
					if(k == j || k == j-1) printf("[%2d] ", vetor[k]);
					else printf(" %2d  ", vetor[k]);
				}
				printf("\n\n");
				getchar();
			}
		}
	}
	return;
}
int main() {
	int tamanho;
	scanf("%d", &tamanho);
	for(int i = 0; i < tamanho; i++) {
		scanf("%d", &vetor[i]);
	}

	BubbleSort(tamanho);
}