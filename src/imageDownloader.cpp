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
wxString ImageDownloader::GenerateDownloadFilename()
{
    return _T("http://radar.weather.gov/ridge/RadarImg/N0R/ATX_N0R_0.gif");
}

/*
    Method to generate the local filename to save to
*/
wxString ImageDownloader::GenerateSavedFilename()
{
    return _T("/home/matt/opencpn/radar/ATX_N0R_Test.gif");
}


wxString ImageDownloader::GenerateWorldFilename()
{
    return _T("http://radar.weather.gov/ridge/RadarImg/N0R/ATX_N0R_0.gfw");
}
