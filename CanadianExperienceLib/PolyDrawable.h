/**
 * @file PolyDrawable.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_POLYDRAWABLE_H

#include "Drawable.h"

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class PolyDrawable : public Drawable {
private:
    /// The polygon color
    wxColour mColor = *wxBLACK;

    ///the collection of points that make up this polygon (drawable)
    std::vector<wxPoint> mPoints;

    ///path object
    wxGraphicsPath mPath;

public:

    /// Default constructor (disabled)
    PolyDrawable() = delete;

    /// Copy constructor (disabled)
    PolyDrawable(const PolyDrawable &) = delete;

    /// Assignment operator
    void operator=(const PolyDrawable &) = delete;


    ///Constructor
    PolyDrawable(const std::wstring &name);

    /**
     * gets the colour of the Polygon
     * @return the colour of the polygon
     */
    wxColour  GetColor() {return mColor; }

    /**
     * Sets the colour of the polygon
     * @param colour of the polygon
     */
     void SetColor(wxColour colour) { mColor = colour; }

     void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

     bool HitTest(wxPoint pos) override;

     void AddPoint(wxPoint point);









};

#endif //CANADIANEXPERIENCE_POLYDRAWABLE_H
