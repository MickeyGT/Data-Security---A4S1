#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
string sir;
map<int, char>mp;

void afiseazaFrecventa(string str)
{
	int fr[26];
	for (int i = 0; i < 26; i++)
		fr[i] = 0;
	for (int i = 0; i < str.length(); i++)
		fr[str[i]-'A']++;
	for (int i = 0; i < 26; i++)
		if(fr[i]!=0)
		{
			mp.insert({ fr[i], i + 'A', });
		}
	for (auto it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << " ";
}

int main()
{
	cout << "Sirul pe care sa calculam frecventa: ";
	getline(cin,sir);
	transform(sir.begin(), sir.end(), sir.begin(), ::toupper);
	afiseazaFrecventa(sir);
	return 0;
}
