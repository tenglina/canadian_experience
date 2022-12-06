/**
 * @file HeadTop.cpp
 * @author Nandini Tengli
 */

#include "pch.h"
#include "HeadTop.h"



/**
 * constructor for this class
 * @param name the name of this object
 * @param filename the image filename of the object
 */
HeadTop::HeadTop(const std::wstring& name, const std::wstring& filename)
        :ImageDrawable(name, filename)
{


}

/**
 * checks if the headTop is a movable object
 * @return true if we can move this object
 */
bool HeadTop::IsMovable()
{
    return true;
}

/**
 * Draws this head top
 *  @param graphics the graphics context for our picture
 */
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ImageDrawable::Draw(graphics);



    DrawEyebrows(graphics, mEyePos);


    DrawEyes(graphics, mEyePos);


}


/**
 * Draws the eyebrows on the head
 * @param graphics the graphics context on which we are drawing
 * @param p an initial position relative to the top of this headTop
 */

void HeadTop::DrawEyebrows(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p)
{

    //Left eyebrow points
    wxPoint p1 = TransformPoint(p);
    wxPoint p2 = TransformPoint(wxPoint (p.x - 20, p.y));

    //Right eyebrow points
    wxPoint p3 = TransformPoint(wxPoint(p.x + 20, p.y));
    wxPoint p4 = TransformPoint(wxPoint (p.x + 40, p.y));


    wxPen eyebrowPen(*wxBLACK, 2);
    graphics->SetPen(eyebrowPen);

    //draw Left eyebrow
    graphics->StrokeLine(p1.x, p1.y,
            p2.x,  p2.y);

    //draw right eyebrow
    graphics->StrokeLine(p3.x, p3.y ,
           p4.x,  p4.y);

}




/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
 * Draws the eyes on the head
 * @param graphics the graphics context on which we are drawing
 * @param p an initial position relative to the top of this headTop
 */
void HeadTop::DrawEyes(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p)
{

    wxPen eyePen(*wxBLACK, 2);
    graphics->SetPen(eyePen);
    wxBrush eyeBrush(*wxBLACK);
    graphics->SetBrush(eyeBrush);

    float wid = 15.0f;
    float hit = 10.0f;

    wxPoint e1 = TransformPoint(wxPoint(p.x - 10, p.y + 13));
    wxPoint e2 = TransformPoint(wxPoint(p.x + 30, p.y + 13));

    //eye 1
    graphics->PushState();
    graphics->Translate(e1.x, e1.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();

    //eye 2
    graphics->PushState();
    graphics->Translate(e2.x, e2.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();

}


/**
 * sets the keyframe for the position and angle we are at
 */
void HeadTop::SetKeyframe()
{
    Drawable::SetKeyframe();

    mChannelPos.SetKeyframe(GetPosition());


}

/**
 * updates the position and angle of drawable according to
 * the key frame we are on
 */
void HeadTop::GetKeyframe()
{
    Drawable::GetKeyframe();

    if (mChannelPos.IsValid())
        SetPosition(mChannelPos.GetPoint());


}


/**
 * adds the channel this drawable is associated with to the timeline
 * links this drawable (head top) to the timeline
 * @param timeline
 */
void HeadTop::SetTimeline(Timeline *timeline)
{
    //set timeline for the angle channel
    Drawable::SetTimeline(timeline);

    //add position channel to timeline
    timeline->AddChannel(&mChannelPos);

}
