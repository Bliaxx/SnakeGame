#pragma once

#include <gmock/gmock.h>
#include "ScoreManager.h"

class MockScoreManager : public ScoreManager {
public:
    MOCK_METHOD(void, AddScore, (int value), (override));
    MOCK_METHOD(void, ResetScore, (), (override));
    MOCK_METHOD(int, GetScore, (), (const, override));
};
