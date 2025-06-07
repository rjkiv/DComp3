#pragma once

class FlowPtrBase {
public:
    int GetInitialState(Hmx::Object*);
protected:
    bool RefreshParamObject();
    Hmx::Object* GetObject();
    Hmx::Object* LoadObject(BinStream&);

    Symbol mObjName;
    FlowNode* unk4;
    int unk8;
};

template <class T>
class FlowPtr : public FlowPtrBase {
public:
    FlowPtr(Hmx::Object*, T*);
    FlowPtr(const FlowPtr&);
    ~FlowPtr();
    void operator=(T*);
    T* operator->();
    T* LoadFromMainOrDir(BinStream&);
private:
    T* Get();

    ObjPtr<T> unkc;
};