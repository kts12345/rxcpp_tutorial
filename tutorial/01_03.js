//01_03.js

var Rx = require("rx")








function test_01_03() {
//-----------------------------------------------------------------------------
  function onSubscribe(observer) {
    var events = [ 
        ()=> observer.onNext(31) 
      , ()=> observer.onCompleted() 
      , ()=> observer.onNext(32)
    ];

    setTimeout(events[0], 1000);
    setTimeout(events[1], 3000);
    setTimeout(events[2], 5000);

    var onDispose = ()=> console.log("onDispose");
    return onDispose;
  };
  
  var handlerNext      =  i=> console.log  ("onNext: "  + i);
  var handlerError     =  e=> console.error("onError: " + e.message);
  var handlerCompleted = ()=> console.log  ("onCompleted");
  
  //--------------
  var observable   = Rx.Observable.create(onSubscribe);
  var subscription = observable.subscribe(handlerNext,
                                          handlerError,
                                          handlerCompleted);

  setTimeout(
      ()=>subscription.dispose()
    , 2000);
//-----------------------------------------------------------------------------
};

/* ������

[14:50:01] [LOG] ----- test start -----
[14:50:02] [LOG] onNext: 31
[14:50:03] [LOG] onDispose
[14:50:06] [LOG] ----- test end   -----

 */
module.exports = test_01_03;

