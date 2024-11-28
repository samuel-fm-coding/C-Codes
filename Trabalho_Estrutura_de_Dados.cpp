#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <locale.h>

using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
    int altura;

    No(int val) : valor(val), esquerda(NULL), direita(NULL), altura(1) {}
};


int obterAltura(No* no) {
    return no ? no->altura : 0;
}

int obterFatorBalanceamento(No* no) {
    return no ? obterAltura(no->esquerda) - obterAltura(no->direita) : 0;
}

void atualizarAltura(No* no) {
    no->altura = 1 + max(obterAltura(no->esquerda), obterAltura(no->direita));
}

No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

No* balancear(No* no) {
    atualizarAltura(no);
    int fator = obterFatorBalanceamento(no);

    // Rotação Simples direita
    if (fator > 1 && obterFatorBalanceamento(no->esquerda) >= 0) {
        return rotacaoDireita(no);
    }

    // Rotação dupla direita (esquerda-direita)
    if (fator > 1 && obterFatorBalanceamento(no->esquerda) < 0) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // Rotação Simples esquerda
    if (fator < -1 && obterFatorBalanceamento(no->direita) <= 0) {
        return rotacaoEsquerda(no);
    }

    // Rotação dupla esquerda (direita-esquerda)
    if (fator < -1 && obterFatorBalanceamento(no->direita) > 0) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

No* inserir(No* no, int valor) {
    if (!no) return new No(valor);

    if (valor < no->valor)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir(no->direita, valor);
    else
        return no;

    return balancear(no);
}

No* encontrarMenor(No* no) {
    No* atual = no;
    while (atual && atual->esquerda) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover(No* no, int valor) {
    if (!no) return no;

    if (valor < no->valor) {
        no->esquerda = remover(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = remover(no->direita, valor);
    } else {
        if (!no->esquerda || !no->direita) {
            No* temp = no->esquerda ? no->esquerda : no->direita;
            delete no;
            return temp;
        } else {
            No* temp = encontrarMenor(no->direita);
            no->valor = temp->valor;
            no->direita = remover(no->direita, temp->valor);
        }
    }

    return balancear(no);
}

void exibirPreOrdem(No* no) {
    if (no) {
        cout << no->valor << " ";
        exibirPreOrdem(no->esquerda);
        exibirPreOrdem(no->direita);
    }
}

void exibirPosOrdem(No* no) {
    if (no) {
        exibirPosOrdem(no->esquerda);
        exibirPosOrdem(no->direita);
        cout << no->valor << " ";
    }
}

void exibirOrdemSimetrica(No* no) {
    if (no) {
        exibirOrdemSimetrica(no->esquerda);
        cout << no->valor << " ";
        exibirOrdemSimetrica(no->direita);
    }
}

bool buscar(No* no, int valor) {
    if (!no) return false;

    if (valor == no->valor)
        return true;
    else if (valor < no->valor)
        return buscar(no->esquerda, valor);
    else
        return buscar(no->direita, valor);
}

No* editar(No* no, int antigoValor, int novoValor) {
    if (!no) return no;

    if (antigoValor == no->valor) {
        no->valor = novoValor;
        return no;
    } else if (antigoValor < no->valor) {
        no->esquerda = editar(no->esquerda, antigoValor, novoValor);
    } else {
        no->direita = editar(no->direita, antigoValor, novoValor);
    }

    return balancear(no);
}

void mostrarArvore(No* no, int espaco = 0, int profundidade = 10) {
    if (no == NULL) return;

    espaco += profundidade;

    mostrarArvore(no->direita, espaco);//sub-direita

    cout << endl;
    for (int i = profundidade; i < espaco; i++) {
        cout << " "; 
    }
    cout << no->valor << endl;

    mostrarArvore(no->esquerda, espaco);//sub-esquerda
}

void exibirEmGrafo(No* no, int nivel = 0) {
    if (no) {
        exibirEmGrafo(no->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) cout << "   ";
        cout << no->valor << endl;
        exibirEmGrafo(no->esquerda, nivel + 1);
    }
}


int main() {
	setlocale(LC_ALL, "Portuguese");
    No* arvore = NULL;
    int opcao, valor, novoValor;

    do {
        cout << "\n\nÁrvore AVL:\n\n";
        cout << "1 - Criar nova árvore\n";
        cout << "2 - Inserir elemento\n";
        cout << "3 - Remover elemento\n";
        cout << "4 - Exibir árvore em pré-ordem\n";
        cout << "5 - Exibir árvore em pós-ordem\n";
        cout << "6 - Exibir árvore em ordem simétrica\n";
        cout << "7 - Exibir árvore em formato de grafo\n";
        cout << "8 - Buscar elemento\n";
        cout << "9 - Editar elemento\n";
        cout << "10 - Balancear a árvore\n";
        cout << "11 - Mostrar árvore\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                arvore = NULL;
                cout << "\nÁrvore criada com sucesso!\n";
                break;
            case 2:
            	system("cls");
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                arvore = inserir(arvore, valor);
                cout << "Valor inserido!\n";
                break;
            case 3:
            	system("cls");
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                arvore = remover(arvore, valor);
                cout << "Valor removido (se existia)!\n";
                break;
            case 4:
            	system("cls");
                cout << "Exibindo em pré-ordem: ";
                exibirPreOrdem(arvore);
                cout << "\n";
                break;
            case 5:
            	system("cls");
                cout << "Exibindo em pós-ordem: ";
                exibirPosOrdem(arvore);
                cout << "\n";
                break;
            case 6:
            	system("cls");
                cout << "Exibindo em ordem simétrica: ";
                exibirOrdemSimetrica(arvore);
                cout << "\n";
                break;
            case 7:
            	system("cls");
                cout << "Exibindo em formato de grafo:\n";
                exibirEmGrafo(arvore);
                break;
            case 8:
            	system("cls");
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                if (buscar(arvore, valor))
                    cout << "Valor encontrado na árvore!\n";
                else
                    cout << "Valor não encontrado!\n";
                break;
            case 9:
            	system("cls");
                cout << "Digite o valor a ser editado: ";
                cin >> valor;
                cout << "\nDigite o novo valor: ";
                cin >> novoValor;
                arvore = editar(arvore, valor, novoValor);
                cout << "\nValor editado com sucesso!\n";
                break;
            case 10:
            	system("cls");
                arvore = balancear(arvore);
                cout << "Balanceamento concluído!\n";
                break;
            case 11:
            	system("cls");
            	cout << "Árvore AVL (visualização estrutural):\n";
    			mostrarArvore(arvore);
    			break;
            case 0:
                cout << "\nPrograma encerrado\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
