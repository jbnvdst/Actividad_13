#include "computadora.h"


computadora::computadora(const string &sistema_operativo, const string &memoria_ram, const string &memoria_interna, const string marca)
{
    this->sistema_operativo = sistema_operativo;
    this->memoria_ram = memoria_ram;
    this->memoria_interna = memoria_interna;
    this->marca = marca;
}

void computadora::setSitema(const string &a)
{
    sistema_operativo = a;
}

string computadora::getSistema()
{
    return sistema_operativo;
}

void computadora::setRam(const string &b)
{
    memoria_ram = b;
}

string computadora::getRam()
{
    return memoria_ram;
}

void computadora::setMemoria(const string &c)
{
    memoria_interna = c;
}

string computadora::getMemoria()
{
    return memoria_interna;
}

void computadora::setMarca(const string &d)
{
    marca = d;
}

string computadora::getMarca()
{
    return marca;
}
