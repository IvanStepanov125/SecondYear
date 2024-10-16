#include "Set.h"
#include "cmath"

Set::Set(size_t mp) : _bitField(mp){
    _maxPower = mp;
}

Set::Set(const Set& set) : _bitField(set._maxPower){
    _maxPower = set._maxPower;
    _bitField = BitField(set._bitField);
}

Set::Set(const BitField& bf) : _bitField(bf){
    _maxPower = bf.GetLength();
}

size_t Set::GetMaxPower(){
    return _maxPower;
}

void Set::InsertElem(uint64_t elem){ //Проверка нужна
    _bitField.SetBit(elem);
}

void Set::DeleteElem(uint64_t elem){ //Проверка нужна
    _bitField.ClrBit(elem);
}

bool Set::IsMember(uint64_t elem){
    return _bitField.GetBit(elem);
}

std::vector<uint64_t> Set::GetPrimary(){
    Set tmp(*this);
    size_t n = GetMaxPower(), qn = static_cast<size_t> (sqrt (n)) + 1;
    
    for (size_t i = 2; i < qn; i ++){
        if (i != 0){
            for (size_t j = i + i; j < n; j += i){
                tmp._bitField.ClrBit(j);
                }
            }
    }
    std::vector<size_t> res;
    for (size_t i = 2; i < n; i++){
        if (tmp._bitField.GetBit(i)){
            res.push_back(i);
        }
    }
    return res;
}