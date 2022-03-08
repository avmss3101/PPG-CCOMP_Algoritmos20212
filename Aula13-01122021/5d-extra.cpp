#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Prox;
} No;

typedef struct ListaLinearEnc {
	No * Inicio;	//Inicio: ^No
	int N;
} ListaLinearEnc;

void Insere(ListaLinearEnc &L, int x) {
	//Theta(1)
	No * novo;
	novo = (No *) malloc(sizeof(No));  //alocar(novo)
	novo->Valor = x;
	novo->Prox = L.Inicio;
	L.Inicio = novo;
	L.N = L.N+1;
}

void Imprime(ListaLinearEnc L) {
	cout << "# elementos: " << L.N << " [";
	No * p;
	p = L.Inicio;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

//5a. o número de valores
int NumVal(No *L){
	if (L != NULL){
		return 1+NumVal(L->Prox);
	} else {
		return 0;
	}
}

//5b. o produto dos valores
int Produto(No * L) {
	//retorna a1*a2*...*aN, onde ai representa o i-ésimo valor de L
	if (L == NULL) {
		return 1;
	} else {
		return L->Valor * Produto(L->Prox); //a2*...*aN
	}
}

//5c. o maior valor
int Maior(No *L){
    if (L == NULL) {
        return -1000000;
    } else {
        int ms;
        ms = Maior(L->Prox);
        if (L->Valor > ms){
            return L->Valor;
        } else {
            return ms;
        }
    }
}

//5d. o último valor
int Ultimo(No *L){
	if(L==NULL){
		return 0;
	} else {
		if(L->Prox==NULL){
			return L->Valor;
		} else {
			return Ultimo(L->Prox);
		}
	}
}

//5d(extra). o primeiro valor
int Primeiro(No *L){
	if (L==NULL){
		return 0;
	} else {
		if(L->Prox==NULL){
			return Primeiro(L->Prox);
		} else {
			return L->Valor;
		}
	}
}

int main() {
	//lista linear encadeada
	//exercicios de recursao
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,9); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,5); Imprime(L); 
	cout << "O  primeiro valor da Lista Encadeada eh = " << Primeiro(L.Inicio) << "\n"; //9
}
