#ifndef MEDIAN_TRACKER_TEST_MANAGER_H
#define MEDIAN_TRACKER_TEST_MANAGER_H

class MedianTrackerTestManager {
public:
    MedianTrackerTestManager();
    virtual ~MedianTrackerTestManager() = default;

    void Run();

private:
    bool Test(int id);
    bool Test1();
    bool Test2();
    bool Test3();
    bool Test4();
    bool Test5();

    const int totalTestCount_;
};

#endif // MEDIAN_TRACKER_TEST_MANAGER_H
