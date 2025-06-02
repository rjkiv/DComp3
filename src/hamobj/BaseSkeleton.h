#pragma once
#include "HamEnums.h"

class BaseSkeleton {
protected:
    void CalcNormalizedOffset(SkeletonJoint, Vector3&) const;
    void LimbNormPos(SkeletonCoordSys, SkeletonJoint, bool, Vector3const&, Vector3&) const;
public:
    BaseSkeleton(){}
    virtual ~BaseSkeleton(){} // 0x0
    virtual void JointPos(SkeletonCoordSys, SkeletonJoint, Vector3&) const = 0; // 0x4
    virtual bool Displacement(const SkeletonHistory*, SkeletonCoordSys, SkeletonJoint, int, Vector3&, int&) const = 0; // 0x8
    virtual bool Displacements(const SkeletonHistory*, SkeletonCoordSys, int, Vector3*, int&) const = 0; // 0xc
    virtual JointConfidence JointConf(SkeletonJoint) const = 0; // 0x10
    virtual bool IsTracked() const = 0; // 0x14
    virtual int QualityFlags() const = 0; // 0x18
    virtual int ElapsedMs() const = 0; // 0x1c
    virtual void CameraToPlayerXfm(SkeletonCoordSys, Transform&) const = 0; // 0x20
    virtual void NormOffset(SkeletonJoint, Vector3&) const; // 0x24
    virtual void CamJointPositions(Vector3*) const; // 0x28
    virtual void CamBoneLengths(float*) const; // 0x2c
    virtual float BoneLength(SkeletonBone, SkeletonCoordSys) const; // 0x30

    void BoneVec(SkeletonBone, SkeletonCoordSys, Vector3&) const;
    void NormPos(SkeletonCoordSys, SkeletonJoint, Vector3&) const;

    static SkeletonJoint MirrorJoint(SkeletonJoint);
    static void MakeCameraToPlayerXfm(SkeletonCoordSys, Transform&, Vector3const*, Vector3const&);
    static const BoneJoints* const sBones;
    static const SkeletonJoint* const sJointParents;
};