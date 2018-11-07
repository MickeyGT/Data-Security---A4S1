#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string sirulNecriptat;
int val;
int main()
{
	cout << "Sirul necryptat: ";
	getline(cin, sirulNecriptat);
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::tolower);
	cout << "Valoarea cu care sa criptam sirul: ";
	cin >> val;
	string sirulCriptat(sirulNecriptat.length(), ' ');
	for (int i = 0; i < sirulNecriptat.size(); i++)
		if (sirulNecriptat[i] != ' ')
			sirulCriptat[i] = (sirulNecriptat[i] - 'a' + val) % 26 + 'a';
		else
			sirulCriptat[i] = ' ';
	cout << "Sirul criptat este: "<<sirulCriptat;
	return 0;
}
