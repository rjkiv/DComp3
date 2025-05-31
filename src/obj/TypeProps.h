#pragma once
#include "obj/ObjRef.h"
#include "obj/ObjPtr_p.h"
#include "obj/Data.h"

class TypeProps : public ObjRefOwner {
public:
    TypeProps(Hmx::Object*);
    virtual ~TypeProps();
    virtual Hmx::Object* RefOwner() const { return mOwner; }
    virtual bool Replace(ObjRef*, Hmx::Object*);

    DataNode* KeyValue(Symbol, bool) const;
    int Size() const;
    void ClearKeyValue(Symbol);
    void SetKeyValue(Symbol, const DataNode&, bool);
    DataArray* GetArray(Symbol);
    void SetArrayValue(Symbol, int, const DataNode&);
    void RemoveArrayValue(Symbol, int);
    void InsertArrayValue(Symbol, int, const DataNode&);
    void Load(BinStreamRev&);
    TypeProps& operator=(const TypeProps&);
    void Save(BinStream&);

    static void operator delete(void*);

private:
    DataArray* mMap; // 0x4
    Hmx::Object* mOwner; // 0x8
    ObjPtrList<Hmx::Object> mObjects; // 0xc

    void ReplaceObject(DataNode&, Hmx::Object*, Hmx::Object*);
    void ReleaseObjects();
    void AddRefObjects();
    void ClearAll();
};