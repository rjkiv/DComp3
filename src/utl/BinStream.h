#pragma once

class BinStream {
public:
    enum SeekType {
        kSeekBegin = 0,
        kSeekCur = 1,
        kSeekEnd = 2
    };
    
    BinStream(bool);
    virtual ~BinStream(){}
    virtual void Flush() = 0;
    virtual int Tell() = 0;
    virtual EofType Eof() = 0;
    virtual bool Fail() = 0;
    virtual const char* Name() const;
    virtual int ReadAsync(void*, int);
    virtual bool Cached() const;
    virtual Platform GetPlatform() const;

    void DisableEncryption();
    void Write(const void*, int);
    void Seek(int, SeekType);
    void WriteEndian(const void*, int);
    bool AddSharedInlined(const FilePath&);
    void EnableWriteEncryption();
    int PopRev(Hmx::Object*);
    void Read(void*, int);
    void ReadEndian(void*, int);
    void ReadString(char*, int);
    void EnableReadEncryption();
    void PushRev(int, Hmx::Object*);

    BinStream& operator<<(const char*);
    BinStream& operator<<(const Symbol&);
    BinStream& operator<<(const String&);

    BinStream& operator>>(int&);
    BinStream& operator>>(unsigned int&);
    BinStream& operator>>(bool&);
    BinStream& operator>>(Symbol&);
    BinStream& operator>>(String&);

    static void operator delete(void*);
private:
    virtual void ReadImpl(void*, int) = 0;
    virtual void WriteImpl(const void*, int) = 0;
    virtual void SeekImpl(int, SeekType) = 0;
protected:
    bool mLittleEndian; // 0x4
    Rand2* mCrypto; // 0x8
    std::vector<ObjVersion>* mRevStack; // 0xc
};

class BinStreamRev {
public:
    BinStreamRev(unsigned int, unsigned int, BinStream&);
    
    unsigned int mRev;
    unsigned int mAltRev;
    BinStream& mBinStream;
};

template <class E> // E is an enum type
class BinStreamEnum {
public:
    E mEnum;
};

template <class E>
BinStreamRev& operator>>(BinStreamRev& bs, BinStreamEnum<E>& e){
    int x; bs.mBinStream >> x;
    e.mEnum = (E)x;
    return bs;
}