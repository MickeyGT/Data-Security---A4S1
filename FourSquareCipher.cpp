#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char matricePlayfair[10][10];
vector<pair<int, int>>pozitieLitere1(26);
vector<pair<int, int>>pozitieLitere2(26);
vector<pair<int, int>>pozitieLitere3(26);
vector<pair<int, int>>pozitieLitere4(26);
string cripteaza(string sirulNecriptat)
{
	if (sirulNecriptat.length() % 2 == 1)
		sirulNecriptat = sirulNecriptat + 'X';
	string sirulCriptat(sirulNecriptat.length(), ' ');
	for (int i = 0; i < sirulNecriptat.length(); i += 2)
	{
		sirulCriptat[i] = matricePlayfair[pozitieLitere1[sirulNecriptat[i] - 'A'].first][pozitieLitere2[sirulNecriptat[i + 1] - 'A'].second];
		sirulCriptat[i + 1] = matricePlayfair[pozitieLitere2[sirulNecriptat[i + 1] - 'A'].first][pozitieLitere1[sirulNecriptat[i] - 'A'].second];	
	}
	return sirulCriptat;
}

string decripteaza(string sirulCriptat)
{
	string sirulDecriptat(sirulCriptat.length(), ' ');
	for (int i = 0; i < sirulCriptat.length(); i += 2)
	{		
		sirulDecriptat[i] = matricePlayfair[pozitieLitere3[sirulCriptat[i] - 'A'].first][pozitieLitere4[sirulCriptat[i + 1] - 'A'].second];
		sirulDecriptat[i + 1] = matricePlayfair[pozitieLitere4[sirulCriptat[i + 1] - 'A'].first][pozitieLitere3[sirulCriptat[i] - 'A'].second];	
	}
	return sirulDecriptat;
}

void creeazaMatricea(string cheia1,string cheia2)
{
	bool exista[26];
	int nr = 0;
	for (int i = 0; i < 26; i++)
		exista[i] = false;
	for (int i = 0; i < cheia1.length(); i++)
		if (cheia1[i] != ' '&&exista[cheia1[i] - 'A'] == false)
		{
			if (cheia1[i] == 'I' || cheia1[i] == 'J')
			{
				matricePlayfair[nr / 5][nr % 5+5] = 'I';
				pozitieLitere3['I'-'A'] = { nr / 5,nr % 5 + 5 };
				exista['I' - 'A'] = exista['J' - 'A'] = true;
			}
			else
			{
				matricePlayfair[nr / 5][nr % 5 + 5] = cheia1[i];
				pozitieLitere3[cheia1[i] - 'A'] = { nr / 5,nr % 5 + 5 };
				exista[cheia1[i] - 'A'] = true;
			}
			nr++;
		}
	for (int i = 0; i < 26; i++)
		if (exista[i] == false)
		{
			if (i + 'A' == 'I')
				exista['J' - 'A'] = true;
			matricePlayfair[nr / 5][nr % 5 + 5] = 'A' + i;
			pozitieLitere3[i] = { nr / 5,nr % 5 + 5 };
			nr++;
		}
	nr = 0;
	for (int i = 0; i < 26; i++)
		exista[i] = false;
	for (int i = 0; i < cheia2.length(); i++)
		if (cheia2[i] != ' '&&exista[cheia2[i] - 'A'] == false)
		{
			if (cheia2[i] == 'I' || cheia2[i] == 'J')
			{
				matricePlayfair[nr / 5 + 5][nr % 5] = 'I';
				pozitieLitere4['I' - 'A'] = { nr / 5 + 5,nr % 5};
				exista['I' - 'A'] = exista['J' - 'A'] = true;
			}
			else
			{
				matricePlayfair[nr / 5 + 5][nr % 5] = cheia2[i];
				pozitieLitere4[cheia2[i] - 'A'] = { nr / 5 + 5,nr % 5 };
				exista[cheia2[i] - 'A'] = true;
			}
			nr++;
		}
	for (int i = 0; i < 26; i++)
		if (exista[i] == false)
		{
			if (i + 'A' == 'I')
				exista['J' - 'A'] = true;
			matricePlayfair[nr / 5 + 5][nr % 5] = 'A' + i;
			pozitieLitere4[i] = { nr / 5 + 5,nr % 5 };
			nr++;
		}
	for (int i = 0; i < 26; i++)
		if (i != 9)
		{
			if (i > 9)
			{
				matricePlayfair[(i - 1) / 5][(i - 1) % 5] = matricePlayfair[(i - 1) / 5 + 5][(i - 1) % 5 + 5] = 'A' + i;
				pozitieLitere1[i] = { (i - 1) / 5,(i - 1) % 5 };
				pozitieLitere2[i] = { (i - 1) / 5 + 5,(i - 1) % 5 + 5 };
			}
			else
			{
				matricePlayfair[i / 5][i % 5] = matricePlayfair[i / 5 + 5][i % 5 + 5] = 'A' + i;
				pozitieLitere1[i] = { i / 5,i % 5 };
				pozitieLitere2[i] = { i / 5 + 5,i % 5 + 5};
			}
		}
}

int main()
{
	string sirulNecriptat;
	//cout << "Sirul necryptat: ";
	//getline(cin, sirulNecriptat);
	sirulNecriptat = "ANA ARE MERE";
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::toupper);
	replace(sirulNecriptat.begin(), sirulNecriptat.end(), 'J', 'I');
	sirulNecriptat.erase(remove_if(sirulNecriptat.begin(), sirulNecriptat.end(), isspace), sirulNecriptat.end());
	for (int i = 0; i < sirulNecriptat.length() - 1; i++)
		if (sirulNecriptat[i] == sirulNecriptat[i + 1])
			sirulNecriptat[i+1] = 'X';
	string cheia1,cheia2;
	//cout << "Valoarea cheii cu care criptam sirul: ";
	//getline(cin, cheia);
	cheia1 = "MIHAI";
	cheia2 = "CATALIN";
	transform(cheia1.begin(), cheia1.end(), cheia1.begin(), ::toupper);
	cheia1.erase(remove_if(cheia1.begin(), cheia1.end(), isspace), cheia1.end());
	transform(cheia2.begin(), cheia2.end(), cheia2.begin(), ::toupper);
	cheia2.erase(remove_if(cheia2.begin(), cheia2.end(), isspace), cheia2.end());
	creeazaMatricea(cheia1, cheia2);
	string sirulCriptat = cripteaza(sirulNecriptat);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	//cout << "Sirul decriptat este : " << decripteaza(sirulCriptat);
	cout << "Sirul decriptat este : " << decripteaza("HGHVUAPAUA");
	return 0;
}
