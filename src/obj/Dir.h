#pragma once
#include "Object.h"

enum InlineDirType {
    kInlineNever = 0,
    kInlineCached = 1,
    kInlineAlways = 2,
    kInlineCachedShared = 3
};

// ObjectDir size: 0xCC
class ObjectDir : public virtual Hmx::Object {    
public:
    // Hmx::Object
    virtual ~ObjectDir();
    virtual Symbol ClassName() const;
    virtual void SetType(Symbol);
    virtual DataNode Handle(DataArray*, bool);
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);
    virtual void Save(BinStream&);
    virtual void Copy(const Hmx::Object*, CopyType);
    virtual void Load(BinStream&);
    virtual void PostSave(BinStream&);
    virtual void SetName(const char*, ObjectDir*);
    virtual ObjectDir* DataDir();
    virtual void PreLoad(BinStream&);
    virtual void PostLoad(BinStream&);
    // ObjectDir
    virtual void SetProxyFile(const FilePath&, bool);
    virtual const FilePath& ProxyFile() { return mProxyFile; }
    virtual void SetSubDir(bool);
    virtual DataArrayPtr GetExposedProperties();
    virtual void SyncObjects();
    virtual void ResetEditorState();
    virtual InlineDirType InlineSubDirType();

protected:
    struct Entry {
        const char* name;
        Hmx::Object* obj;
    };

    class Viewport {
        Transform mXfm;
    };

    struct InlinedDir {
        ObjDirPtr<ObjectDir> dir; // 0x0
        FilePath file; // 0x14
        bool shared; // 0x1c
        InlineDirType inlineDirType; // 0x20
    };

    enum ViewportId {
        kNumViewports = 7
    };

    ObjectDir();
    virtual void AddedObject(Hmx::Object*);
    virtual void RemovingObject(Hmx::Object*);
    virtual void OldLoadProxies(BinStream&, int);

    KeylessHash<const char*, Entry> mHashTable; // 0x8
    StringTable mStringTable; // 0x28
    FilePath mProxyFile; // 0x3c
    bool mProxyOverride; // 0x44
    InlineDirType mInlineProxyType; // 0x48
    DirLoader *mLoader; // 0x4c
    std::vector<ObjDirPtr<ObjectDir> > mSubDirs; // 0x50
    bool mIsSubDir; // 0x5c
    InlineDirType mInlineSubDirType; // 0x60
    const char *mPathName; // 0x64
    FilePath mStoredFile; // 0x68
    std::vector<InlinedDir> mInlinedDirs; // 0x70
    std::vector<Viewport> mViewports; // 0x7c
    ViewportId mCurViewportID; // 0x88
    Hmx::Object* unk8c; // 0x8c
    Hmx::Object* mCurCam; // 0x90
    int mAlwaysInlined; // 0x94
    const char *mAlwaysInlineHash; // 0x98
};