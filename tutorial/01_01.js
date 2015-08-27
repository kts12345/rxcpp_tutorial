//01_01.js

var Rx = require("rx") 






function test_01_01() {
//-----------------------------------------------------------------------------
  function onSubscribe(observer) {
    observer.onNext(11);
    observer.onNext(12);
    observer.onCompleted();
  };
  
  var handlerNext      = i  => console.log  ("onNext: "  + i);
  var handlerError     = e  => console.error("onError: " + e.message);
  var handlerCompleted = () => console.info ("onCompleted");
  
  var observable   = Rx.Observable.create(onSubscribe);
  var subscription = observable.subscribe(handlerNext,
										                      handlerError,
										                      handlerCompleted);
//-----------------------------------------------------------------------------
}

module.exports = test_01_01; 