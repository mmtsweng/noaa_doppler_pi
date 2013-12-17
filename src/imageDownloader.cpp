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
