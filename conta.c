#include<stdio.h>
#include<stdlib.h>
#include "conta.h"

struct contaBancaria{
	float saldo;
	float empr;
};

TcontaBancaria *criar(){
	TcontaBancaria *conta = (TcontaBancaria*)malloc(sizeof(TcontaBancaria));
	conta->saldo = 0;
	conta->empr = 0;
	return conta;
}

void pedirEmprestimo(TcontaBancaria *contaBancaria, float v){
	if(v < 0){
		printf("\nValor para pedir o emprestimo %.2f e menor que zero\n", v);
		printf("\nOPERACAO CANCELADA\n", v);
	}else{
		contaBancaria->empr += v;
		contaBancaria->saldo += v;
	}
	 
}

void pagarEmprestimo(TcontaBancaria *contaBancaria, float v){
	float c;
	if(v < 0){
		printf("\nValor para pagar o emprestimo %.2f e menor que zero\n", v);
		printf("\nOPERACAO CANCELADA\n", v);
	}
	else{
		if(v > contaBancaria->empr){
			printf("\nValor maior do que o emprestimo atual R$%.2f reais\n", v);
			c = v - contaBancaria->empr;
			depositar(contaBancaria, c);
			v = v - c;
			contaBancaria->saldo = (contaBancaria->saldo) - v;
			contaBancaria->empr = (contaBancaria->empr) - v;
			printf("\nO emprestimo de R$%.2f reais\n foi pago", v);
		}
		else{
			contaBancaria->saldo = (contaBancaria->saldo) - v;
			contaBancaria->empr = (contaBancaria->empr) - v;
			printf("\nO emprestimo de R$%.2f reais foi pago\n", v);
		}
	
		if(contaBancaria->empr < 0){
			contaBancaria->empr = 0;
		}		
	}
}

void depositar(TcontaBancaria *contaBancaria, float v){
	if(v < 0){
		printf("\nValor para depositar %.2f e menor que zero\n", v);
		printf("\nOPERACAO CANCELADA\n", v);
	}
	else{
		if(contaBancaria->empr > 0){
			contaBancaria->saldo = (contaBancaria->saldo) + v;
			pagarEmprestimo(contaBancaria, v);
		}
		else{
			contaBancaria->saldo += v; 
		}		
	}
}

void saldo(TcontaBancaria *contaBancaria){
	printf("\nSaldo: %.2f\n", contaBancaria->saldo);
//	return contaBancaria->saldo;
}

void sacar(TcontaBancaria *contaBancaria, float v){
	float c;
	if(v < 0){
		printf("\nValor para saque %.2f e menor que zero\n", v);
		printf("\nOPERACAO CANCELADA\n", v);
	}
	else{
		if(v > (contaBancaria->saldo)){
			printf("\nValor de saque maior do que o saldo atual R$%.2f reais\n", v);
			c = v - contaBancaria->saldo;
			printf("\nSera feito um emprestimo de R$%.2f reais \n", c);
			v = v - c;
			pedirEmprestimo(contaBancaria, c);
			contaBancaria->saldo = (contaBancaria->saldo) - v;
		}
		else{
			contaBancaria->saldo = (contaBancaria->saldo) - v;
		}
	}
	if(contaBancaria->saldo < 0){
		contaBancaria->saldo = 0;
	}
	
}

void valorEmprestado(TcontaBancaria *contaBancaria){
	printf("\nValor do Emprestimo: %.2f\n", contaBancaria->empr);
//	return contaBancaria->empr;
}


