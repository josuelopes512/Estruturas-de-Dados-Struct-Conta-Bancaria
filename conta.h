typedef struct contaBancaria TcontaBancaria;
TcontaBancaria *criar();
void pedirEmprestimo(TcontaBancaria *contaBancaria, float v);
void pagarEmprestimo(TcontaBancaria *contaBancaria, float v);
void depositar(TcontaBancaria *contaBancaria, float v);
void sacar(TcontaBancaria *contaBancaria, float v);
void saldo(TcontaBancaria *contaBancaria);

