#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct node {
	int v_int;
	vector<char> p;
	double v_double;
};

node vetor[25];

//Se compare retorna true, quer dizer que jah ta na ordem certa
bool compare(const node &s1, const node &s2) {
	//O criterio que eu quero que seja usado
	//Quero que o maior double fique na frente
	if(s1.v_double != s2.v_double) return s1.v_double > s2.v_double;
	/*Isso eh equivalente a:
	if(a > b) return true;
	else if(a < b) return false; */

	//Se os dois doubles forem iguais
	else if(s1.v_int != s2.v_int) {
		//Se A inteiro eh par, quero que ele fique na frente
		if(s1.v_int%2 == 0) return true;
		else return false;
	}

	//Se nao fica na frente quem tem mais chars no vetor
	else return s1.p.size() > s2.p.size();
}

int main() {
	vetor[0].v_int = 3; vetor[0].v_double = 2.0; vetor[0].p.push_back('a'); vetor[0].p.push_back('b');
	vetor[1].v_int = 3; vetor[1].v_double = 3.0; vetor[1].p.push_back('a');
	vetor[2].v_int = 2; vetor[2].v_double = 2.0; vetor[2].p.push_back('a');
	vetor[3].v_int = 3; vetor[3].v_double = 3.0; vetor[3].p.push_back('a'); vetor[3].p.push_back('b');
	sort(vetor, vetor + 4, compare);
	for(int i = 0; i < 4; i++) {
		printf("%d %lf %lu\n", vetor[i].v_int, vetor[i].v_double, vetor[i].p.size());
	}
	return 0;
}