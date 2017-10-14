//
// Created by adnan on 14/10/2017.
//

#include "Register.h"



Register::Register() {

}

Register::Register(const Register &src) {
    mData = src.mData;
}

Register::Register(Register &&src) {
    mData = src.mData;
}

Register::~Register() {

}

Register &Register::operator=(Register &&src) {
    if ( this == &src ) return *this;
    mData = src.mData;
    return *this;
}

Register &Register::operator=(const Register &src) {
    if ( this == &src ) return *this;
    mData = src.mData;
    return *this;
}

template <typename T>
Register &Register::operator=(T &&src) {
    mData = src;
    return *this;
}

template <typename T>
Register &Register::operator=(const T &src) {
    mData = src;
    return *this;
}
