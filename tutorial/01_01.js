//01_01.js

var Rx = require("rx") 






function test_01_01() {
//-----------------------------------------------------------------------------
  function onSubscribe(observer) {
    observer.onNext(11);
    observer.onCompleted();
    observer.onNext(12);

    var onDispose = ()=>console.log("onDispose");
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
//-----------------------------------------------------------------------------
}

/* 실행 결과

[14:46:09] [LOG] ----- test start -----
[14:46:09] [LOG] onNext: 11
[14:46:09] [LOG] onCompleted
[14:46:09] [INFO] onDispose
[14:46:09] [LOG] ----- test end   -----

 */
module.exports = test_01_01; 