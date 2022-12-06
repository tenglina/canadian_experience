/**
 * @file PictureObserver.h
 * @author Nandini Tengli
 *
 *
 */



#ifndef CANADIANEXPERIENCE_PICTUREOBSERVER_H
#define CANADIANEXPERIENCE_PICTUREOBSERVER_H

class Picture;

#include <memory>


/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class PictureObserver {
private:

    /// Picture we are observing
    std::shared_ptr<Picture> mPicture;


protected:
    /// Constructor
    PictureObserver() {}


public:

   virtual  ~PictureObserver();

    /// Copy Constructor (Disabled)
    PictureObserver(const PictureObserver &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const PictureObserver &) = delete;

    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;

    /**
     * Gets the picture that this observer observes
     * @return picture that the observer observes
     */
    std::shared_ptr<Picture> GetPicture() {return mPicture;}


    void SetPicture(std::shared_ptr<Picture> picture);


};

#endif //CANADIANEXPERIENCE_PICTUREOBSERVER_H
