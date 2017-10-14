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

    inline Register(const Register<N>& src) {
        mData = src.mData;
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
};


template<typename T, unsigned int N>
inline Register<N> operator^(const Register<N>& reg, const T& other) {
    Register<N> res(reg);
    res ^= other;
    return res;
}

template<typename T, unsigned int N>
inline Register<N> operator^(const T& other, const Register<N>& reg) {
    return reg ^ other;
};

template<typename T, unsigned int N>
inline Register<N> operator&(const Register<N>& reg, const T& other) {
    Register<N> res(reg);
    res.mData &= other;
    return res;
};

#endif //STUDYBOY_REGISTER_H
