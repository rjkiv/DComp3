#pragma once
#include "utl/TextStream.h"
#include <vector>

class FixedString {
protected:
    const char* mStr; // 0x0
public:
    FixedString(char*, int);

    FixedString& operator+=(const char*);
    bool operator<(const FixedString&) const;
    unsigned int find_last_of(char) const;
    unsigned int find_last_of(const char*) const;
    void ToLower();
    void ToUpper();
    void ReplaceAll(char, char);
    unsigned int find(char, unsigned int) const;
    unsigned int find(char) const;
    unsigned int find(const char*, unsigned int) const;
    unsigned int find_first_of(const char*, unsigned int) const;
    int compare(unsigned int, unsigned int, const char*) const;
    char& operator[](unsigned int);
    unsigned int find(const char*) const;
    bool contains(const char*) const;

    static unsigned int const npos;
};

class String : public TextStream, public FixedString {
public:
    String();
    String(unsigned int, char);
    String(const char*);
    String(Symbol);
    String(const String&);
    virtual ~String();
    virtual void Print(const char *);

    bool operator!=(const char*) const;
    bool operator==(const char*) const;
    String& erase();
    bool operator!=(const FixedString&) const;
    bool operator==(const FixedString&) const;
    bool operator==(Symbol) const;
    void reserve(unsigned int);
    String& operator+=(const char*);
    String& operator+=(Symbol);
    String& operator+=(const FixedString&);
    String& operator+=(char);
    String& operator=(const FixedString&);
    String& operator=(const String&);
    void resize(unsigned int);
    String& replace(unsigned int, unsigned int, const char*);
    String& erase(unsigned int);
    String& erase(unsigned int, unsigned int);
    String& insert(unsigned int, unsigned int, char);
    String& insert(unsigned int, const char*);
    String& operator=(const char*);
    String& operator=(Symbol);
    String operator+(const char*) const;
    String operator+(char) const;
    String operator+(const FixedString&) const;
    String substr(unsigned int) const;
    String substr(unsigned int, unsigned int) const;
    int split(const char*, std::vector<String>&) const;
};