#include <iostream>
#include <list>
#include <string>
using namespace std;

// Definição da estrutura de dados para mercadorias
struct Mercadoria {
    string nome;
};

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<int, Mercadoria>> table[hashGroups];
public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, const Mercadoria& mercadoria);
    void removeItem(int key);
    Mercadoria* searchItem(int key);
    void displayTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++)
        sum += table[i].size();
    if (!sum)
        return true;
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, const Mercadoria& mercadoria) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = mercadoria;
            cout << "[ATENÇÃO] Chave já existe. Valor substituído." << endl;
            break;
        }
    }
    if (!keyExists)
        cell.emplace_back(key, mercadoria);
    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removido." << endl;
            break;
        }
    }
    if (!keyExists)
        cout << "[ATENÇÃO] Chave não encontrada. Nada removido." << endl;
    return;
}

Mercadoria* HashTable::searchItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            cout << "[INFO] Item encontrado. Mercadoria: " << bItr->second.nome << endl;
            return &(bItr->second);
        }
    }
    cout << "[ATENÇÃO] Chave não encontrada." << endl;
    return nullptr;
}

void HashTable::displayTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
            cout << "Chave = " << bItr->first << ", Mercadoria: " << bItr->second.nome << endl;
    }
    return;
}

int main() {
    HashTable HT;
    Mercadoria canetaBIC = {"Caneta BIC"};
    Mercadoria caderno = {"Caderno"};
    Mercadoria lapis = {"Lápis"};

    // Caso de Teste 1: Inserção de Mercadorias
    HT.insertItem(905, canetaBIC);
    HT.insertItem(201, caderno);
    HT.insertItem(332, lapis);

    // Exibe a tabela após a inserção
    HT.displayTable();

    // Caso de Teste 2: Remoção de Mercadorias
    HT.removeItem(201);

    // Exibir a tabela após a remoção
    HT.displayTable();

    // Caso de Teste 3: Busca de Mercadorias
    HT.searchItem(332);

    // Verifica se a tabela hash está vazia
    if (HT.isEmpty())
        cout << "A tabela Hash está vazia." << endl;
    else
        cout << "A tabela Hash não está vazia." << endl;

    return 0;
}