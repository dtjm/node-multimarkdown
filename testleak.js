var MMD = require("./build/Release/multimarkdown.node");

var i = 0;
var input = "";
while(true){
    //console.log(i+=10);
    MMD.convert(input);
    input += "aaaaaaaaaa";
}
