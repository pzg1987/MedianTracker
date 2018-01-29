#ifndef MEDIAN_TRACKER_INPUT_READER_H
#define MEDIAN_TRACKER_INPUT_READER_H

#include "MedianTrackerInput.h"

class MedianTrackerInputReader {
public:
    MedianTrackerInputReader() = default;
    virtual ~MedianTrackerInputReader() = default;

    const MedianTrackerInput& ObtainInput();

private:
    MedianTrackerInput input;
};

#endif // MEDIAN_TRACKER_INPUT_READER_H
