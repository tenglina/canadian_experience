/**
 * @file ImageDrawable.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_IMAGEDRAWABLE_H

#include "Drawable.h"

/**
 * class that draws objects with images
 */
class ImageDrawable : public Drawable{
private:

    ///the center of the object
    wxPoint mCenter = wxPoint(0,0);



protected:
    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;


public:

    ///// Default constructor (disabled)
    ImageDrawable() = delete;

    /// Copy constructor (disabled)
    ImageDrawable(const ImageDrawable &) = delete;

    /// Assignment operator
    void operator=(const ImageDrawable &) = delete;


    ///Constructor
    ImageDrawable(const std::wstring &name, const std::wstring &filename);



    /**
     * Get the center of the image
     * @return point the center point of the image
     */
     wxPoint GetCenter() { return mCenter; }

     /**
      * Set the center of the image
      * @param center the center point of the image
      */
      void SetCenter(wxPoint center) { mCenter = center; }

      void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

      bool HitTest(wxPoint pos) override;

};

#endif //CANADIANEXPERIENCE_IMAGEDRAWABLE_H
