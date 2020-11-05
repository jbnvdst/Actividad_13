#ifndef ARREGLODINAMICO_H_INCLUDED
#define ARREGLODINAMICO_H_INCLUDED

#include <iostream>
using namespace std;

template <class T>
class ArregloDinamico
{
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX =5;

public:
    ArregloDinamico();
    ~ArregloDinamico();
    void insertar_inicio(const T& s);
    void insertar_final(const T& s);
    void insertar(const T& s, size_t p);


    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);

    T* buscar(const T& s);
    ArregloDinamico<T*> buscar_todos(const T& s);

    size_t size();

    T operator[](size_t p)
    {
        return arreglo[p];
    }

    friend ArregloDinamico<T>& operator<<(ArregloDinamico<T> &a, const T& v)
    {
        a.insertar_final(v);

        return a;
    }

private:
    void expandir();
};

template <class T>
ArregloDinamico<T>::ArregloDinamico()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico()
{
    delete[] arreglo;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T& s)
{
    if(cont = tam)
    {
        expandir();
    }
    for(size_t i = cont; i > 0; i--)
    {
        arreglo[i+1] = arreglo[i-1];
    }
    arreglo[0] = s;
    cont ++;
}

template <class T>
void ArregloDinamico<T>::insertar_final(const T& s)
{
    if(cont == tam)
    {
        expandir();
    }
    arreglo[cont] = s;
    cont++;
}

template <class T>
void ArregloDinamico<T>::expandir()
{
    T *nuevo = new T[tam+MAX];

    for(size_t i = 0; i < cont; i++)
    {
        nuevo[i] = arreglo[i];
    }

    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

template <class T>
size_t ArregloDinamico<T>::size()
{
    return cont;
}

template <class T>
void ArregloDinamico<T>::insertar(const T& s, size_t p)
{
    if(p >= cont)
    {
        cout << "Posicion no v�lida" << endl;
        return;
    }

    if(cont == tam)
    {
        expandir();
    }

    for(size_t i = cont; i > p; i--)
    {
        arreglo[i] = arreglo[i-1];
    }

    arreglo[p] = s;
    cont++;
}

template<class T>
void ArregloDinamico<T>::eliminar_final()
{
    if (cont == 0)
    {
        cout << "Arreglo vac�o" << endl;
        return;
    }

    cont --;
}

template<class T>
void ArregloDinamico<T>::eliminar_inicio()
{
    if (cont == 0)
    {
        cout << "Arreglo vac�o" << endl;
        return;
    }

    for(size_t i = 0; i < cont-1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }

    cont --;
}

template<class T>
void ArregloDinamico<T>::eliminar(size_t p)
{
    if (cont == 0)
    {
        cout << "Arreglo vac�o" << endl;
        return;
    }

    for(size_t i = p; i < cont - 1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }

    cont--;
}

template <class T>
T* ArregloDinamico<T>::buscar(const T& s)
{
    for(size_t i = 0; i < cont; i++)
    {
        if(s == arreglo[i])
        {
            return &arreglo[i];
        }
    }

    return nullptr;
}

template <class T>
ArregloDinamico<T*> ArregloDinamico<T>::buscar_todos(const T& s)
{
    ArregloDinamico<T*> ptrs;

    for(size_t i = 0; i < cont; i++)
    {
        if(s == arreglo[i])
        {
            ptrs.insertar_final(&arreglo[i]);
        }
    }

    return ptrs;
}



#endif // ARREGLODINAMICO_H_INCLUDED
