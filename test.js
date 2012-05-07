var MMD = require("./build/Release/multimarkdown");
var FS = require("fs");
var WaitGroup = require("./deps/waitgroup.js/lib/waitgroup.js");
var path = "deps/peg-multimarkdown/MarkdownTest/MultiMarkdownTests";

FS.readdir(path, function(err, files){
    files = files.slice(2);
    files.forEach(function(f){
        if(f.indexOf(".text") == -1) {
            return;
        }

        var wg = new WaitGroup;
        var htmlName = f.replace(".text", ".html");
        var referenceData, outputData;

        wg.add()
        FS.readFile(path + "/" + f, "utf8", function(err, data){
            var outputData = MMD.convert(data);
            wg.done();
        });

        wg.add();
        FS.readFile(path + "/" + htmlName, "utf8", function(err, data){
            htmlData = data;
            wg.done();
        });

        wg.wait(function(){
            if(outputData !== htmlData) {
                console.log(f + " !== " + htmlName);
            } else {
                console.log(f + " OK\n");
            }
        });
    });
});
