#include <regex>
#include <string>
#include <iostream>
#include <regex>
#include <vector>


using namespace std;

pair<int,int> count_love_hate(vector<string> palavras) {
    int love = 0;
    int hate = 0;
    cout << palavras.size()<< endl;
    for (auto palavra: palavras) {
        for (int i = 0; i < palavra.size(); i++) {
            if (ispunct(palavra[i])) {
                palavra.erase(i--, 1);
            }
        }
        // lowercase word
        for (int i = 0; i < palavra.size(); i++) {
            if (isalpha(palavra[i])) {
                palavra[i] = tolower(palavra[i]);
            }
        }
        cout<< palavra << endl;
        if (palavra == "love") {
            love++;
        } else if (palavra == "hate") {
            hate++;
        }
    }
    return make_pair(love, hate);
}
