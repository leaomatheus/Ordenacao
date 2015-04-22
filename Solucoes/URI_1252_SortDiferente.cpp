#include <algorithm>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
int N, M;

// A < B?
bool comp (const int &a, const int &b)
{
    int p1 = a%M;
    int p2 = b%M;
     
    if (p1 != p2) return p1 < p2;

    //Numero impar (A) na frente, ou seja, A < B eh true
    if (a%2 == 1 && b%2 == 0) return true;

    //Numero impar (B) na frente, ou seja, A < B eh false
    if (a%2 == 0 && b%2 == 1) return false;
    
    //Se ambos sao impares, vigora maior na frente
    if (a % 2 && b%2) return a > b;
    //Caso contrario, menor na frente
    else return a < b;
}

int main()
{
    vector<int> vet;
    int aux;
     
    while (scanf("%d %d", &N, &M) != EOF && N != 0)
    {
        printf("%d %d\n", N, M);
        vet.clear();
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &aux);
            vet.push_back(aux);
        }
        sort (vet.begin(), vet.end(), comp);
         
        for (int i = 0; i < N; i++)
        {
            printf("%d\n", vet.at(i));
        }
    }
}