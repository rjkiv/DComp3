#pragma once
#include "Data.h"
#include "ObjRef.h"
#include "TypeProps.h"
#include "../utl/Str.h"

namespace Hmx {
    // Object size: 0x2C
    class Object : public ObjRefOwner {
    private: // maybe these coulda been protected idk
        ObjRef mRefs; // 0x4
        TypeProps* mTypeProps; // 0x10
        DataArray* mTypeDef; // 0x14
        String mNote; // 0x18
        const char* mName; // 0x20
        ObjectDir* mDir; // 0x24
        MsgSinks* mSinks; // 0x28
    public:
        enum CopyType {
            kCopyDeep = 0,
            kCopyShallow = 1,
            kCopyFromMax = 2
        };

        Object();
        virtual ~Object();
        virtual Object *RefOwner() { return this; }
        virtual bool Replace(ObjRef*, Hmx::Object*);
        virtual Symbol ClassName() const;
        virtual void SetType(Symbol);
        virtual DataNode Handle(DataArray*, bool);
        virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
        virtual void InitObject();
        virtual void Save(BinStream&);
        virtual void Copy(const Hmx::Object*, CopyType);
        virtual void Load(BinStream&);
        virtual void PreSave(BinStream&){}
        virtual void PostSave(BinStream&){}
        virtual void Print(){}
        virtual void Export(DataArray*, bool);
        virtual void SetTypeDef(DataArray*);
        virtual DataArray* ObjectDef(Symbol);
        virtual void SetName(const char*, ObjectDir*);
        virtual ObjectDir* DataDir();
        virtual void PreLoad(BinStream&);
        virtual void PostLoad(BinStream&){}
        virtual const char* FindPathName();

        Symbol Type() const;

        static Symbol StaticClassName();
    };
}