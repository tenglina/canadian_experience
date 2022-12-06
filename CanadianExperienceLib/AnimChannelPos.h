/**
 * @file AnimChannelPos.h
 * @author Nandini Tengli
 *
 *
 */


/**
 * Animation channel for positions.
 */
#ifndef CANADIANEXPERIENCE_ANIMCHANNELPOS_H
#define CANADIANEXPERIENCE_ANIMCHANNELPOS_H


#include "AnimChannel.h"

class AnimChannelPos : public AnimChannel{
private:

    /// the position tracked by this channel
    wxPoint mPoint;

protected:

    /**
     * class that describes a keyframe in this channel
     */
    class KeyframePos : public Keyframe
    {
        private:

            /// the position tracked by this keyframe
            wxPoint mPoint = wxPoint(0,0);

            /// the channel associated with this keyframe
            AnimChannelPos *mChannel;

        public:
        
            ///// Default constructor (disabled)
            KeyframePos() = delete;
            
            /// Copy constructor (disabled)
            KeyframePos(const KeyframePos &) = delete;
            
            /// Assignment operator
            void operator=(const KeyframePos &) = delete;



            /// Use this keyframe as keyframe 1
            void UseAs1() override { mChannel->mKeyframe1 = this; }

            /// Use this keyframe as keyfraem 2
            void UseAs2() override { mChannel->mKeyframe2 = this; }

            /// Use this keyframe as the angle
            void UseOnly() override { mChannel->mPoint = mPoint; }

            /** 
            * Constructor
            * @param channel The channel we are for
            * @param point The position for the keyframe
             */
            KeyframePos(AnimChannelPos *channel, wxPoint point) :
            Keyframe(channel), mChannel(channel), mPoint(point) { }

            /**
             * gets the position tracked by this keyframe
             * @return position tacked by this keyframe
             */
            wxPoint GetPosition() { return mPoint; }

    };

    void Tween(double t) override;

private:

    /// The first position keyframe
    KeyframePos *mKeyframe1 = nullptr;

    /// The second position keyframe
    KeyframePos *mKeyframe2 = nullptr;




public:

    /// Default constructor
    AnimChannelPos() {}

    /// Copy constructor (disabled)
    AnimChannelPos(const AnimChannelPos &) = delete;

    /// Assignment operator
    void operator=(const AnimChannelPos &) = delete;


    void SetKeyframe(wxPoint point);

    /**
     * gets position of actor or drawable associated with this channel
     * @return position of actor/drawable of this channel
     */
    wxPoint GetPoint() { return mPoint; }




};

#endif //CANADIANEXPERIENCE_ANIMCHANNELPOS_H
