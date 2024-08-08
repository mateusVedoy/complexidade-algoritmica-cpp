#include <iostream>
#include <vector>

//sempre irá executar 1 busca exata pelo indice do array
//funciona em qualquer tipo de array/lista
void complexidadeConstante(const std::vector<int>& arr, int indice) {
    int contador = 1;
    int resultado = arr[indice];
    std::cout << "\nComplexidade constante: ";
    printf("achei o valor %d, no índice %d com %d acesso ao array de %ld posições\n", resultado, indice, contador, arr.size());
}

//poderá, no melhor cenário executar 1 acesso, como também no pior cenário executar N acessos. Onde N é o tamanho do array
//funciona em qualquer tipo de lista/array
void complexidadeLinear(const std::vector<int>& arr, int valor) {
    int contador = 1;
    for(int x = 0; x < arr.size(); x++) {
        contador++;
        if(arr[x] == valor){
            std::cout << "\nComplexidade linear: ";
            printf("achei o valor %d com %d acessos ao array de %ld posições\n", valor, contador, arr.size());
            return;
        }
    }
}

//conhecida como busca binária
//a cada busca executada, reduz pela metade o tamanho do array a ser acessado
//funciona apenas em listas/arrays ordenadas(os)
void complexidadeLogaritmica(const std::vector<int>& arr, int valor) {
    int contador = 1;
    int metade_um = 0;
    int metade_dois = arr.size() - 1;
    
    while(metade_um <= metade_dois) {
        int meio = metade_um + (metade_dois - metade_um) / 2; //aqui pode haver arredondamento para cima do valor
        
        if (arr[meio] == valor) {
            std::cout << "\nComplexidade logarítmica: ";
            printf("achei o valor %d com %d acessos ao array de %ld posições\n", valor, contador, arr.size());
            return;
        }
        
        if (arr[meio] < valor) {
            metade_um = meio + 1;
        } else {
            metade_dois = meio -1;
        }
        
        contador++;
    }
    
    std::cout << "\nComplexidade logarítmica: ";
    printf("não achei o valor %d com %d acessos ao array de %ld posições\n", valor, contador, arr.size());
}

//recebe uma lista desordenada
//ordenada a lista 
//busca valor
void complexidadeLinearLogaritmica(std::vector<int> arr, int primeiraMetade, int segundaMetade, int valor, int contador) {

    contador++;
    
    int meio = primeiraMetade + (segundaMetade - primeiraMetade) / 2;
    
    if (arr[meio] == valor) {
        std::cout << "\nComplexidade linear logaritmica: ";
        printf("achei o valor %d com %d acessos ao array de %ld posições\n", valor, contador, arr.size());
        
        return;
    }
    
    int indicesAteValor = 0;
    
    for(int x = primeiraMetade; x <= segundaMetade; x++) {
        
        if (arr[x] == valor) {
            break;
        }
        
        indicesAteValor++;
        
    }
    
    printf("\n...Faltam %d índices até o valor %d", indicesAteValor, valor);
    
    if (arr[meio] < valor)
        primeiraMetade = meio + 1;
    else
        segundaMetade = meio - 1;
        
    complexidadeLinearLogaritmica(arr, primeiraMetade, segundaMetade, valor, contador);
    
    return;
}

//-----------------------------------

//FALTA QUADRÁTICA O(n^2)

//FALTA EXPONENCIAL O(2^n)

//FALTA FATORIAL O(n!)


int main()
{
    std::vector<int> arr_ordenado = {1, 2, 3, 4, 5};
    int valor = 3;
    
    complexidadeConstante(arr_ordenado, valor);
    complexidadeLinear(arr_ordenado, valor);
    complexidadeLogaritmica(arr, valor);
     complexidadeLinearLogaritmica(arr, 0, arr.size() - 1, valor, 0);
}