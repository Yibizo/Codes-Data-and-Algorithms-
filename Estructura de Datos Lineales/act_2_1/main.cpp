//Descripción: Implementación del header linked_list.h con diversos casos prueba
//Autor: Diego Mejía Suárez - A01024228
//Fecha de Creación: 29/09/2020
//Fecha de Modificación: 02/10/2020

#include "linked_list.h"

using namespace std;

int main(){

    //creación del objeto lista y agregación de valores a la lista
    LinkedList<int> list;
    list.push(56);
    list.push(48);
    list.push(42);
    list.push(10);
    list.push(10);
    list.push(3);
    list.push(3);
    cout << "Current list:" << endl;
    list.print();

    //Contar por el número 10 que se repite 2 veces
    cout << "Count for 10:\n" << list.Count(10) << endl;
    //Contar por el número 42 que se repite 1 vez
    cout << "Count for 42:\n" << list.Count(42) << endl;
    //Contar por el número 100 que no se repite
    cout << "Count for 100:\n" << list.Count(100) << endl;

    //Insertar el nodo con el valor de 1, que va al inicio de la lista
    cout << "Sorted insert number 1:" << endl;
    Node<int> *node1 = new Node<int>(1, NULL);
    list.SortedInsert(node1);
    list.print();

    //Insertar el nodo con el valor de 40, que va en medio de la lista
    cout << "Sorted insert number 40:" << endl;
    Node<int> *node40 = new Node<int>(40, NULL);
    list.SortedInsert(node40);
    list.print();

    //Insertar el nodo con el valor de 100, que va al final de la lista
    cout << "Sorted insert number 100:" << endl;
    Node<int> *node100 = new Node<int>(100, NULL);
    list.SortedInsert(node100);
    list.print();

    //Quitar nodos con valores que se duplican
    cout << "Remove duplicates:" << endl;
    list.RemoveDuplicates();
    list.print();

    //revertir el orden de los valores de la lista
    cout << "Reverse:" << endl;
    list.Reverse();
    list.print();
    
    //borrar todos los nodos de la lista hasta que head apunte a NULL
    cout << "Delete list and free memory:" << endl;
    list.DeleteList();
    list.print();

    //Insertar el nodo con el valor de 100 si la lista está vacía
    Node<int> *node101 = new Node<int>(101, NULL);
    list.SortedInsert(node101);
    list.print();
}
