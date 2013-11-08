#ifndef  WX_PRECOMP
#include <wx/wx.h>
#endif

#ifndef DOPPLER_IMAGE_H
#define DOPPLER_IMAGE_H

#include "gfw.h"

class doppler_image
{
    public:
        doppler_image();
        virtual ~doppler_image();

        void LoadImage(wxString filePath);
        wxBitmap *GetStretchedImage();
    protected:
    private:
        wxBitmap    *m_sourceImage;

};

#endif // DOPPLER_IMAGE_H
