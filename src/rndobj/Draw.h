#pragma once
#include "Highlight.h"

// size 0x7c
class RndDrawable : public virtual RndHighlightable {
public:
    // RndHighlightable
    virtual void Highlight();
    // Hmx::Object
    virtual ~RndDrawable();
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    // RndDrawable
    virtual void UpdateSphere() { mSphere.Zero(); }
    virtual float GetDistanceToPlane(const Plane &, Vector3 &) { return 0.0f; }
    virtual bool MakeWorldSphere(Sphere &, bool) { return 0; }
    virtual RndCam *CamOverride() { return 0; }
    virtual void Mats(std::list<class RndMat *> &, bool) {}
    virtual void Draw();
    virtual void DrawShowing() {}
    virtual bool DrawShowingBudget(float);
    virtual void ListDrawChildren(std::list<RndDrawable *> &) {}
    virtual RndDrawable *CollideShowing(const Segment &, float &, Plane &) { return 0; }
    virtual int CollidePlane(const Plane &);
    virtual void CollideList(const Segment &, std::list<Collision> &);
    virtual void DrawPreClear() {}
    virtual void UpdatePreClearState() {}
protected:
    RndDrawable();

    bool mShowing; // 0x8
    Sphere mSphere; // 0xc
    float mOrder; // 0x20
    ObjPtrVec<RndTransformable, ObjectDir> mClipPlanes; // 0x24
};

// void RndDrawable::Save(BinStream& bs){
//     bs << 4;
//     bs << mShowing;
//     bs << mSphere; // write the vector and then the radius
//     bs << mOrder;
//     bs << mClipPlanes; // write the number of objects in the vector and then their names
// }