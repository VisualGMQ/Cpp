#ifndef __SURFACEINFO_HPP__
#define __SURFACEINFO_HPP__
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
using namespace std;

void outputSurfaceInfo(SDL_Surface* surface){
	SDL_PixelFormat* format = surface->format;
    if(format){
        cout<<"[format]:"<<endl;
        cout<<"\t[pixel format]:"<<endl;
        if(format->palette)
            cout<<"\t\tncolors:\t"<<format->palette->ncolors<<endl;
        cout<<"\tformat:\t\t"<<SDL_GetPixelFormatName(format->format)<<endl;
        cout<<"\tBitsPerPixel:\t"<<int(format->BitsPerPixel)<<" Bits"<<endl;
        cout<<"\tBytesPerPixel:\t"<<int(format->BytesPerPixel)<<" Bytes"<<endl;
        cout<<"\tRmask:\t\t"<<hex<<int(format->Rmask)<<endl
            <<"\tBmask:\t\t"<<int(format->Bmask)<<endl
            <<"\tGmask:\t\t"<<int(format->Gmask)<<endl
            <<"\tAmask:\t\t"<<int(format->Amask)<<endl;
        cout<<dec<<endl;
    }
	cout<<"pitch num:\t"<<surface->pitch<<" Bytes"<<endl;
    cout<<"w:\t\t"<<surface->w<<endl
        <<"h:\t\t"<<surface->h<<endl;
    cout<<"refcount:\t"<<surface->refcount<<endl;
}
#endif
