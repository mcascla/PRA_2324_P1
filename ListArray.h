#include <iostream>
#include <algorithm>
#include <iterator>
#include "List.h"

using namespace std;
template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
		T arr1 = new T[new_size];
		int i;
		for(i=0;i<max;i++)
			arr1[i]=arr[i];
		delete []arr;
		arr = arr1; // arr no se ha borrado, si no que se ha quedado apuntando a null
		max = new_size;
	}

    public:
	ListArray(){
		this->arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
	}
	~ListArray(){
		delete []arr;
	}
	T operator[](int pos){
		if(pos < 0 || pos > n)
			throw out_of_range("Posicion no valida");
		else
			return arr[pos];
	}
        friend std::ostream& operator<<(ostream &out, const ListArray<T> &list){
		out << list.arr;
		return out;
	}

	void insert(int pos, T e){
		if(pos<0 || pos > size()-1)
			throw out_of_range ("Posicion no valida");
		arr[pos] = e;
	}

	void append(T e){
		arr[size()-1] = e;
	}

	void prepend(T e){
	arr[0] = e;
	}

	T remove(int pos){
		T ret;
		if(pos<0 || pos > size()-1)
			throw out_of_range("Posicion no valida");
		ret = arr[pos];
		//arr[pos] = nullptr;
		
		n--;
		return ret;
	}

	T get(int pos){
		if(pos<0 || pos > size()-1)
                        throw out_of_range("Posicion no valida");
		return arr[pos];		
	}

	int search(T e){
		int i;
		do{
		   i++;
		}while(arr[i] != e);

		if(i>size()-1)
			return -1;
		else
			return i;
	}

	bool empty(){
		if(n==0)
			return true;
		else
			return false;
	}

	int size(){
		return n;
	}
    
};
