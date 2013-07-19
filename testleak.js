var MMD = require("./build/Release/multimarkdown.node");

var i = 0;
var input = "";
while(i < 1000000){
    //console.log(i+=10);
    MMD.convert(input);
    input += "aaaaaaaaaa";
}