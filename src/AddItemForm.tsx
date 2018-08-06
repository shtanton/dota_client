import * as React from "karet";
import * as L from "partial.lenses";
import * as U from "karet.util";
import graph from "./graph";

interface item {
	name: string;
	price: number;
	ingredients: Array<number>;
}

const mutate = graph(`
	mutation addItem ($item: AddItemInput!) {
		addItem(item: $item)
	}
`);

const addItem = (item: item) => mutate({ item }) as Promise<number>;

const value = U.atom({});

const numberLens = L.lens(
	(n: number) => n.toString(),
	(s: string) => parseInt(s.replace(/[^0-9]/g, "") || "0"),
);

const Template = () => (
	<div>
		<U.Input value={U.view(["name", L.valueOr("")], value)} />
		<U.Input value={U.view(["price", L.valueOr(0), numberLens], value)} />
	</div>
);

export default Template;
