#include <iostream>
#include "Set.h"


int main() {
    BitField mass(26);
    Set array(mass);
    for (size_t i = 1; i < 26; i++){
        array.InsertElem(i);
    }
    std::vector res = array.GetPrimary();

    for (size_t i = 0; i < res.size(); i ++){
        std::cout << res[i] << " ";
    }
}