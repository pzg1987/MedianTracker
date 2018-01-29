#ifndef MEDIAN_TRACKER_INPUT_H
#define MEDIAN_TRACKER_INPUT_H

#include "MedianTrackerInputType.h"

struct MedianTrackerInput {
    MedianTrackerInput() : MedianTrackerInput(MedianTrackerInputType::NONE, 0) {}
    MedianTrackerInput(MedianTrackerInputType type, int value) : type_(type), value_(value) {}
    virtual ~MedianTrackerInput() = default;

    MedianTrackerInputType type_;
    int value_;
};

#endif // MEDIAN_TRACKER_INPUT_H
