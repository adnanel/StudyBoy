//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_REGISTER_H
#define STUDYBOY_REGISTER_H

typedef unsigned char Reg8Bit;
typedef unsigned int  Reg16Bit;
typedef unsigned long Reg32Bit;


template <typename T>
class Register {
    T mData;

public:
    inline Register();

    inline Register(const Register& src);
    inline Register(Register&& src) noexcept;

    inline ~Register();

    inline Register& operator=(const Register& src);
    inline Register& operator=(Register&& src) noexcept;

    inline Register& operator=(const T& src);
    inline Register& operator=(T&& src) noexcept;

    explicit operator T() {
        return mData;
    }
};


#endif //STUDYBOY_REGISTER_H
