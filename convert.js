var MMD = require("./build/Release/multimarkdown.node");
var input = "";

process.stdin.on("data", function(chunk){
    input += chunk.toString();
});
process.stdin.on("end", function(){
    console.log(MMD.convert(input));
    process.exit(0);
});

process.stdin.resume();
