#ifndef NOAA_CONTROL_PANEL_H
#define NOAA_CONTROL_PANEL_H

#include "dialogDefinitions.h"
#include "settings.h"
#include "imageDownloader.h"

//Forward Declaration to avoid circular dependency
class noaa_doppler_pi;

class noaa_control_panel: public PreferencesDialog
{
    public:
        noaa_control_panel(noaa_doppler_pi *ppi, wxWindow* parent);
        virtual ~noaa_control_panel();
        void SetSettings (noaaPi_settings *settings);
    protected:
        noaa_doppler_pi     *m_noaa_doppler_pi;
        wxWindow            *pParent;
        void CheckBoxClicked( wxCommandEvent &event );
        void DownloadClickEvent( wxCommandEvent& event );
        void BlurAmountChanged( wxScrollEvent& event );
        void SiteIDChanged( wxCommandEvent& event );
		void ImageTypeChanged( wxCommandEvent& event );
		void OnActivate( wxActivateEvent& event );

    private:
        noaaPi_settings     *m_settings;
        ImageDownloader     *downloader;
        wxArrayString       *stationList;
        wxArrayString       *typeList;
        bool DownloadImage(wxString station, wxString radarType);
};

#endif // NOAA_CONTROL_PANEL_H
