#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string sirulNecifrat,sirulCifrat;
int val;

string cifreaza(int nr, string sirulNecifrat)
{
	string sirulCifrat(sirulNecifrat.length(), ' ');
	for (int i = 0; i < sirulNecifrat.size(); i++)
		if (sirulNecifrat[i] != ' ')
			sirulCifrat[i] = (sirulNecifrat[i] - 'a' + nr) % 26 + 'a';
		else
			sirulCifrat[i] = ' ';
	return sirulCifrat;
}

string descifreaza(int nr, string sirulCifrat)
{
	return cifreaza(26-nr,sirulCifrat);
}

int main()
{
	cout << "Sirul necryptat: ";
	getline(cin, sirulNecifrat);
	transform(sirulNecifrat.begin(), sirulNecifrat.end(), sirulNecifrat.begin(), ::tolower);
	cout << "Valoarea cu care sa criptam sirul: ";
	cin >> val;
	sirulCifrat = cifreaza(val, sirulNecifrat);
	cout << "Sirul criptat este: " << sirulCifrat<<'\n';
	cout << "Sirul decriptat este: " << descifreaza(val, sirulCifrat);
	return 0;
}
