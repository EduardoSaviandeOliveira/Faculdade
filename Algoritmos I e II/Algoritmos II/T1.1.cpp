#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

int LeitorDaQuantidadeDeLadosERolagens(int escolha, int* frequenciaDeRolagemDosLados);
void ZeradorDoVetor(int* frequenciaDeRolagemDosLados);
int RecebedorDaQuantidadeDeLadosRolados(int lados, int rolagens, int* frequenciaDeRolagemDosLados);
int RecebedorDaQuantidadeDeLadosRolados(int dados, int lados, int rolagens, int* frequenciaDeRolagemDosLados);
double CalculadorDePossibilidades(int lados, int* frequenciaDeRolagemDosLados, int rolagens, int dados = 0);


int main()
{
	int escolha;
	bool is_running = true;
	int frequenciaDeRolagemDosLados[100];

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	while (is_running)
	{
		cout << "\t Escolha uma opção: \n\n"
			"1-Rolar um dado.\n\n"
			"2-Rolar mais de um dado.\n\n"
			"3-Sair\n\n"
			"Escolha: ";
		cin >> escolha;
		switch (escolha)
		{
		case 1:
			LeitorDaQuantidadeDeLadosERolagens(escolha, frequenciaDeRolagemDosLados);
			break;
		case 2:
			LeitorDaQuantidadeDeLadosERolagens(escolha, frequenciaDeRolagemDosLados);
			break;
		default:
			cout << "\n Programa encerrado. \n";
			is_running = false;
			break;
		}

	}
	return 0;
}

int LeitorDaQuantidadeDeLadosERolagens(int escolha, int* frequenciaDeRolagemDosLados)
{
	int quantidadeDeLados = 0;
	int quantidadeDeRolagens = 0;
	int quantidadeDeDados = 0;

	if (escolha == 1) //Leitor para a escolha 1 de um dado//
	{
		while (true) //Quantidade de lados do dado//
		{
			cout << "\n Escolha a quantidade lados que o dado terá, entre os números 1 e 100! \n Quantidade: ";
			cin >> quantidadeDeLados;

			if (quantidadeDeLados > 1 && quantidadeDeLados < 100) { break; }

			cout << "\n Valor inválido, a quantidade lados deve ser entre 1 e 100.";
		}

		while (true) //Quantidade de rolagens que o dado dará//
		{
			cout << "\n Escolha a quantidade rolagens que o dado terá, deverá ser maior que 0! \n Quantidade: ";
			cin >> quantidadeDeRolagens;

			if (quantidadeDeRolagens > 0) { break; }

			cout << "\n Valor inválido, a quantidade de rolagens deve ser maior que 0.";
		}

		RecebedorDaQuantidadeDeLadosRolados(quantidadeDeLados, quantidadeDeRolagens, frequenciaDeRolagemDosLados);
		return 0;
	}
	else //Leitor para a escolha 2 de vários dados//
	{
		while (quantidadeDeLados * quantidadeDeDados <= 0 || quantidadeDeLados * quantidadeDeDados >= 100)
		{
			while (true) //Quantidade de Dados que serão rolados//
			{
				cout << "\n Escolha a quantidade de dados que serão rolados, deverá ser maior que 0! \n Quantidade: ";
				cin >> quantidadeDeDados;

				if (quantidadeDeDados > 0) { break; }

				cout << "\n Valor inválido, a quantidade de dados deve ser maior que 0.";
			}

			while (true) //Quantidade de lados que o dado terá//
			{
				cout << "\n Escolha a quantidade lados que o dado terá, entre os números 1 e 99! \n Quantidade: ";
				cin >> quantidadeDeLados;

				if (quantidadeDeLados > 1 && quantidadeDeLados < 99) { break; }

				cout << "\n Valor inválido, a quantidade lados deve ser entre 1 e 99.";
			}
			if (quantidadeDeLados * quantidadeDeDados >= 100) {
				cout << "\n O valor da soma total possível tem que ser menor que 100!";
				quantidadeDeDados = 0;
				quantidadeDeLados = 0;
			}

		}

		while (true) //Quantidade de rolagens que o dado fará//
		{
			cout << "\n Escolha a quantidade rolagens que o dado terá, deverá ser maior que 0! \n Quantidade: ";
			cin >> quantidadeDeRolagens;

			if (quantidadeDeRolagens > 0) { break; }

			cout << "\n Valor inválido, a quantidade de rolagens deve ser maior que 0.";
		}
		RecebedorDaQuantidadeDeLadosRolados(quantidadeDeDados, quantidadeDeLados, quantidadeDeRolagens, frequenciaDeRolagemDosLados);
		return 0;
	}
}

void ZeradorDoVetor(int* frequenciaDeRolagemDosLados) //Inicializados/zerador do vetor//
{
	for (int i = 0; i < 100; i++)
	{
		frequenciaDeRolagemDosLados[i] = 0;
	}
}

int RecebedorDaQuantidadeDeLadosRolados(int lados, int rolagens, int* frequenciaDeRolagemDosLados) /* Função para receber os números da opção de um dado */
{
	ZeradorDoVetor(frequenciaDeRolagemDosLados);

	for (int i = 0; i < rolagens; i++)
	{
		int valor = 1 + (rand() % lados);
		frequenciaDeRolagemDosLados[valor - 1]++;
	}
	int dados = 0;

	CalculadorDePossibilidades(lados, frequenciaDeRolagemDosLados, rolagens, dados);

	return 0;
}

int RecebedorDaQuantidadeDeLadosRolados(int dados, int lados, int rolagens, int* frequenciaDeRolagemDosLados) // Função para receber os números da opção de vários dados//
{
	ZeradorDoVetor(frequenciaDeRolagemDosLados);

	for (int i = 0; i < rolagens; i++)
	{
		int valor = 0;

		for (int j = 0; j < dados; j++)
		{
			valor += (1 + (rand() % lados));
		}
		frequenciaDeRolagemDosLados[valor - 1]++;
	}
	CalculadorDePossibilidades(lados, frequenciaDeRolagemDosLados, rolagens, dados);

	return 0;
}

double CalculadorDePossibilidades(int lados, int* frequenciaDeRolagemDosLados, int rolagens, int dados) //Mostrador da Estatística//
{

	cout << "\n Distribuição: \n";

	if (dados == 0)
	{
		for (int i = 0; i < lados; i++)
		{
			double percentual = ((double)frequenciaDeRolagemDosLados[i]) / ((double)rolagens) * 100; //Variavel para o calculo percentual//
			cout << "\n O número " << i + 1 << " rolou " << frequenciaDeRolagemDosLados[i] << " vezes, um percentual de " << percentual << " % . \n";
		}
	}
	else {
		for (int i = 0; i < dados * lados; i++)
		{
			double percentual = ((double)frequenciaDeRolagemDosLados[i]) / (double)rolagens * 100; //Variavel para o calculo percentual//
			cout << "\n O número " << i + 1 << " rolou " << frequenciaDeRolagemDosLados[i] << " vezes, um percentual de " << percentual << " % . \n";
		}
	}
	system("pause");

	return 0;
}
