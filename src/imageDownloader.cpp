#include "imageDownloader.h"

ImageDownloader::ImageDownloader()
{
    //ctor
}

ImageDownloader::~ImageDownloader()
{
    //dtor
}

/*
    Method to download a URL to a specified file
*/
bool ImageDownloader::DownloadFile(wxString url, wxString destination)
{
    wxLogMessage(_T("NOAADOPPLER: Downloading File: %s"), url.c_str());
    wxURL fileDL(url);
    if (fileDL.GetError()==wxURL_NOERR)
    {
        wxInputStream *in = fileDL.GetInputStream();
        if (in && in->IsOk())
        {
            wxFFileOutputStream out(destination);
            in->Read(out);
        }
        delete in;
        return true;
    }
    return false;
}

/*
    Method to generate the http:// filename requested to be downloaded
*/
wxString ImageDownloader::GenerateDownloadFilename(wxString station, wxString radarType)
{
    wxString filename = _T("http://radar.weather.gov/ridge/RadarImg/");
    filename.append(radarType);
    filename.append(_T("/"));
    filename.append(station);
    filename.append(_T("_"));
    filename.append(radarType);
    filename.append(_T("_0.gif"));
    return filename;
}

/*
    Method to generate the local filename to save to
*/
wxString ImageDownloader::GenerateSavedFilename(wxString station, wxString radarType)
{
    wxString filename = _T("/home/matt/opencpn/radar/");
    filename.append(station);
    filename.append(_T("_"));
    filename.append(radarType);
    filename.append(_T("_Live.gif"));
    return filename;

    return _T("/home/matt/opencpn/radar/ATX_N0R_Live.gif");
}

/*
    Method to generate the world file filename
*/
wxString ImageDownloader::GenerateWorldFilename(wxString station, wxString radarType)
{
    return _T("http://radar.weather.gov/ridge/RadarImg/N0R/ATX_N0R_0.gfw");
}
