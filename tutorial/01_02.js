//01_02.js

var Rx = require("rx")






function test_01_02() {
//-----------------------------------------------------------------------------
  function onSubscribe(observer) {
    function genEvents() {
      observer.onNext(21);
      observer.onNext(22);
      observer.onCompleted();
    };
    setTimeout(genEvents, 2000);
  };
  
  var handlerNext =       i => console.log  ("onNext: " + i);
  var handlerError =      e => console.error("onError: " + e.message);
  var handlerCompleted = () => console.info ("onCompleted");
  
  var observable   = Rx.Observable.create(onSubscribe);
  var subscription = observable.subscribe(handlerNext,
                                          handlerError,
                                          handlerCompleted);
//-----------------------------------------------------------------------------
};

module.exports = test_01_02;

