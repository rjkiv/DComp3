#pragma once

class CharBonesSamples : public CharBones {
public:    
    CharBonesSamples();
    virtual ~CharBonesSamples() {}
    virtual void ScaleAdd(CharClip *, float, float, float);
    virtual void Print();
    virtual bool SyncProperty(DataNode&, DataArray*, int, PropOp);

    void Save(BinStream&);
    void LoadData(BinStreamRev&);
    void LoadHeader(BinStreamRev&);
    void Load(BinStream&);

    int mNumSamples; // 0x54
    int mPreviewSample; // 0x58
    char* mRawData; // 0x5c
    std::vector<float> mFrames; // 0x60
};