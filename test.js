var MMD = require("./build/Release/multimarkdown");

setInterval(function(){
    console.log(MMD.convert("### heading"));
}, 200);
