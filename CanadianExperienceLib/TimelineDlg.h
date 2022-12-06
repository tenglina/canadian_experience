/**
 * @file TimelineDlg.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_TIMELINEDLG_H
#define CANADIANEXPERIENCE_TIMELINEDLG_H

class Timeline;
/**
 * Timeline dialog box
 */
class TimelineDlg final : public wxDialog {
private:

    ///the timeline used by this app
    Timeline * mTimeline;

    /// Number of frames in the animation
    int mNumberOfFrames;

    /// Frame rate of animation
    int mFrameRate;

public:
    
    /// Default constructor (disabled)
    TimelineDlg() = delete;
    
    /// Copy constructor (disabled)
    TimelineDlg(const TimelineDlg &) = delete;
    
    /// Assignment operator
    void operator=(const TimelineDlg &) = delete;
    
    
    /// Constructor
    TimelineDlg(wxWindow* parent, Timeline* timeline);

    void OnOK(wxCommandEvent& event);

};

#endif //CANADIANEXPERIENCE_TIMELINEDLG_H
