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
        wxString GenerateSavedFilename(wxString station, wxString radarType);
        wxString GenerateDownloadFilename(wxString station, wxString radarType);
        wxString GenerateWorldFilename(wxString station, wxString radarType);
    protected:
    private:
        wxURL           *fileDL;

};

#endif // IMAGEDOWNLOADER_H
