#include<stdio.h>
#include "conta.h"
#include<stdlib.h>

int main(){
	TcontaBancaria *c = criar();
	float deposito, saque, emprestimo;
	printf("Digite o valor para depositar\n");
	scanf("%f", &deposito);
	depositar(c, deposito);
	saldo(c);
	
	
	valorEmprestado(c);
	//pedirEmprestimo(c, 25.0);
	sacar(c, 160);
	saldo(c);
	valorEmprestado(c);
	//saldo(c);
	//depositar( c, 26.0);
	//saldo(c);
	//valorEmprestado(c);
	pagarEmprestimo(c, -26);
	saldo(c);
	valorEmprestado(c);

	
	/*
	printf("saque\n");
	sacar(c, (float)2);
	saldo(c);
	printf("emprestimo\n");
	pedirEmprestimo(c, 15.6);
	saldo(c);
	valorEmprestado(c);
	printf("pagar emprestimo\n");
	pagarEmprestimo(c, 15.5);
	saldo(c);
	valorEmprestado(c);
	*/

}
