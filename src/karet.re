module Karet = {
	let component = ReasonReact.reducerComponent("Karet");

	let make = (children: Kefir.stream_like('t, ReasonReact.reactElement)) => {
		...component,
			initialState: () => ReasonReact.null,
			reducer: (newState, _) => {
				ReasonReact.Update(newState);
			},
			didMount: ({send, onUnmount}) => {
				let fn = data => {
					Kefir.(
						switch data {
							| Value(contents) => send(contents)
							| Error(err) => send(err)
							| End => ()
							}
					)
				};
				let sub = children |> Kefir.onAny(fn);
				onUnmount(() => Kefir.offAny(sub, children));
			},
			render: ({state}) => {
				state;
			}
	};
};

let toDom = s => <Karet> ...s </Karet>;

module Input = {
	let component = ReasonReact.reducerComponent("Input");

	let make = (~value, _children) => {
		...component,
		initialState: () => "",
		reducer: (state, _) => ReasonReact.Update(state),
		didMount: ({send, onUnmount}) => {
			let sub = value |> Kefir.onAny(data => {
				Kefir.(
					switch data {
						| Value(contents) => send(contents)
						| Error(err) => send(err)
						| End => ()
					}
				)
			});
			onUnmount(() => Kefir.offAny(sub, value));
		},
		render: ({state}) => <input
			value=state
			onChange={
				event => {
					KaretUtil.set(ReactEvent.Form.target(event)##value, value)
				}
			}
		/>
	};
}
