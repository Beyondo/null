#ifdef __linux__
#include "clipboard_api.h"
#include <X11/Xlib.h>
#include <string>
using namespace std;
namespace null
{
	auto clipboard_api::get_text() -> string
	{
		Display* display = XOpenDisplay(NULL);
		Window window = XDefaultRootWindow(display);
		Atom atom = XInternAtom(display, "CLIPBOARD", false);
		Atom type;
		int format;
		unsigned long length;
		unsigned long bytes_left;
		unsigned char* data;
		XGetWindowProperty(display, window, atom, 0, 0, false, AnyPropertyType, &type, &format, &length, &bytes_left, &data);
		XGetWindowProperty(display, window, atom, 0, bytes_left, false, AnyPropertyType, &type, &format, &length, &bytes_left, &data);
		string text = string(reinterpret_cast<char*>(data));
		XFree(data);
		XCloseDisplay(display);
		return text;
	}
	void clipboard_api::set_text(const string& text)
	{
		Display* display = XOpenDisplay(NULL);
		Window window = XDefaultRootWindow(display);
		Atom atom = XInternAtom(display, "CLIPBOARD", false);
		XSetSelectionOwner(display, atom, window, CurrentTime);
		XFlush(display);
		XCloseDisplay(display);
	}
}
#endif