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

int Merge(int * vet, int left, int right) {
	int aux_count = 0;
	int mid = (left+right)/2;

	int p1, p2, inv;
	p1 = left;
	p2 = mid+1;

	inv = 0;

	while(p1 <= mid && p2 <= right) {
		if(vet[p1] <= vet[p2])
			aux[aux_count++] = vet[p1++];
		
		else {
			//elemento da segunda metade passou da segunda
			//Computa inversao
			aux[aux_count++] = vet[p2++];
			inv += mid-p1+1;
		}
	}
	while(p1 <= mid)
		aux[aux_count++] = vet[p1++];

	while(p2 <= right)
		aux[aux_count++] = vet[p2++];
	
	for(int i = 0; i < aux_count; i++) {
		vet[left++] = aux[i];
	}
	return inv;
}

int MergeSort(int * vet, int left, int right) {
	if(left >= right) return 0;

	int mid = (left+right)/2;
	int inv = 0;
	inv += MergeSort(vet, left, mid);
	inv += MergeSort(vet, mid+1, right);
	inv += Merge(vet, left, right);
	return inv;
}

int main() {
	int n, ans;
	while(scanf("%d", &n) != EOF && n != 0) {
		for(int i = 0; i < n; i++) 
			scanf("%d", &vet[i]);

		ans = MergeSort(vet, 0, n-1);
		printf("%d\n", ans);
	}
}