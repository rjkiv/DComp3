#pragma once
#include "../math/Vec.h"
#include "../obj/Data.h"
#include "../utl/Symbol.h"
#include "HamEnums.h"

struct ErrorFrameInput {

};

struct ErrorNodeInput {
    Vector3const mNodeComponentWeight; // 0x0
    Ham1NodeWeight* mNodeWeight; // 0x10
};

// examples from config/scoring.dta:
//  (l_elbow
//     (type kErrorHam1Euclidean)
//     (coord_sys kCoordLeftArm)
//     (base_joint kJointShoulderLeft)
//     (joint kJointElbowLeft)
//     (feedback_limbs kFeedbackRightArm)
//     (xz_error_axis kJointShoulderLeft kJointShoulderRight)
//     (component_weight_ranges
//       (0.1 1)
//       (1 1)
//       (0.1 1)
//     )
//  )

// ErrorNode size: 0x1c
class ErrorNode {
protected:
    ErrorNode(ErrorNodeType, const DataArray*);

    void InitNormBones(const DataArray*, SkeletonBone (&)[3]);

    ErrorNodeType mType; // 0x4
    Symbol mNodeName; // 0x8 - node name: looks to be l_elbow in the above example
    SkeletonJoint mJoint; // 0xc
    FeedbackLimbs mFeedbackLimbs; // 0x10
    SkeletonJoint mXErrorAxis; // 0x14
    SkeletonJoint mZErrorAxis; // 0x18
public:
    virtual ~ErrorNode(){}
    virtual bool SkipFirstFrame() const = 0;
    virtual void CalcError(const ErrorFrameInput&, const ErrorNodeInput&, Vector3&) const = 0;
    virtual void VizError(SkeletonViz&, const ErrorFrameInput&, const ErrorNodeInput&) const = 0;

    bool XZErrorAxis(Vector3&, const DancerSkeleton&) const;
    static ErrorNode* Create(const DataArray*);
};

// Ham1EuclideanNode size: 0x3c
class Ham1EuclideanNode : public ErrorNode {
private:
    SkeletonCoordSys mCoordSys; // 0x1c
    SkeletonJoint mBaseJoint; // 0x20
    float mComponentWeightRanges[3][2]; // 0x24
public:
    Ham1EuclideanNode(ErrorNodeType, const DataArray*);
    virtual ~Ham1EuclideanNode(){}
    virtual bool SkipFirstFrame() const { return false; }
    virtual void CalcError(const ErrorFrameInput&, const ErrorNodeInput&, Vector3&) const;
    virtual void VizError(SkeletonViz&, const ErrorFrameInput&, const ErrorNodeInput&) const {}
};

//  (l_hand_vdisp
//     (type kErrorDisplacement)
//     (base_joint kJointShoulderLeft)
//     (joint kJointHandLeft)
//     (feedback_limbs kFeedbackRightArm)
//     (norm_bones kBoneArmUpperLeft kBoneArmLowerLeft kBoneHandLeft)
//  )

// BaseDisplacementNode size: 0x2c
class BaseDisplacementNode : public ErrorNode {
protected:
    struct DisplacementData {

    };

    struct Ham1DisplacementData {

    };

    bool Displacements(const ErrorFrameInput&, DisplacementData&) const;
    bool Displacements(const ErrorFrameInput&, DisplacementData&, Ham1DisplacementData&) const;

    SkeletonJoint mBaseJoint; // 0x1c
    SkeletonBone mNormBones[kMaxNumNormBones]; // 0x20
public:
    BaseDisplacementNode(ErrorNodeType, const DataArray*);
    virtual ~BaseDisplacementNode(){}
    virtual bool SkipFirstFrame() const { return true; }
};

// DisplacementNode size: 0x2c
class DisplacementNode : public BaseDisplacementNode {
public:
    DisplacementNode(ErrorNodeType, const DataArray*);
    virtual ~DisplacementNode(){}
    virtual bool SkipFirstFrame() const { return true; }
    virtual void CalcError(const ErrorFrameInput&, const ErrorNodeInput&, Vector3&) const;
    virtual void VizError(SkeletonViz&, const ErrorFrameInput&, const ErrorNodeInput&) const {}
};

//  (hip_disp
//     (type kErrorHam1Displacement)
//     (joint kJointHipCenter)
//     (feedback_limbs kFeedbackLeftLeg kFeedbackRightLeg)
//     (xz_error_axis kJointHipLeft kJointHipRight)
//     (norm_bones kBoneBackUpper)
//     (potential_angle_op
//       (type kErrorScaleDist)
//       (rate 17.36111)
//       (perfect_dist 3.0e-2)
//     )
//  )

struct ScaleOp {
    ErrorScaleType mType; // 0x0
    float mPerfectDist; // 0x4
    float mRate; // 0x8
};

// Ham1DisplacementNode size: 0x38
class Ham1DisplacementNode : public BaseDisplacementNode {
private:
    struct ErrorData {

    };
    
    ScaleOp mPotentialAngleOp; // 0x2c

    void Errors(const ErrorFrameInput&, const ErrorNodeInput&, ErrorData&, DisplacementData&, Ham1DisplacementData&) const;
public:
    Ham1DisplacementNode(ErrorNodeType, const DataArray*);
    virtual ~Ham1DisplacementNode(){}
    virtual bool SkipFirstFrame() const { return true; }
    virtual void CalcError(const ErrorFrameInput&, const ErrorNodeInput&, Vector3&) const;
    virtual void VizError(SkeletonViz&, const ErrorFrameInput&, const ErrorNodeInput&) const {}
};

//  (l_hand_vpos
//     (type kErrorPosition)
//     (base_joint kJointShoulderLeft)
//     (joint kJointHandLeft)
//     (feedback_limbs kFeedbackRightArm)
//     (norm_bones kBoneArmUpperLeft kBoneArmLowerLeft kBoneHandLeft)
//  )

// PositionNode size: 0x2c
class PositionNode : public ErrorNode {
private:
    SkeletonJoint mBaseJoint; // 0x1c
    SkeletonBone mNormBones[kMaxNumNormBones]; // 0x20
public:
    PositionNode(ErrorNodeType, const DataArray*);
    virtual ~PositionNode(){}
    virtual bool SkipFirstFrame() const { return false; }
    virtual void CalcError(const ErrorFrameInput&, const ErrorNodeInput&, Vector3&) const;
    virtual void VizError(SkeletonViz&, const ErrorFrameInput&, const ErrorNodeInput&) const {}
};