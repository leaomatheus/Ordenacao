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

int vet[MAXN];
int aux[MAXN];

//Funcao que divide o vetor em duas partes
//Assume que a primeira parte estah ordenada
//E que a segunda parte estah ordenada
//Mistura as duas e forma uma soh ordenada
void Merge(int * vet, int left, int right) {
	int aux_count = 0;
	//A posicao do meio no vetor
	int mid = (left+right)/2;

	//P1 e P2 sao os ponteiros que vao percorrer o vetor
	//P1 percorre a primeira metade (de left ate mid)
	//P2 percorre a segunda metade (de mid+1 ate right)
	int p1, p2;
	p1 = left;
	p2 = mid+1;

	//Enquanto nao percorreu nenhuma das metades inteira
	while(p1 <= mid && p2 <= right) {
		if(vet[p1] <= vet[p2])
			aux[aux_count++] = vet[p1++]; //Se o da primeira metade eh menor
		
		else
			aux[aux_count++] = vet[p2++]; //Se o da segunda metade eh menor
	}
	//Ja percorreu uma metade inteira, agora soh colocar os elementos da outra metade
	//Os elementos da outra metade jah estao ordenados entre si

	while(p1 <= mid)
		aux[aux_count++] = vet[p1++];

	while(p2 <= right)
		aux[aux_count++] = vet[p2++];
	
	//Copia os dados do vetor auxiliar pro vetor original
	for(int i = 0; i < aux_count; i++) {
		vet[left++] = aux[i];
	}
	return;
}
void MergeSort(int * vet, int left, int right, int nivel) {
	//Se left == right (so tem 1 elemento) ou left > right (deu merda), encerra
	if(left >= right) return;

	//Divide o vetor em dois
	int mid = (left+right)/2;
	
	//Ordena a primeira metade
	MergeSort(vet, left, mid, nivel+1);
	//Ordena a segunda metade
	MergeSort(vet, mid+1, right, nivel+1);
	//Junta as duas metades
	Merge(vet, left, right);

	return;
}

int main() {
	int tam;
	scanf("%d", &tam);
	for(int i = 0; i < tam; i++) {
		scanf("%d", &vet[i]);
	}
	MergeSort(vet, 0, tam-1, 0);

	for(int i = 0; i < tam; i++) {
		printf("%d", vet[i]);
	}
}