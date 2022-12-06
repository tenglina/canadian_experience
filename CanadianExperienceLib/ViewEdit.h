/**
 * @file ViewEdit.h
 * @author Charles B. Owen
 *
 * Basic edit view class for the Canadian Experience
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#ifndef CANADIANEXPERIENCE_VIEWEDIT_H
#define CANADIANEXPERIENCE_VIEWEDIT_H

#include "PictureObserver.h"
class Actor;
class Drawable;

/**
 * Basic edit view class for the Canadian Experience
 */
class ViewEdit final : public wxScrolledCanvas, public PictureObserver {
private:
    /// The last mouse position
    wxPoint mLastMouse = wxPoint(0, 0);


    /// The current mouse mode
    enum class Mode {Move, Rotate};

    /// The currently set mouse mode
    Mode mMode = Mode::Move;

    ///member variable holfing the actor that is selected
    std::shared_ptr<Actor> mSelectedActor;

    ///member variable holding the drawable that is selected
    std::shared_ptr<Drawable> mSelectedDrawable;




public:

    ViewEdit(wxFrame* parent);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

    void UpdateObserver() override;



    void OnEditMove(wxCommandEvent& event);
    void OnEditRotate(wxCommandEvent& event);


    void OnUpdateEditMove(wxUpdateUIEvent& event);
    void OnUpdateEditRotate(wxUpdateUIEvent& event);



};

#endif //CANADIANEXPERIENCE_VIEWEDIT_H
