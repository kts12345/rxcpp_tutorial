//01_02.js

var Rx = require("rx")








function test_01_02() {
//-----------------------------------------------------------------------------
  function onSubscribe(observer) {
    var events = [ 
        ()=>observer.onNext(21) 
      , ()=>observer.onCompleted() 
      , ()=>observer.onNext(22)
    ];

    setTimeout(events[0], 1000);
    setTimeout(events[1], 3000);
    setTimeout(events[2], 5000);

    var onDispose = ()=> console.log("onDispose");
    return onDispose;
  };
  
  var handlerNext =       i=> console.log  ("onNext: " + i);
  var handlerError =      e=> console.error("onError: " + e.message);
  var handlerCompleted = ()=> console.log  ("onCompleted");
  
  //--------------
  var observable   = Rx.Observable.create(onSubscribe);
  var subscription = observable.subscribe(handlerNext,
                                          handlerError,
                                          handlerCompleted);
//-----------------------------------------------------------------------------
};

/* 실행결과
 
[14:47:28] [LOG] ----- test start -----
[14:47:29] [LOG] onNext: 21
[14:47:31] [LOG] onCompleted
[14:47:31] [LOG] onDispose
[14:47:33] [LOG] ----- test end   -----

 */
module.exports = test_01_02;

