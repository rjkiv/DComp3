#pragma once
#include "obj/ObjRef.h"
#include <vector>

// ObjPtr size: 0x14
template <class T>
class ObjPtr : public ObjRefConcrete<T, ObjectDir> {
private:
    Hmx::Object* mOwner; // 0x10
public:
    ObjPtr(Hmx::Object* owner, T* ptr);
    virtual ~ObjPtr(){}
    virtual Hmx::Object* RefOwner() const { return mOwner; }
};

// ObjOwnerPtr size: 0x14
template <class T>
class ObjOwnerPtr : public ObjRefConcrete<T, ObjectDir> {
private:
    ObjRefOwner* mOwner; // 0x10
public:
    ObjOwnerPtr(ObjRefOwner* owner, T* ptr);
    virtual ~ObjOwnerPtr(){}
    virtual Hmx::Object* RefOwner() const { return mObj->RefOwner(); }
    virtual void Replace(Hmx::Object* obj){
        mOwner->Replace(this, obj);
    }
};

enum EraseMode {

};

enum ObjListMode {
    kObjListNoNull,
    kObjListAllowNull,
    kObjListOwnerControl
};

// ObjPtrVec size: 0x1c
template <class T1, class T2 = class ObjectDir>
class ObjPtrVec : public ObjRefOwner {
    // Node size: 0x14
    struct Node : public ObjRefConcrete<T1, T2> {
        virtual ~Node(){}
        virtual Hmx::Object* RefOwner() const;
        virtual void Replace(Hmx::Object*);
        virtual ObjRefOwner* Parent() const { return unk10; }

        ObjRefOwner* unk10; // 0x10
    };
    std::vector<Node> mNodes; // 0x4
    Hmx::Object* mOwner; // 0x10
    EraseMode mEraseMode; // 0x14
    ObjListMode mListMode; // 0x18
};

// ObjPtrList size: 0x14
template <class T1, class T2 = class ObjectDir>
class ObjPtrList : public ObjRefOwner {
public:
    ObjPtrList(ObjRefOwner*, ObjListMode);
    virtual ~ObjPtrList(){}
private:
    // Node size: 0x14
    struct Node : public ObjRefConcrete<T1, T2> {
        virtual ~Node(){}
        virtual Hmx::Object* RefOwner() const;
        virtual void Replace(Hmx::Object*);
        virtual ObjRefOwner* Parent() const { return unk10; }

        ObjRefOwner* unk10; // 0x10
    };
    int mSize; // 0x4
    Node* mNodes; // 0x8
    ObjRefOwner* mOwner; // 0xc
    ObjListMode mListMode; // 0x10

    virtual Hmx::Object* RefOwner() const;
    virtual bool Replace(ObjRef*, Hmx::Object*);
};

// // ObjDirPtr size: 0x14
// template <class T>
// class ObjDirPtr : public ObjRefConcrete<T, ObjectDir> {
//     DirLoader* mLoader; // 0x10
// };