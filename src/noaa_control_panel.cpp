#include "noaa_doppler_pi.h"
#include "noaa_control_panel.h"
#include <wx/wx.h>

noaa_control_panel::noaa_control_panel( noaa_doppler_pi * ppi, wxWindow* parent)
    : PreferencesDialog( parent )
{
    m_noaa_doppler_pi = ppi;
    pParent = parent;
}

noaa_control_panel::~noaa_control_panel()
{
    //dtor
}

/*
    Set Settings Values
*/
void noaa_control_panel::SetSettings(noaaPi_settings *settings)
{
    this->m_sldBlur->SetValue(settings->blurFactor);
    this->m_chkShowDialog->SetValue(settings->showOverlay);
    this->m_txtImagePath->SetValue(settings->sourceImagePath);
    m_settings = settings;
}

/*
*/
void noaa_control_panel::BlurAmountChanged(wxScrollEvent &event)
{
    m_settings->blurFactor = this->m_sldBlur->GetValue();
    m_noaa_doppler_pi->UpdateSettings(m_settings);
}

/*
    Visibility Checkbox clicked
*/
void noaa_control_panel::CheckBoxClicked(wxCommandEvent &event)
{
    m_settings->showOverlay = this->m_chkShowDialog->IsChecked();
    m_noaa_doppler_pi->UpdateSettings(m_settings);
}

/*
    Download Image Clicked
*/
void noaa_control_panel::DownloadClickEvent(wxCommandEvent &event)
{
    wxLogMessage(_T("NOAADOPPLER: Downloading File!"));
    downloader = new ImageDownloader();
    if (downloader->DownloadFile(_T("http://radar.weather.gov/ridge/RadarImg/N0R/ATX_N0R_0.gif"), _T("/home/matt/opencpn/radar/ATX_N0R_Test.gif")))
    {
        wxLogMessage(_T("NOAADOPPLER: Success"));
    }
    else
    {
        wxLogMessage(_T("NOAADOPPLER: Failed"));
    }
    delete downloader;

    m_settings->blurFactor = this->m_sldBlur->GetValue();
    m_settings->showOverlay = this->m_chkShowDialog->IsChecked();
    m_settings->sourceImagePath = _T("/home/matt/opencpn/radar/ATX_N0R_Test.gif"); //this->m_txtImagePath->GetValue();
    m_noaa_doppler_pi->UpdateSettings(m_settings);
}
