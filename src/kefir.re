type stream_like('a, 'b);
type _stream;
type stream('a) = stream_like(_stream, 'a);

[@bs.module "kefir"] external interval: int => 'a => stream('a) = "";

[@bs.module "kefir"] external fromEvents: Dom.eventTarget_like('b) => string => (Dom.event_like('c) => 'a) => stream('a) = "fromEvents";

[@bs.module "kefir"] external fromPromise: Js.Promise.t('a) => stream('a) = "fromPromise";

[@bs.send.pipe: stream('a)] external toProperty: (unit => 'a) => stream('a) = "toProperty";

[@bs.send] external _onValue: stream_like('t, 'a) => ('a => unit) => unit = "onValue";
let onValue = fn => s => _onValue(s, fn);

type event('a) =
| Value('a)
| Error('a)
| End;
[@bs.deriving abstract]
type jsEvent('a) = {
	[@bs.as "type"] type_: string,
	value: 'a,
};
type anySubscription('a) = jsEvent('a) => unit;
let onAnyBind = cb => e => {
	switch (type_Get(e)) {
		| "value" => cb(Value(valueGet(e)))
		| "error" => cb(Error(valueGet(e)))
		| "end" => cb(End)
		| _ => ()
	}
};
[@bs.send] external _onAny: stream_like('t, 'a) => (jsEvent('a) => unit) => unit = "onAny";
let onAny = cb => (s: stream_like('t, 'a)) => {
	let sub: anySubscription('a) = onAnyBind(cb);
	_onAny(
		s,
		sub,
	);
	sub;
};
[@bs.send] external _offAny: stream_like('t, 'a) => anySubscription('a) => unit = "offAny";
let offAny = cb => s => _offAny(
	s,
	cb,
);

[@bs.send] external _map: stream_like('t, 'a) => ('a => 'b) => stream_like('t, 'b) = "map";
let map = fn => s => _map(s, fn);

[@bs.send] external _scan: stream_like('t, 'a) => ('b => 'a => 'b) => 'b => stream_like('t, 'b) = "scan";
let scan = fn => init => s => _scan(s, fn, init);

[@bs.module "kefir"] external _combine: 'a => 'b => 'c = "combine";
let combine: ('a => 'b => 'c) => stream_like('t, 'a) => stream_like('t, 'b) => stream_like('t, 'c) =
	fn => a => b => _combine([|a, b|], fn);

[@bs.module "kefir"] external merge: array(stream_like('t, 'a)) => stream_like('t, 'a) = "merge";
