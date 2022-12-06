/**
 * @file PolyDrawable.cpp
 * @author Nandini Tengli
 */

#include "pch.h"
#include "PolyDrawable.h"

/**
 * construcst the polygon type we are drawing
 * @param name the name of polygon we are constructing
 * for the polygon
 */
PolyDrawable::PolyDrawable(const std::wstring& name)
        :Drawable(name)
{

}

/**
 * Adds point to the object
 * @param point point to be added to the object
 */
void PolyDrawable::AddPoint(wxPoint point)
{
    mPoints.push_back(point);

}

/**
 * Draws the polygon
 * @param graphics the graphics context we are using to draw
 */
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!mPoints.empty()) {

        wxGraphicsPath path = graphics->CreatePath();


        path.MoveToPoint(RotatePoint(mPoints[0], mPlacedR) + mPlacedPosition);
        for (auto i = 1; i<mPoints.size(); i++)
        {
            path.AddLineToPoint(RotatePoint(mPoints[i], mPlacedR) + mPlacedPosition);
        }
        path.CloseSubpath();

        wxBrush brush(mColor);
        graphics->SetBrush(brush);
        graphics->FillPath(path);

        mPath = path;



    }


}


/**
 * Tests if a given position is inside the polygon
 * @param pos
 * @return true if the position is inside the polygon
 */
bool PolyDrawable::HitTest(wxPoint pos)
{
    return mPath.Contains(pos);
}
