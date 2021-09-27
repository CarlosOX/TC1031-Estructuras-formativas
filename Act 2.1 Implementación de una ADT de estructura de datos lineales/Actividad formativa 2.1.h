#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val): value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt): value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source): value(source.value), next(source.next) {}




template <class T>
class List {
public:
	List();
	List(const List<T>&);
	~List();

	void insertion(T);
	void addFirst(T);
	void update(int,T);
	T search(T);
	void deleteAt(int);
	bool empty() const;
	void clear();
	string toString() const;
	
private:
	Link<T> *head;
	int 	size;
	
};


template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}



template <class T>
void List<T>::addFirst(T val)  {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}


template <class T>
void List<T>::insertion(T val)  {
	
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);

	if (empty()) {
		addFirst(val);
		return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
	
}


template <class T>
void List<T>::update(int itr, T val)  {
	
	int cont=0;
	
	Link<T>  *p;
	
	p=head;
	
	if(itr==0){
		head->value=val;
	}
	
	while(cont != itr){
		p=p->next;
		cont++;
	}
	
	p->value =val;
		
}

template <class T>
T List<T>::search(T val) {
	
	int cont=0;
	Link<T> *p;
	
	p=head;
	
	while(p->value!= val){
		p=p->next;
		cont++;
		
		if(p->next==0){
			if(p->value==val){
				return cont;
			}
			else{
				return -1;
			}
		}
		
		
	}
	
	return cont;
}


template <class T>
void List<T>::deleteAt(int itr){
	int cont=0;
	
	
	Link<T> *p, *q;
	p=head;
	q=NULL;
	
	while ((cont !=itr)&&(p!=NULL)){
		q=p;
		p=p->next;
		cont++;
	}
	
	
	if(q==NULL){
		head=head->next;
		delete p;
	}
	
	
	else{
		q->next= p->next;
		delete p;
	}
	
	size--;	
}



template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}



		



