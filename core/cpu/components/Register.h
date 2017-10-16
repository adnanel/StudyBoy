//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_REGISTER_H
#define STUDYBOY_REGISTER_H


#include <bitset>

template <unsigned int N>
class Register {
    std::bitset<N> mData;

    class IndexWrapperHelper {
        std::bitset<N> mBitset;
        size_t mIndex;

    public:
        IndexWrapperHelper(std::bitset<N>& bitset, size_t index) : mBitset(bitset), mIndex(index) {}

        IndexWrapperHelper& operator=(bool val) {
            mBitset.set(mIndex, val);
            return *this;
        }

        operator bool() {
            return mBitset[mIndex];
        }
    };
public:
    inline Register() {}

    template<typename T>
    inline Register(const T& src) : mData(src) {
    }

    inline Register(const Register<N>& src) : mData(src.mData) {
    }


    inline Register(Register<N>&& src) noexcept {
        mData = src.mData;
    }

    inline Register<N>& operator=(const Register<N>& src) {
        if ( this == &src ) return *this;
        mData = src.mData;
        return *this;
    }

    inline Register<N>& operator=(Register<N>&& src) noexcept {
        if ( this == &src ) return *this;
        mData = src.mData;
        return *this;
    }

    inline Register<N>& operator=(unsigned long long n) {
        mData = n;
        return *this;
    }

    unsigned long long to_ullong() const {
        return mData.to_ullong();
    }

    inline IndexWrapperHelper operator[](size_t n) {
        return IndexWrapperHelper(mData, n);
    }

    inline bool operator[](size_t n) const {
        return mData[n];
    }

    inline Register<N>& operator^=(const Register<N>& other) {
        mData ^= other.mData;
        return *this;
    }

    template<typename T>
    inline Register<N>& operator^=(T other) {
        mData ^= other;
        return *this;
    }

    inline bool any() const {
        return mData.any();
    }


    template<typename T>
    inline Register<N> operator^(const T& other) const  {
        Register<N> res(*this);
        res ^= other;
        return res;
    }


    template<typename T>
    inline Register<N> operator&(const T& other) const  {
        Register<N> res(*this);
        res.mData &= other;
        return res;
    };

    template<typename T>
    inline Register<N> operator>>(const T& other) const {
        Register<N> res(*this);
        res.mData >>= other;
        return res;
    };


    template<typename T>
    inline Register<N> operator<<(const T& other) const  {
        Register<N> res(*this);
        res.mData <<= other;
        return res;
    };


    template<typename T>
    inline Register<N> operator|(const T& other) const  {
        Register<N> res(*this);
        res.mData |= other;
        return res;
    };

    inline Register<N>& operator+=(const Register<N>& other) {
        mData = mData.to_ullong() + other.mData.to_ullong();
        return *this;
    }

    inline Register<N>& operator+=(const std::bitset<N>& other) {
        mData = mData.to_ullong() + other.to_ullong();
        return *this;
    }

    inline Register<N>& operator-=(const std::bitset<N>& other) {
        mData = mData.to_ullong() - other.to_ullong();
        return *this;
    }

    template<typename T>
    inline Register<N>& operator-=(const T& other) {
        mData = mData.to_ullong() - other;
        return *this;
    }

    template<typename T>
    inline Register<N>& operator+=(const T& other) {
        mData = mData.to_ullong() + other;
        return *this;
    }

    template<typename T>
    inline Register<N> operator+(const T& other) const {
        Register copy(*this);
        return copy += other;
    }

    template<typename T>
    inline Register<N> operator-(const T& other) const {
        Register copy(*this);
        return copy -= other;
    }

    inline operator std::bitset<N>() {
        return mData;
    }

};
template<unsigned int N, typename T>
inline Register<N> operator+(const T& other, const Register<N>& reg) {
    return reg + other;
};

template<unsigned int N, typename T>
inline Register<N> operator-(const T& other, const Register<N>& reg) {
    return reg - other;
};

template<unsigned int A, unsigned int B>
inline static Register<A + B> CombineRegisters(const Register<A>& a, const Register<B>& b) {
    Register<A + B> res = (a.to_ullong() << B) | b.to_ullong();
    return res;
};

template<unsigned int A, unsigned int B>
inline static void SplitRegister(const Register<A+B>& reg, Register<A>& high, Register<B>& low) {
    high = reg.to_ullong() >> B;
    low = (reg.to_ullong() << A) >> A;
};

#endif //STUDYBOY_REGISTER_H
