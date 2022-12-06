/**
 * @file TimelineTest.cpp
 * @author Nandini Tengli
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <Timeline.h>
#include <AnimChannelAngle.h>

TEST(TimelineTest, NumFrames)
{
    Timeline timeline;

    // Default value
    ASSERT_EQ(300, timeline.GetNumFrames());

    // Set new value
    timeline.SetNumFrames(100);
    ASSERT_EQ(100, timeline.GetNumFrames());

    timeline.SetNumFrames(50);
    ASSERT_EQ(50, timeline.GetNumFrames());

}

TEST(TimelineTest, FrameRate)
{
    Timeline timeline;

    // Default value
    ASSERT_EQ(30, timeline.GetFrameRate());

    // set new frame rate and get new frame rate
    timeline.SetFrameRate(96.0);
    ASSERT_EQ(96, timeline.GetFrameRate());

    timeline.SetFrameRate(42);
    ASSERT_EQ(42, timeline.GetFrameRate());
}

TEST(TimelineTest, GetCurrentTime)
{
    Timeline timeline;

    // Default value
    ASSERT_NEAR(0, timeline.GetCurrentTime(), 0.00001);

    // new values
    timeline.SetCurrentTime(99.87);
    ASSERT_NEAR(99.87, timeline.GetCurrentTime(), 0.00001);

    timeline.SetCurrentTime(103.8779);
    ASSERT_NEAR(103.8779, timeline.GetCurrentTime(), 0.00001);

}

TEST(TimelineTest, GetDuration)
{
    Timeline timeline;

    // Default value
    ASSERT_NEAR(10, timeline.GetDuration(), 0.0001);

    // Changed duration
    timeline.SetFrameRate(375);
    ASSERT_NEAR(300.0 / 375.0, timeline.GetDuration(), 0.0001);

    timeline.SetNumFrames(789);
    ASSERT_NEAR(789.0 / 375.0, timeline.GetDuration(), 0.0001);
}

TEST(TimelineTest, GetCurrentFrame)
{
    Timeline timeline;

    // Default value
    ASSERT_EQ(0, timeline.GetCurrentFrame());

    // Changed time
    timeline.SetCurrentTime(9.27);
    ASSERT_EQ(278, timeline.GetCurrentFrame());
}

TEST(TimelineTest, Add)
{
    Timeline timeline;
    AnimChannelAngle channel;

    timeline.AddChannel(&channel);
    ASSERT_EQ(&timeline, channel.GetTimeline());
}