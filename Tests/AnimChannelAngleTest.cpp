/**
 * @file AnimChannelAngleTest.cpp
 * @author Nandini Tengli
 */
 
#include <pch.h>
#include "gtest/gtest.h"

#include <AnimChannelAngle.h>


TEST(AnimChannelAngleTest, GetName)
{
    AnimChannelAngle animChannelAngle;

    //default name
    std::wstring name = animChannelAngle.GetName();
    ASSERT_EQ(L"", name);

    // Set name
    std::wstring name1 = std::wstring(L"angle1");
    animChannelAngle.SetName(name1);
    ASSERT_EQ(name1, animChannelAngle.GetName());



}