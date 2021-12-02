#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&);
	~DList();

	void insertion(T);
	void deleteAt(int);
	void update(int,T);
	T  search(T);
	int  length() const;
	bool contains(T) const;
	bool empty() const;
	void clear();
	string toStringForward() const;
	string toStringBackward()const;
	
	

private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}


template <class T>
int DList<T>::length() const {
	return size;
}


template <class T>
bool DList<T>::contains(T val) const {
	DLink<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}


template <class T>
void DList<T>::insertion(T val){
	
	DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
T DList<T>::search(T val){
	
	
	int cont=0;
	DLink<T> *p;
	
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
void DList<T>::update(int itr, T val)  {
	

	int cont=0;
	
	DLink<T>  *p;
	
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
void DList<T>::deleteAt(int itr){


	int cont=0;
	
	DLink<T> *p, *q;
	p=head;
	q=NULL;
	
		
		while ((cont !=itr)&&(p!=NULL)){
			q=p;
			p=p->next;
			cont++;
		}
		
		
		if(q==NULL){
			head=head->next;
			p->next->previous=0;
			delete p;
		}
		

		else{
				
			q->next= p->next;
			p->next->previous=q;
			delete p;
		}
		
		size--;		
}
	
		




template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	DLink<T> *p;
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
	
template <class T>
string DList<T>::toStringBackward() const {
	stringstream aux;
	DLink<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}





