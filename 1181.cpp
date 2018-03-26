#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareVector(const string &string1,const string &string2) {
	if (string1.size() == string2.size())
		return string1 < string2;
	else
		return string1.size() < string2.size();
		
}

int main() {
	int int_count;
	vector<string> vector_words;
	string string_temp;
	vector<string>::iterator iter_words;
	vector<string>::iterator iter_unique;

	cin >> int_count;
	for (int i = 0; i<int_count;i++) {
		cin >> string_temp;
		vector_words.push_back(string_temp);
	}

	sort(vector_words.begin(), vector_words.end(), compareVector);
	iter_unique = unique(vector_words.begin(), vector_words.end());
	for (iter_words = vector_words.begin(); iter_words != iter_unique; iter_words++) {
			cout << *iter_words << endl;
	}

	return 0;
}