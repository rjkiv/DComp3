#pragma once
#include "BaseSkeleton.h"

class SkeletonCallback {
public:
    SkeletonCallback(){}
    virtual ~SkeletonCallback(){}
    virtual void Clear() = 0;
    // pure 2
    virtual void PostUpdate(const SkeletonUpdateData*) = 0;
    virtual void Draw(const BaseSkeleton&, SkeletonViz&) = 0;
};