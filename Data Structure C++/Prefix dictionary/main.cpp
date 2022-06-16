#include <iostream>
#include "Prefix Dictionary.h"
using namespace std;

int main()
{
	Dictionary dictionary;

	string s = "chandan";
	dictionary.insert(s);
	s = "mittal";
	dictionary.insert(s);
	s = "chirag";
	dictionary.insert(s);
	s = "shashank";
	dictionary.insert(s);
	s = "abhinav";
	dictionary.insert(s);
	s = "arun";
	dictionary.insert(s);
	s = "abhishek";
	dictionary.insert(s);
	s = "polytech";
	dictionary.insert(s);
	s = "universty";
	dictionary.insert(s);
	s = "student";
	dictionary.insert(s);
	s = "russia";
	dictionary.insert(s);
	s = "education";
	dictionary.insert(s);

	cout << (dictionary.search("chandan") ? "found chandan\n" : "didnt find chandan\n");
	cout << (dictionary.search("arun") ? "found arun\n" : "didn't find arun\n");
	cout << (dictionary.search("abhi") ? "found abhi\n" : "didn't find abhi\n");
	cout << (dictionary.search("arun") ? "found arun\n" : "didn't find arun\n");
	cout << (dictionary.search("polytech") ? "found arun\n" : "didn't find arun\n");
	cout << (dictionary.search("universty") ? "found universty\n" : "didn't find universty\n");
	cout << (dictionary.search("student") ? "found student\n" : "didn't find student\n");
	cout << (dictionary.search("russia") ? "found russia\n" : "didn't find russia\n");
	cout << (dictionary.search("education") ? "found education\n" : "didn't find education\n");

	Node *root = dictionary.head;

	Remove(root, "arun");
	cout << (dictionary.search("arun") ? "found arun\n" : "didn't find arun\n");
	Remove(root, "universty");
	cout << (dictionary.search("universty") ? "found universty\n" : "didn't find universty\n");

	cout << "number of words with prefix abhi are: " << dictionary.words_with_prefix("abhi") << endl;
	cout << "number of words with prefix ch are: " << dictionary.words_with_prefix("ch") << endl;
	cout << "number of words with prefix k are: " << dictionary.words_with_prefix("k") << endl;

	return 0;
}