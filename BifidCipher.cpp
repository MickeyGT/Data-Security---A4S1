#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

char matricePlayfair[5][5];
vector<pair<int, int>>pozitieLitere(26);

string cripteaza(string sirulNecriptat)
{
	string sirulCriptat;
	deque<int>deq;
	int i = 0;
	while (i < sirulNecriptat.length())
	{
		int ending = i + 4;
		for (; i < sirulNecriptat.length() && i <= ending; i++)
			deq.push_back(pozitieLitere[sirulNecriptat[i] - 'A'].first);
		for (int j=ending-4; j < sirulNecriptat.length() && j <= ending; j++)
			deq.push_back(pozitieLitere[sirulNecriptat[j] - 'A'].second);
	}
	
	for (auto it = deq.begin(); it != deq.end(); it ++)
	{
		auto val = *it;
		it++;
		sirulCriptat += matricePlayfair[val][*it];
	}
	return sirulCriptat;
}

string decripteaza(string sirulCriptat)
{
	string sirulDecriptat;
	int i = 0;
	while (i < sirulCriptat.length())
	{
		deque<int>deq;
		int ending = i + 4;
		for (; i < sirulCriptat.length() && i <= ending; i++)
		{
			deq.push_back(pozitieLitere[sirulCriptat[i] - 'A'].first);
			deq.push_back(pozitieLitere[sirulCriptat[i] - 'A'].second);
		}
		for (int j = 0; j < deq.size()/2; j++)
		{
			sirulDecriptat += matricePlayfair[deq[j]][deq[j+ deq.size() / 2]];
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
		if (cheia[i] != ' '&&exista[cheia[i] - 'A'] == false)
		{
			if (cheia[i] == 'I' || cheia[i] == 'J')
			{
				matricePlayfair[nr / 5][nr % 5] = 'I';
				exista['I' - 'A'] = exista['J' - 'A'] = true;
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
		if (exista[i] == false)
		{
			if (i + 'A' == 'I')
				exista['J' - 'A'] = true;
			matricePlayfair[nr / 5][nr % 5] = 'A' + i;
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
	string cheia;
	//cout << "Valoarea cheii cu care criptam sirul: ";
	//getline(cin, cheia);
	cheia = "ROYAL NEW ZEALAND NAVY";
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	cheia.erase(remove_if(cheia.begin(), cheia.end(), isspace), cheia.end());
	creeazaMatricea(cheia);
	string sirulCriptat = cripteaza(sirulNecriptat);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	cout << "Sirul decriptat este : " << decripteaza(sirulCriptat);
	return 0;
}
