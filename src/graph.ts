import graphql from "graphql.js";

const graph: (string) => (any?) => Promise<any> = graphql(
	"http://localhost:3000/graphql",
	{
		method: "POST",
		asJSON: true,
	},
);

export default graph;
