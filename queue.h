#include "Node.h"

template <class T> 
class queue{
    public: 
        queue();
        ~queue();

        void push(T data);
        void pop();
        T front();
        bool empty();
        int size();

    private: 
        Node<T> *fin;
        int tam;
};

//Constructor
template <class T> 
queue<T>::queue(){
    fin = NULL;
    tam = 0;
}

template <class T> 
queue<T>::~queue(){
    if(fin != NULL){
        Node<T> *aux = fin->getNext();
        fin->setNext(NULL);
        fin = aux;
        while(fin!=NULL){
            fin = fin->getNext();
            delete aux;
            aux = fin;
        }
    }
}

template <class T> 
void queue<T>::push(T data){
    if(fin == NULL){ //to check if queue is empty
        fin = new Node<T>(data);
        fin->setNext(fin);
    }else{
        fin->setNext(new Node<T>(data,fin->getNext()));
        fin = fin->getNext();
    }
    tam++;
}

template <class T> 
void queue<T>::pop(){
    Node<T> *aux = fin->getNext();
    if(aux==fin){
        fin=NULL;
    }else{
        fin->setNext(aux->getNext());
    }
    delete aux;
    tam--;
}

template <class T> 
T queue<T>::front(){
    return fin->getNext()->getData();
}

template <class T> 
int queue<T>::size(){
    return tam;
}

template <class T> 
bool queue<T>::empty(){
    return (fin == NULL);
}

