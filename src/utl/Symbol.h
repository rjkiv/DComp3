#pragma once

class Symbol {
private:
    const char* mStr;
public:
    Symbol();
    Symbol(const char*);

    bool operator==(const char*) const;

    static void PreInit(int, int);
    static void Init();
    static void Terminate();
};