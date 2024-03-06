#include <iostream>

#include <vector>
#include <thread>
#include "wordprocessor.h"
#include "entrada.h"
using namespace std;
int NUM_THREADS = 8;
int main(){
    vector<thread> threads;
    vector<string> palavras = lerArquivo("../test.txt");
    vector<int> love(NUM_THREADS, 0);
    vector<int> hate(NUM_THREADS, 0);
    for (int i = 0; i < NUM_THREADS; i++) {
        vector<string> slice;
        if (i == NUM_THREADS - 1) {
            slice = vector<string>(palavras.begin() + i * (palavras.size() / NUM_THREADS), palavras.end());
        } else {
            slice = vector<string>(palavras.begin() + i * (palavras.size() / NUM_THREADS),
                                 palavras.begin() + (i + 1) * (palavras.size() / NUM_THREADS));
        }
        threads.emplace_back(count_love_hate, slice,
                                 ref(love[i]), ref(hate[i]));
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
    for(int i = 1; i < NUM_THREADS; i++){
        love[0] += love[i];
        hate[0] += hate[i];
    }
    cout << "Love: " << love[0] << endl;
    cout << "Hate: " << hate[0] << endl;
}