#pragma once
#include "obj/Object.h"

// FlowNode size: 0x8C
class FlowNode : public virtual Hmx::Object {
public:
    enum QueueState {

    };
    enum StopMode {

    };
    // Hmx::Object
    virtual ~FlowNode();    
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    virtual const char* FindPathName();
    // FlowNode
    virtual void SetParent(FlowNode*, bool);
    virtual FlowNode* GetParent(){ return mParent; }
    virtual bool Activate();
    virtual void Deactivate(bool);
    virtual void ChildFinished(FlowNode*);
    virtual void RequestStop();
    virtual void RequestStopCancel();
    virtual void Execute(QueueState){}
    virtual bool IsRunning();
    virtual Flow* GetOwnerFlow();
    virtual void MiloPreRun();
    virtual void MoveIntoDir(ObjectDir*, ObjectDir*);
    virtual void UpdateIntensity();
    virtual bool ActivateTrigger();
    virtual bool Activate(Hmx::Object*);

    Flow* GetTopFlow();
    bool HasRunningNode(FlowNode*);
    DrivenPropertyEntry* GetDrivenEntry(Symbol);

    static Hmx::Object* LoadObjectFromMainOrDir(BinStream&, ObjectDir*);
    static FlowNode* DuplicateChild(FlowNode*);
    static Symbol StaticClassName();
    static Hmx::Object* NewObject();
    static void* operator new(unsigned int);
    static void operator delete(void*);
protected:
    FlowNode();

    void PushDrivenProperties();
    void ActivateLabel(FlowLabel*);
    void ActivateChild(FlowNode*);

    static float sIntensity;
    static bool sPushDrivenProperties;

    bool mDebugOutput; // 0x8
    String mDebugComment; // 0xc
    ObjPtrVec<FlowNode> unk14; // 0x14
    ObjPtrList<FlowNode> unk30; // 0x30
    FlowNode* mParent; // 0x44
    ObjVector<DrivenPropertyEntry> unk48; // 0x48
    bool unk58; // 0x58
    // Object offset at 0x60
};