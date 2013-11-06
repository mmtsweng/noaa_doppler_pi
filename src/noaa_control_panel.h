#ifndef NOAA_CONTROL_PANEL_H
#define NOAA_CONTROL_PANEL_H

#include "dialogDefinitions.h"

class noaa_doppler_pi;

class noaa_control_panel : public PreferencesDialog
{
    public:
        noaa_control_panel(noaa_doppler_pi &_noaa_doppler_pi, wxWindow* parent);
        virtual ~noaa_control_panel();
    protected:
        noaa_doppler_pi &m_noaa_doppler_pi;
        void CheckBoxClicked( wxCommandEvent &event );
    private:
};

#endif // NOAA_CONTROL_PANEL_H
