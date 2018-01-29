#include "MedianTrackerManager.h"
#include "MedianTrackerTestManager.h"

int main(int argc, char** argv) {
    // Running with "-t" starts testing.
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 't' && argv[1][2] == '\0') {
        MedianTrackerTestManager testManager;
        testManager.Run();
    } else {
        MedianTrackerManager manager;
        manager.Run();
    }

    return 0;
}
