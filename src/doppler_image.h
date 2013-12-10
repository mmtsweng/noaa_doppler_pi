#ifndef  WX_PRECOMP
#include <wx/wx.h>
#endif

#ifndef DOPPLER_IMAGE_H
#define DOPPLER_IMAGE_H

#include "gfw.h"
#include  "../include/opencpn/ocpn_plugin.h"
#include "settings.h"

class doppler_image
{
    public:
        doppler_image();
        virtual ~doppler_image();

        void LoadImage(wxString filePath);
        void UpdateSettings(noaaPi_settings *settings);
        wxBitmap *GetStretchedImage(PlugIn_ViewPort *vp, wxWindow *parentWindow);
    protected:
    private:
        wxBitmap            *m_sourceImage;
        wxBitmap            *m_cachedImage;
        PlugIn_ViewPort     *m_lastViewPort;
        void                CalculateWorldFile();
        wxBitmap            GenerateClippedImage(PlugIn_ViewPort *vp);
        wxRect              CalculateClippingArea(PlugIn_ViewPort *vp);
        gfw_world_file      m_gfw;
        noaaPi_settings     *m_settings;

};

#endif // DOPPLER_IMAGE_H
