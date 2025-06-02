#pragma once
#include "BaseSkeleton.h"
#include "HamEnums.h"

class ArchiveSkeleton : public BaseSkeleton {
private:
    Vector3 mJointPositions[kNumJoints]; // 0x4
    JointConfidence mJointConfs[kNumJoints]; // 0x144
    int mElapsedMs; // 0x194
    bool mTracked; // 0x198
    int mQualityFlags; // 0x19c
public:
    ArchiveSkeleton();
    virtual ~ArchiveSkeleton(){} // 0x0
    virtual void JointPos(SkeletonCoordSys, SkeletonJoint, Vector3&) const; // 0x4
    virtual bool Displacement(const SkeletonHistory*, SkeletonCoordSys, SkeletonJoint, int, Vector3&, int&) const; // 0x8
    virtual bool Displacements(const SkeletonHistory*, SkeletonCoordSys, int, Vector3*, int&) const; // 0xc
    virtual JointConfidence JointConf(SkeletonJoint) const; // 0x10
    virtual bool IsTracked() const; // 0x14
    virtual int QualityFlags() const; // 0x18
    virtual int ElapsedMs() const; // 0x1c
    virtual void CameraToPlayerXfm(SkeletonCoordSys, Transform&) const; // 0x20
    virtual void NormOffset(SkeletonJoint, Vector3&) const; // 0x24
    virtual void CamJointPositions(Vector3*) const; // 0x28
    virtual void CamBoneLengths(float*) const; // 0x2c
    virtual float BoneLength(SkeletonBone, SkeletonCoordSys) const; // 0x30

    ArchiveSkeleton& operator=(const ArchiveSkeleton&);
    void Set(const Skeleton&);
};