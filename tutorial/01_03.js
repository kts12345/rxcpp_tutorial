//01_03.js

var Rx = require("rx")






function test_01_03() {
//-----------------------------------------------------------------------------
  function onSubscribe(observer){
    function gen_events() {
      observer.onNext(21);
      observer.onNext(22);
      observer.onCompleted();
    };
    setTimeout(gen_events, 2000);

    var onDispose = ()=> console.info("onDispose");
    return onDispose;
  };
  
  var handlerNext      = (i)=> console.log  ("onNext: "  + i);
  var handlerError     = (e)=> console.error("onError: " + e.message);
  var handlerCompleted = () => console.info ("onCompleted");
  
  var observable   = Rx.Observable.create(onSubscribe);
  var subscription = observable.subscribe(handlerNext,
                                          handlerError,
                                          handlerCompleted);

  var dispose = ()=>subscription.dispose(); 
  setTimeout(dispose, 3000);
//-----------------------------------------------------------------------------
};

module.exports = test_01_03;

