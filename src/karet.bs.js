// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Kefir = require("./kefir.bs.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Karet");

function make(children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              var fn = function (data) {
                if (typeof data === "number") {
                  return /* () */0;
                } else {
                  return Curry._1(send, data[0]);
                }
              };
              var sub = Kefir.onAny(fn, children);
              return Curry._1(param[/* onUnmount */4], (function () {
                            return Kefir.offAny(sub, children);
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              return param[/* state */1];
            }),
          /* initialState */(function () {
              return null;
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (newState, _) {
              return /* Update */Block.__(0, [newState]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var Karet = /* module */[
  /* component */component,
  /* make */make
];

function toDom(s) {
  return ReasonReact.element(undefined, undefined, make(s));
}

var component$1 = ReasonReact.reducerComponent("Input");

function make$1(value, _) {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              var sub = Kefir.onAny((function (data) {
                      if (typeof data === "number") {
                        return /* () */0;
                      } else {
                        return Curry._1(send, data[0]);
                      }
                    }), value);
              return Curry._1(param[/* onUnmount */4], (function () {
                            return Kefir.offAny(sub, value);
                          }));
            }),
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function (param) {
              return React.createElement("input", {
                          value: param[/* state */1],
                          onChange: (function ($$event) {
                              value.set($$event.target.value);
                              return /* () */0;
                            })
                        });
            }),
          /* initialState */(function () {
              return "";
            }),
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */(function (state, _) {
              return /* Update */Block.__(0, [state]);
            }),
          /* jsElementWrapped */component$1[/* jsElementWrapped */13]
        ];
}

var Input = /* module */[
  /* component */component$1,
  /* make */make$1
];

exports.Karet = Karet;
exports.toDom = toDom;
exports.Input = Input;
/* component Not a pure module */
