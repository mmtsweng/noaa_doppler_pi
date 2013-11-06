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
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class PreferencesDialog
///////////////////////////////////////////////////////////////////////////////
class PreferencesDialog : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* mChkShowDialog;
		wxButton* btn_Ok;
	
	public:
		
		PreferencesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 152,324 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~PreferencesDialog();
	
};

#endif //__DIALOGDEFINITIONS_H__
