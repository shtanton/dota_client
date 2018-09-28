[@bs.deriving abstract]
type options = {
	method: string,
	headers: Js.Dict.t(string),
	asJSON: bool,
};
type graph;

[@bs.module] external _graphql: (string, options) => graph = "graphql.js";
let graphql = (~headers=[], ~method="POST", ~asJSON=false, url) => {
	let _headers = Js.Dict.fromList(headers);
	_graphql(
		url,
		options(
			~headers=_headers,
			~method,
			~asJSON,
		),
	);
};

[@bs.send] external query: graph => string => 'a => Js.Promise.t('b) = "query";
