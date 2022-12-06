/**
 * @file AnimChannelPos.cpp
 * @author Nandini Tengli
 */


#include "pch.h"
#include "AnimChannelPos.h"


/**
 * sets a keyframe
 * @param point the position tracked by this key frame
 * that is the current position
 */
void AnimChannelPos::SetKeyframe(wxPoint point)
{

    // Create a keyframe of the appropriate type
    // Telling it this channel and the angle
    auto keyframe = std::make_shared<KeyframePos>(this, point);

    // Insert it into the collection
    InsertKeyframe(keyframe);

}


/**
 * calculates position between keyframes
 * @param t the percentage of distance covered
 * between the two keyframes (to the left of where
 * we are and to the right of where we are)
 */
void AnimChannelPos::Tween(double t)
{
    wxPoint a = mKeyframe1->GetPosition();
    wxPoint b = mKeyframe2->GetPosition();

    mPoint = wxPoint(int(a.x + t * (b.x - a.x)),
            int(a.y + t * (b.y - a.y)));

}
