#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int vet[1000];

// a < b
bool comp(const int &a, const int &b) {
	if(a > b) return true;
	else return false;
}

struct comparador{
	bool operator() (const int &a, const int &b) const{
		return a > b;
	}
};
int main() {
	int n;
	priority_queue <int, vector<int>, comparador> pq;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &vet[i]);
		pq.push(vet[i]);
		printf("%d\n", pq.top());
	}
	sort(vet, vet + n, comp);
	for(int i = 0; i < n; i++) printf("%d",vet[i]);
	
	return 0;
}