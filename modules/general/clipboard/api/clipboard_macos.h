#ifdef __APPLE__
#include "clipboard_api.h"
#include <ApplicationServices/ApplicationServices.h>
#include <string>
using namespace std;
namespace null
{
	auto clipboard_api::get_text() -> string
	{
		// Get the clipboard
		PasteboardRef clipboard;
		PasteboardCreate(kPasteboardClipboard, &clipboard);
		// Get the text from the clipboard
		CFArrayRef items;
		PasteboardCopyItemFlavors(clipboard, kPasteboardClipboard, &items);
		CFIndex count = CFArrayGetCount(items);
		for (CFIndex i = 0; i < count; i++)
		{
			CFStringRef flavor = (CFStringRef)CFArrayGetValueAtIndex(items, i);
			if (CFStringCompare(flavor, CFSTR("public.utf8-plain-text"), 0) == kCFCompareEqualTo)
			{
				CFDataRef data;
				PasteboardCopyItemFlavorData(clipboard, kPasteboardClipboard, flavor, &data);
				CFIndex length = CFDataGetLength(data);
				CFIndex used;
				CFIndex converted;
				CFStringEncoding encoding = kCFStringEncodingUTF8;
				CFIndex max = length * 3;
				CFIndex bufsize = max + 1;
				char* buffer = (char*)malloc(bufsize);
				CFStringGetBytes((CFStringRef)data, CFRangeMake(0, length), encoding, 0, false, (UInt8*)buffer, max, &used);
				buffer[used] = 0;
				string text = string(buffer);
				free(buffer);
				return text;
			}
		}
		return "";
	}
	void clipboard_api::set_text(const string& text)
	{
		// Get the clipboard
		PasteboardRef clipboard;
		PasteboardCreate(kPasteboardClipboard, &clipboard);
		// Set the text to the clipboard
		CFStringRef string = CFStringCreateWithCString(NULL, text.c_str(), kCFStringEncodingUTF8);
		PasteboardClear(clipboard);
		PasteboardPutItemFlavor(clipboard, kPasteboardClipboard, CFSTR("public.utf8-plain-text"), string, 0);
	}
}
#endif