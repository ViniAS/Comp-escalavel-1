#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "wordprocessor.h"
#include "entrada.h"

using namespace std;

struct ThreadResult {
    int num_threads;
    int love;
    int hate;
    long long duration; // Tempo em milissegundos
};

// Função para contar love e hate
ThreadResult count_love_hate_wrapper(vector<string>& palavras, int num_threads) {
    vector<thread> threads;
    vector<int> love(num_threads, 0);
    vector<int> hate(num_threads, 0);

    // Medir o tempo inicial
    auto start_time = chrono::high_resolution_clock::now();

    for (int i = 0; i < num_threads; i++) {
        vector<string> slice;
        if (i == num_threads - 1) {
            slice = vector<string>(palavras.begin() + i * (palavras.size() / num_threads), palavras.end());
        } else {
            slice = vector<string>(palavras.begin() + i * (palavras.size() / num_threads),
                                   palavras.begin() + (i + 1) * (palavras.size() / num_threads));
        }
        threads.emplace_back(count_love_hate, slice, ref(love[i]), ref(hate[i]));
    }

    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
    }

    // Calcular o tempo decorrido
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();

    return {num_threads, love[0], hate[0], duration};
}

int main() {
    vector<string> palavras = lerArquivo("test.txt");

    vector<ThreadResult> results;

    for (int num_threads = 1; num_threads <= 100; num_threads++) {
        ThreadResult result = count_love_hate_wrapper(palavras, num_threads);
        results.push_back(result);
    }

    // salva os resultados em um arquivo csv 
    ofstream file("results.csv");
    file << "num_threads,love,hate,duration" << endl;
    for (auto result : results) {
        file << result.num_threads << "," << result.love << "," << result.hate << "," << result.duration << endl;
    }
    file.close();

    return 0;
}
