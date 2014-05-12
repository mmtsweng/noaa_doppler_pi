#include "noaa_doppler_pi.h"
#include "noaa_control_panel.h"
#include "dialogDefinitions.h"
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
    this->m_dlGauge->Hide();
    m_settings = settings;
}

/*
    Amount of blur applied to imagery changed
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
    downloader = new ImageDownloader();
    m_settings->showOverlay = this->m_chkShowDialog->IsChecked();
    m_noaa_doppler_pi->UpdateSettings(m_settings);
    downloader = NULL;
}

/*
    Download Image Clicked
*/
void noaa_control_panel::DownloadClickEvent(wxCommandEvent &event)
{
    this->m_dlGauge->Show();
    this->m_dlGauge->SetValue(10);
    wxLogMessage(_T("NOAADOPPLER: Downloading File!"));

    wxString station = _T("ATX");
    wxString radarType = _T("N0R");

    if (DownloadImage(station, radarType))
    {
        this->m_dlGauge->SetValue(80);
        m_noaa_doppler_pi->UpdateSettings(m_settings);
        this->m_dlGauge->SetValue(100);
    }
    else
    {
        this->m_dlGauge->SetValue(0);
        wxLogMessage(_T("NOAADOPPLER: Failed"));
    }
    delete downloader;
}

/*
    Method to download the current radar image, and save it to the local file path
*/
bool noaa_control_panel::DownloadImage(wxString station, wxString radarType)
{
    try
    {
        downloader = new ImageDownloader();
        wxString savedFile = downloader->GenerateSavedFilename();

        if (downloader->DownloadFile(downloader->GenerateDownloadFilename(), savedFile ))
        {
            wxLogMessage(_T("NOAADOPPLER: Successfully downloaded image file"));
            m_settings->blurFactor = this->m_sldBlur->GetValue();
            m_settings->showOverlay = this->m_chkShowDialog->IsChecked();
            m_settings->savedFile = savedFile;
            m_settings->sourceImagePath = _T("/home/matt/opencpn/radar/");
            this->m_dlGauge->SetValue(80);
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

/*
    Window Activated
*/
void noaa_control_panel::OnActivate(wxActivateEvent& e)
{
    this->m_dlGauge->Hide();
}

void noaa_control_panel::SiteIDChanged( wxCommandEvent& event )
{}

void noaa_control_panel::ImageTypeChanged( wxCommandEvent& event )
{}
