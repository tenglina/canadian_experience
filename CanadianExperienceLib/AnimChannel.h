/**
 * @file AnimChannel.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNEL_H
#define CANADIANEXPERIENCE_ANIMCHANNEL_H

class Timeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */
class AnimChannel {
private:

    /// the name of this channel
    std::wstring mName;

    /// index to keyframe to the left of where we are at
    int mKeyframe1 = -1;

    /// index to the keyframe to the right of where we are at
    int mKeyframe2 = -1;

    /// The timeline object
    Timeline *mTimeline = nullptr;




protected:

    /// Default constructor
    AnimChannel() {} ;

    /// Class that represents a keyframe
    class Keyframe
    {
    private:

        /// the number of the frame
        int mFrame;

        /// The channel this keyframe is associated with
        AnimChannel * mChannel = nullptr;

    protected:
        /**
         * Constructor
         * @param channel Channel we are associated with
         */
        Keyframe(AnimChannel *channel) : mChannel(channel) {}

    public:

        ///// Default constructor (disabled)
        Keyframe() = delete;

        /// Copy constructor (disabled)
        Keyframe(const Keyframe &) = delete;

        /// Assignment operator
        void operator=(const Keyframe &) = delete;

        /**
         * Get frame
         * @return frame
         */
         int GetFrame() const {return mFrame; }

         /**
          * Set frame
          * @param frame the frame to be set
          */
          void SetFrame(int frame) { mFrame = frame; }

          /**
           * sets the keyframe to be used as 1
           */
          virtual void UseAs1() =0;

          /**
           * sets the keyframe to be used as 2
           */
          virtual void UseAs2() =0;

          /**
           * sets the keyframe to be used as 3
           */
          virtual void UseOnly() =0;
    };


    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);


    /**
     * calculates positions and angles in between key frames
     * @param t the percetage of distance we are
     * from the left key frame with respect to the right keyframe
     */
    virtual void Tween(double t) =0;

private:
    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;

public:

    ///destructor
    virtual ~AnimChannel() {}

    /// Copy constructor (disabled)
    AnimChannel(const AnimChannel &) = delete;

    /// Assignment operator
    void operator=(const AnimChannel &) = delete;



    /**
     * get the name of the animation channel
     * @return name of the animation channel
     */
    std::wstring GetName() const { return mName; }

    /**
     * Sets the name of the animation channel
     * @param name the name of the animation channel
     * to be set
     */
     void SetName(std::wstring name) {mName = name; }


     bool IsValid();


     void SetFrame(int frame);


     /**
      * sets the pointer to the timeline in this object
      * @param timeline the timeline this channel
      * is associated with
      */
     void SetTimeline(Timeline * timeline) { mTimeline = timeline; }


     /**
      * Get pointer to timeline that this channel is associated with
      * @return timeline the timeline pointer
      */
      Timeline * GetTimeline() { return mTimeline; }


      /**
       * Deletes the current frame if present
       *
       */
      void DeleteFrame();










};

#endif //CANADIANEXPERIENCE_ANIMCHANNEL_H
