//01_03.js

var Rx = require("rx") 






function test_01_01() {
//-----------------------------------------------------------------------------
  var whenSubscribe = (observer) => {
    observer.onNext(31);
    observer.onNext(32);
    //observer.onCompleted();
    
    var whenDispose = () => {
      console.log("when dispose");
    }

    return whenDispose;

  };
  
  var handler_next      = (i)=> console.log  ("on_next: "  + i);
  var handler_error     = (e)=> console.error("on_error: " + e.message);
  var handler_completed = () => console.info ("on_completed");
  
  var observable   = Rx.Observable.create(whenSubscribe);
  var subscription = observable.subscribe(handler_next,
										                      handler_error,
										                      handler_completed);
  subscription.dispose();
//-----------------------------------------------------------------------------
}

module.exports = test_01_01; 