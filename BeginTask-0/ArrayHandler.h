//Andrey chert
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    size_t _min;
    size_t _max;
    size_t count;
public:
    ArrayHandler(size_t size = 10) {
        _size = size;
        _array = new T[_size];
        _max = 0;
        _min = 100000001;
        count = 0;
    }

    void AppendElem(T elem) {
        if (count == _size){
            T* array_2 = new T [_size * 10];
            for (size_t i = 0; i < count; i ++){
                array_2[i] = _array[i];
            }
            delete [] _array;
            _array = array_2;
        }
        _array[count] = elem;
        count ++;
        if (_min > elem){
            _min = elem;
        }

        else if (_max < elem){
            _max = elem;
        }
    }

    bool IsContains(T elem) {
        return false;
    }

    T GetMax() {
        return _max;
    }

    T GetMin() {
        return _min;
    }

    ~ArrayHandler() {
        delete [] _array;
    }

};