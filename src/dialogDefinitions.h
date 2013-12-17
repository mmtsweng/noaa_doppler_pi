///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGDEFINITIONS_H__
#define __DIALOGDEFINITIONS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_UPDATE 1000

///////////////////////////////////////////////////////////////////////////////
/// Class PreferencesDialog
///////////////////////////////////////////////////////////////////////////////
class PreferencesDialog : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* m_chkShowDialog;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText1;
		wxSlider* m_sldBlur;
		wxStaticLine* m_staticline3;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_txtRadarURL;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_txtImagePath;
		wxButton* m_btnDownload;
		wxStaticLine* m_staticline2;
		wxButton* btn_Ok;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CheckBoxClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void BlurAmountChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void DownloadClickEvent( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PreferencesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,370 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PreferencesDialog();
	
};

#endif //__DIALOGDEFINITIONS_H__
