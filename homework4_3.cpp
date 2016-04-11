#include<iostream>
#include<iterator>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	vector<int>number;
	vector<int>odd_number;
	vector<int>even_number;
	vector<int>::iterator iter;

	ofstream fout_1, fout_2;
	fout_1.open("3_3_1out.txt");
	fout_2.open("3_3_2out.txt");
	
	//using istream_iterator to read
	istream_iterator<int> in(cin);
	istream_iterator<int> eof;
	copy(in, eof, back_inserter(number));
	//judge the number and store in vector
	for (iter = number.begin(); iter != number.end(); iter++)
		if ((*iter) % 2 != 0)
		{
			odd_number.push_back(*iter);
		}
		else
		{
			even_number.push_back(*iter);
		}

	
	//use ostream_iterator,drlimited by space
	ostream_iterator<int> odd(fout_1, " "); 
	copy(odd_number.begin(), odd_number.end(), odd);
	//use ostream_iterator,drlimited by return character
	ostream_iterator<int> even(fout_2, "\n");
	copy(even_number.begin(), even_number.end(), even);
	
	
	//close files
	fout_1.close();
	fout_2.close();
	return 0;
}
