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
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_chkShowDialog = new wxCheckBox( this, wxID_ANY, wxT("Show Overlay"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_chkShowDialog, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Blur Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL, 5 );
	
	m_sldBlur = new wxSlider( this, wxID_ANY, 5, 0, 15, wxDefaultPosition, wxSize( 220,-1 ), wxSL_HORIZONTAL );
	bSizer3->Add( m_sldBlur, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("ImagePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer4->Add( m_staticText2, 0, wxALL, 5 );
	
	m_txtImagePath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0 );
	bSizer4->Add( m_txtImagePath, 0, wxALL, 5 );
	
	m_btnDownload = new wxButton( this, wxID_UPDATE, wxT("Download"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_btnDownload, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 1, wxEXPAND, 5 );
	
	
	MainVertSizer->Add( bSizer2, 1, wxEXPAND, 5 );
	
	btn_Ok = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	MainVertSizer->Add( btn_Ok, 0, wxALL, 5 );
	
	
	this->SetSizer( MainVertSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_chkShowDialog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	m_btnDownload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog::DownloadClickEvent ), NULL, this );
}

PreferencesDialog::~PreferencesDialog()
{
	// Disconnect Events
	m_chkShowDialog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	m_btnDownload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog::DownloadClickEvent ), NULL, this );
	
}
