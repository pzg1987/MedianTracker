#ifndef MEDIAN_TRACKER_MANAGER_H
#define MEDIAN_TRACKER_MANAGER_H

#include "BSTMedianTracker.h"
#include "MedianTrackerInputReader.h"

class MedianTrackerManager {
public:
    MedianTrackerManager() = default;
    virtual ~MedianTrackerManager() = default;

    void Run();

private:
    MedianTrackerInputReader inputReader_;
    BSTMedianTracker bstMedianTracker_;
};

#endif // MEDIAN_TRACKER_MANAGER_H
