#ifndef _DEMOPI_H_
#define _DEMOPI_H_

#include "wx/wxprec.h"
#include "wx/timer.h"

#ifndef  WX_PRECOMP
#include <wx/wx.h>
#endif //precompiled headers

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    1

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    8

#define     NOAADOPPLER_TOOL_POSITION    -1          // Request default positioning of toolbar tool


#include "../include/opencpn/ocpn_plugin.h"
#include "noaa_control_panel.h"
#include "gfw.h"
#include "doppler_image.h"

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------
class noaa_doppler_pi : public opencpn_plugin_18, wxEvtHandler
{
public:
    noaa_doppler_pi(void* ppimgr);

    //    The required PlugIn Methods
    int Init(void);
    bool DeInit(void);

    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();

    wxBitmap *GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();

    //    The Plugin Specific Methods
    void SetDopplerVisibility(bool visible);

    //    The override PlugIn Methods
    void OnToolbarToolCallback(int id);
    void OnContextMenuItemCallback(int id);
    bool RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp);
    void SetCursorLatLon(double lat, double lon);
    bool RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp);
    int GetToolbarToolCount(void);
    void SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix);


private:
    //Private Methods
    void ResetToolbarIcon();
    void ShowPropertiesWindow();

    // UI Windows
    noaa_control_panel  *m_controlPanelWindow;
    wxWindow            *m_parent_window;
    wxAuiManager        *m_AUImgr;
    wxFileConfig        *m_pconfig;
    doppler_image       *m_overlayImage;
    int                 m_show_id;
    int                 m_hide_id;
    int                 m_toolbar_item_id;
    bool                m_showDoppler;
};
#endif


