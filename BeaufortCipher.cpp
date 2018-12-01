#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string cripteaza(string sirulNecriptat, string cheia)
{
	string sirulCriptat(sirulNecriptat.length(), ' ');
	for (int i = 0; i < sirulNecriptat.size(); i++)
		sirulCriptat[i] = 'A' + ((cheia[i] - sirulNecriptat[i]) + 26) % 26;
	return sirulCriptat;
}

string decripteaza(string sirulCriptat, string cheia)
{
	string sirulDecriptat(sirulCriptat.length(), ' ');
	for (int i = 0; i < sirulCriptat.size(); i++)
		sirulDecriptat[i] = 'A' + ((cheia[i] - sirulCriptat[i]) + 26) % 26;
	return sirulDecriptat;
}

int main()
{
	string sirulNecriptat;
	cout << "Sirul necryptat: ";
	getline(cin, sirulNecriptat);
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::toupper);
	cout << "Valoarea cheii cu care criptam sirul: ";
	string cheia;
	getline(cin, cheia);
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	while (cheia.length() < sirulNecriptat.length())
		cheia += cheia;
	string sirulCriptat = cripteaza(sirulNecriptat, cheia);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	cout << "Sirul decriptat este : " << decripteaza(sirulCriptat, cheia);
	return 0;
}
