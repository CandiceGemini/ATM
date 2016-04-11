#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>


using namespace std;

typedef pair<string, int> PAIR;
// for out2
struct cmp
{
    bool operator() (const PAIR& P1, const PAIR& P2)
    {
        return P1.second > P2.second;
    }
};


int main()
{
    ifstream fin;
    ofstream fout1, fout2;
    fin.open("test.txt");
    fout1.open("3_1_1out.txt");
    fout2.open("3_1_2out.txt");
    
    string word;
    map<string, int> words_count;
    map<string, int>::iterator iter;
    
    while (fin.good())
    {
		fin >> word;
       //capital to lowercase
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
		//test if the word has appeared
        if (words_count[word])
        {
            words_count[word]++;
        }
        else
        {
            words_count[word]=1;
        }
    }
   //in lexicographic order
    for (iter = words_count.begin(); iter != words_count.end(); iter++)
    {
        fout1 << iter->first << ": " << iter->second << endl;
    }
  //in descending frequency order
    vector<PAIR>frequency;
    for (iter = words_count.begin(); iter != words_count.end(); iter++)
    {
		frequency.push_back(*iter);
    }
	sort(frequency.begin(), frequency.end(), cmp());
	for (int i = 0; i < frequency.size(); i++)
    {
		fout2 << frequency[i].first << ": " << frequency[i].second << endl;
    }
    //close files
    fin.close();
    fout1.close();
    fout2.close();
    return 0;
}