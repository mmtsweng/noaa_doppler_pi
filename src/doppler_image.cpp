#include "doppler_image.h"
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
    wxLogMessage(wxT("NOAADOPPLER: LAT:%f, Lon:%f, latmax:%f, lonmax:%f, width:%f, height:%f"), vp->lat_min, vp->lon_min, vp->lat_max, vp->lon_max, parentWindow->GetScreenRect().GetWidth(), parentWindow->GetScreenRect().GetHeight());

    //Check for new image
    if (m_cachedImage || (m_lastViewPort && (m_lastViewPort->clat != vp->clat || m_lastViewPort->clon != vp->clon)))
    {
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
        croppedImage.Rescale(800,600, wxIMAGE_QUALITY_NORMAL);
        return croppedImage;
}

wxRect doppler_image::CalculateClippingArea(PlugIn_ViewPort *vp)
{
        wxRect clipRectangle;

        //Find top left corner
        double degFrom0 = (m_gfw.coordY - vp->lat_max);
        double ratioOfImg = (degFrom0 / m_gfw.coordMaxY);
        clipRectangle.SetTop(abs(floor((ratioOfImg * 550) + 0.5)));
        wxLogMessage(wxT("NOAADOPPLER: ImageRectT: deg0:%f, ratio:%f"), degFrom0, ratioOfImg);

        degFrom0 = (m_gfw.coordX - vp->lon_min);
        ratioOfImg = (degFrom0 / m_gfw.coordMaxX);
        clipRectangle.SetLeft(abs(floor((ratioOfImg * 600) + 0.5)));
        wxLogMessage(wxT("NOAADOPPLER: ImageRectL: deg0:%f, ratio:%f"), degFrom0, ratioOfImg);

        //Find bottom right
        degFrom0 = (m_gfw.coordY - vp->lat_min);
        ratioOfImg = (degFrom0 / m_gfw.coordMaxY);
        clipRectangle.SetBottom(abs(floor((ratioOfImg * 550) + 0.5)));
        wxLogMessage(wxT("NOAADOPPLER: ImageRectB: deg0:%f, ratio:%f"), degFrom0, ratioOfImg);

        degFrom0 = (m_gfw.coordX - vp->lon_max);
        ratioOfImg = (degFrom0 / m_gfw.coordMaxX);
        clipRectangle.SetRight(abs(floor((ratioOfImg * 600) + 0.5)));
        wxLogMessage(wxT("NOAADOPPLER: ImageRectR: deg0:%f, ratio:%f"), degFrom0, ratioOfImg);

        wxLogMessage(wxT("NOAADOPPLER: ImageRect: top:%d, left:%d, bottom%d, right%d"), clipRectangle.GetTop(), clipRectangle.GetLeft(), clipRectangle.GetBottom(), clipRectangle.GetRight());

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
    m_gfw.coordMaxX = (600 * (fabs(m_gfw.scaleX)));
    m_gfw.coordMaxY = (550 * (fabs(m_gfw.scaleY)));
    m_gfw.totalDegreesX = (m_gfw.coordX + m_gfw.coordMaxX);
    m_gfw.totalDegreesY = (m_gfw.coordY + (-m_gfw.coordMaxY));

    wxLogMessage(wxT("NOAADOPPLER: WorldFile scaleX:%f, scaleY:%f, rotationX:%f, rotationY:%f, coordX:%f, coordY:%f" ), m_gfw.scaleX, m_gfw.scaleY, m_gfw.rotationX, m_gfw.rotationY, m_gfw.coordX, m_gfw.coordY);
    wxLogMessage(wxT("NOAADOPPLER: WorldFile coordMaxX:%f, coordMaxY:%f, totaldegX:%f, totalegY:%f" ), m_gfw.coordMaxX, m_gfw.coordMaxY, m_gfw.totalDegreesX, m_gfw.totalDegreesY);

}




