#pragma once
#include "flow/FlowNode.h"

class FlowQueueable : public FlowNode {
public:
    // Hmx::Object
    virtual ~FlowQueueable();
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    // FlowNode
    virtual void Deactivate(bool);
    virtual void ChildFinished(FlowNode*);
    virtual void RequestStopCancel();

    void ReleaseListener(Hmx::Object*);
protected:
    FlowQueueable();

    int mInterrupt; // 0x5c
    std::list<Hmx::Object*> unk60; // 0x60
    // Object offset at 0x6c
};