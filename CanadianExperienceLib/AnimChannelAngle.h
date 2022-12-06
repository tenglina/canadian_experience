/**
 * @file AnimChannelAngle.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNELANGLE_H
#define CANADIANEXPERIENCE_ANIMCHANNELANGLE_H

#include "AnimChannel.h"

/**
 * Animation channel for angles.
 */
class AnimChannelAngle : public AnimChannel {
private:

    /// angle in this channel
    double mAngle;

protected:

    /**
     * class that describes a keyframe in this channel 
     */
    class KeyframeAngle : public Keyframe{
        private:

            /// the angle tracked by this channel
            double mAngle = 0;

        /// The channel this keyframe is associated with
        AnimChannelAngle *mChannel;


    public:

        ///// Default constructor (disabled)
        KeyframeAngle() = delete;

        /// Copy constructor (disabled)
        KeyframeAngle(const KeyframeAngle &) = delete;

        /// Assignment operator
        void operator=(const KeyframeAngle &) = delete;

        /**
         * Constructor
         * @param channel The channel we are for
         * @param angle The angle for the keyframe
         */
        KeyframeAngle(AnimChannelAngle *channel, double angle) :
                Keyframe(channel), mChannel(channel), mAngle(angle) {}


        /**
         * getter for angle
         * @return angle
         */
         double GetAngle() const { return mAngle; }



        /// Use this keyframe as keyframe 1
        void UseAs1() override { mChannel->mKeyframe1 = this; }

        /// Use this keyframe as keyfraem 2
        void UseAs2() override { mChannel->mKeyframe2 = this; }

        /// Use this keyframe as the angle
        void UseOnly() override { mChannel->mAngle = mAngle; }

    };

    void Tween(double t) override;

private:

    /// The first angle keyframe
    KeyframeAngle *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle *mKeyframe2 = nullptr;

public:


    /// Default constructor
    AnimChannelAngle() {}

    /// Copy constructor (disabled)
    AnimChannelAngle(const AnimChannelAngle &) = delete;

    /// Assignment operator
    void operator=(const AnimChannelAngle &) = delete;


    /**
     * get angle of channel
     * @return Angle
     */
     double GetAngle() const { return mAngle; }

     void SetKeyframe(double angle);




};

#endif //CANADIANEXPERIENCE_ANIMCHANNELANGLE_H
