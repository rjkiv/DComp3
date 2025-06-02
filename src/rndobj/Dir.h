#pragma once
#include "../obj/Dir.h"
#include "Draw.h"
#include "Anim.h"
#include "Trans.h"
#include "Poll.h"

// RndDir size: 0x238
class RndDir : public ObjectDir, public RndDrawable, public RndAnimatable, public RndTransformable, public RndPollable {
public:
    // Hmx::Object
    virtual ~RndDir();
    virtual bool Replace(ObjRef*, Hmx::Object*);
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    virtual void Export(DataArray*, bool);
    virtual void PreLoad(BinStream&);
    virtual void PostLoad(BinStream&);
    // RndHighlightable
    virtual void Highlight();
    // RndPollable
    virtual void Poll();
    virtual void Enter();
    virtual void Exit();
    virtual void ListPollChildren(std::list<RndPollable *> &) const;
    // RndAnimatable
    virtual void SetFrame(float, float);
    virtual float EndFrame();
    virtual void ListAnimChildren(std::list<RndAnimatable *> &) const;
    // RndDrawable
    virtual void UpdateSphere();
    virtual float GetDistanceToPlane(const Plane &, Vector3 &);
    virtual bool MakeWorldSphere(Sphere &, bool);
    virtual void Draw();
    virtual void DrawShowing();
    virtual void ListDrawChildren(std::list<RndDrawable *> &);
    virtual RndDrawable *CollideShowing(const Segment &, float &, Plane &);
    virtual int CollidePlane(const Plane &);
    virtual void CollideList(const Segment &, std::list<Collision> &);
    // ObjectDir
    virtual void SetSubDir(bool);
    virtual void SyncObjects();
    virtual void ChainSourceSubdir(Hmx::Object*, ObjectDir*);
    virtual void CollideListSubParts(const Segment&, std::list<RndDrawable::Collision>&);
protected:
    RndDir();

    virtual void RemovingObject(Hmx::Object*);
    virtual void OldLoadProxies(BinStream&, int);

    std::vector<RndDrawable*> mDraws; // 0x1b4
    std::vector<RndAnimatable*> mAnims; // 0x1c0
    std::vector<RndPollable*> mPolls; // 0x1cc
    std::vector<RndPollable*> mEnters; // 0x1d8
    ObjPtr<RndEnviron> mEnv; // 0x1e4
    Symbol mTestEvent; // 0x1f8
    // Hmx::Object offset: 0x200
};