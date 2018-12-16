#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string cripteaza(string sirulNecriptat, string cheia)
{
	string sirulCriptat;
	char matrix[50][50];
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			matrix[i][j] = 0;
	int line = ceil(1.0*sirulNecriptat.size() / cheia.size());
	for(int i=0;i<line;i++)
		for(int j=0;j< cheia.size();j++)
			if (i*cheia.size() + j <= sirulNecriptat.size() - 1)
			{
				matrix[i][j] = sirulNecriptat[i*cheia.size() + j];
			}
	for (int j = 0; j < cheia.size(); j++)
		if (matrix[line-1][j] == 0)
			matrix[line-1][j] = 'X';
	vector<pair<int, int>>keyValues;
	for (int i = 0; i < cheia.size(); i++)
		keyValues.push_back({ cheia[i],i });
	sort(keyValues.begin(), keyValues.end());
	for (auto it : keyValues)
	{
		for (int i = 0; i < line; i++)
			if(matrix[i][it.second]!=0)
				sirulCriptat += matrix[i][it.second];
	}
	return sirulCriptat;
}

string decripteaza(string sirulCriptat,string cheia)
{
	string sirulDecriptat;
	
	char matrix[50][50];
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			matrix[i][j] = 0;
	int line = ceil(1.0*sirulCriptat.size() / cheia.size());
	vector<pair<int, int>>keyValues;
	for (int i = 0; i < cheia.size(); i++)
		keyValues.push_back({ cheia[i],i });
	sort(keyValues.begin(), keyValues.end());
	int nr = 0;
	for (auto it : keyValues)
	{
		for (int i = 0; i < line; i++)
			matrix[i][it.second] = sirulCriptat[nr++];
	}
	for (int i = 0; i < line; i++)
		for (int j = 0; j < cheia.size(); j++)
			if (matrix[i][j]!='X')
			{
				sirulDecriptat += matrix[i][j];
			}
	return sirulDecriptat;
}


int main()
{
	string sirulNecriptat;
	//cout << "Sirul necryptat: ";
	//getline(cin, sirulNecriptat);
	sirulNecriptat = "defend the east wall of the castle";
	transform(sirulNecriptat.begin(), sirulNecriptat.end(), sirulNecriptat.begin(), ::toupper);
	sirulNecriptat.erase(remove_if(sirulNecriptat.begin(), sirulNecriptat.end(), isspace), sirulNecriptat.end());
	string cheia;
	//cout << "Valoarea cheii cu care criptam sirul: ";
	//getline(cin, cheia);
	cheia = "zebra";
	transform(cheia.begin(), cheia.end(), cheia.begin(), ::toupper);
	cheia.erase(remove_if(cheia.begin(), cheia.end(), isspace), cheia.end());
	//creeazaMatricea(cheia1, cheia2);
	string sirulCriptat = cripteaza(sirulNecriptat,cheia);
	cout << "Sirul criptat este : " << sirulCriptat << "\n";
	//cout << "Sirul decriptat este : " << decripteaza(sirulCriptat);
	cout << "Sirul decriptat este : " << decripteaza(sirulCriptat,cheia);
	return 0;
}
