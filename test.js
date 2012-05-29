var MMD = require("./build/Release/multimarkdown.node");

var expected = {
    "aabb": "<p>aabb</p>",
    "ab": "<p>ab</p>",
    "c": "<p>c</p>",
    "å": "<p>å</p>"
};

console.log("MultiMarkdown Test");

for(var input in expected){
    var out = MMD.convert(input);
    if(expected[input] !== out) {
        console.log("FAIL");
        console.log("input:", input, "expected:", expected[input], "actual:", out);
    } else {
        console.log("OK  ");
    }
}
