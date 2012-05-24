var MMD = require("./build/Release/multimarkdown.node");

var expected = {
    "a": "<p>a</p>",
    "ab": "<p>ab</p>",
    "c": "<p>c</p>"
};

console.log("MultiMarkdown Test");

for(var input in expected){
    var out = MMD.convert(input);
    if(expected[input] !== out) {
        console.log("FAIL");
        console.log(input, ">>", expected[input], out);
    } else {
        console.log("OK  ");
    }
}
