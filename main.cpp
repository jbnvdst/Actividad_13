#include <iostream>
#include "ArregloDinamico.h"
#include "computadora.h"

using namespace std;

int main()
{
    ArregloDinamico<computadora> computadoras;

    computadora z01("Windows", "8GB", "1TB", "DELL");
    computadora z02("Linux", "12GB", "3TB", "LENOVO");
    computadora z03("Windows", "8GB", "1TB", "DELL");

    computadoras << z01 << z02 << z03 << << z02 << z02;
    computadora z04("Windows", "8GB", "1TB", "DELL");

    ArregloDinamico<computadora*> ptrs = computadoras.buscar_todos(z04);

    if (ptrs.size() > 0)
    {
        for(size_t i = 0; i < ptrs.size(); i++)
        {
            computadora *z = ptrs[i];
            cout << *z << endl;
        }
    }
    else
    {
        cout << "No existen coincidencias" << endl;
    }

    //computadora *ptr = computadoras.buscar(z04);

    //cout << ptr << endl;

    /*ArregloDinamico<int> arreglo;

    for (size_t i = 0; i < 10; i++)
    {
        arreglo.insertar_final(i);
    }

    arreglo.insertar(5, 2);

    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    arreglo.eliminar(1);


    for(size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;

    int *s = arreglo.buscar(2);
    cout << s << " " << *s << endl;
    *s = 20;
    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;*/

    return 0;
}
