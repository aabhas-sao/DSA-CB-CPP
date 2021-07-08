template<typename T>
class vector {
    int cs;
    int ms;
    T * arr;

    public:
    vector() {
        cs = 0; 
        ms = 1;
        arr = new int[ms];
    }

    void push_back(T data);
    void display();
    int container();
    int size();
    void pop_back();

};


template<typename T>
void vector<T>::push_back(T data) {
    if(cs == ms) {
        T* oldArr = arr;
        ms = 2 * ms;
        arr = new int[ms];
        arr = oldArr; // these lines are sketchy
    }
    arr[cs] = data;
    cs++;
}

template<typename T>
void vector<T>::display() {
    for(int i = 0; i < cs; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
int vector<T>::container() {
    return ms;
}

template<typename T>
int vector<T>::size() {
    return cs;
}

template<typename T>
void vector<T>::pop_back() {
    cs--;
}