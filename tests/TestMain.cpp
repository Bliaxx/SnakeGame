#include "ScoreDisplayTest.h"
#include "TransformComponentTest.h"
#include "FoodTest.h"
#include "InputManagerTest.h"
#include "ScoreManagerTest.h"
#include "MoveSettingsTest.h"
#include "SnakeSegmentTest.h"
#include "SnakeTest.h"

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}