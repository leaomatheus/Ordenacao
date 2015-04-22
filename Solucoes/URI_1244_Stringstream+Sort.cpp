#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
 
bool comp (const string& a, const string & b)
{
    //Qual o criterio A < B
    //Se tamanho de A > tamanho de B, retorna true (ja ta na ordem certa)
    //Se tamanho de A < ou != tamanho de B, retorna false (ordem nao necessariamente certa)
    
    //Pro sort, se nem a > b nem b > a (ou seja, a == b), ele pode trocar ou nao
    //Se for stable_sort, ele mantem a ordem original
    //Ou seja, se nao for a > b nem b > a, ele deixa do jeito que ta

    return a.size() > b.size();
}

int main()
{
    int n;

    string lixo;
    string linha_inteira;
    string palavra;

    stringstream ss;
    //Vetor de strings que representa uma linha
    vector<string> line;
 
    cin >> n; //Cin eh o mesmo scanf (soh que de C++)

    //Esse getline eh so pra pegar a quebra de linha (o \n depois do inteiro)
    getline (cin, lixo);

    for (int k = 0; k < n; k++)
    {
        //Le a linha inteira
        getline (cin, linha_inteira);
        ss.clear();
        line.clear();
        
        //Passa a linha pro stringstream
        ss << linha_inteira;
        //Enquanto tiver palavras dentro do stringstream, vai tirando e adicionando em line
        while (ss >> palavra)
        {
            line.push_back(palavra);
        }
        
        //Se der empate no teste de comp, mantem a ordem original
        stable_sort (line.begin(), line.end(), comp);
 
        //Printa as palavras
        for (int i = 0; i < line.size(); i++)
        {
            if (i > 0) cout << " ";
            cout << line.at(i);
        }
        cout << endl;
    }
}