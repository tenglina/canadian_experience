/**
 * @file Picture.cpp
 * @author Nandini Tengli
 */


#include "pch.h"
#include "Picture.h"
#include "PictureObserver.h"
#include "Actor.h"



/**
 * Add an observer to this picture.
 * @param observer The observer to add
 */
void Picture::AddObserver(PictureObserver* observer)
{
    mObservers.push_back(observer);
}

/**
 * Remove an observer from this picture
 * @param observer The observer to remove
 */
void Picture::RemoveObserver(PictureObserver* observer)
{
    auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
    if (loc != std::end(mObservers))
    {
        mObservers.erase(loc);
    }
}

/**
 * Update all observers to indicate the picture has changed.
 */
void Picture::UpdateObservers()
{
    for (auto observer : mObservers)
    {
        observer->UpdateObserver();
    }
}

/**
 * draws the picture
 * @param graphics the graphics context we are drawing with
 */
void Picture::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto actor : mActors)
    {
        actor->Draw(graphics);
    }



}

/**
 * adds an actor to the picture
 * @param actor shared pointer to the actor
 * we are adding
 */

void Picture::AddActor(std::shared_ptr<Actor> actor)
{
    mActors.push_back(actor);
    actor->SetPicture(this);
}


/**
 * Set the current animation time
 *
 * This forces the animation of all
 * objects to the current animation location.
 * @param time The new time.
 */
void Picture::SetAnimationTime(double time)
{
    mTimeline.SetCurrentTime(time);


    for (auto actor : mActors)
    {

        actor->GetKeyframe();
//        actor->SetPosition(actor->GetPositionChannel()->GetPoint());
    }

    UpdateObservers();

}