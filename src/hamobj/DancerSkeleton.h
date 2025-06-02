#pragma once
#include "BaseSkeleton.h"
#include "HamEnums.h"

// DancerSkeleton size: 0x2D8
class DancerSkeleton : public BaseSkeleton {
private:
    Vector3 mCamJointPositions[kNumJoints]; // 0x4
    Vector3 mCamJointDisplacements[kNumJoints]; // 0x144
    float mCamBoneLengths[kNumBones]; // 0x284
    int mElapsedMs; // 0x2d0
    bool mTracked; // 0x2d4
public:
    DancerSkeleton();
    DancerSkeleton(const DancerSkeleton&);
    virtual ~DancerSkeleton(){} // 0x0
    virtual void JointPos(SkeletonCoordSys, SkeletonJoint, Vector3&) const; // 0x4
    virtual bool Displacement(const SkeletonHistory*, SkeletonCoordSys, SkeletonJoint, int, Vector3&, int&) const; // 0x8
    virtual bool Displacements(const SkeletonHistory*, SkeletonCoordSys, int, Vector3*, int&) const; // 0xc
    virtual JointConfidence JointConf(SkeletonJoint) const { return 2; } // 0x10
    virtual bool IsTracked() const; // 0x14
    virtual int QualityFlags() const { return 0; } // 0x18
    virtual int ElapsedMs() const; // 0x1c
    virtual void CameraToPlayerXfm(SkeletonCoordSys, Transform&) const; // 0x20
    virtual void CamJointPositions(Vector3*) const; // 0x28
    virtual void CamBoneLengths(float*) const; // 0x2c
    virtual float BoneLength(SkeletonBone, SkeletonCoordSys) const; // 0x30

    DancerSkeleton& operator=(const DancerSkeleton&);
    void CamJointDisplacements(Vector3*) const;
    void Init();
    void Set(const BaseSkeleton&);
    void SetDisplacementElapsedMs(int);
    Vector3const& CamJointPos(SkeletonJoint) const;
    Vector3const& CamJointDisplacement(SkeletonJoint) const;
    void SetCamJointPos(SkeletonJoint, Vector3const&);
    void SetCamJointDisplacement(SkeletonJoint, Vector3const&);
    void Write(BinStream&);
    void Read(BinStream&);
};