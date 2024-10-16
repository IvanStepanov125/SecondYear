#include "BitField.h"
#include "vector"

class Set{
    private:
        BitField _bitField;
        size_t _maxPower;
    public:
        Set(size_t mp);
        Set(const Set& set);
        Set(const BitField& bf);
        operator BitField(); //?

        size_t GetMaxPower();
        void InsertElem(uint64_t elem);
        void DeleteElem(uint64_t elem);
        bool IsMember(uint64_t elem);
        std::vector<uint64_t> GetPrimary();

        bool operator==(const Set& tmp);
        Set& operator=(const Set& tmp);
        Set& operator+(const Set& tmp); //объединение двух множеств
        Set& operator+(uint64_t elem); //добавление элемента
        Set& operator-(uint64_t elem); //удаление элемента
        Set& operator*(const Set& tmp); //пересечене двух множеств
        Set& operator~();//дополнение

        friend std::istream& operator>>(std::istream istr, Set& set);
        
        friend std::ostream& operator<<(std::ostream ostr, Set& set);

};