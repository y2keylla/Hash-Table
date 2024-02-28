// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract Idade {

    // Variável para a idade 
    uint public idade;

    // Variável para o endereço do dono do contrato
    address private donoContrato;

    // Modificador para restringir o acesso as funções apenas para o dono do contrato
    modifier apenasDono() {
        require(msg.sender == donoContrato, "Apenas o dono do contrato pode realizar esta operacao");
        _;
    }

    // Construtor que define o dono como o endereço (carteira) que implantou o contrato
    constructor() {
        idade = 18;
        donoContrato = msg.sender;
    }

    // Função para definir a idade (acessível apenas para o dono do contrato)
    function setIdade(uint novaIdade) public apenasDono {
        idade = novaIdade;
    }

    // Função para ler/ver a idade (consulta)
    function getIdade() public view returns (uint) apenasDono {
        return idade;
    }
}
