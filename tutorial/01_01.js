//01_01.js

var Rx = require("rx") 






function test_01_01() {
//-----------------------------------------------------------------------------
  var whenSubscribe = (observer) => {
    observer.onNext(11);
    observer.onNext(12);
    observer.onCompleted();
  };
  
  var handler_next      = (i)=> console.log  ("on_next: "  + i);
  var handler_error     = (e)=> console.error("on_error: " + e.message);
  var handler_completed = () => console.info ("on_completed");
  
  var observable   = Rx.Observable.create(whenSubscribe);
  var subscription = observable.subscribe(handler_next,
										                      handler_error,
										                      handler_completed);
//-----------------------------------------------------------------------------
}

module.exports = test_01_01; 