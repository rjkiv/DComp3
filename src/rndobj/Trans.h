#pragma once
#include "Highlight.h"

class RndTransformable : public virtual RndHighlightable {
public:
    enum Constraint {
        kNone = 0,
        kLocalRotate = 1,
        kParentWorld = 2,
        kLookAtTarget = 3,
        kShadowTarget = 4,
        kBillboardZ = 5,
        kBillboardXZ = 6,
        kBillboardXYZ = 7,
        kFastBillboardXYZ = 8,
        kTargetWorld = 9 // unused?
    };

    // RndHighlightable
    virtual void Highlight();
    // Hmx::Object
    virtual ~RndTransformable();
    virtual bool Replace(ObjRef*, Hmx::Object*);
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    virtual void Print();
protected:
    RndTransformable();

    // RndTransformable
    virtual void UpdatedWorldXfm(){}
    
    Transform mLocalXfm; // 0x8
    Transform mWorldXfm; // 0x48
    ObjOwnerPtr<RndTransformable> mParent; // 0x88
    std::list<RndTransformable*> mChildren; // 0x9c
    ObjPtr<RndTransformable> mTarget; // 0xa4
    Constraint mConstraint; // 0xb8
    bool mPreserveScale; // 0xbc
    bool unkbd; // 0xbd - dirty?
    // Object begins at 0xc4
};