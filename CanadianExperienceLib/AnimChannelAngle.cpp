/**
 * @file AnimChannelAngle.cpp
 * @author Nandini Tengli
 */


#include "pch.h"
#include "AnimChannelAngle.h"

/**
 * Set a keyframe
 *
 * This function allocates a new keyframe and sends it to
 * AnimChannel, which will insert it into the collection of keyframes.
 * @param angle Angle for the keyframe.
 */
void AnimChannelAngle::SetKeyframe(double angle)
{
    // Create a keyframe of the appropriate type
    // Telling it this channel and the angle
    auto keyframe = std::make_shared<KeyframeAngle>(this, angle);

    // Insert it into the collection
    InsertKeyframe(keyframe);
}


/**
 * calculates angles of drawables between keyframes
 * @param t the percentage of distance covered
 * between the two keyframes (to the left of where
 * we are and to the right of where we are)
 */
void AnimChannelAngle::Tween(double t)
{
    mAngle = mKeyframe1->GetAngle() * (1 - t) +
            mKeyframe2->GetAngle() * t;
}
