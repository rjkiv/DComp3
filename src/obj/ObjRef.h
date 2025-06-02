#pragma once

// forward decs
namespace Hmx { class Object; }
class ObjRef;
class ObjRefOwner;

// ObjRefOwner size: 0x4
class ObjRefOwner {
public:
    ObjRefOwner(){}
    virtual ~ObjRefOwner(){}
    virtual Hmx::Object* RefOwner() const = 0;
    virtual bool Replace(ObjRef*, Hmx::Object*) = 0;
};

// ObjRef size: 0xc
class ObjRef {
public:
    ObjRef(){}
    virtual ~ObjRef(){}
    virtual Hmx::Object* RefOwner() const { return nullptr; }
    virtual bool IsDirPtr(){ return false; }
    virtual Hmx::Object* GetObj() const;
    virtual void Replace(Hmx::Object*);
    virtual ObjRefOwner* Parent() const { return nullptr; }

    // seems to be a linked list of an Object's refs
    ObjRef* prev; // 0x4
    ObjRef* next; // 0x8
};

// ObjRefConcrete size: 0x10
template <class T1, class T2 = class ObjectDir>
class ObjRefConcrete : public ObjRef {
protected:
    T1* mObj; // 0xc
public:
    ObjRefConcrete(T1* obj) : mObj(obj){
        if(obj){
            // prev gets set here too
            next->prev = this;
        }
    }
    virtual ~ObjRefConcrete(){
        if(mObj){
            next->prev = prev;
            prev->next = next;
        }
    }
    virtual Hmx::Object* GetObj() const { return mObj; }
    virtual void Replace(Hmx::Object* obj){ SetObj(obj); }

    void SetObjConcrete(T1*);
    void CopyRef(const ObjRefConcrete&);
    Hmx::Object* SetObj(Hmx::Object*);
    bool Load(class BinStream&, bool, ObjectDir*);
};