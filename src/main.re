module U = KaretUtil;
module L = Lens;

let (>|=) = p => fn => Js.Promise.then_(value => Js.Promise.resolve(fn(value)), p);
let (>>=) = p => fn => Js.Promise.then_(fn, p);

let graph = Graphql.graphql(~asJSON=true, ~method="POST", "http://localhost:3000/graphql");

type item = {
	name: string,
	price: int
}

module Items = {
	type input = unit;
	[@bs.deriving abstract]
		type _item = {
			name: string,
			price: int
		};
	[@bs.deriving abstract]
		type output = {
			items: array(_item),
		};
	let run: input => Js.Promise.t(array(item)) = variables => Graphql.query(graph, {|
	query {
		items {
			name
			price
		}
	}
	|}, variables) >|= (data => {
		itemsGet(data) |>
		Array.map(item => {
			name: nameGet(item),
			price: priceGet(item)
		})
	})
};

let items = Items.run() |> Kefir.fromPromise |> Kefir.toProperty(() => [||]);

let itemsDom = items |> Kefir.map(s => s |> Array.map(item => <li>{ReasonReact.string(item.name)}</li>) |> ReasonReact.array |> (l => <ul>l</ul>)) |> Karet.toDom;

let initialItem = AddItemForm.Item.{
	name: "",
	price: 0,
	recipe: [||],
};

let item = KaretUtil.atom(initialItem);

ReactDOMRe.renderToElementWithId(
	<div>
		itemsDom
		<AddItemForm value=item/>
	</div>,
	"react"
);
