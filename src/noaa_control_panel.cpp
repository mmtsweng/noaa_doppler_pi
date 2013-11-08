#include "noaa_control_panel.h"
#include <wx/wx.h>

noaa_control_panel::noaa_control_panel( noaa_doppler_pi &_noaa_doppler_pi, wxWindow* parent)
    : PreferencesDialog( parent ), m_noaa_doppler_pi(m_noaa_doppler_pi)
{
    //ctor
}

noaa_control_panel::~noaa_control_panel()
{
    //dtor
}

void noaa_control_panel::CheckBoxClicked(wxCommandEvent &event)
{
    wxLogMessage(_T("NOAADOPPLER: Checkbox Clicked"));
    //this->m_noaa_doppler_pi.SetDopplerVisibility(event.IsChecked());
}
