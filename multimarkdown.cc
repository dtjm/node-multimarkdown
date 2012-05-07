#include <node.h>
#include <v8.h>
// #include "vendor/peg-multimarkdown/markdown_peg.h"
//
enum markdown_extensions {
    EXT_SMART            = 1 << 0,
    EXT_NOTES            = 1 << 1,
    EXT_FILTER_HTML      = 1 << 2,
    EXT_FILTER_STYLES    = 1 << 3,
    EXT_COMPATIBILITY    = 1 << 4,
    EXT_PROCESS_HTML     = 1 << 5,
	EXT_NO_LABELS		 = 1 << 6,
};

enum markdown_formats {
    HTML_FORMAT,
    LATEX_FORMAT,
    MEMOIR_FORMAT,
    BEAMER_FORMAT,
    OPML_FORMAT,
    GROFF_MM_FORMAT,
    ODF_FORMAT,
    ODF_BODY_FORMAT
};

extern "C" {
    char * markdown_to_string(char *text, int extensions, int output_format);
}

using namespace v8;
char *outbuf;
int outbuflen = -1;
void reallocOutBuf(int len) {
    if(len < outbuflen) {
        return;
    }

    free(outbuf);
    outbuflen = len + 1;
    outbuf = (char*) malloc(outbuflen);
}

Handle<Value> convert(const Arguments& args) {
    HandleScope scope;

    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass string as first argument")));
        return scope.Close(Undefined());
    }

    Local<String> ls = args[0]->ToString();

    int stringLen = ls->Length();
    reallocOutBuf(stringLen);
    printf("%s\n", outbuf);
    ls->WriteUtf8(outbuf, stringLen, NULL, 0);
    char *out = markdown_to_string(outbuf, 0, HTML_FORMAT);

    return scope.Close(String::New(out));
}

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("convert"),
            FunctionTemplate::New(convert)->GetFunction());
}


NODE_MODULE(multimarkdown, init)
