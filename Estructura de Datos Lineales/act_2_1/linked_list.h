//Descripción: Programa que crea listas enlazadas a través de punteros y utiliza funciones para manipular valores dentro de esta lista
//Autor: Diego Mejía Suárez - A01024228
//Fecha de Creación: 29/09/2020
//Fecha de Modificación: 01/10/2020

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <bits/stdc++.h>

using namespace std;

//clase Nodo que tiene como atributos su valor y el puntero al siguiente valor, con métodos que obtiene
//y define siguiente puntero, y el valor en el puntero
template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext){
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;}
    Node<T> *get_next() {return next;}
    void set_next(Node<T> *pNext) {next = pNext;}
};

//clase LinkedList que tiene como atributo el nodo head para definir el inicio de la lista
template <class T>
class LinkedList{

private:
    Node<T> *head;
public:
    ~LinkedList(){}
    LinkedList(){head = NULL;}

    //FUNCIÓN 1
    //función que cuenta cuantas veces aparece un número en la lista y regresa el número de veces que este
    // es encontrado
    //O(n)
    int Count(T searchFor){
        Node<T> *ptr = head;
        int counter = 0;
        while (ptr != NULL){
            //aumentar el contador si se encuentra el valor
            if(ptr->get_val() == searchFor){
                counter++;
            }
            ptr = ptr->get_next();
            }
        return counter;
    }
    
    //FUNCIÓN 2
    //función que borra cada nodo de la lista y libera la memoria de cada uno en el proceso
    //O(n)
    void DeleteList(){
        int listLength = length();
        if(listLength != 0){
            //ciclo que se repite las veces del tamaño de la lista que elimina el primer nodo de la lista
            for(size_t i=0;i<listLength;i++){
                delete_item(0);
            }
        }
    }
    
    //FUNCIÓN 3
    //función que toma un nodo y lo acomoda en una lista ordenada de acuerdo a su valor
    //O(n)
    void SortedInsert(Node<T> *newNode){
        int listLength = length();
        T pVal = newNode->get_val();
        //solo si la lista tiene elementos
        if(listLength != 0){
            Node<T> *ptr = head;
            int counter = 0;
            //si el valor es menor que el primer elemento de la lista
            if(pVal < ptr->get_val()){
                push(pVal);
            }
            else{
                while(ptr != NULL){
                    //colocar el elemento en la posición con la que se comparó utilizando el contador
                    if(pVal <= ptr->get_val()){
                        insert_item(pVal,counter);
                        break;
                    }
                    //moverse de puntero y aumentar contador si no se cumple lo anterior
                    ptr = ptr->get_next();
                    counter++;
                }
            }
            //si se llega al final de la lista, poner el elemento en la última posición de la lista
            if(counter == listLength){
                insert_item(pVal,listLength);
            }
        }
        //si la lista está vacía
        else{
            push(pVal);
        }
    }

    //FUNCIÓN 4
    //función que borra todos los elementos de la lista ordenada que se duplican
    //O(n)
    void RemoveDuplicates(){
        int listLength = length();
        //solo si la lista tiene más de un elemento
        if(listLength > 1){
            Node<T> *ptr = head;
            Node<T> *nextOfNext = NULL;
            while(ptr->get_next() != NULL){
                //si el siguiente valor es el mismo que el actual
                if(ptr->get_val() == (ptr->get_next()->get_val())){
                    //guardar el siguiente siguiente valor, y liberar memoria del siguiente
                    nextOfNext = (ptr->get_next())->get_next();
                    free(ptr->get_next());
                    //definir el siguiente como siguiente siguiente
                    ptr->set_next(nextOfNext);
                }
                //solo avanzar al siguiente puntero si no se encuentran más valores duplicados
                else{
                    ptr = ptr->get_next();
                }
            }
        }
    }
    
    //FUNCIÓN 5
    //función que invierte las posiciones de los elementos de la lista ordenada
    //O(n)
    void Reverse(){
        Node<T> *ptr = head;
        int listLength = length();
        //solo si la lista tiene más de un elemento
        if(listLength > 1){
            Node<T> *ptr = head;
            Node<T> *pre = NULL;
            Node<T> *next = NULL;
            while(ptr != NULL){
                //guardar el siguiente, e igualar el siguiente al anterior
                next = ptr->get_next();
                ptr->set_next(pre);
                //igualar el anterior al apuntador, y el apuntador al siguiente para seguir con el ciclo
                pre = ptr;
                ptr = next;
            }
            //como último paso, igualar el head al anterior
            head = pre;
        }
    }

    void print(){
        if(length() != 0){
            Node<T> *ptr = head;
            while (ptr != NULL){
                cout << ptr->get_val() << "  ";
                ptr = ptr->get_next();
                }
            cout << std::endl;
        }
        else{
            cout << "(empty list)" << endl;
        }
    }
    
    void push(T pVal){
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    }

    int length(){
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL){
            length++;
            ptr = ptr->get_next();
        }
        return length;
    }

    void delete_item(int index){
        if (head == NULL || index >= length() || index < 0)
            return;
        if (index == 0){
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            return;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL && index > i){
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
    };

    void insert_item(T pVal, int index)
    {
        if (index > length() || index < 0)
            return;
        if (index == 0){
            push(pVal);
            return;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL && index > i){
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        Node<T> *node = new Node<T>(pVal, ptr);
        pre->set_next(node);
    };
};

#endif
