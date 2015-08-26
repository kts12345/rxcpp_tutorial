//01_03.js

var Rx = require("rx")






function test_01_03() {
//-----------------------------------------------------------------------------
  var whenSubscribe = (observer) => {
  //  var gen_events = () => {
      observer.onNext(21);
      observer.onNext(22);
      observer.onCompleted();
   // };
   // setTimeout(gen_events, 500);

    var on_dispose = ()=> 
          console.info("on_dispose");
    //return on_dispose;
  };
  
  var handler_next      = (i)=> { throw {message:"aaa"} ; }; // console.log ("on_next: " + i);
  var handler_error     = (e)=> console.error("on_error: " + e.message);
  var handler_completed = () => console.info ("on_completed");
  
  var observable   = Rx.Observable.create(whenSubscribe);
  var subscription = observable.subscribe(handler_next,
                                          handler_error,
                                          handler_completed);
//-----------------------------------------------------------------------------
};

module.exports = test_01_03;

