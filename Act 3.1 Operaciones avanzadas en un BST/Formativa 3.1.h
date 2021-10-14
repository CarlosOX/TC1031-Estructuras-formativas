#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>


using namespace std;

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	int level;
	Node *left, *right;

	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*,int);
	void add(T);
	bool find(T);
	void removeChilds();
	void preorder(stringstream&) const;
	void inorder(stringstream&) const;
	void postorder(stringstream&) const;
	void levelbylevel(stringstream&) const;
	int height();	
	void ancestors(T,stringstream&) const;
	int whatlevelamI(T);
	

	friend class BST<T>;
};


template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), level(1){}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, int lev)
	: value(val), left(le), right(ri), level(lev) {}
	
	
	
template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
void Node<T>::inorder(stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	
	if (aux.tellp()!=1){
		aux<<" ";
		
	}
	
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
	}
	if (right != 0) {
		right->postorder(aux);
	}
	aux << value;
	if (aux.tellp()!=1){
		aux<<" ";
	}

}


 /*
template <class T>
void Node<T>::levelbylevel(stringstream &aux) const {
	
	

		
}

*/

//ESTA
template <class T>
int Node<T>::height(){
	

	int alturaizq,alturader;
	
	if(left == NULL && right == NULL){
		return 1;
	}
	
	if(left != NULL){
		alturaizq=left->height();
	}
	
	if(right != NULL){
		alturader=right->height();
		
	}

	return (max(alturaizq,alturader)+1);
}

/*
template <class T>
void Node<T>::ancestors(T,stringstream &aux) const{

	if(val==value){
		return 
	}


}

*/



template <class T>
int Node<T>::whatlevelamI(T val) {

	if (value ==val) {
		return level;
	}
	else if (val < value) {
		level++;
		left->whatlevelamI(val);
		
	} 
	
	else if (val > value) {
		
		level++;
		right->whatlevelamI(val);
	}
	
}



template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}







//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX//

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void removeAll();
	string visit() const;
	int height();
	string ancestors(T) const;
	int whatlevelamI(T);
	
	

};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}


template<class T>
string BST<T>::visit() const{
	
	stringstream aux;

	aux <<"[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux <<"]";
	
	aux<<"\n";
	
	aux<<"[";
	if (!empty()){
		root->inorder(aux);
	}
	aux<<"]";
	
	aux<<"\n";
	
	aux<<"[";
	if(!empty()){
		root->postorder(aux);
	}
	aux<<"]";
	
	return aux.str();
	
}





template <class T>
int BST<T>::height() {	

	if (root != 0) {
		root->height();
	}
	
	else{
		return -1;
	}
}


/*
template <class T>
string BST<T>::ancestors(val){
	
	
}
*/

template <class T>
int BST<T>::whatlevelamI(T val) {
	if (root !=0){
		root->whatlevelamI(val);
	}
	else{
		return -1;
	}
	
	
}



template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}


	
