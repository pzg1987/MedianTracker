#include "MedianTrackerManager.h"

#include <cstdio>

#include "MedianTrackerInput.h"
#include "MedianTrackerInputType.h"

void MedianTrackerManager::Run() {
    MedianTrackerInput input = inputReader_.ObtainInput();
    while (input.type_ != MedianTrackerInputType::QUIT_REQUEST) {
        switch (input.type_) {
        case MedianTrackerInputType::MEDIAN_REQUEST:
            printf("%f ", bstMedianTracker_.GetMedian());
            break;
        case MedianTrackerInputType::NUMBER:
            bstMedianTracker_.InsertNumber(input.value_);
            break;
        default:
            return;
        }

        input = inputReader_.ObtainInput();
    }
}
