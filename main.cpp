#include <iostream>

#include <vector>
#include <thread>
#include "wordprocessor.h"
#include "entrada.h"
using namespace std;

int main(){
    vector<string> palavras = lerArquivo("test.txt");
    cout << palavras.size()<< endl;
    pair<int,int> result = count_love_hate(palavras);
    cout << "Love: " << result.first << endl;
    cout << "Hate: " << result.second << endl;
    return 0;
}