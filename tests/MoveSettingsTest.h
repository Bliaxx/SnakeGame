#pragma once

#include <gtest/gtest.h>
#include "MoveSettings.h"

class MoveSettingsTest : public ::testing::Test {
protected:
    MoveSettings* moveSettings;

    virtual void SetUp() {
        moveSettings = new MoveSettings(1.0f);
    }

    virtual void TearDown() {
        delete moveSettings;
    }
};

TEST_F(MoveSettingsTest, InitialSpeed) {
    ASSERT_EQ(moveSettings->GetSpeed(), 1.0f);
}

TEST_F(MoveSettingsTest, SetSpeed) {
    moveSettings->SetSpeed(2.0f);
    ASSERT_EQ(moveSettings->GetSpeed(), 2.0f);
}

TEST_F(MoveSettingsTest, UpdateSpeed) {
    moveSettings->SetSpeed(1.5f);
    ASSERT_EQ(moveSettings->GetSpeed(), 1.5f);

    moveSettings->SetSpeed(3.0f);
    ASSERT_EQ(moveSettings->GetSpeed(), 3.0f);
}
