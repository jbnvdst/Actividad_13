#ifndef computadora_h
#define computadora_h

#include <iostream>
#include <iomanip>

using namespace std;

class computadora
{
private:
    string sistema_operativo;
    string memoria_ram;
    string memoria_interna;
    string marca;

public:
    computadora();
    computadora(const string &sistema_operativo, const string &memoria_ram, const string &memoria_interna, const string marca);

    void setSitema(const string &a);
    string getSistema();

    void setRam(const string &a);
    string getRam();

    void setMemoria(const string &a);
    string getMemoria();

    void setMarca(const string &a);
    string getMarca();

    friend ostream& operator<<(ostream &out, const computadora &z)
    {
        out << left;
        out << setw(10) << z.sistema_operativo;
        out << setw(6) << z.memoria_ram;
        out << setw(6) << z.memoria_interna;
        out << setw(10) << z.marca;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in, computadora &z)
    {
        //string temp;

        cout << "Sistema Operativo:";
        getline(cin, z.sistema_operativo);

        cout << "Memoria Ram:";
        getline(cin, z.memoria_ram);

        cout << "Memoria Interna:";
        getline(cin, z.memoria_interna);

        cout << "Marca:";
        getline(cin, z.marca);

        return in;
    }

    bool operator==(const computadora& z)
    {
        return sistema_operativo == z.sistema_operativo;
    }

    bool operator==(const computadora& z) const
    {
        return sistema_operativo == z.sistema_operativo;
    }

};

#endif //computadora_h
