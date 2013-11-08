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
    CalculateWorldFile();
}

wxBitmap *doppler_image::GetStretchedImage(PlugIn_ViewPort *vp, wxWindow *parentWindow)
{
    wxLogMessage(wxT("NOAADOPPLER: LAT:%f, Lon:%f, latmax:%f, lonmax:%f, width:%f, height:%f"), vp->clat, vp->clon, vp->lat_max, vp->lon_max, parentWindow->GetScreenRect().GetWidth(), parentWindow->GetScreenRect().GetHeight());

    //Check for new image
    if (m_cachedImage || (m_lastViewPort && (m_lastViewPort->clat != vp->clat || m_lastViewPort->clon != vp->clon)))
    {
        wxPoint pl;
        GetCanvasPixLL(vp, &pl, vp->clat, vp->clon);
        m_lastViewPort = vp;
        wxImage image = m_sourceImage->ConvertToImage();
        wxRect clipRectangle;
        clipRectangle.x = 230;
        clipRectangle.y = 300;
        clipRectangle.SetTop(230);
        clipRectangle.SetLeft(300);
        clipRectangle.SetBottom(400);
        clipRectangle.SetRight(400);
        wxImage croppedImage = image.GetSubImage(clipRectangle);
        croppedImage.Rescale(800,600, wxIMAGE_QUALITY_NORMAL);
        m_cachedImage = new wxBitmap(croppedImage);
    }

    return m_cachedImage;

}

void doppler_image::CalculateWorldFile()
{
    //Image:    600px W
    //          550px H

    //NOAADOPPLER: LAT:47.311729, Lon:-122.470121, Scl:109937.078125, pxh:0.000000, pxw:1.000000, rot:0.000000
    //NOAADOPPLER: LAT:47.298700, Lon:-122.441300, Scl:52894.578125, latmax:47.338924, lonmax:-122.321890, rot:0.000000

    gfw = new gfw_world_file();
    gfw->scaleX = 0.0107884909889915;
    gfw->rotationX=0;
    gfw->rotationY=0;
    gfw->scaleY = -0.0107884909889915;
    gfw->coordX = -125.725156347101;
    gfw->coordY = 51.1564404713024;
    gfw->coordMaxX = (600 * gfw->scaleX);
    gfw->coordMaxY = (550 * (abs(gfw->scaleY)));
    gfw->totalDegreesX = (gfw->coordMaxX - gfw->coordX) * gfw->scaleX;
    gfw->totalDegreesY = (gfw->coordMaxY - gfw->coordY) * gfw->scaleY;

    wxLogMessage(wxT("NOAADOPPLER: WorldFile scaleX:%f, scaleY:%f, rotationX:%f, rotationY:%f, coordX:%f, coordY:%f" ), gfw->scaleX, gfw->scaleY, gfw->rotationX, gfw->rotationY, gfw->coordX, gfw->coordY);
//    wxLogMessage(wxT("NOAADOPPLER: WorldFile coordMaxX:%3.5f, coordMaxY:%3.5f, totaldegX:%3.5f, totalegY:%3.5f" ), gfw.coordMaxX, gfw.coordMaxY, gfw.totalDegreesX, gfw.totalDegreesY);

}




