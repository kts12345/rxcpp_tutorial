//main.js 

// Patch console.x methods in order to add timestamp information
require("console-stamp")(console, "HH:MM:ss");













console.log("----- test start -----");
//-----------------------------------------------------------------------------
//require("./01_01.js")();
//require("./01_02.js")();
  require("./01_03.js")();
//-----------------------------------------------------------------------------

process.on(
    'exit'
  , ()=> console.log("----- test end   -----")
);
