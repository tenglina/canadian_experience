/**
 * @file Drawable.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_DRAWABLE_H
#define CANADIANEXPERIENCE_DRAWABLE_H

class Actor;
class Timeline;


/**
 * Abstract base class for drawable elements of our picture.
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
#include <memory>
#include "AnimChannelAngle.h"


class Drawable {
private:

    ///the position of the Drawable
    wxPoint mPosition = wxPoint(0,0);

    ///the name of the Drawable
    std::wstring mName;

    ///the rotation of the Drawable?
    double mRotation = 0;

    /// The actor using this drawable
    Actor *mActor = nullptr;


    ///The childer of this Drawable
    std::vector<std::shared_ptr<Drawable>> mChildren;

    ///The parent of this Drawable object
    Drawable * mParent = nullptr;

    /// The animation channel for animating the angle of this drawable
    AnimChannelAngle mChannel;


protected:

    ///the placed position of the drawable
    wxPoint mPlacedPosition = wxPoint(0,0);

    ///the placed position of the drawable
    double mPlacedR = 0;


    ///Constructor
    Drawable(const std::wstring &name);


    ///Rotates a given point by a given angle
    wxPoint RotatePoint(wxPoint point, double angle);



public:

    /// Default constructor (disabled)
    Drawable() = delete;

    /// Copy constructor (disabled)
    Drawable(const Drawable &) = delete;

    /// Assignment operator (disabled)
    void operator=(const Drawable &) = delete;

    /**
     * Gets the name of the drawable
     * @return name of the drawable
     *
     */
     std::wstring GetName() const { return mName; }

     /**
      * Get the position of the drawable
      * @return position of the drawable
      */
     wxPoint GetPosition() const { return mPosition; }

      /**
       * Set position of the drawable
       * @param pos the new position of the drawable to be set
       */
      void SetPosition(wxPoint pos) { mPosition = pos; }

       /**
        * Get the rotation of the drawable
        * @return the rotataion of the drawable
        */
       double GetRotation() const {return mRotation; }

        /**
         * Set rotation of the drawable
         * @param rot the rotation amount of the drawable to be set
         *
         */
        void SetRotation(double rot) { mRotation = rot; }


        /**
         * virtual function that draws on the picture
         *
         * @param graphics the graphics context which we draw
         */

        virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

        void SetActor(Actor *actor);


        /**
         * checks if this drawable has been clicked on
         * @param pos the position to test
         * @return true if position is that if this drawable
         */
        virtual bool HitTest(wxPoint pos) = 0;

        /**
         * determines if this drawable is movable
         * @return true if this drawbale is movable
         */
        virtual bool IsMovable() { return false; }


        virtual void Move(wxPoint delta);



        void Place(wxPoint offset, double rotate);

        void AddChild(std::shared_ptr<Drawable> child);

        /**
         * Sets the parent of this drawable
         * @param parent the parent pointer to this drawable
         */
        void SetParent(Drawable * parent) { mParent = parent; }

        /**
         * Get the parent of this drawable
         * @return parent pointer of this drawable
         */
         Drawable * GetParent() { return mParent; }


         virtual void SetTimeline(Timeline *timeline);

         /**
        * The angle animation channel
        * @return Pointer to animation channel
        */
        AnimChannelAngle* GetAngleChannel() { return &mChannel; }

        virtual void SetKeyframe();

        virtual void GetKeyframe();


};

#endif //CANADIANEXPERIENCE_DRAWABLE_H
