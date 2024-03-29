#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;

//Funcoes
void counter(int v[], int n, char c);
void printer(int qtd, int letter);
bool duplicate(const string word, const vector<string> lista);

int main()
{
	vector<string> words;
	string file4read, file4write, line;
	ifstream infile;
	ofstream outfile;
	char *tok = NULL, *write = NULL;
	int dup = 0, contador[26] = {0};
	regex reg ("[A-Z ;'-]+");
	regex reg2 ("(.*[- '].*)+");
	// Impressao interface inicial
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY" << endl;
	cout << "=======================================" << endl;
	cout << "\nDictionary file ? ";
	getline(cin, file4read);
	cout << "Word list file ? ";
	getline(cin, file4write);
	cout << "\nExtracting simple word files from file " << file4read << "," << endl;
	cout << "beginning with letter ..." << endl << endl;
	//Abertura de arquivos
	infile.open(file4read);
	outfile.open(file4write);
	//Verificação de abertura
	if (infile.fail())
	{
		cerr << "Error opening file: " << file4read << endl;
		exit(1);
	}
	if (outfile.fail())
	{
		cerr << "Error opening file: " << file4write << endl;
		exit(1);
	}

	//Separação de headlines
	while(!infile.eof())
	{
		//Conversao para char* com o objetivo de utilizar strtok
		getline(infile, line);
		write = new char[line.length() + 1];
		strcpy(write, line.c_str());
		//Separação de palavras simples
		if (regex_match(write, reg))
		{
			tok = strtok(write, ";");
			while (tok != NULL)
			{
				if(tok[0] == ' ') tok = &tok[1];
				if(tok[strlen(tok)-1] == ' ') tok[strlen(tok)-1] = '\0';

				//cout << tok << endl;
				if (!regex_match(tok, reg2))
				{
					counter(contador, 25, tok[0]);
					if(!duplicate(tok, words))
					words.push_back(tok);
					else
					dup++;
				}
				tok = strtok(NULL, ";");
			}
		}
	}
	//Ordenando o vetor
	sort(words.begin(), words.end());
	//Transfere vetor para o arquivo
	for (size_t i = 0; i < words.size(); i++)
	{
		outfile << words.at(i) << endl;
	}
	//Fechando os arquivos
	infile.close();
	outfile.close();

	//Impressao da interface
	for (int i = 0; i < 26; i++)
	{
		if (contador[i] != 0)
		{
			printer(contador[i], i);
		}
	}
	cout << "\nNumber of simple words = " << words.size()+ dup  << endl;
	cout << "\nSorting words ..." << endl;
	cout << "\nRemoving duplicate words ..." << endl;
	cout << "\nNumber of non-duplicate simple words = " << words.size() << endl;
	cout << "\nSaving words into file " << file4write << " ... "<< endl;
	cout << "\nEnd of processing." << endl << endl;


	return 0;
}
//Contagem do numero de palavras
void counter(int v[], int n, char c)
{
	switch (c)
	{
		case 'A':
		v[0] += 1;
		break;
		case 'B':
		v[1] += 1;
		break;
		case 'C':
		v[2] += 1;
		break;
		case 'D':
		v[3] += 1;
		break;
		case 'E':
		v[4] += 1;
		break;
		case 'F':
		v[5] += 1;
		break;
		case 'G':
		v[6] += 1;
		break;
		case 'H':
		v[7] += 1;
		break;
		case 'I':
		v[8] += 1;
		break;
		case 'J':
		v[9] += 1;
		break;
		case 'K':
		v[10] += 1;
		break;
		case 'L':
		v[11] += 1;
		break;
		case 'M':
		v[12] += 1;
		break;
		case 'N':
		v[13] += 1;
		break;
		case 'O':
		v[14] += 1;
		break;
		case 'P':
		v[15] += 1;
		break;
		case 'Q':
		v[16] += 1;
		break;
		case 'R':
		v[17] += 1;
		break;
		case 'S':
		v[18] += 1;
		break;
		case 'T':
		v[19] += 1;
		break;
		case 'U':
		v[20] += 1;
		break;
		case 'V':
		v[21] += 1;
		break;
		case 'W':
		v[22] += 1;
		break;
		case 'X':
		v[23] += 1;
		break;
		case 'Y':
		v[24] += 1;
		break;
		case 'Z':
		v[25] += 1;
		break;
	}
}
//Impressao dos pontos a cada 100 palavras
void printer(int qtd, int letter)
{

	switch (letter)
	{
		case 0:
		cout << "A" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";

		}
		cout << endl;
		break;
		case 1:
		cout << "B" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 2:
		cout << "C" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 3:
		cout << "D" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 4:
		cout << "E" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 5:
		cout << "F" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 6:
		cout << "G" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 7:
		cout << "H" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 8:
		cout << "I" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 9:
		cout << "J" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 10:
		cout << "K" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 11:
		cout << "L" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 12:
		cout << "M" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 13:
		cout << "N" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 14:
		cout << "O" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 15:
		cout << "P" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 16:
		cout << "Q" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 17:
		cout << "R" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 18:
		cout << "S" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 19:
		cout << "T" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 20:
		cout << "U" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;

		break;
		case 21:
		cout << "V" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 22:
		cout << "W" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;

		break;
		case 23:
		cout << "X" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;

		break;
		case 24:
		cout << "Y" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";
		}
		cout << endl;
		break;
		case 25:
		cout << "Z" << endl;
		for (int i = 0; i < qtd / 100; i++) {

			cout << ".";

		}
		cout << endl;
		break;
	}
}
bool duplicate(const string word, const vector<string> lista)
{
	for (size_t i = 0; i < lista.size(); i++)
	{
		if (lista.at(i)==word)
		return true;
	}
	return false;
}
