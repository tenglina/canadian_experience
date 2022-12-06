/**
 * @file ViewTimeline.h
 * @author Charles B. Owen
 *
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H

#include "PictureObserver.h"

/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxScrolledCanvas, public PictureObserver{
private:

    /// Bitmap image for the pointer
    std::unique_ptr<wxImage> mPointerImage;

    /// Graphics bitmap to display
    wxGraphicsBitmap mPointerBitmap;


    /// Path to the image directory
    std::wstring mImageDirPath;

    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);



    /// Flag to indicate we are moving the pointer
    bool  mMovingPointer = false;




public:
    static const int Height = 90;      ///< Height to make this window

    /// Default constructor (disabled)
    ViewTimeline() = delete;

    /// Copy constructor (disabled)
    ViewTimeline(const ViewTimeline &) = delete;

    /// Assignment operator
    void operator=(const ViewTimeline &) = delete;


    ///constructor
    ViewTimeline(wxFrame* parent, std::wstring path);

    ///updates the observer
    void UpdateObserver() override;

    void OnEditTimelineProperties(wxCommandEvent& event);


    void DrawTimeLine(std::shared_ptr<wxGraphicsContext> graphics);

    void OnEditSetKeyframe(wxCommandEvent& event);
    void OnEditDeleteKeyframe(wxCommandEvent& event);


};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
