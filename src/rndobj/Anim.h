#pragma once
#include "../obj/Object.h"

class RndAnimatable : public virtual Hmx::Object {
public:
    enum Rate {
        k30_fps = 0,
        k480_fpb = 1,
        k30_fps_ui = 2,
        k1_fpb = 3,
        k30_fps_tutorial = 4,
    };

    // Hmx::Object
    virtual ~RndAnimatable();
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    // RndAnimatable
    virtual bool Loop(){ return false; }
    virtual void StartAnim(){}
    virtual void EndAnim(){}
    virtual void SetFrame(float, float);
    virtual float StartFrame(){ return 0; }
    virtual float EndFrame(){ return 0; }
    virtual Hmx::Object* AnimTarget();
    virtual void SetKey(float){}
    virtual void ListAnimChildren(std::list<RndAnimatable*>&) const {}
    virtual DataNode OnListFlowLabels(DataArray*){ return 0; }
protected:
    RndAnimatable();

    float mFrame; // 0x8
    Rate mRate; // 0xc
};