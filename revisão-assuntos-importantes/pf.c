
#include <stdio.h>
typedef int TipoFuncao();

int Load()
{
	printf("%s\n", 	__FUNCTION__);
	return 10;
}

int Print()
{
	printf("%s\n", 	__func__);
	return 20;
}
int Quit()
{
	printf("%s\n", 	__func__);
	return 30;
}
void SetCallbackFunc(TipoFuncao **GuardaEnderecoDeUmaFuncao, TipoFuncao *PonteiroParaUmaFuncao)
{
	*GuardaEnderecoDeUmaFuncao = PonteiroParaUmaFuncao;
}

int main()
{
	int opcao, retorno;
	TipoFuncao *ptrF;
	do {
		printf("Digite sua opcao(1,2,3) :");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1:
				ptrF = Load;
				break;
			case 2:
				ptrF = Print;
				break;
			case 3:
				SetCallbackFunc(&ptrF, Quit);
				break;
		}
		retorno = (*ptrF)(); // chama uma função a partir de ptrF
							 // e obtem o retorno 
		printf ("Retorno da função: %d\n\n", retorno);
	} while(opcao !=3);
}
