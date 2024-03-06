#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> lerArquivo(string nomeArquivo) {
    vector<string> palavras;
    ifstream arquivo(nomeArquivo);
    string palavra;

    // split word, ignore special characters
    while (arquivo >> palavra) {
        // remove special characters
        // for (int i = 0; i < palavra.size(); i++) {
        //     if (ispunct(palavra[i])) {
        //         palavra.erase(i--, 1);
        //     }
        // }
        // // lowercase word
        // for (int i = 0; i < palavra.size(); i++) {
        //     if (isalpha(palavra[i])){
        //     palavra[i] = tolower(palavra[i]);
        // }}
        palavras.push_back(palavra);
    } 
    arquivo.close();
    return palavras;
}

//int main() {
//    vector<string> linhas = lerArquivo("test.txt");
//    for (string linha : linhas) {
//        cout << linha << endl;
//    }
//    return 0;
//}