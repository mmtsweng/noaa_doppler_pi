
#ifndef  WX_PRECOMP
#include <wx/wx.h>
#endif //precompiled headers

#include <wx/aui/aui.h>
#include "noaa_doppler_pi.h"
#include "icons.h"

// the class factories, used to create and destroy instances of the PlugIn
extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new noaa_doppler_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//UI Elements
wxWindow        *m_parent_window;
wxAuiManager    *m_AUImgr;

/*
    Constructor
        Initialize Images
*/
noaa_doppler_pi::noaa_doppler_pi(void *ppimgr)
    : opencpn_plugin_18(ppimgr)
{
    initialize_images();
}


/*
    Initialization
*/
int noaa_doppler_pi::Init(void)
{
    wxLogMessage(_T("NOAADOPPLER: Initializing"));

    // Get a pointer to the opencpn display canvas, to use as a parent for windows created
    m_parent_window = GetOCPNCanvasWindow();

    // Get a reference to the OCPN Configuration object
    //m_pconfig = GetOCPNConfigObject();

    // Create the Context Menu Items

    //    In order to avoid an ASSERT on msw debug builds,
    //    we need to create a dummy menu to act as a surrogate parent of the created MenuItems
    //    The Items will be re-parented when added to the real context meenu
    wxMenu dummy_menu;

    wxMenuItem *pmi = new wxMenuItem(&dummy_menu, -1, _("Show PlugIn DemoWindow"));
    m_show_id = AddCanvasContextMenuItem(pmi, this );
    SetCanvasContextMenuItemViz(m_show_id, true);

    wxMenuItem *pmih = new wxMenuItem(&dummy_menu, -1, _("Hide PlugIn DemoWindow"));
    m_hide_id = AddCanvasContextMenuItem(pmih, this );
    SetCanvasContextMenuItemViz(m_hide_id, false);

    //Set Default Values
    m_controlPanelWindow = NULL;

    // This PlugIn needs a toolbar icon
    m_toolbar_item_id  = InsertPlugInTool(_T(""), _img_noaadoppler_inactive, _img_noaadoppler_inactive, wxITEM_CHECK,
        _("NOAA Doppler"), _T(""), NULL, NOAADOPPLER_TOOL_POSITION, 0, this);

    return (
               INSTALLS_CONTEXTMENU_ITEMS     |
               WANTS_PREFERENCES              |
               WANTS_CONFIG                   |
               WANTS_TOOLBAR_CALLBACK         |
               WANTS_OPENGL_OVERLAY_CALLBACK  |
               INSTALLS_TOOLBAR_TOOL          |
               INSTALLS_CONTEXTMENU_ITEMS
           );
}


/*
    DeInitialize the plugin
        Disconnect timer
*/
bool noaa_doppler_pi::DeInit(void)
{
    wxLogMessage(_T("NOAADOPPLER: DeInit"));

    m_AUImgr->DetachPane(m_controlPanelWindow);
    if(m_controlPanelWindow)
    {
        m_controlPanelWindow->Close();
    }

    if (_img_noaadoppler_inactive)
    {
        delete _img_noaadoppler_inactive;
    }
    if (_img_noaadoppler_active)
    {
        delete _img_noaadoppler_active;
    }

    return true;
}


/*
    Show Preferences
*/
void noaa_doppler_pi::OnToolbarToolCallback(int id)
{
    SetToolbarItemState(m_toolbar_item_id, true);
    ShowPropertiesWindow();
}


/*
    Method to show the Properies window
*/
void noaa_doppler_pi::ShowPropertiesWindow()
{
    if (!m_controlPanelWindow)
    {
        wxLogMessage(_T("NOAADOPPLER: Create Window"));

        m_controlPanelWindow = new noaa_control_panel(*this, m_parent_window);
    }
    wxLogMessage(_T("NOAADOPPLER: Show Window"));
    if(m_controlPanelWindow->ShowModal() == wxID_OK)
    {
        SetToolbarItemState(m_toolbar_item_id, false);
    }
}


/*
    Refresh icons
*/
void noaa_doppler_pi::ResetToolbarIcon()
{
    RequestRefresh(m_parent_window);
}



//////////////////////////////////////
//          Items Below are         //
//        Common to all plugins     //
//////////////////////////////////////


/*
    Method to return the bitmap for the toolbar
*/
wxBitmap *noaa_doppler_pi::GetPlugInBitmap()
{
      return _img_noaadoppler_inactive;
}

int noaa_doppler_pi::GetAPIVersionMajor()
{
    return MY_API_VERSION_MAJOR;
}

int noaa_doppler_pi::GetAPIVersionMinor()
{
    return MY_API_VERSION_MINOR;
}

int noaa_doppler_pi::GetPlugInVersionMajor()
{
    return PLUGIN_VERSION_MAJOR;
}

int noaa_doppler_pi::GetPlugInVersionMinor()
{
    return PLUGIN_VERSION_MINOR;
}

wxString noaa_doppler_pi::GetCommonName()
{
    return _("NOAA Doppler Overlay");
}

wxString noaa_doppler_pi::GetShortDescription()
{
    return _("NOAA Doppler Overlay PlugIn for OpenCPN");
}

wxString noaa_doppler_pi::GetLongDescription()
{
    return _("NOAA Doppler PlugIn for OpenCPN\n\rDisplay NOAA NEXRAD Raday images as an overlay on OpenCPN");

}

void noaa_doppler_pi::OnContextMenuItemCallback(int id)
{

}

bool noaa_doppler_pi::RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp)
{
    return false;
}

void noaa_doppler_pi::SetCursorLatLon(double lat, double lon)
{
}

bool noaa_doppler_pi::RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp)
{
    return false;
}

int noaa_doppler_pi::GetToolbarToolCount(void)
{
    return 1;
}

void noaa_doppler_pi::SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix)
{
}
