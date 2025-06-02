#pragma once

// size: 0x48
class SkeletonHistoryArchive {
protected:
    std::vector<ArchiveSkeleton> mArchives[6]; // 0x0
public:
    SkeletonHistoryArchive();
    ~SkeletonHistoryArchive(){}

    const std::vector<ArchiveSkeleton>& GetArchive(int) const;
    void AddToHistory(int, const Skeleton&);
    void ClearHistory(int);
};

class SkeletonHistory {
protected:
    virtual bool PrevSkeleton(const Skeleton&, int, ArchiveSkeleton&, int&) const = 0;

    bool PrevFromArchive(const SkeletonHistoryArchive&, const Skeleton&, int, ArchiveSkeleton&, int&) const;
};