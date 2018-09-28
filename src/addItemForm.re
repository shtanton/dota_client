module U = KaretUtil;
module L = Lens;
open L.Infix;

let component = ReasonReact.statelessComponent("AddItemForm");

module Item = {
	type t = {
		name: string,
		price: int,
		recipe: array(int),
	};

	module Lens = {
		let name = L.lens(i => i.name, (name, i) => {...i, name});
		let price = L.lens(i => i.price, (price, i) => {...i, price});
		let recipe = L.lens(i => i.recipe, (recipe, i) => {...i, recipe});
	};
}

let make = (~value, _children) => {
	...component,
	render: _ => {
		<div>
			<Karet.Input value=U.view(Item.Lens.name, value)/>
			<Karet.Input value=U.view(Item.Lens.price <-> L.string_of_int, value)/>
		</div>
	}
};
