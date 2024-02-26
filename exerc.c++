#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class ContaBancaria {
public:
    static bool verificarSaldoSuficiente(double valor) {
        // Implemente a lógica de verificação de saldo aqui
        return true;
    }
};

aspect SaldoInsuficienteAspect {
    before() : execution("ContaBancaria::sacar(double)") {
        double valor = 0.0; // Obtenha o valor do saque
        if (valor > 0 && !ContaBancaria::verificarSaldoSuficiente(valor)) {
            throw std::runtime_error("Saldo insuficiente para sacar " + std::to_string(valor));
        }
    }
};
