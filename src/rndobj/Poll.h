#pragma once

class RndPollable : public virtual Hmx::Object {
public:
    RndPollable(){}

    // Hmx::Object
    virtual ~RndPollable(){}
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    // RndPollable
    virtual bool PollEnabled() const { return true; }
    virtual void Poll() {}
    virtual void Enter();
    virtual void Exit();
    virtual void ListPollChildren(std::list<RndPollable *> &) const {}
};