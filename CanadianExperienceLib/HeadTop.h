/**
 * @file HeadTop.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_HEADTOP_H
#define CANADIANEXPERIENCE_HEADTOP_H

#include "ImageDrawable.h"
#include "AnimChannelPos.h"
#include "Timeline.h"

/**
 * the class that describes the top head (of an actor)
 */

class HeadTop : public ImageDrawable{
private:

    ///a reference point for drawing eyes and eyebrows
    wxPoint mEyePos = wxPoint(45, 65);

    /// The animation channel for animating the position of headtop
    AnimChannelPos mChannelPos;

public:

    ///// Default constructor (disabled)
    HeadTop() = delete;

    /// Copy constructor (disabled)
    HeadTop(const HeadTop &) = delete;

    /// Assignment operator
    void operator=(const HeadTop &) = delete;


    ///constructor
    HeadTop(const std::wstring &name, const std::wstring &filename);



    bool IsMovable() override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;


     void DrawEyebrows(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p);

     wxPoint TransformPoint(wxPoint p);

     void DrawEyes(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p);

     /**
      * sets an initial position relative to
      * which the eyes and eyebrows can be drawn
      * @param p the reference position to be set
      */
     void SetEyePos(wxPoint p) { mEyePos = p; }


     void SetKeyframe() override;

     void GetKeyframe() override;

     void SetTimeline(Timeline *timeline) override;

};

#endif //CANADIANEXPERIENCE_HEADTOP_H
