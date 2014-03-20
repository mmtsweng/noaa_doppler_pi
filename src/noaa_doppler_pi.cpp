
//NOAA DOPPLER PLUG IN
//  - Matt Brown
//
//
//  OPEN CPN Plugin to download and render NOAA created RIDGE enhanced doppler imagery as an overlay over
//      the chart.
//  For more information about the data:
//      http://radar.weather.gov/ridge/GIS.html - explanation of GIS imagery
//      http://www.srh.noaa.gov/jetstream/doppler/ridge_download.htm - description of how to find relevent imagery

#ifndef  WX_PRECOMP
#include "wx/wxprec.h"
#include <wx/wx.h>
#endif //precompiled headers
#include "wx/fileconf.h"
#include <wx/aui/aui.h>
#include "noaa_doppler_pi.h"
#include "noaa_control_panel.h"
#include "icons.h"
#include "doppler_image.h"

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
doppler_image   *m_overlayImage;

/*
    Constructor
        Initialize Images
*/
noaa_doppler_pi::noaa_doppler_pi(void *ppimgr)
    : opencpn_plugin_18(ppimgr)
{
    initialize_images();
    m_overlayImage = new doppler_image();
    m_settings = new noaaPi_settings();
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
    m_pconfig = GetOCPNConfigObject();

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
    LoadConfig(m_settings);
    UpdateSettings(m_settings);

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
               INSTALLS_CONTEXTMENU_ITEMS     |
               WANTS_OVERLAY_CALLBACK
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
    if (m_overlayImage)
    {
        delete m_overlayImage;
    }

    return true;
}


/*
    Show Preferences
*/
void noaa_doppler_pi::OnToolbarToolCallback(int id)
{
    ShowPropertiesWindow();
}


/*
    Method to show the Properies window
*/
void noaa_doppler_pi::ShowPropertiesWindow()
{
    SetToolbarItemState(m_toolbar_item_id, false);
    if (!m_controlPanelWindow)
    {
        m_controlPanelWindow = new noaa_control_panel(this, m_parent_window);
        m_controlPanelWindow->SetSettings(m_settings);
        RequestRefresh(m_parent_window);
    }

    if(m_controlPanelWindow->ShowModal() == wxID_OK)
    {
    }
    SetToolbarItemState(m_toolbar_item_id, false);
}


/*
    Refresh icons
*/
void noaa_doppler_pi::ResetToolbarIcon()
{
    RequestRefresh(m_parent_window);
}


/*
    UI has new settings to update
*/
void noaa_doppler_pi::UpdateSettings(noaaPi_settings *settings)
{
    wxLogMessage(_T("NOAADOPPLER: Updating Settings"));
    m_overlayImage->UpdateSettings(settings);
    if (m_settings->showOverlay)
    {
        SetToolbarToolBitmaps(m_toolbar_item_id, _img_noaadoppler_active, _img_noaadoppler_active);
    }
    else
    {
        SetToolbarToolBitmaps(m_toolbar_item_id, _img_noaadoppler_inactive, _img_noaadoppler_inactive);
    }

    SaveConfig(settings);
    RequestRefresh(m_parent_window);
}

/*
    OpenGL Rendering
*/
bool noaa_doppler_pi::RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp)
{
    if (m_overlayImage && m_settings->showOverlay)
    {
        wxLogMessage(_T("NOAADOPPLER: GL Overlay"));


        //Create OpenGL Texture
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        GLuint* m_glTextures = new GLuint[1];
        glGenTextures(1, m_glTextures);
        wxBitmap textureBMP = *m_overlayImage->GetStretchedImage(vp, m_parent_window);
        wxImage textureImage = textureBMP.ConvertToImage();

        if (textureImage.IsOk())
        {
            int width = textureImage.GetWidth();
            int height = textureImage.GetHeight();
            unsigned char *Data = new unsigned char[width * height * 4];
            unsigned char *pColor = textureImage.GetData();
            unsigned char *pAlpha = textureImage.GetAlpha();
            unsigned char *pData = Data;

            //Copy Color and Alpha into RGBA temporary storage
            for (int i=0; i<width*height; i++)
            {
                for (int j=0; j<3; j++)
                {
                    *pData++ = *pColor++;
                }
                *pData++ = *pAlpha++;
            }

            //Render Texture
            glBindTexture(GL_TEXTURE_2D, m_glTextures[0]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_RECTANGLE, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);

            //Delete temporary storage
            delete [] Data;
        }
    }
    return false;
}

/*
    Non-OpenGL Rendering
*/
bool noaa_doppler_pi::RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp)
{
    if (m_overlayImage && m_settings->showOverlay)
    {
        wxPoint *pt = new wxPoint();
        pt->x = 0;
        pt->y = 0;
        dc.DrawBitmap(*m_overlayImage->GetStretchedImage(vp, m_parent_window), *pt, true);
    }
    return false;
}


/*
    Method to load plugin settings from config file
*/
bool noaa_doppler_pi::LoadConfig(noaaPi_settings *settings)
{
    wxFileConfig *pConf = m_pconfig;

    if(!pConf)
    {
        wxLogMessage(_T("NOAADOPPLER: No configuration"));
        return false;
    }

    wxLogMessage(_T("NOAADOPPLER: Loading Settings"));
    settings->showOverlay = false;


    pConf->SetPath ( _T( "/Settings/NoaaDoppler" ) );
    pConf->Read ( _T( "blurFactor" ), &settings->blurFactor, 5);
    pConf->Read ( _T( "SourceImageHeight" ), &settings->sourceImageHeight, 550);
    pConf->Read ( _T( "SourceImageWidth" ), &settings->sourceImageWidth, 600);
    pConf->Read ( _T( "SourceImagePath" ), &settings->sourceImagePath, _T("/home/matt/opencpn/radar/ATX_N0R_1.gif"));

    return true;
}


/*
    Method to save plugin settings to config file
*/
bool noaa_doppler_pi::SaveConfig(noaaPi_settings *settings)
{
    wxFileConfig *pConf = m_pconfig;

    if(pConf)
    {
        pConf->SetPath ( _T ( "/Settings/NoaaDoppler" ) );
        pConf->Write ( _T( "ShowOverlay" ), settings->showOverlay);
        pConf->Write ( _T( "blurFactor" ), settings->blurFactor);
        pConf->Write ( _T( "SourceImageHeight" ), settings->sourceImageHeight);
        pConf->Write ( _T( "SourceImageWidth" ), settings->sourceImageWidth);
        pConf->Write ( _T( "SourceImagePath" ), settings->sourceImagePath);

        //Automatically write changes
        pConf->Flush();

        return true;
    }
    else
    {
        wxLogMessage(_T("NOAADOPPLER: No configuration"));
        return false;
    }
}

//////////////////////////////////////
//          Items Below are         //
//        Common to all plugins     //
//////////////////////////////////////



void noaa_doppler_pi::UpdateAuiStatus(void)
{
      //    This method is called after the PlugIn is initialized
      //    and the frame has done its initial layout, possibly from a saved wxAuiManager "Perspective"
      //    It is a chance for the PlugIn to syncronize itself internally with the state of any Panes that
      //    were added to the frame in the PlugIn ctor.

      //    We use this callback here to keep the context menu selection in sync with the window state

    printf("NOAADOPPLER: UpdateAuiStatus");
    wxAuiPaneInfo &pane = m_AUImgr->GetPane(m_controlPanelWindow);
    if(!pane.IsOk())
        return;

    printf("update %d\n",pane.IsShown());

    SetCanvasContextMenuItemViz(m_hide_id, pane.IsShown());
    SetCanvasContextMenuItemViz(m_show_id, !pane.IsShown());

}


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

void noaa_doppler_pi::SetCursorLatLon(double lat, double lon)
{
}


int noaa_doppler_pi::GetToolbarToolCount(void)
{
    return 1;
}

void noaa_doppler_pi::SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix)
{
}
