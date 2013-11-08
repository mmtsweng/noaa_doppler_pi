#include "doppler_image.h"

doppler_image::doppler_image()
{
    //Add Image Handler
    wxImageHandler *gifLoader = new wxGIFHandler();
    wxImage::AddHandler(gifLoader);
    m_sourceImage = NULL;
}

doppler_image::~doppler_image()
{
    //dtor
}

void doppler_image::LoadImage(wxString filePath)
{
    if (m_sourceImage)
    {
        delete m_sourceImage;
    }
    m_sourceImage = new wxBitmap();
    m_sourceImage->LoadFile(filePath, wxBITMAP_TYPE_GIF);
}

wxBitmap *doppler_image::GetStretchedImage()
{
    return m_sourceImage;
}




