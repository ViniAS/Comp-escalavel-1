#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readfile(const string &filename) {
    vector<string> words;

    ifstream file(filename);
    string word;

    // separar em palavras
    while (file >> word) {
        words.push_back(word);
    } 
    file.close();
    return words;
}