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

void InsereNo(No *&L, int x) {
	No * novo;
	novo = (No *) malloc(sizeof(No));  //alocar(novo)
	novo->Valor = x;
	novo->Prox=L;
	L = novo;
}

void ImprimeNos(No * L) {
	cout << "[";
	No * p;
	p = L;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

void Imprime(ListaLinearEnc L) {
	cout << "# elementos: " << L.N << " ";
	ImprimeNos(L.Inicio);
}

No* Soma2a2(No *L){
	if (L==NULL||L->Prox==NULL){
		return NULL;
	} else {
		No *R;
		R = Soma2a2(L->Prox);
		No * p = L->Prox;
		while (p != NULL) {
			int v;
			v = L->Valor + p->Valor;
			InsereNo(R,v);
			p = p->Prox;
		}
		return R;
	}
}

No* SomaConsecutivos(No *L){
	if (L==NULL||L->Prox==NULL){
		return NULL;
	} else {
		No *R;
		R = SomaConsecutivos(L->Prox);
		InsereNo(R,L->Valor+L->Prox->Valor);
		return R;
	}
}

int main() {
	//lista linear
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,5); Imprime(L); 
	Insere(L,2); Imprime(L);
	Insere(L,10); Imprime(L);
	Insere(L,1); Imprime(L);

	//cout << "A Lista Encadeada com valores somados 2 a 2 eh = \n"; 
	//ImprimeNos(Soma2a2(L.Inicio));		
	cout << "A Lista Encadeada com a soma dos nós consecutivos eh = \n"; 
	ImprimeNos(SomaConsecutivos(L.Inicio));		
}

