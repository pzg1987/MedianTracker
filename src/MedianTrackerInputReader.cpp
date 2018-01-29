#include "MedianTrackerInputReader.h"

#include <cstdio>

const MedianTrackerInput& MedianTrackerInputReader::ObtainInput() {
    // Reset the input.
    input.type_ = MedianTrackerInputType::NONE;
    input.value_ = 0;

    // Get a single character from standard input omitting spaces.
    int character = getc(stdin);
    while (character == ' ') {
        character = getc(stdin);
    }

    // Assign input type based on the retrieved character.
    if (character == 'm') {
        input.type_ = MedianTrackerInputType::MEDIAN_REQUEST;
    } else if (character == 'q') {
        input.type_ = MedianTrackerInputType::QUIT_REQUEST;
    } else if (character == '-' || (character >= '0' && character <= '9')) {
        input.type_ = MedianTrackerInputType::NUMBER;
        // If this is a number then put back the first digit and read a whole integer at once.
        ungetc(character, stdin);
        scanf("%d", &input.value_);
    }

    return input;
}
