#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int maiorSeq(vector<int> array, int n,int &sumMax){
    // Quando temos uma lista com um só elemento, na recursão vamos diminuindo o array.
    if(n==0){
        return sumMax;
    }
    else if(n==1) {
        if(array[0]>sumMax){return array[0];}
        else{return sumMax;}
    }
    // Vetor que vai receber juntos os números de mesmo sinal que estão juntos.
    vector<int> joinArray;  // Ex: array = [1,3,-2,-3,2,3,4] -> joinArray = [4,-5,9].
    int numElemJoinArray = 0; // Recebe número de elementos no novo array joinArray.
    int temp=0; // Somaremos as parcelas de mesmo sinal nessa variável, quando trocar o sinal adicionamos no joinArray e zeremos ele.
    bool positive; // Indicador se estamos numa parte positiva do array ou negativa.
    if(array[0]>=0){
        bool positive = true;
    }
    else{
        bool positive = false;
    }
    int count = 0; // Indica em qual parte estamos no array.
    for(count; count<n; count++){ // Loop para adicionar os novos elementos no joinArray.
        int newTemp = temp+array[count];
        if(newTemp<temp && positive){ // Indica que estamos numa parte do array que muda de sinal de positivo para negativo.
            positive = false; // Estamos entranado numa parte negativa.
            joinArray.push_back(temp); // Adiciona o intervalo de mesmo sinal somado no joinArray.
            numElemJoinArray++; // Aumenta o número de elementos no array.
            if(temp>sumMax){ // Verificação da soma máxima, sumMax.
                sumMax=temp;
            }
            temp = 0; // Zerando o temp.
        }
        else if(newTemp>temp && !positive){ // Indica que estamos numa parte do array que muda de sinal de positivo para negativo.
            positive = true; // Estamos entrando numa parte positiva.
            joinArray.push_back(temp); // Adiciona o intervalo de mesmo sinal somado no joinArray.
            numElemJoinArray++; // Aumenta o número de elementos no array.
            temp=0; // Zerando o temp.
        }
        temp += array[count]; // Soma no temporário
        if(count==n-1){ // Se estamos no último loop pracisamos adicionar no array o último elemento
            joinArray.push_back(temp);
            numElemJoinArray++;
        if(temp>sumMax){
            sumMax=temp;
            }
        }
    }
    vector<int> newArray; // Agora que temos números intercalados, vamos juntar de dois em dois.
    int numElemNewArray = 0; // Contando quantos elementos tem o nosso newArray.
    temp = 0; // Nele guardamos a soma de 2 em 2.
    for(int i=0; i<numElemJoinArray; i++){ // Percorremos nossa lista joinArray.
        if(temp==0){ // Se o temp é nulo então significa que ele foi zerado ou estamos começando agora.
            temp=joinArray[i];
        }
        else{
            temp+=joinArray[i];
            newArray.push_back(temp); // Adicionamos a soma no newArray.
            if(temp>sumMax){
                sumMax=temp; // Atualizamos o sumMax.
            }
            numElemNewArray++;
            temp = 0;
        }
    }
    if(temp!=0){ // Caso tivermos um número ímpar de elementos.
        newArray.push_back(temp);
        numElemNewArray++;
        if(temp>sumMax){
            sumMax=temp;
        }
    }
    if(numElemNewArray>=0){ // Recursão
         array = newArray;
         n = numElemNewArray;
        for(int x: array){
            cout << x << " ";
        }
        cout << endl;
         return maiorSeq(array, n, sumMax);
     }
    return sumMax;
}


int main(){
    vector<int> array = {2,-1, 2, -1, 2, -1, 2, -1};

    int n = array.size();

    int sumMax = INT_MIN;

    int result = maiorSeq(array, n, sumMax);

    cout << "Maior sequência: " << result << endl;

    return 0;
}