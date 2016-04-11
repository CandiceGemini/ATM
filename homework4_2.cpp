#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
#include<fstream>
#include<algorithm>
#include<vector>
#include <cctype>

using namespace std;


//function object
	bool string_sort(const string &str1, const string &str2)
	{
		return str1.length() < str2.length();
	}




int main()
{
	ifstream fin;
	fin.open("article.txt");
	ofstream fout;
	fout.open("3_2out.txt");
	

	
	string word;
	vector<string>word_sort;
	vector<string>::iterator iter;

	while (fin.good())
	{
		
		fin >> word;
		//capital to lowercase
		for (int i = 0; i < word.length();i++)
		{
			word[i] = tolower(word[i]);
		}
		//guarantee the same word is stored once
		vector<string>::iterator result = find(word_sort.begin(), word_sort.end(), word); 
		if (result == word_sort.end())
		{
			word_sort.push_back(word);
		}
	}
	//using sort
	sort(word_sort.begin(), word_sort.end(), string_sort);
	//output
	for (iter = word_sort.begin(); iter != word_sort.end(); iter++)
	{
		fout << *iter << endl;
	}
	// close files
	fin.close();
	fout.close();

	return 0;
}