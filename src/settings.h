
#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

struct noaaPi_settings{
    bool showOverlay;
    int blurFactor;
    int sourceImageHeight;
    int sourceImageWidth;
    wxString sourceImagePath;
    wxString savedFile;
    wxString sourceWorldFilePath;
};

#endif // SETTINGS_H_INCLUDED
