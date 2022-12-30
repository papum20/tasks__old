#include "libr.h"
using namespace std;


//1

void to_lower(char s[])
{
	for(int i = 0; i < strlen(s); i++)
		if(s[i] >= 65 && s[i] <= 90) s[i] += 32;
}

void to_upper(char s[])
{
	for(int i = 0; i < strlen(s); i++)
		if(s[i] >= 97 && s[i] <= 122) s[i] -= 32;
}

//2

int occurrencies(char s[], char e)
{
	int res = 0;
	for(int i = 0; i < strlen(s); i++)
		res++;
	return res;
}

void init_arr(int A[], int length)
{
	for(int i = 0; i < length; i++)
		A[i] = 0;
}

void hist_chars(char s[])
{
	int o[26];
	init_arr(o, 26);

	char tmp[strlen(s) + 1];
	strcpy(tmp, s);
	to_upper(tmp);

	for(int i = 0; i < strlen(tmp); i++)
		o[(int)(tmp[i] - 65)]++;


	//PRINT
	for(int i = 0; i < 26; i++)
	{
		if(o[i] > 0)
		{
			cout << (char)(i + 65) << "(" << o[i] << "): ";
			for(int j = 0; j < o[i]; j++) cout << "X";
			cout << endl;
		}
	}
}



//3

bool find_substr(char s[], char subs[])
{
	bool found = strlen(subs) == 0;
	int i_s = 0, i_sub = 0;

	while(!found && i_s < strlen(s))
	{
		if(subs[i_sub] == s[i_s]) i_sub++;
		else if(subs[0] == s[i_s]) i_sub = 1;
		else i_sub = 0;

		if(i_sub == strlen(subs)) found = true;
		i_s++;
	}

	return found;
}


int index_substr(char s[], char subs[])
{
	int index = 0;
	bool found = strlen(subs) == 0;
	int i_s = 0, i_sub = 0;

	while(!found && i_s < strlen(s))
	{
		if(i_sub == 0 && subs[i_sub] == s[i_s]) index = i_s;

		if(subs[i_sub] == s[i_s]) i_sub++;
		else if(subs[0] == s[i_s]) i_sub = 1;
		else i_sub = 0;

		if(i_sub == strlen(subs)) found = true;
		i_s++;
	}

	if(!found) return -1;
	else return index;
}

void remove_substr(char s[], char subs[])
{
	if(find_substr(s, subs))
	{
		int start = index_substr(s, subs);
		for(int i = 0; i < strlen(s); i++)
			s[start + i] = s[start + i + strlen(subs)];
	}

}

