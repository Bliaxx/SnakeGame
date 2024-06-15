#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ScoreDisplayTest.h"
#include "TransformComponentTest.h"
#include "FoodTest.h"
#include "InputManagerTest.h"

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}