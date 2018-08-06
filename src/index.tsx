import * as React from "karet";
import { render } from "react-dom";
import Kefir from "kefir";
import * as R from "ramda";
import * as U from "karet.util";
import * as L from "partial.lenses";
import graph from "./graph";

import AddItemForm from "./AddItemForm";

const getItems = graph(`
	query items {
		items {
			id
			name
			price
		}
	}
`);

const items = U.thru(getItems, U.fromPromise, U.view(["items", L.valueOr([])]));

const App = () => (
	<div>
		{U.mapElemsWithIds(
			"id",
			(elem, id) => <div key={id}>{U.view("name", elem)}</div>,
			items,
		)}
		<AddItemForm />
	</div>
);

render(<App />, document.getElementById("react"));
