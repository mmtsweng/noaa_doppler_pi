#ifndef  WX_PRECOMP
#include <wx/wx.h>
#endif

#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <wx/url.h>
#include <wx/wfstream.h>


class ImageDownloader
{
    public:
        /** Default constructor */
        ImageDownloader();
        /** Default destructor */
        virtual ~ImageDownloader();

        bool DownloadFile(wxString url, wxString destination);
    protected:
    private:
        wxURL           *fileDL;

};

#endif // IMAGEDOWNLOADER_H
