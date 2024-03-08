# Plot o resultado do arquivo de saída do programa principal
"""
dados = 
num_threads,love,hate,duration
1,92,5,12
2,49,3,11
3,24,2,8
4,16,2,5
5,9,2,3
6,7,2,3
7,6,2,4 
"""

import matplotlib.pyplot as plt
import pandas as pd


def plot_results(csv):
    data = pd.read_csv(csv)
    print(data.head())
    # Cria um subplot com 1 linha e 2 colunas
    plt.figure(figsize=(9, 5))
    plt.subplot(1, 2, 1)

    # Plota o gráfico Num Threads x Love
    plt.plot(data['num_threads'], data['block_size'], marker='o', label='Love')
    plt.xlabel('Num Threads')
    plt.ylabel('Block Size')
    plt.title('Num Threads x Block Size')
    plt.legend()
    plt.grid()
    # Muda para o segundo subplot
    plt.subplot(1, 2, 2)

    # Plota o gráfico Num Threads x Duration
    plt.plot(data['num_threads'], data['duration'], marker='o')
    plt.xlabel('Num Threads')
    plt.ylabel('Duration (ms)')
    plt.title('Num Threads x Duration')
    plt.grid()

    # Ajusta o layout para evitar sobreposição
    plt.tight_layout()

    # Salva a imagem
    plt.savefig('plot.png')


if __name__ == '__main__':
    plot_results('results.csv')
