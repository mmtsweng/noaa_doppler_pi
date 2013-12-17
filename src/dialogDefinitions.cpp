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
	
	m_chkShowDialog = new wxCheckBox( this, wxID_ANY, wxT("Show Overlay"), wxDefaultPosition, wxDefaultSize, 0 );
	MainVertSizer->Add( m_chkShowDialog, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	MainVertSizer->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Blur Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	MainVertSizer->Add( m_staticText1, 0, 0, 5 );
	
	m_sldBlur = new wxSlider( this, wxID_ANY, 5, 0, 15, wxDefaultPosition, wxSize( 220,-1 ), wxSL_HORIZONTAL );
	MainVertSizer->Add( m_sldBlur, 0, wxALL, 5 );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	MainVertSizer->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Image URL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	MainVertSizer->Add( m_staticText3, 0, wxALL, 5 );
	
	m_txtRadarURL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0 );
	MainVertSizer->Add( m_txtRadarURL, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Local File Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	MainVertSizer->Add( m_staticText2, 0, wxALL, 5 );
	
	m_txtImagePath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0 );
	MainVertSizer->Add( m_txtImagePath, 0, wxALL, 5 );
	
	m_btnDownload = new wxButton( this, wxID_UPDATE, wxT("Download"), wxDefaultPosition, wxDefaultSize, 0 );
	MainVertSizer->Add( m_btnDownload, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	MainVertSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	btn_Ok = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	MainVertSizer->Add( btn_Ok, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	this->SetSizer( MainVertSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_chkShowDialog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_btnDownload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog::DownloadClickEvent ), NULL, this );
}

PreferencesDialog::~PreferencesDialog()
{
	// Disconnect Events
	m_chkShowDialog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_btnDownload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog::DownloadClickEvent ), NULL, this );
	
}
