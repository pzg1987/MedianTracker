#include "MedianTrackerTestManager.h"

#include <cstdio>

#include "BSTMedianTracker.h"

namespace {
    bool CompareFloats(float a, float b, float epsilon = 0.001f) {
        return a > b ? a - b < epsilon : b - a < epsilon;
    }
}

MedianTrackerTestManager::MedianTrackerTestManager()
  : totalTestCount_(5) {
}

void MedianTrackerTestManager::Run() {
   printf("\nBSTMedianTracker testing started.\n");

   int passedCount = 0;
   for (int id = 1; id <= totalTestCount_; id++) {
       printf("\n Executing test number %d:\n", id);
       if (Test(id)) {
           passedCount++;
           printf(" Test number %d: PASSED\n", id);
       } else {
           printf(" Test number %d: FAILED\n", id);
       }
   }

   printf("\n%d out of %d tests succeeded.\n\n", passedCount, totalTestCount_);
}

bool MedianTrackerTestManager::Test(int id) {
    switch (id) {
    case 1:
        return Test1();
    case 2:
        return Test2();
    case 3:
        return Test3();
    case 4:
        return Test4();
    case 5:
        return Test5();
    default:
        return false;
    }
}

// Test if the example from the task description works.
bool MedianTrackerTestManager::Test1() {
    bool passed = true;
    BSTMedianTracker bstMedianTracker;
    float expectedMedianValue;
    float receivedMedianValue;

    bstMedianTracker.InsertNumber(3);
    bstMedianTracker.InsertNumber(5);
    expectedMedianValue = 4.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue,receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    bstMedianTracker.InsertNumber(8);
    expectedMedianValue = 5.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    bstMedianTracker.InsertNumber(6);
    expectedMedianValue = 5.5;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    return passed;
}

// Test if inserting the same number multiple times works.
bool MedianTrackerTestManager::Test2() {
    bool passed = true;
    BSTMedianTracker bstMedianTracker;
    float expectedMedianValue;
    float receivedMedianValue;

    bstMedianTracker.InsertNumber(7);
    bstMedianTracker.InsertNumber(4);
    bstMedianTracker.InsertNumber(6);
    bstMedianTracker.InsertNumber(6);
    expectedMedianValue = 6.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    bstMedianTracker.InsertNumber(8);
    bstMedianTracker.InsertNumber(9);
    bstMedianTracker.InsertNumber(6);
    expectedMedianValue = 6.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    bstMedianTracker.InsertNumber(8);
    bstMedianTracker.InsertNumber(10);
    bstMedianTracker.InsertNumber(9);
    bstMedianTracker.InsertNumber(8);
    expectedMedianValue = 8.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    return passed;
}

// Test if negative numbers work.
bool MedianTrackerTestManager::Test3() {
    bool passed = true;
    BSTMedianTracker bstMedianTracker;
    float expectedMedianValue;
    float receivedMedianValue;

    bstMedianTracker.InsertNumber(3);
    bstMedianTracker.InsertNumber(-5);
    expectedMedianValue = -1.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    bstMedianTracker.InsertNumber(8);
    expectedMedianValue = 3.0;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    bstMedianTracker.InsertNumber(-2);
    expectedMedianValue = 0.5;
    receivedMedianValue = bstMedianTracker.GetMedian();
    if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
        passed = false;
        printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
    }

    return passed;
}

// Test if inserting 10'000 positive consecutive numbers works.
bool MedianTrackerTestManager::Test4() {
    bool passed = true;
    BSTMedianTracker bstMedianTracker;
    float expectedMedianValue;
    float receivedMedianValue;

    bstMedianTracker.InsertNumber(0);
    expectedMedianValue = 0.0f;
    for (int i = 1; i <= 10000; i++) {
        bstMedianTracker.InsertNumber(i);
        expectedMedianValue += 0.5f;
        receivedMedianValue = bstMedianTracker.GetMedian();
        if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
            passed = false;
            printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
        }
    }

    return passed;
}

// Test if inserting 10'000 both negative and positive numbers works.
bool MedianTrackerTestManager::Test5() {
    bool passed = true;
    BSTMedianTracker bstMedianTracker;
    float expectedMedianValue;
    float receivedMedianValue;

    bstMedianTracker.InsertNumber(0);
    for (int i = 1; i <= 10000; i++) {
        if (i % 2 == 1) {
            bstMedianTracker.InsertNumber(i);
            expectedMedianValue = 0.5f;
        } else {
            bstMedianTracker.InsertNumber(-i);
            expectedMedianValue = 0.0f;
        }
        receivedMedianValue = bstMedianTracker.GetMedian();
        if (!CompareFloats(expectedMedianValue, receivedMedianValue)) {
            passed = false;
            printf(" Wrong median value calculated.\n Expected: %f, received: %f", expectedMedianValue, receivedMedianValue);
        }
    }

    return passed;
}
