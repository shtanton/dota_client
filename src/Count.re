let component  = ReasonReact.statelessComponent("Count");

let make = (~message, _children) => {
	...component,
	render: (_self) =>
		<div>{ReasonReact.string(message)}</div>
};
