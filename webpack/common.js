const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = {
	entry: {
		main: "./src/main.bs.js",
	},
	output: {
		filename: "[name].js",
		path: path.resolve("dist"),
	},
	module: {
		rules: [
			{
				test: /\.[jt]s$/,
				exclude: /node_modules/,
			},
		],
	},
	plugins: [
		new HtmlWebpackPlugin({
			template: "src/index.html",
			filename: "index.html",
		}),
	],
	resolve: {
		extensions: [".js"],
	},
};
