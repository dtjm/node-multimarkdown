#include <node.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>

enum markdown_extensions {
    EXT_SMART            = 1 << 0,
    EXT_NOTES            = 1 << 1,
    EXT_FILTER_HTML      = 1 << 2,
    EXT_FILTER_STYLES    = 1 << 3,
    EXT_COMPATIBILITY    = 1 << 4,
    EXT_PROCESS_HTML     = 1 << 5,
    EXT_NO_LABELS        = 1 << 6,
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
char *buf = NULL;
int buflen = -1;
void reallocbuf(int len) {
    // Do the actual allocation if we requested more space that we have
    // allocated.
    if(len > buflen) {
        buflen = len + 1;
        buf = (char*) realloc(buf, buflen);
    }

    // Clear the memory space
    memset(buf, 0, len + 1);
}

int format = HTML_FORMAT;
int extensions = 0;

Handle<Value> convert(const Arguments& args) {
    HandleScope scope;

    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass string as first argument")));
        return scope.Close(Undefined());
    }

    Local<String> ls = args[0]->ToString();

    int stringLen = ls->Length();
    reallocbuf(stringLen);
    ls->WriteUtf8(buf, stringLen, NULL, 0);
    char *out = markdown_to_string(buf, extensions, format);

    Local<String> outString = String::New(out);
    free(out);

    return scope.Close(outString);
}

Handle<Value> setFormat(const Arguments& args) {
    HandleScope scope;

    if(args.Length() < 1 || !args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Must pass string as first argument")));
        return scope.Close(Undefined());
    }

    char argbuf[10];
    Local<String> s = args[0]->ToString();
    s->WriteUtf8(argbuf, 10, NULL, 0);
    if(strcmp("latex", argbuf) == 0) {
        format = LATEX_FORMAT;
    }
    else {
        format = HTML_FORMAT;
    }
}

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("convert"),
            FunctionTemplate::New(convert)->GetFunction());
}


NODE_MODULE(multimarkdown, init)
