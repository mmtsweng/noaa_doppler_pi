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
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Blur Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, 0, 5 );
	
	m_sldBlur = new wxSlider( this, wxID_ANY, 5, 0, 15, wxDefaultPosition, wxSize( 220,-1 ), wxSL_HORIZONTAL );
	bSizer3->Add( m_sldBlur, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	m_chkShowDialog = new wxCheckBox( this, wxID_ANY, wxT("Show Overlay"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_chkShowDialog, 0, wxALL, 5 );
	
	
	fgSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Radar Site ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer5->Add( m_staticText4, 0, wxALL, 5 );
	
	wxString m_cboRadarChoices[] = { wxT("atx|Everett/Seattle-Tacoma, WA"), wxT("otx|Spokane, WA") };
	int m_cboRadarNChoices = sizeof( m_cboRadarChoices ) / sizeof( wxString );
	m_cboRadar = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cboRadarNChoices, m_cboRadarChoices, 0 );
	m_cboRadar->SetSelection( 0 );
	bSizer5->Add( m_cboRadar, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Imagery Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer5->Add( m_staticText5, 0, wxALL, 5 );
	
	wxString m_choice2Choices[] = { wxT("N0R|Base Reflectivity"), wxT("N0S|Storm Relative Motion"), wxT("N0V|Base Velocity"), wxT("N1P|One Hour Precipitation"), wxT("NCR|Composite Reflectivity") };
	int m_choice2NChoices = sizeof( m_choice2Choices ) / sizeof( wxString );
	m_choice2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2NChoices, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	bSizer5->Add( m_choice2, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Download File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer6->Add( m_staticText6, 0, wxALL, 5 );
	
	m_txtRadarURL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0 );
	bSizer6->Add( m_txtRadarURL, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Local Directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );
	
	m_txtImagePath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0 );
	bSizer6->Add( m_txtImagePath, 0, wxALL, 5 );
	
	m_btnDownload = new wxButton( this, wxID_UPDATE, wxT("Download"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btnDownload, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer6, 1, wxEXPAND, 5 );
	
	
	fgSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer1->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	btn_Ok = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( btn_Ok, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	MainVertSizer->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( MainVertSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sldBlur->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_chkShowDialog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	m_cboRadar->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialog::SiteIDChanged ), NULL, this );
	m_choice2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialog::ImageTypeChanged ), NULL, this );
	m_btnDownload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog::DownloadClickEvent ), NULL, this );
}

PreferencesDialog::~PreferencesDialog()
{
	// Disconnect Events
	m_sldBlur->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_sldBlur->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PreferencesDialog::BlurAmountChanged ), NULL, this );
	m_chkShowDialog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PreferencesDialog::CheckBoxClicked ), NULL, this );
	m_cboRadar->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialog::SiteIDChanged ), NULL, this );
	m_choice2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PreferencesDialog::ImageTypeChanged ), NULL, this );
	m_btnDownload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialog::DownloadClickEvent ), NULL, this );
	
}
