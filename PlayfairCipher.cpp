#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char matricePlayfair[5][5];
vector<pair<int, int>>pozitieLitere(26);

string cripteaza(string sirulNecriptat)
{
	if (sirulNecriptat.length() % 2 == 1)
		sirulNecriptat = sirulNecriptat + 'X';
	string sirulCriptat(sirulNecriptat.length(), ' ');
	for (int i = 0; i < sirulNecriptat.length(); i+=2)
	{
		if (pozitieLitere[sirulNecriptat[i] - 'A'].first == pozitieLitere[sirulNecriptat[i + 1] - 'A'].first)
		{
			sirulCriptat[i] = matricePlayfair[pozitieLitere[sirulNecriptat[i] - 'A'].first][(pozitieLitere[sirulNecriptat[i] - 'A'].second + 1) % 5];
			sirulCriptat[i+1] = matricePlayfair[pozitieLitere[sirulNecriptat[i+1] - 'A'].first][(pozitieLitere[sirulNecriptat[i+1] - 'A'].second + 1) % 5];
		}
		else
			if(pozitieLitere[sirulNecriptat[i] - 'A'].second == pozitieLitere[sirulNecriptat[i + 1] - 'A'].second)
			{
				sirulCriptat[i] = matricePlayfair[(pozitieLitere[sirulNecriptat[i] - 'A'].first + 1) % 5][pozitieLitere[sirulNecriptat[i] - 'A'].second];
				sirulCriptat[i + 1] = matricePlayfair[(pozitieLitere[sirulNecriptat[i + 1] - 'A'].first + 1) % 5][pozitieLitere[sirulNecriptat[i + 1] - 'A'].second];
			}
			else
			{
				sirulCriptat[i] = matricePlayfair[pozitieLitere[sirulNecriptat[i] - 'A'].first][pozitieLitere[sirulNecriptat[i+1] - 'A'].second];
				sirulCriptat[i + 1] = matricePlayfair[pozitieLitere[sirulNecriptat[i + 1] - 'A'].first][pozitieLitere[sirulNecriptat[i] - 'A'].second];
			}
	}
	return sirulCriptat;
}

string decripteaza(string sirulCriptat)
{
	string sirulDecriptat(sirulCriptat.length(), ' ');
	for (int i = 0; i < sirulCriptat.length(); i += 2)
	{
		if (sirulCriptat[i] == sirulCriptat[i + 1])
		{
			sirulDecriptat[i] = sirulCriptat[i];
			sirulDecriptat[i + 1] = sirulCriptat[i];
		}
		else
			if (pozitieLitere[sirulCriptat[i] - 'A'].first == pozitieLitere[sirulCriptat[i + 1] - 'A'].first)
			{
				sirulDecriptat[i] = matricePlayfair[pozitieLitere[sirulCriptat[i] - 'A'].first][(pozitieLitere[sirulCriptat[i] - 'A'].second + 4) % 5];
				sirulDecriptat[i + 1] = matricePlayfair[pozitieLitere[sirulCriptat[i + 1] - 'A'].first][(pozitieLitere[sirulCriptat[i + 1] - 'A'].second + 4) % 5];
			}
			else
				if (pozitieLitere[sirulCriptat[i] - 'A'].second == pozitieLitere[sirulCriptat[i + 1] - 'A'].second)
				{
					sirulDecriptat[i] = matricePlayfair[(pozitieLitere[sirulCriptat[i] - 'A'].first + 4) % 5][pozitieLitere[sirulCriptat[i] - 'A'].second];
					sirulDecriptat[i + 1] = matricePlayfair[(pozitieLitere[sirulCriptat[i + 1] - 'A'].first + 4) % 5][pozitieLitere[sirulCriptat[i + 1] - 'A'].second];
				}
				else
				{
					sirulDecriptat[i] = matricePlayfair[pozitieLitere[sirulCriptat[i] - 'A'].first][pozitieLitere[sirulCriptat[i + 1] - 'A'].second];
					sirulDecriptat[i + 1] = matricePlayfair[pozitieLitere[sirulCriptat[i + 1] - 'A'].first][pozitieLitere[sirulCriptat[i] - 'A'].second];
				}
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
		if(cheia[i]!=' '&&exista[cheia[i]-'A']==false)
		{
			if(cheia[i] == 'I' || cheia[i] == 'J')
			{
				matricePlayfair[nr / 5][nr % 5] = 'I';
				exista['I' - 'A' ] = exista['J'-'A'] = true;
				pozitieLitere['I' - 'A'] = { nr / 5 ,nr % 5 };
			}
			else
			{
				matricePlayfair[nr / 5][nr % 5] = cheia[i];
				exista[cheia[i] - 'A'] = true;
				pozitieLitere[cheia[i] - 'A'] = { nr / 5 ,nr % 5 };
			}
			nr++;
		}
	for (int i = 0; i < 26; i++)
		if(exista[i]==false)
		{
			if (i + 'A' == 'I')
				exista['J' - 'A' ] = true;
			matricePlayfair[nr / 5][nr % 5] = 'A'+i;
			pozitieLitere[i] = { nr / 5 ,nr % 5 };
			nr++;
		}
}

int main()
{
	string sirulNecriptat;
	//cout << "Sirul necryptat: ";
	//getline(cin, sirulNecriptat);
	sirulNecriptat = "PT BOAT ONE OWE NINE LOST IN ACTION IN BLACKETT STRAIT TWO MILES SW MERESU COVE X CREW OF TWELVE X REQUEST ANY INFORMATION";
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::toupper);
	replace(sirulNecriptat.begin(), sirulNecriptat.end(), 'J', 'I');
	sirulNecriptat.erase(remove_if(sirulNecriptat.begin(), sirulNecriptat.end(), isspace), sirulNecriptat.end());
	for (int i = 0; i < sirulNecriptat.length() - 1; i++)
		if (sirulNecriptat[i] == sirulNecriptat[i + 1])
			sirulNecriptat.insert(i + 1, "X");
	string cheia;
	//cout << "Valoarea cheii cu care criptam sirul: ";
	//getline(cin, cheia);
	cheia = "ROYAL NEW ZEALAND NAVY";
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	cheia.erase(remove_if(cheia.begin(), cheia.end(), isspace), cheia.end());
	creeazaMatricea(cheia);
	string sirulCriptat = cripteaza(sirulNecriptat);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	//cout << "Sirul decriptat este : " << decripteaza(sirulCriptat);
	cout << "Sirul decriptat este : " << decripteaza("KXIEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAIPOBOTEIZONTXBYBWTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ");
	return 0;
}
