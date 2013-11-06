///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialogDefinitions.h"

///////////////////////////////////////////////////////////////////////////

PreferencesDialog::PreferencesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainVertSizer;
	MainVertSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	mChkShowDialog = new wxCheckBox( this, wxID_ANY, wxT("Show Overlay"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( mChkShowDialog, 0, wxALL, 5 );
	
	
	MainVertSizer->Add( bSizer2, 1, wxEXPAND, 5 );
	
	btn_Ok = new wxButton( this, wxID_OK, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	MainVertSizer->Add( btn_Ok, 0, wxALL, 5 );
	
	
	this->SetSizer( MainVertSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	mChkShowDialog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
}

PreferencesDialog::~PreferencesDialog()
{
	// Disconnect Events
	mChkShowDialog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	
}
