/**
 * @file Timeline.cpp
 * @author Nandini Tengli
 */

#include "pch.h"
#include "Timeline.h"
#include "AnimChannel.h"


/**
 * Constructor
 */
Timeline::Timeline()
{
}

/**
 * adds an animation channel to the timeline
 * @param channel the channel to be added
 */
void Timeline::AddChannel(AnimChannel *channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);

}

/**
 * Sets the current time
 *
 * Ensures all of the channels are
 * valid for that point in time.
 * @param t The new time to set
 */
void Timeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}


/**
 * iterates over all channels
 * calling delete keyframe on each to delete the keyframe we are on
 */
void Timeline::DeleteKeyframe()
{
    for(auto channel: mChannels)
    {
        channel->DeleteFrame();
    }

}
