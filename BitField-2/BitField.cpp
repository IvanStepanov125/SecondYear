#include "BitField.h"

size_t BitField::GetMemIndex(size_t n) const{
    if (n >= _sizeBit)
        throw "Bit out of range!";
    return n / (8 * sizeof(uint16_t));
}
uint16_t BitField::GetMask(size_t n) const {
     return 1 << (n % (8 * sizeof(uint16_t)));
}

BitField::BitField(size_t len) {
    _sizeBit = len;
    _memSize = (len / (8 * sizeof(uint16_t))) + (len % (8 * sizeof(uint16_t)) != 0);
    _mem = new uint16_t[_memSize];
    std::memset(_mem,0, _memSize);
    // for (size_t i = 0; i < _memSize; ++i)
    //     _mem[i] = 0;
}

BitField::BitField(const BitField& tmp) {
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = new uint16_t[_memSize];
    std::memcpy(_mem, tmp._mem, _memSize*sizeof(uint16_t));
    // for (size_t i = 0; i < _memSize; ++i)
    //     _mem[i] = tmp._mem[i];
}

BitField::BitField(const BitField&& tmp){
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = tmp._mem;
}

BitField& BitField::operator=(const BitField& tmp) {
    if (_sizeBit != tmp._sizeBit){
        delete [] _mem;
        _sizeBit = tmp._sizeBit;
        _memSize = tmp._memSize;
        _mem = new uint16_t[_memSize];
    }
    std::memcpy(_mem, tmp._mem, _memSize*sizeof(uint16_t));
    //for (size_t i = 0; i < _memSize; ++i)
    //    _mem[i] = tmp._mem[i];
    return *this;
}

BitField& BitField::operator=(const BitField&& tmp){
    _sizeBit = tmp._sizeBit;
    _memSize = tmp._memSize;
    _mem = tmp._mem;
    return *this;
}
    

void BitField::SetBit(size_t n) {
    // if (n >= _sizeBit)
    //     throw "Bit out of range!";
    _mem[GetMemIndex(n)] |= GetMask(n);
}
void BitField::ClrBit(size_t n) {
    _mem[GetMemIndex(n)] &= ~GetMask(n);
}
uint8_t BitField::GetBit(size_t n) const {
    // if (n >= _sizeBit){
    //     throw "PSHNH Bit out of range";
    // }
    return ((_mem[GetMemIndex(n)] & GetMask(n)) != 0);
}
BitField BitField::operator|(const BitField& tmp) {
    BitField B(*this);
    
    for (size_t i=0; i < _memSize; i++){
        B._mem[i] = _mem[i] | tmp._mem[i];
    }
    return B;
}

BitField BitField::operator&(const BitField& tmp) {
    BitField B(*this);
    
    for (size_t i=0; i < _memSize; i++){
        B._mem[i] &= tmp._mem[i];
    }
    return B;
}
BitField BitField::operator^(const BitField& tmp) {
    BitField B(*this);
    
    for (size_t i=0; i < _memSize; i++){
        B._mem[i] ^= tmp._mem[i];
    }
    return B;
}

bool BitField::operator==(const BitField& tmp) const{
    // if(_sizeBit != tmp._sizeBit){
    //     return false;
    // }
    for(size_t i = 0; i < _memSize; i++){
        if(_mem[i] != tmp._mem[i]){
            return false;
        }
    }
    return true;
}

BitField BitField::operator~(){ //размеры битовых полей могут быть разными
    BitField res = BitField(*this);
    for (int i = 0; i < _sizeBit; i++){
        if (GetBit(i)){
            res.ClrBit(i);
        }
        else{
            res.SetBit(i);
        }
    }
    return res;
}

