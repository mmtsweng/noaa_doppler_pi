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
}

/*
    Visibility Checkbox clicked
*/
void noaa_control_panel::CheckBoxClicked(wxCommandEvent &event)
{
    wxLogMessage(_T("NOAADOPPLER: Checkbox Clicked"));
    //this->m_noaa_doppler_pi.SetDopplerVisibility(event.IsChecked());
}

/*
    Download Image Clicked
*/
void noaa_control_panel::DownloadClickEvent(wxCommandEvent &event)
{
    m_settings.blurFactor = this->m_sldBlur->GetValue();
    m_settings.showOverlay = this->m_chkShowDialog->IsChecked();
    m_settings.sourceImagePath = this->m_txtImagePath->GetValue();
    m_noaa_doppler_pi->UpdateSettings(&m_settings);
}
