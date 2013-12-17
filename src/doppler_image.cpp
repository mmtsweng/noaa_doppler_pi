#include "doppler_image.h"
#include "settings.h"
#include <math.h>

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
    //Exit if we don't have a good new file to load
    if (filePath.length()<1)
    {
        return;
    }

    //Delete existing image
    if (m_sourceImage != NULL)
    {
        delete m_sourceImage;
    }

    //Load new image
    m_sourceImage = new wxBitmap();
    m_sourceImage->LoadFile(filePath, wxBITMAP_TYPE_GIF);
    CalculateWorldFile();
}

wxBitmap *doppler_image::GetStretchedImage(PlugIn_ViewPort *vp, wxWindow *parentWindow)
{
    //Check for new image
    if ((m_cachedImage) || ((!m_lastViewPort) && (m_lastViewPort->pix_width != vp->pix_width || m_lastViewPort->pix_height != vp->pix_height)))
    {
        wxLogMessage(wxT("NOAADOPPLER: VPwidth:%d, VPHeight%d, LastWdith:%d LastHeight:%d"), vp->pix_width, vp->pix_height, m_lastViewPort->pix_width, m_lastViewPort->pix_height);

        wxPoint pl;
        GetCanvasPixLL(vp, &pl, vp->clat, vp->clon);
        m_lastViewPort = vp;

        m_cachedImage = new wxBitmap(GenerateClippedImage(vp));
    }

    return m_cachedImage;

}

wxBitmap doppler_image::GenerateClippedImage(PlugIn_ViewPort *vp)
{
    wxImage image = m_sourceImage->ConvertToImage();
    wxImage croppedImage = image.GetSubImage(CalculateClippingArea(vp));
    croppedImage.InitAlpha();
    croppedImage.Rescale(vp->pix_width,vp->pix_height, wxIMAGE_QUALITY_NORMAL);
    wxImage blurredImage = croppedImage.Blur(m_settings->blurFactor);

    image = NULL;
    croppedImage = NULL;
    return blurredImage;
}

wxRect doppler_image::CalculateClippingArea(PlugIn_ViewPort *vp)
{
    wxRect clipRectangle;

    //Breakout of calculation
    /*
    double degFrom0 = (m_gfw.coordY - vp->lat_max);
    double ratioOfImg = (degFrom0 / m_gfw.coordMaxY);
    clipRectangle.SetTop(abs(floor((ratioOfImg * 550) + 0.5)));
    wxLogMessage(wxT("NOAADOPPLER: ImageRectT: deg0:%f, ratio:%f"), degFrom0, ratioOfImg);
    wxLogMessage(wxT("NOAADOPPLER: ImageRect: top:%d, left:%d, bottom%d, right%d"), clipRectangle.GetTop(), clipRectangle.GetLeft(), clipRectangle.GetBottom(), clipRectangle.GetRight());
    */

    clipRectangle.SetTop(abs(floor((((m_gfw.coordY - vp->lat_max) / m_gfw.coordMaxY) * m_settings->sourceImageHeight) + 0.5)));
    clipRectangle.SetLeft(abs(floor((((m_gfw.coordX - vp->lon_min) / m_gfw.coordMaxX) * m_settings->sourceImageWidth) + 0.5)));
    clipRectangle.SetBottom(abs(floor((((m_gfw.coordY - vp->lat_min) / m_gfw.coordMaxY) * m_settings->sourceImageHeight) + 0.5)));
    clipRectangle.SetRight(abs(floor((((m_gfw.coordX - vp->lon_max) / m_gfw.coordMaxX) * m_settings->sourceImageWidth) + 0.5)));

    return clipRectangle;
}

void doppler_image::CalculateWorldFile()
{
    //Image:    600px W
    //          550px H

    //NOAADOPPLER: LAT:47.311729, Lon:-122.470121, Scl:109937.078125, pxh:0.000000, pxw:1.000000, rot:0.000000
    //NOAADOPPLER: LAT:47.298700, Lon:-122.441300, Scl:52894.578125, latmax:47.338924, lonmax:-122.321890, rot:0.000000

    m_gfw.scaleX = 0.0107884909889915;
    m_gfw.rotationX=0;
    m_gfw.rotationY=0;
    m_gfw.scaleY = -0.0107884909889915;
    m_gfw.coordX = -125.725156347101;
    m_gfw.coordY = 51.1564404713024;
    m_gfw.coordMaxX = (m_settings->sourceImageWidth * (fabs(m_gfw.scaleX)));
    m_gfw.coordMaxY = (m_settings->sourceImageHeight * (fabs(m_gfw.scaleY)));
    m_gfw.totalDegreesX = (m_gfw.coordX + m_gfw.coordMaxX);
    m_gfw.totalDegreesY = (m_gfw.coordY + (-m_gfw.coordMaxY));

    wxLogMessage(wxT("NOAADOPPLER: WorldFile scaleX:%f, scaleY:%f, rotationX:%f, rotationY:%f, coordX:%f, coordY:%f" ), m_gfw.scaleX, m_gfw.scaleY, m_gfw.rotationX, m_gfw.rotationY, m_gfw.coordX, m_gfw.coordY);
    wxLogMessage(wxT("NOAADOPPLER: WorldFile coordMaxX:%f, coordMaxY:%f, totaldegX:%f, totalegY:%f" ), m_gfw.coordMaxX, m_gfw.coordMaxY, m_gfw.totalDegreesX, m_gfw.totalDegreesY);

}

void doppler_image::UpdateSettings(noaaPi_settings *settings)
{
    m_settings = settings;
    LoadImage(settings->sourceImagePath);
}



