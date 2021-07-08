#include <iostream>
#include<cstring>
using namespace std;

template <typename T>
class Node {
public:
	string key;
	T data;
	Node<T>* next;

	Node(string key, T val) {
		this->key = key;
		data = val;
		next = NULL; 
	}
	~Node() {
		if(next != NULL) {
			delete next;
		}
	}
};
// return sum of two numbers 

template <typename T>
class HashTable {
private:
	Node<T>** table;
	int current_size;
	int table_size;

	int hashFunction(string key) {
		int hash = 0;
		int p = 1;
		for(int i = 0; i < key.length(); i++) {
			hash += (key[i] * p)%table_size;
			hash %= table_size;
			p = (p * 27) % table_size;
		}
		return hash;
	}

	bool isPrime(int n) {
		if(n == 0 || n == 1) return false;
		if(n == 2) return true;
		if(n % 2 == 0) return false;
		for(int i = 3; i * i <= n; i++) {
			if(n % i == 0) return false;
		}

		return true;
	}

	int nextPrime(int n) {
		int ts = n;
		while(true) {
			n++;
			if(isPrime(n) == true && n >= 2 * ts) {
				break;
			}
		}
		return n;
	}

	void rehash() {
		Node<T>** oldTable = table;
		int oldTableSize = table_size;
		table_size = nextPrime(table_size);

		// create a new table of size of next prime number and initialize with NULL
		table = new Node<T>*[table_size];
		
		for(int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}

		current_size = 0;

		// rehash and place elements from older table to newer table
		for(int i = 0; i < oldTableSize; i++) {
			Node<T>* head = oldTable[i];
			while(head != NULL) {
				insert(head->key, head->data);
				head = head->next;
			}
			if(oldTable[i] != NULL) {
				delete oldTable[i];
			}
		}

		delete [] oldTable;
	}

public:
	HashTable(int ts = 7) {
		table_size = ts;
		table = new Node<T>*[table_size];

		for(int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}

		current_size = 0;
	}

	T& operator[](string key) {
		T* f = search(key);
		if(f == NULL) {
			T garbage;
			insert(key, garbage);
			f = search(key);
		}
		return *f;
	}

	void insert(string key, T t) {
		int idx = hashFunction(key);
		Node<T>* head = table[idx];
		Node<T>* newNode = new Node<T>(key, t);

		newNode->next = head;
		table[idx] = newNode;
		
		current_size++;
		float loadFactor = current_size / (1.0 * table_size);
		if(loadFactor > 0.7) {
			rehash();
		}
	}

	void print() {
		for(int i = 0; i < table_size; i++) {
			Node<T>* head = table[i];
			cout << "Bucket" << " " << i << " ";
			while(head != NULL) {
				cout << head->key << " -> ";
				cout << head->data << " ";
				head = head->next;
			}
			cout << endl;
		}
	}

	T* search(string key) {
		int idx = hashFunction(key);
		Node<T>* head = table[idx];
		while(head != NULL) {
			if(key == head->key) {
				return &head->data;
			}
			head = head->next;
		}
		return NULL;
	}

	void erase(string key) {
		int idx = hashFunction(key);
		Node<T>* temp = table[idx];
		
		if(temp == NULL) return;

		if(temp->key == key) {
			Node<T>* toD = temp;
			table[idx] = temp->next;
			toD->next = NULL;
			delete toD;
			return;
		}

		while(temp->next != NULL && temp->next->key != key) {
			temp = temp->next;
		}
		Node<T>* toD = temp->next;
		temp->next = toD->next;
		toD->next = NULL;
		delete toD;
	}
};