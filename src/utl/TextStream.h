#pragma once
#include "utl/Symbol.h"

class TextStream {
public:
    TextStream(){}
    virtual ~TextStream() {}
    virtual void Print(const char *) = 0;

    void Space(int i);
    TextStream& operator<<(bool);
    TextStream &operator<<(char);
    TextStream &operator<<(int);
    TextStream &operator<<(unsigned char);
    TextStream &operator<<(unsigned int);
    TextStream &operator<<(unsigned short);
    TextStream &operator<<(unsigned long);
    TextStream &operator<<(float);
    TextStream &operator<<(const char *);
    TextStream &operator<<(Symbol);
    TextStream &operator<<(unsigned long long);
};