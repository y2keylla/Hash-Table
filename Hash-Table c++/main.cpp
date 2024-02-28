#include <iostream>
#include <list>
#include <string>
using namespace std;

// Definição da estrutura de dados para uma mercadoria
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
    void collisionTest(); // Nova função para testar colisões
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

void HashTable::collisionTest() {
    // Teste 5: Verificação de Colisão
    // Inserir uma mercadoria com uma chave que cause colisão
    int key = 10; // Chave que causará colisão
    Mercadoria colisao1 = {"Lápis"}; // Exemplo de mercadoria
    insertItem(key, colisao1);

    // Inserir outra mercadoria com uma chave diferente que também cause colisão
    key += hashGroups; // Incrementar a chave para evitar substituição
    Mercadoria colisao2 = {"Caderno"}; // Exemplo de outra mercadoria
    insertItem(key, colisao2);

    // Exibir a tabela após a inserção das mercadorias com colisão
    cout << "\n[INFO] Exibindo tabela após inserção das mercadorias com colisão:"
         << endl;
    displayTable();
}

int main() {
    HashTable HT;
    Mercadoria canetaBIC = {"Caneta BIC"};
    Mercadoria caderno = {"Caderno"};
    Mercadoria lapis = {"Lápis"};

    // Teste 1: Inserção de Mercadorias
    HT.insertItem(905, canetaBIC);
    HT.insertItem(201, caderno);
    HT.insertItem(332, lapis);

    // Exibir a tabela após a inserção
    cout << "[INFO] Exibindo tabela após inserção das mercadorias:" << endl;
    HT.displayTable();

    // Teste 2: Remoção de Mercadorias
    HT.removeItem(201);
    cout << "\n[INFO] Exibindo tabela após remoção da mercadoria:" << endl;
    HT.displayTable();

    // Teste 3: Busca de Mercadorias
    HT.searchItem(332);

    // Teste 4: Verificação de Tabela Vazia
    if (HT.isEmpty())
        cout << "\nA tabela Hash está vazia." << endl;
    else
        cout << "\nA tabela Hash não está vazia." << endl;

    // Teste 5: Verificação de Colisão
    HT.collisionTest();

    return 0;
}