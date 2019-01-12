#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include <tuple>
using namespace std;

char matriceTrifid[3][3][3];
vector<tuple<int, int,int>>pozitieLitere(27);

string cripteaza(string sirulNecriptat)
{
	int matriceCriptare[3][100],x,y,z;
	string sirulCriptat;
	for(int i=0;i < sirulNecriptat.length();i++)
	{
		tie(x, y, z) = pozitieLitere[sirulNecriptat[i] - 'A'];
		matriceCriptare[0][i] = x;
		matriceCriptare[1][i] = y;
		matriceCriptare[2][i] = z;
	}
	for (int j = 0; j < sirulNecriptat.length() / 5; j++)
	{
		int nr = 0;
		for (int i = j*5; i < j*5+5; i++)
		{
			x = matriceCriptare[(nr / 5)][j * 5+nr % 5];
			nr++;
			y = matriceCriptare[(nr / 5)][j * 5 + nr % 5];
			nr++;
			z = matriceCriptare[(nr / 5)][j * 5 + nr % 5];
			nr++;
			sirulCriptat += matriceTrifid[x][y][z];
		}
	}
	return sirulCriptat;
}

string decripteaza(string sirulCriptat)
{
	string sirulDecriptat;
	int matriceCriptare[3][100], x, y, z;
	int nr = 0;
	for (int j = 0; j < sirulCriptat.length(); j++)
	{
		if(sirulCriptat[j]!='+')
			tie(x, y, z) = pozitieLitere[sirulCriptat[j] - 'A'];
		else
			x = y = z = 2;
		matriceCriptare[(nr / 5)][(j / 5)*5 + nr % 5] = x;
		nr++;
		matriceCriptare[(nr / 5)][(j / 5) * 5 + nr % 5] = y;
		nr++;
		matriceCriptare[(nr / 5)][(j / 5) * 5 + nr % 5] = z;
		nr++;
		nr = nr % 15;
	}

	for (int i = 0; i < sirulCriptat.length(); i++)
	{
		x = matriceCriptare[0][i];
		y = matriceCriptare[1][i];
		z = matriceCriptare[2][i];
		sirulDecriptat += matriceTrifid[x][y][z];
	}

	return sirulDecriptat;
}

void creeazaMatricea(string cheia)
{
	bool exista[26];
	int nr = 0;
	for (int i = 0; i < 26; i++)
		exista[i] = false;
	for (int i = 0; i < cheia.length(); i++)
		if (cheia[i] != ' '&&exista[cheia[i] - 'A'] == false)
		{
			matriceTrifid[nr / 9][(nr % 9) / 3][(nr % 9) % 3]= cheia[i];
			exista[cheia[i] - 'A'] = true;
			pozitieLitere[cheia[i] - 'A'] = make_tuple(nr / 9, (nr % 9) / 3, (nr % 9) % 3);
			nr++;
		}
	for (int i = 0; i < 26; i++)
		if (exista[i] == false)
		{
			matriceTrifid[nr / 9][(nr % 9) / 3][(nr % 9) % 3] = 'A'+i;
			pozitieLitere[i] = make_tuple(nr / 9, (nr % 9) / 3, (nr % 9) % 3);
			nr++;
		}
	matriceTrifid[2][2][2] = '+';
	pozitieLitere[26] = make_tuple(2, 2, 2);
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
	string cheia;
	//cout << "Valoarea cheii cu care criptam sirul: ";
	//getline(cin, cheia);
	cheia = "ABECEDAR";
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	cheia.erase(remove_if(cheia.begin(), cheia.end(), isspace), cheia.end());
	creeazaMatricea(cheia);
	string sirulCriptat = cripteaza(sirulNecriptat);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	cout << "Sirul decriptat este : " << decripteaza(sirulCriptat);
	return 0;
}
