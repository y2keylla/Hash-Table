# Documentação Casos de Teste

## Teste 1: Inserção de Mercadorias

### Descrição:
Inserir mercadorias na tabela hash e verificar se elas são inseridas corretamente.

### Passos:
1. Inserir as mercadorias "Caneta BIC", "Caderno" e "Lápis" na tabela hash.
2. Exibir a tabela hash após a inserção das mercadorias.

### Resultado Esperado:
- As mercadorias devem ser inseridas na tabela hash.
- As informações das mercadorias inseridas devem ser corretamente associadas às chaves correspondentes na tabela hash.

### Resultado Real:
- As mercadorias foram inseridas na tabela hash.
- As informações das mercadorias estão corretamente associadas às chaves correspondentes na tabela hash.

## Teste 2: Remoção de Mercadorias

### Descrição:
Remover uma mercadoria da tabela hash e verificar se a remoção é bem-sucedida.

### Passos:
1. Inserir algumas mercadorias na tabela hash.
2. Remover a mercadoria com a chave 201 (caderno) da tabela hash.
3. Exibir a tabela hash após a remoção.

### Resultado Esperado:
- A mercadoria com a chave 201 (caderno) deve ser removida.
- As outras mercadorias devem permanecer na tabela hash.

### Resultado Real:
- A mercadoria com a chave 201 (caderno) foi removida corretamente.
- As outras mercadorias permaneceram na tabela hash após a remoção.

## Teste 3: Busca de Mercadorias

### Descrição:
Buscar uma mercadoria na tabela hash e verificar se ela é encontrada.

### Passos:
1. Inserir algumas mercadorias na tabela hash.
2. Buscar a mercadoria com a chave 332 (lápis) na tabela hash.

### Resultado Esperado:
- A mercadoria com a chave 332 (lápis) deve ser encontrada na tabela hash.
- O nome da mercadoria deve ser exibido após a busca.

### Resultado Real:
- A mercadoria com a chave 332 (lápis) foi encontrada na tabela hash.
- O nome da mercadoria foi exibido após a busca.

## Teste 4: Verificação de Tabela Vazia

### Descrição:
Verificar se a função `isEmpty` retorna corretamente se a tabela hash está vazia ou não.

### Passos:
1. Criar uma tabela hash vazia.
2. Verificar se a tabela hash está vazia usando a função `isEmpty`.
3. Inserir algumas mercadorias na tabela hash.
4. Verificar novamente se a tabela hash está vazia usando a função `isEmpty`.

### Resultado Esperado:
- A função `isEmpty` deve retornar verdadeiro quando a tabela hash estiver vazia e falso quando houver mercadorias na tabela.
- A mensagem "A tabela Hash está vazia." deve ser exibida se a tabela estiver vazia, e "A tabela Hash não está vazia." se houver mercadorias na tabela.

### Resultado Real:
- A função `isEmpty` retornou verdadeiro quando a tabela hash estava vazia e falso após a inserção de mercadorias, conforme esperado.
- A mensagem "A tabela Hash está vazia." foi exibida quando a tabela estava vazia, e "A tabela Hash não está vazia." após a inserção de mercadorias.

## Teste 5: Verificação de Colisão

### Descrição:
Verificar se a tabela hash lida corretamente com a situação de colisão, ou seja, quando duas chaves diferentes resultam no mesmo índice hash.

### Passos:
1. Inserir uma mercadoria na tabela hash com uma chave que resulte no mesmo índice hash de uma mercadoria já existente.
2. Inserir outra mercadoria com uma chave diferente que resulte no mesmo índice hash, causando colisão.
3. Verificar se ambas as mercadorias estão presentes na mesma lista encadeada correspondente ao índice hash.

### Resultados Esperados:
- A tabela hash deve lidar corretamente com a colisão, inserindo ambas as mercadorias na mesma lista encadeada correspondente ao índice hash.
- As duas mercadorias devem ser encontradas na mesma lista encadeada e associadas a chaves diferentes.

### Resultados Reais:
- As duas mercadorias foram inseridas corretamente na mesma lista encadeada correspondente ao índice hash com colisão.
- As duas mercadorias foram encontradas na mesma lista encadeada e associadas a chaves diferentes, indicando que a tabela hash lidou corretamente com a colisão.