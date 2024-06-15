#pragma once

#include <gtest/gtest.h>
#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include "MockWindow.h"


class InputManagerTest : public ::testing::Test {
protected:
    InputManager inputManager;
    std::unique_ptr<MockWindow> mockWindow;
    sf::Event event;

    virtual void SetUp() override {
        mockWindow = std::make_unique<MockWindow>();
    }

    virtual void TearDown() override {
        mockWindow.reset();
    }
};

TEST_F(InputManagerTest, BindKey) {
    inputManager.BindKey(sf::Keyboard::A, "ActionA");
    inputManager.BindKey(sf::Keyboard::B, "ActionB");

    inputManager.BindAction("ActionA", []() { SUCCEED(); });
    inputManager.BindAction("ActionB", []() { SUCCEED(); });

    EXPECT_CALL(*mockWindow, pollEvent(testing::_))
        .WillOnce(testing::DoAll(testing::SetArgReferee<0>(event), testing::Return(true)))
        .WillRepeatedly(testing::Return(false));

    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::A;

    inputManager.ProcessInput(mockWindow.get());
}

TEST_F(InputManagerTest, BindAction) {
    bool actionCalled = false;
    inputManager.BindAction("TestAction", [&actionCalled]() { actionCalled = true; });

    inputManager.BindKey(sf::Keyboard::C, "TestAction");

    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::C;

    EXPECT_CALL(*mockWindow, pollEvent(testing::_))
        .WillOnce(testing::DoAll(testing::SetArgReferee<0>(event), testing::Return(true)))
        .WillRepeatedly(testing::Return(false));

    inputManager.ProcessInput(mockWindow.get());

    ASSERT_TRUE(actionCalled);
}

TEST_F(InputManagerTest, ProcessInput_CloseWindow) {
    event.type = sf::Event::Closed;

    EXPECT_CALL(*mockWindow, pollEvent(testing::_))
        .WillOnce(testing::DoAll(testing::SetArgReferee<0>(event), testing::Return(true)))
        .WillRepeatedly(testing::Return(false));

    EXPECT_CALL(*mockWindow, close()).Times(1);

    inputManager.ProcessInput(mockWindow.get());
}