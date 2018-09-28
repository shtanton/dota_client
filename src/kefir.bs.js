// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Kefir = require("kefir");

function onValue(fn, s) {
  s.onValue(fn);
  return /* () */0;
}

function onAnyBind(cb, e) {
  var match = e.type;
  switch (match) {
    case "end" : 
        return Curry._1(cb, /* End */0);
    case "error" : 
        return Curry._1(cb, /* Error */Block.__(1, [e.value]));
    case "value" : 
        return Curry._1(cb, /* Value */Block.__(0, [e.value]));
    default:
      return /* () */0;
  }
}

function onAny(cb, s) {
  var sub = function (param) {
    return onAnyBind(cb, param);
  };
  s.onAny(sub);
  return sub;
}

function offAny(cb, s) {
  s.offAny(cb);
  return /* () */0;
}

function map(fn, s) {
  return s.map(fn);
}

function scan(fn, init, s) {
  return s.scan(fn, init);
}

function combine(fn, a, b) {
  return Kefir.combine(/* array */[
              a,
              b
            ], fn);
}

exports.onValue = onValue;
exports.onAnyBind = onAnyBind;
exports.onAny = onAny;
exports.offAny = offAny;
exports.map = map;
exports.scan = scan;
exports.combine = combine;
/* kefir Not a pure module */
