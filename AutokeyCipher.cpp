#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string cripteaza(string sirulNecriptat, string cheia)
{
	string sirulCriptat(sirulNecriptat.length(), ' ');
	for (int i = 0; i < sirulNecriptat.size(); i++)
		sirulCriptat[i] = 'A' + (sirulNecriptat[i] - 'A' + cheia[i] - 'A') % 26;
	return sirulCriptat;
}

string decripteaza(string sirulCriptat, string key)
{
	string sirulDecriptat(sirulCriptat.length(), ' ');
	for (int i = 0; i < sirulCriptat.size(); i++)
	{
		sirulDecriptat[i] = 'A' + (26 + sirulCriptat[i] - key[i]) % 26;
		key += sirulDecriptat[i];
	}
	return sirulDecriptat;
}

int main()
{
	string sirulNecriptat;
	cout << "Sirul necryptat: ";
	getline(cin, sirulNecriptat);
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::toupper);
	cout << "Valoarea cheii cu care criptam sirul: ";
	string cheia,cheiaOriginala;
	getline(cin, cheia);
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	cheiaOriginala = cheia;
	int i = 0;
	while (cheia.length() < sirulNecriptat.length())
	{
		cheia += sirulNecriptat[i];
		i++;
	}
	string sirulCriptat = cripteaza(sirulNecriptat, cheia);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	cout << "Sirul decriptat este : " << decripteaza(sirulCriptat, cheiaOriginala);
	return 0;
}
