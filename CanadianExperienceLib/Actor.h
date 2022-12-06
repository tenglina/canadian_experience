/**
 * @file Actor.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ACTOR_H
#define CANADIANEXPERIENCE_ACTOR_H

class Drawable;
class Picture;

#include "AnimChannelPos.h"


/**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class Actor {
private:

    /// The actors Name
    std::wstring mName;

    /// The enabled(Drawable) Status of the Actor
    bool mEnabled = true;

    ///the position of the Actor
    wxPoint mPosition = wxPoint(0,0);

    /// The clikable staus of the Actor
    bool mClickable = true;

    ///The root drawable
    std::shared_ptr<Drawable>  mRoot;


    /// The collection of drawable objects associated with this actor
    std::vector<std::shared_ptr<Drawable>> mDrawablesInOrder;


    ///the pointer to the picture this actor is a part of
    Picture * mPicture = nullptr;


    /// The animation channel for animating the position of this drawable
    AnimChannelPos mChannelPos;


public:

    /// Default constructor (disabled)
    Actor() = delete;

    /// Copy constructor (disabled)
    Actor(const Actor &) = delete;

    /// Assignment operator
    void operator=(const Actor &) = delete;

    ///constructor
    Actor(const std::wstring &name);

    /// Destructor
    virtual ~Actor() {}


    void SetRoot(std::shared_ptr<Drawable> root);

    void Draw(std::shared_ptr<wxGraphicsContext> ) ;

    std::shared_ptr<Drawable> HitTest(wxPoint pos);

    void AddDrawable(std::shared_ptr<Drawable> drawable);

    /**
    * Get the actor name
    * @return Actor name
    * */
    std::wstring GetName() const { return mName; }

    /**
     * Actor is enabled
     * @return enabled status
     */
    bool IsEnabled() const { return mEnabled; }

    /**
     * Set Actor enabled
     * @param enabled New enabled status
     */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /**
     * Get the position of the actor
     * @return position of the actor
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * Sets the postion of the actor
     * @param position the position of the actor
     */
     void SetPosition(wxPoint position) { mPosition = position; }

     /**
      * Gets the status of clickable of actor
      * @return the clickable status of the actor
      */
      bool IsClickable() const { return mClickable; }

      /**
       * sets the clickable status of the actor
       * @param clickableStatus the clickable status for actor
       */
       void SetClickable(bool clickableStatus) { mClickable = clickableStatus; }


       /**
        * Get the pciture this actor is a part of
        * @return picture this actor is a part of
        */
       Picture* GetPicture() { return mPicture; }



    void  SetPicture(Picture * picture);

    void SetKeyframe();
    void GetKeyframe();

    /**
     * gets position channel of the actor
     * @return position channel of actor
     */
    AnimChannelPos * GetPositionChannel() { return &mChannelPos; }









};

#endif //CANADIANEXPERIENCE_ACTOR_H
