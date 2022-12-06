/**
 * @file ViewTimeline.cpp
 * @author Charles B. Owen
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include <sstream>

#include "ViewTimeline.h"
#include "Picture.h"
#include "TimelineDlg.h"
#include "Actor.h"

using namespace std;


/// Y location for the top of a tick mark
const int TickTop = 15;

/// The spacing between ticks in the timeline
const int TickSpacing = 4;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// Size of the tick mark labels
const int TickFontSize = 15;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

/// Filename for the pointer image
const std::wstring PointerImageFile = L"/pointer.png";


/**
 * Constructor
 * @param parent The main wxFrame object
 * @param path the path to the directory with images
 */
ViewTimeline::ViewTimeline(wxFrame* parent, std::wstring path) :
    wxScrolledCanvas(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(100, Height),
            wxBORDER_SIMPLE)
{
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
            &ViewTimeline::OnEditTimelineProperties, this,
            XRCID("EditTimelineProperties"));

    mImageDirPath = path;


    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::OnEditSetKeyframe, this,
                    XRCID("EditSetKeyframe"));
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::OnEditDeleteKeyframe, this,
                XRCID("EditDeleteKeyframe"));


}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    DoPrepareDC(dc);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    // Scrolling support
    auto size = GetPicture()->GetTimeline()->GetNumFrames()*TickSpacing + BorderLeft + BorderRight;
    SetVirtualSize(size, 30);
    SetScrollRate(1, 1);

    DrawTimeLine(graphics);

    mPointerImage = make_unique<wxImage>(mImageDirPath + PointerImageFile, wxBITMAP_TYPE_ANY);
    mPointerBitmap =  graphics->CreateBitmapFromImage(*mPointerImage);


    //drawing the timeline pointer
    double pointerPos = GetPicture()->GetTimeline()->GetCurrentFrame() * TickSpacing + 4;
    graphics->DrawBitmap(mPointerBitmap,
            pointerPos, TickTop,
            mPointerImage->GetWidth(),
            mPointerImage->GetHeight());


}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{

    auto click = CalcUnscrolledPosition(event.GetPosition());

    int x = click.x;

    // Get the timeline
    Timeline *timeline = GetPicture()->GetTimeline();
    int pointerX = (int)(timeline->GetCurrentTime() *
            timeline->GetFrameRate() * TickSpacing + 4);

    mMovingPointer = x >= pointerX - mPointerImage->GetWidth() / 2 &&
            x <= pointerX + mPointerImage->GetWidth() / 2;

//    if(mMovingPointer)
//    {
//        int xx = 0;
//
//    }



}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewTimeline::OnLeftUp(wxMouseEvent &event)
{


}

/**
* Handle the mouse move event
* @param event
*/
void ViewTimeline::OnMouseMove(wxMouseEvent &event)
{
    if (mMovingPointer && event.LeftIsDown())
    {
        auto click = CalcUnscrolledPosition(event.GetPosition());


        double time = static_cast<double>((click.x - BorderLeft)) / (GetPicture()->GetTimeline()->GetFrameRate() * TickSpacing);

        if(GetPicture()->GetTimeline()->GetDuration() < time)
        {
            GetPicture()->SetAnimationTime(GetPicture()->GetTimeline()->GetDuration());
        }
        else if(time < 0)
        {

            GetPicture()->SetAnimationTime(0);


        }
        else
        {
            GetPicture()->SetAnimationTime(time);

        }

    }
    else
    {
        mMovingPointer = false;
    }


}

/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
    Refresh();
    Update();
}

/**
 * Handle an Edit>Timeline Properties... menu option
 * @param event The menu event
 */
void ViewTimeline::OnEditTimelineProperties(wxCommandEvent& event)
{
    TimelineDlg dlg(this->GetParent(), GetPicture()->GetTimeline());
    if(dlg.ShowModal() == wxID_OK)
    {
        // The dialog box has changed the Tmeline settings
        GetPicture()->UpdateObservers();

    }
}

/**
 * Draws the timeline
 * @param graphics created and used in this window
 */
void ViewTimeline::DrawTimeLine(std::shared_ptr<wxGraphicsContext> graphics)
{
    double posx;
    wxPen pen(*wxBLACK, 1);
    graphics->SetPen(pen);
    bool onSecond;

    wxFont font(wxSize(0, 16),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    double numFrames = GetPicture()->GetTimeline()->GetNumFrames();
    for(int i = 0; i < numFrames + 1; ++i)
    {
        onSecond = (i % GetPicture()->GetTimeline()->GetFrameRate()) == 0;
        posx = TickSpacing*i + BorderLeft;
        if(not onSecond)
        {
            //short strokes
            graphics->StrokeLine(posx, TickTop, posx, TickTop + TickShort);

        }
        else
        {
           //Long strokes
            graphics->StrokeLine(posx, TickTop, posx, TickTop + TickLong);

            std::wstringstream str;
            std::wstring wstr;

            // Convert the tick number to seconds in a string
            str << i / GetPicture()->GetTimeline()->GetFrameRate();
            wstr = str.str();
            graphics->SetFont(font, *wxBLACK);
            double w;
            double h;
            graphics->GetTextExtent(wstr, &w, &h);
            graphics->SetPen(pen);
            graphics->SetFont(font, *wxBLACK);
            graphics->DrawText(wstr, posx - 0.5*w, TickTop + TickLong + 1);

        }
    }
}


/**
 * Handle Edit->Set Keyframe event
 * @param event
 */
void ViewTimeline::OnEditSetKeyframe(wxCommandEvent& event)
{
    auto picture = GetPicture();
    for (auto actor : *picture)
    {

        actor->SetKeyframe();

    }



}

/**
 * Handle Edit->Delete Keyframe event
 * @param event
 */
void ViewTimeline::OnEditDeleteKeyframe(wxCommandEvent& event)
{

    GetPicture()->GetTimeline()->DeleteKeyframe();
    GetPicture()->SetAnimationTime(GetPicture()->GetTimeline()->GetCurrentTime());

}


