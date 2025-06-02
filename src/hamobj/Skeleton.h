#pragma once
#include "BaseSkeleton.h"
#include "HamEnums.h"

// TrackedJoint size: 0x74
struct TrackedJoint {
    Vector3 mJointPos[5]; // 0x0
    // ...
    JointConfidence unk70; // 0x70
};

// Skeleton size: 0xAD4
class Skeleton : public BaseSkeleton {
protected:
    // size 0x148
    struct CameraDisplacement {
        int unk0;
        int unk4;
        Vector3 unk8[kNumJoints];
    };
    
    bool PrevTrackedSkeleton(const SkeletonHistory*, int, int&, ArchiveSkeleton&) const;

    TrackedJoint mTrackedJoints[kNumJoints]; // 0x4
    float mCamBoneLengths[kNumBones]; // 0x914
    Transform mPlayerXfms[5]; // 0x960
    int unkaa0; // some sort of state or enum?
    int unkaa4; // quality flags
    int unkaac;
    int unkac0; // skel idx
    float unkac4;
    std::vector<CameraDisplacement> mCamDisplacements; // 0xac8
public:

    Skeleton(){}
    virtual ~Skeleton(){} // 0x0
    virtual void JointPos(SkeletonCoordSys, SkeletonJoint, Vector3&) const; // 0x4
    virtual bool Displacement(const SkeletonHistory*, SkeletonCoordSys, SkeletonJoint, int, Vector3&, int&) const; // 0x8
    virtual bool Displacements(const SkeletonHistory*, SkeletonCoordSys, int, Vector3*, int&) const; // 0xc
    virtual JointConfidence JointConf(SkeletonJoint) const; // 0x10
    virtual bool IsTracked() const; // 0x14
    virtual int QualityFlags() const; // 0x18
    virtual int ElapsedMs() const; // 0x1c
    virtual void CameraToPlayerXfm(SkeletonCoordSys, Transform&) const; // 0x20
    virtual void CamJointPositions(Vector3*) const; // 0x28
    virtual void CamBoneLengths(float*) const; // 0x2c
    virtual float BoneLength(SkeletonBone, SkeletonCoordSys) const; // 0x30

    Skeleton& operator=(const Skeleton&);
    void PostUpdate(){}
    bool IsValid() const;
    bool IsSitting() const;
    bool IsSideways() const;
    const TrackedJoint& HandJoint(SkeletonSide) const;
    const TrackedJoint& ElbowJoint(SkeletonSide) const;
    const TrackedJoint& ShoulderJoint(SkeletonSide) const;
    const TrackedJoint& HipJoint(SkeletonSide) const;
    const TrackedJoint& KneeJoint(SkeletonSide) const;
    bool ProfileMatched() const;
    int GetEnrollmentIndex() const;
    bool NeedIdentify() const;
    void ScreenPos(SkeletonJoint, Vector2&) const;
    bool Velocity(const SkeletonHistory&, SkeletonCoordSys, SkeletonJoint, int, Vector3&, int&) const;
    bool RequestIdentity();
    bool EnrollIdentity(int);
    void Init();
    void Poll(int, const SkeletonFrame&);

    static int IdentityCallback(void*, _NUI_IDENTITY_MESSAGE*);
};